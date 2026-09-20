#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "axis.h"
#include "config.h"

#define CALIBRATION_VERSION 2u

typedef struct {
    uint32_t magic;
    uint32_t version;
    axis_config_t axis[HELI_AXIS_COUNT];
    uint32_t crc32;
} calibration_data_t;

void calibration_defaults(calibration_data_t *data);
bool calibration_validate(const calibration_data_t *data);
bool calibration_load(calibration_data_t *data);
bool calibration_save(calibration_data_t *data);
