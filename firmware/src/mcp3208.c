#include "mcp3208.h"
#include "config.h"
#include "hardware/spi.h"
#include "pico/stdlib.h"

#ifndef HELI_SPI
#define HELI_SPI spi0
#endif

void mcp3208_init(void) {
    spi_init(HELI_SPI, HELI_SPI_BAUD_HZ);
    spi_set_format(HELI_SPI, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);

    gpio_set_function(HELI_PIN_SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(HELI_PIN_SPI_MOSI, GPIO_FUNC_SPI);
    gpio_set_function(HELI_PIN_SPI_MISO, GPIO_FUNC_SPI);

    gpio_init(HELI_PIN_SPI_CS);
    gpio_set_dir(HELI_PIN_SPI_CS, GPIO_OUT);
    gpio_put(HELI_PIN_SPI_CS, 1);
}

uint16_t mcp3208_read(uint8_t channel) {
    channel &= 7u;
    uint8_t tx[3] = {
        (uint8_t)(0x06u | (channel >> 2)),
        (uint8_t)(channel << 6),
        0u
    };
    uint8_t rx[3] = {0};

    gpio_put(HELI_PIN_SPI_CS, 0);
    spi_write_read_blocking(HELI_SPI, tx, rx, 3);
    gpio_put(HELI_PIN_SPI_CS, 1);

    return (uint16_t)(((rx[1] & 0x0Fu) << 8) | rx[2]);
}

uint16_t mcp3208_read_oversampled(uint8_t channel) {
    // Four 12-bit samples are accumulated directly into a 14-bit numeric
    // domain (0..16380). This preserves the existing calibration scale while
    // keeping seven-axis acquisition within the 1 ms report budget.
    uint32_t sum = 0;
    for (uint8_t i = 0; i < HELI_ADC_SAMPLES_PER_AXIS; ++i) {
        sum += mcp3208_read(channel);
    }
    return (uint16_t)sum;
}
