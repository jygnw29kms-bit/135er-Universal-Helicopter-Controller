#pragma once
#include <stdint.h>
#include <stdbool.h>
typedef enum { AXIS_BIPOLAR=0, AXIS_UNIPOLAR=1 } axis_mode_t;
typedef struct { uint16_t raw_min,raw_center,raw_max,filtered_raw,deadzone; axis_mode_t mode; bool invert; } axis_state_t;
uint16_t axis_filter(axis_state_t *a,uint16_t sample);
uint16_t axis_map(axis_state_t *a,uint16_t raw);
