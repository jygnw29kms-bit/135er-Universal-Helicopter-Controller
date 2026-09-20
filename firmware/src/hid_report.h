#pragma once
#include <stdint.h>
typedef struct __attribute__((packed)){uint16_t cyclic_roll,cyclic_pitch,collective,throttle,pedals,brake_left,brake_right;uint32_t buttons;uint8_t hat;} heli_hid_report_t;
void hid_report_init(heli_hid_report_t*r);
