#pragma once
#include <stdbool.h>
#include "axis.h"

#define HELI_AXIS_COUNT 7

typedef struct {
    axis_state_t axis[HELI_AXIS_COUNT];
    uint32_t version;
    uint32_t crc32;
} calibration_data_t;

void calibration_defaults(calibration_data_t *data);
bool calibration_load(calibration_data_t *data);
bool calibration_save(const calibration_data_t *data);
