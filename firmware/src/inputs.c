#include "inputs.h"
#include "config.h"
#include "pico/stdlib.h"

typedef struct {
    uint8_t count;
    bool stable_pressed;
} debounce_t;

static debounce_t button_db[HELI_BUTTON_COUNT];
static debounce_t hat_db[4];

static bool update_debounce(debounce_t *d, bool pressed) {
    if (pressed == d->stable_pressed) {
        d->count = 0;
        return d->stable_pressed;
    }
    if (++d->count >= HELI_INPUT_DEBOUNCE_SAMPLES) {
        d->stable_pressed = pressed;
        d->count = 0;
    }
    return d->stable_pressed;
}

static void init_input(uint pin) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_IN);
    gpio_pull_up(pin);
}

void inputs_init(void) {
    for (uint8_t i = 0; i < HELI_BUTTON_COUNT; ++i) init_input(HELI_BUTTON_PINS[i]);
    init_input(HELI_PIN_HAT_UP);
    init_input(HELI_PIN_HAT_RIGHT);
    init_input(HELI_PIN_HAT_DOWN);
    init_input(HELI_PIN_HAT_LEFT);
}

void inputs_task(void) {
    for (uint8_t i = 0; i < HELI_BUTTON_COUNT; ++i) {
        update_debounce(&button_db[i], !gpio_get(HELI_BUTTON_PINS[i]));
    }
    update_debounce(&hat_db[0], !gpio_get(HELI_PIN_HAT_UP));
    update_debounce(&hat_db[1], !gpio_get(HELI_PIN_HAT_RIGHT));
    update_debounce(&hat_db[2], !gpio_get(HELI_PIN_HAT_DOWN));
    update_debounce(&hat_db[3], !gpio_get(HELI_PIN_HAT_LEFT));
}

uint32_t inputs_buttons(void) {
    uint32_t bits = 0;
    for (uint8_t i = 0; i < HELI_BUTTON_COUNT; ++i) {
        if (button_db[i].stable_pressed) bits |= (1u << i);
    }
    return bits;
}

uint8_t inputs_hat(void) {
    bool up = hat_db[0].stable_pressed;
    bool right = hat_db[1].stable_pressed;
    bool down = hat_db[2].stable_pressed;
    bool left = hat_db[3].stable_pressed;

    if (up && down) up = down = false;
    if (left && right) left = right = false;

    if (up && right) return 1;
    if (down && right) return 3;
    if (down && left) return 5;
    if (up && left) return 7;
    if (up) return 0;
    if (right) return 2;
    if (down) return 4;
    if (left) return 6;
    return 8;
}
