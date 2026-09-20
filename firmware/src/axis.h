#pragma once
#include <stdint.h>

typedef struct {
    uint16_t raw_min;
    uint16_t raw_center;
    uint16_t raw_max;
    uint16_t deadzone;
    uint16_t filtered;
} axis_state_t;

uint16_t axis_apply_calibration(axis_state_t *axis, uint16_t raw);
uint16_t axis_filter(axis_state_t *axis, uint16_t sample);
