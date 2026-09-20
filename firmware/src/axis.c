#include "axis.h"
#include "config.h"
#include <string.h>

static uint16_t clamp_u16(int32_t value) {
    if (value < 0) return 0;
    if (value > 65535) return 65535;
    return (uint16_t)value;
}

void axis_state_init(axis_state_t *state, const axis_config_t *config) {
    memset(state, 0, sizeof(*state));
    state->config = *config;
}

void axis_state_set_config(axis_state_t *state, const axis_config_t *config) {
    state->config = *config;
    state->filter_seeded = false;
    state->filtered_raw = 0;
}

bool axis_config_valid(const axis_config_t *c) {
    if (!c) return false;
    if (c->raw_max > HELI_ADC_RAW_MAX || c->raw_min >= c->raw_max) return false;
    if (c->mode > AXIS_UNIPOLAR || c->invert > 1u) return false;
    if (c->filter_shift > 5u || c->expo > 100u) return false;
    if (c->mode == AXIS_BIPOLAR &&
        !(c->raw_min < c->raw_center && c->raw_center < c->raw_max)) return false;
    return true;
}

uint16_t axis_filter(axis_state_t *state, uint16_t sample) {
    if (!state->filter_seeded || state->config.filter_shift == 0u) {
        state->filtered_raw = sample;
        state->filter_seeded = true;
        return sample;
    }

    int32_t delta = (int32_t)sample - (int32_t)state->filtered_raw;
    int32_t step = delta >> state->config.filter_shift;

    // Ensure a one-count correction is not lost forever through integer rounding.
    if (step == 0 && delta != 0) step = (delta > 0) ? 1 : -1;
    state->filtered_raw = (uint16_t)((int32_t)state->filtered_raw + step);
    return state->filtered_raw;
}

static uint16_t apply_center_deadzone(uint16_t value, uint16_t deadzone) {
    if (deadzone == 0u || deadzone >= 32767u) return value;

    int32_t x = (int32_t)value - 32768;
    int32_t mag = x < 0 ? -x : x;
    if (mag <= deadzone) return 32768u;

    int32_t remaining = 32767 - (int32_t)deadzone;
    int32_t scaled = ((mag - (int32_t)deadzone) * 32767) / remaining;
    if (scaled > 32767) scaled = 32767;
    return clamp_u16(32768 + (x < 0 ? -scaled : scaled));
}

static uint16_t apply_bipolar_expo(uint16_t value, uint8_t expo) {
    if (expo == 0u) return value;

    int64_t x = (int32_t)value - 32768;
    int64_t cubic = (x * x * x) / (32768LL * 32768LL);
    int64_t mixed = ((100 - expo) * x + expo * cubic) / 100;
    return clamp_u16((int32_t)(32768 + mixed));
}

uint16_t axis_map(const axis_state_t *state, uint16_t raw) {
    const axis_config_t *c = &state->config;
    if (raw < c->raw_min) raw = c->raw_min;
    if (raw > c->raw_max) raw = c->raw_max;

    uint32_t out;
    if (c->mode == AXIS_UNIPOLAR) {
        uint32_t span = (uint32_t)c->raw_max - c->raw_min;
        out = span ? ((uint32_t)(raw - c->raw_min) * 65535u) / span : 0u;
    } else if (raw <= c->raw_center) {
        uint32_t span = (uint32_t)c->raw_center - c->raw_min;
        out = span ? ((uint32_t)(raw - c->raw_min) * 32768u) / span : 32768u;
    } else {
        uint32_t span = (uint32_t)c->raw_max - c->raw_center;
        out = span ? 32768u + ((uint32_t)(raw - c->raw_center) * 32767u) / span : 32768u;
    }

    uint16_t mapped = (uint16_t)out;
    if (c->mode == AXIS_BIPOLAR) {
        mapped = apply_center_deadzone(mapped, c->deadzone);
        mapped = apply_bipolar_expo(mapped, c->expo);
    }
    if (c->invert) mapped = (uint16_t)(65535u - mapped);
    return mapped;
}

uint16_t axis_process(axis_state_t *state, uint16_t sample) {
    return axis_map(state, axis_filter(state, sample));
}
