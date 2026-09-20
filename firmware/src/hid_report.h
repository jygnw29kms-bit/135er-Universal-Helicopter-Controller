#pragma once
#include <stdint.h>

typedef struct __attribute__((packed)) {
    uint16_t cyclic_roll;
    uint16_t cyclic_pitch;
    uint16_t collective;
    uint16_t throttle;
    uint16_t pedals;
    uint16_t brake_left;
    uint16_t brake_right;
    uint32_t buttons;
    uint8_t hat;
} heli_hid_report_t;

void hid_report_init(heli_hid_report_t *report);
