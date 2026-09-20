#include <stdio.h>
#include "pico/stdlib.h"
#include "axis.h"
#include "calibration.h"
#include "hid_report.h"

int main(void) {
    stdio_init_all();

    calibration_data_t calibration;
    calibration_load(&calibration);

    heli_hid_report_t report;
    hid_report_init(&report);

    while (true) {
        // TODO:
        // 1. Read Hall sensors
        // 2. Filter + calibrate
        // 3. Read buttons / hat
        // 4. Send TinyUSB HID report
        sleep_ms(1);
    }

    return 0;
}
