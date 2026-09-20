#pragma once
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    AXIS_BIPOLAR = 0,
    AXIS_UNIPOLAR = 1
} axis_mode_t;

typedef struct {
    uint16_t raw_min;
    uint16_t raw_center;
    uint16_t raw_max;
    uint16_t deadzone;
    uint8_t mode;
    uint8_t invert;
    uint8_t filter_shift;
    uint8_t expo;
} axis_config_t;

typedef struct {
    axis_config_t config;
    uint16_t filtered_raw;
    bool filter_seeded;
} axis_state_t;

void axis_state_init(axis_state_t *state, const axis_config_t *config);
void axis_state_set_config(axis_state_t *state, const axis_config_t *config);
bool axis_config_valid(const axis_config_t *config);
uint16_t axis_filter(axis_state_t *state, uint16_t sample);
uint16_t axis_map(const axis_state_t *state, uint16_t raw);
uint16_t axis_process(axis_state_t *state, uint16_t sample);
