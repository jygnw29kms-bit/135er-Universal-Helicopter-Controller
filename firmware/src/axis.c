#include "axis.h"

static uint16_t clamp_u16(int32_t v) {
    if (v < 0) return 0;
    if (v > 65535) return 65535;
    return (uint16_t)v;
}

uint16_t axis_filter(axis_state_t *axis, uint16_t sample) {
    // Lightweight IIR filter: 75% previous, 25% new sample.
    uint32_t filtered = ((uint32_t)axis->filtered * 3u + sample) / 4u;
    axis->filtered = (uint16_t)filtered;
    return axis->filtered;
}

uint16_t axis_apply_calibration(axis_state_t *axis, uint16_t raw) {
    if (raw <= axis->raw_center) {
        uint32_t span = axis->raw_center - axis->raw_min;
        if (span == 0) return 32768;
        int32_t out = (int32_t)((uint32_t)(raw - axis->raw_min) * 32768u / span);
        return clamp_u16(out);
    }

    uint32_t span = axis->raw_max - axis->raw_center;
    if (span == 0) return 32768;
    uint32_t out = 32768u + ((uint32_t)(raw - axis->raw_center) * 32767u / span);
    return clamp_u16((int32_t)out);
}
