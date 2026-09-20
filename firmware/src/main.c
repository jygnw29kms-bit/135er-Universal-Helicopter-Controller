#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"
#include "axis.h"
#include "calibration.h"
#include "cli.h"
#include "config.h"
#include "hid_report.h"
#include "inputs.h"
#include "mcp3208.h"
#include <string.h>

static calibration_data_t cal;
static axis_state_t axes[HELI_AXIS_COUNT];
static heli_hid_report_t report;
static heli_diagnostics_t diag;

static void sample_axes(void) {
    uint16_t value[HELI_AXIS_COUNT];
    for (uint8_t i = 0; i < HELI_AXIS_COUNT; ++i) {
        uint16_t raw = mcp3208_read_oversampled(i);
        diag.latest_raw[i] = raw;
        value[i] = axis_process(&axes[i], raw);
    }

    report.cyclic_roll = value[0];
    report.cyclic_pitch = value[1];
    report.collective = value[2];
    report.throttle = value[3];
    report.pedals = value[4];
    report.brake_left = value[5];
    report.brake_right = value[6];
}

int main(void) {
    board_init();
    mcp3208_init();
    inputs_init();

    calibration_load(&cal);
    for (uint8_t i = 0; i < HELI_AXIS_COUNT; ++i)
        axis_state_init(&axes[i], &cal.axis[i]);

    hid_report_init(&report);
    memset(&diag, 0, sizeof(diag));
    cli_init(&cal, axes, &diag);

    tusb_init();

    absolute_time_t next = delayed_by_us(get_absolute_time(), HELI_HID_INTERVAL_US);

    while (true) {
        tud_task();
        cli_task();

        if (time_reached(next)) {
            int64_t lateness = -absolute_time_diff_us(get_absolute_time(), next);
            if (lateness > (int64_t)HELI_HID_INTERVAL_US) {
                ++diag.loop_overruns;
                next = delayed_by_us(get_absolute_time(), HELI_HID_INTERVAL_US);
            } else {
                next = delayed_by_us(next, HELI_HID_INTERVAL_US);
            }

            inputs_task();
            sample_axes();
            report.buttons = inputs_buttons();
            report.hat = inputs_hat();

            if (tud_hid_ready()) {
                tud_hid_report(0, &report, sizeof(report));
                ++diag.report_count;
            }
        }
    }
}
