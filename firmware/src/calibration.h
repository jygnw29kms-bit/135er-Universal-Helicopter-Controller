#pragma once
#include <stdbool.h>
#include <stdint.h>
#include "axis.h"
#define HELI_AXIS_COUNT 7
typedef struct{uint32_t magic,version;axis_state_t axis[HELI_AXIS_COUNT];uint32_t crc32;} calibration_data_t;
void calibration_defaults(calibration_data_t*d);
bool calibration_load(calibration_data_t*d);
bool calibration_save(const calibration_data_t*d);
