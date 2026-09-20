#pragma once
#include <stdint.h>

#define HELI_AXIS_COUNT 7
#define HELI_BUTTON_COUNT 8
#define HELI_HID_INTERVAL_US 1000u

#define HELI_SPI_BAUD_HZ 1000000u
#define HELI_ADC_SAMPLES_PER_AXIS 4u
#define HELI_ADC_RAW_MAX 16380u

#define HELI_PIN_SPI_MISO 16
#define HELI_PIN_SPI_CS   17
#define HELI_PIN_SPI_SCK  18
#define HELI_PIN_SPI_MOSI 19

// Eight active-low direct buttons. Expansion beyond eight buttons is planned
// via a shift-register/I/O-expander source without changing the HID format.
static const uint8_t HELI_BUTTON_PINS[HELI_BUTTON_COUNT] = {2,3,4,5,6,7,8,9};

// Active-low four-way hat. Diagonals are generated from simultaneous presses.
#define HELI_PIN_HAT_UP    10
#define HELI_PIN_HAT_RIGHT 11
#define HELI_PIN_HAT_DOWN  12
#define HELI_PIN_HAT_LEFT  13

#define HELI_INPUT_DEBOUNCE_SAMPLES 5u
