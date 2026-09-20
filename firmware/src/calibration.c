#include "calibration.h"
#include "hardware/flash.h"
#include "hardware/regs/addressmap.h"
#include "hardware/sync.h"
#include "pico/stdlib.h"
#include <string.h>

#define CAL_MAGIC 0x48454C49u
#define CAL_FLASH_OFFSET (PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE)

static uint32_t crc32(const uint8_t *p, size_t n) {
    uint32_t c = 0xFFFFFFFFu;
    while (n--) {
        c ^= *p++;
        for (int k = 0; k < 8; ++k)
            c = (c >> 1) ^ (0xEDB88320u & -(int32_t)(c & 1u));
    }
    return ~c;
}

static uint32_t calibration_crc(const calibration_data_t *d) {
    return crc32((const uint8_t *)d, sizeof(*d) - sizeof(d->crc32));
}

void calibration_defaults(calibration_data_t *d) {
    memset(d, 0, sizeof(*d));
    d->magic = CAL_MAGIC;
    d->version = CALIBRATION_VERSION;

    for (uint8_t i = 0; i < HELI_AXIS_COUNT; ++i) {
        axis_config_t *a = &d->axis[i];
        a->raw_min = 300;
        a->raw_center = 8190;
        a->raw_max = 16000;
        a->deadzone = (i == 0 || i == 1 || i == 4) ? 120 : 0;
        a->mode = (i == 0 || i == 1 || i == 4) ? AXIS_BIPOLAR : AXIS_UNIPOLAR;
        a->invert = 0;
        a->filter_shift = 2; // 1/4 IIR correction per new sample.
        a->expo = 0;
    }
    d->crc32 = calibration_crc(d);
}

bool calibration_validate(const calibration_data_t *d) {
    if (!d || d->magic != CAL_MAGIC || d->version != CALIBRATION_VERSION) return false;
    if (d->crc32 != calibration_crc(d)) return false;
    for (uint8_t i = 0; i < HELI_AXIS_COUNT; ++i) {
        if (!axis_config_valid(&d->axis[i])) return false;
    }
    return true;
}

bool calibration_load(calibration_data_t *d) {
    const calibration_data_t *stored =
        (const calibration_data_t *)(XIP_BASE + CAL_FLASH_OFFSET);

    memcpy(d, stored, sizeof(*d));
    if (!calibration_validate(d)) {
        calibration_defaults(d);
        return false;
    }
    return true;
}

bool calibration_save(calibration_data_t *d) {
    if (!d) return false;
    d->magic = CAL_MAGIC;
    d->version = CALIBRATION_VERSION;
    d->crc32 = calibration_crc(d);
    if (!calibration_validate(d)) return false;

    uint8_t sector[FLASH_SECTOR_SIZE];
    memset(sector, 0xFF, sizeof(sector));
    memcpy(sector, d, sizeof(*d));

    uint32_t irq_state = save_and_disable_interrupts();
    flash_range_erase(CAL_FLASH_OFFSET, FLASH_SECTOR_SIZE);
    flash_range_program(CAL_FLASH_OFFSET, sector, FLASH_SECTOR_SIZE);
    restore_interrupts(irq_state);
    return true;
}
