#include "hid_report.h"
#include <string.h>

void hid_report_init(heli_hid_report_t *report) {
    memset(report, 0, sizeof(*report));
    report->cyclic_roll = 32768;
    report->cyclic_pitch = 32768;
    report->pedals = 32768;
    report->hat = 8; // HID neutral hat
}
