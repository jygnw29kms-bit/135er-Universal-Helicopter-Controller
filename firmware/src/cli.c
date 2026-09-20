#include "cli.h"
#include "tusb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static calibration_data_t *g_cal;
static axis_state_t *g_axes;
static heli_diagnostics_t *g_diag;
static char line[160];
static size_t line_len;

static const char *axis_names[HELI_AXIS_COUNT] = {
    "roll", "pitch", "collective", "throttle", "pedals", "brake_left", "brake_right"
};

static void out(const char *s) {
    if (tud_cdc_connected()) {
        tud_cdc_write_str(s);
        tud_cdc_write_flush();
    }
}

static int axis_index(const char *name) {
    for (int i = 0; i < HELI_AXIS_COUNT; ++i)
        if (strcmp(name, axis_names[i]) == 0) return i;
    return -1;
}

static void show_axis(int i) {
    char b[220];
    const axis_config_t *a = &g_cal->axis[i];
    snprintf(b, sizeof(b),
        "%s raw=%u min=%u center=%u max=%u mode=%s inv=%u dead=%u filter=%u expo=%u\r\n",
        axis_names[i], g_diag->latest_raw[i], a->raw_min, a->raw_center, a->raw_max,
        a->mode == AXIS_BIPOLAR ? "bipolar" : "unipolar",
        a->invert, a->deadzone, a->filter_shift, a->expo);
    out(b);
}

static void process_line(char *s) {
    char *cmd = strtok(s, " ");
    if (!cmd) return;

    if (strcmp(cmd, "help") == 0) {
        out("help | status | cal show | cal set <axis> <min> <center> <max> | "
            "invert <axis> <0|1> | deadzone <axis> <0..32766> | "
            "filter <axis> <0..5> | expo <axis> <0..100> | save | defaults\r\n");
        return;
    }

    if (strcmp(cmd, "status") == 0) {
        char b[96];
        snprintf(b, sizeof(b), "reports=%lu overruns=%lu\r\n",
                 (unsigned long)g_diag->report_count,
                 (unsigned long)g_diag->loop_overruns);
        out(b);
        for (int i = 0; i < HELI_AXIS_COUNT; ++i) show_axis(i);
        return;
    }

    if (strcmp(cmd, "cal") == 0) {
        char *sub = strtok(NULL, " ");
        if (sub && strcmp(sub, "show") == 0) {
            for (int i = 0; i < HELI_AXIS_COUNT; ++i) show_axis(i);
            return;
        }
        if (sub && strcmp(sub, "set") == 0) {
            char *name = strtok(NULL, " ");
            char *smin = strtok(NULL, " ");
            char *scenter = strtok(NULL, " ");
            char *smax = strtok(NULL, " ");
            int i = name ? axis_index(name) : -1;
            if (i < 0 || !smin || !scenter || !smax) {
                out("ERR usage: cal set <axis> <min> <center> <max>\r\n");
                return;
            }
            axis_config_t candidate = g_cal->axis[i];
            candidate.raw_min = (uint16_t)strtoul(smin, NULL, 0);
            candidate.raw_center = (uint16_t)strtoul(scenter, NULL, 0);
            candidate.raw_max = (uint16_t)strtoul(smax, NULL, 0);
            if (!axis_config_valid(&candidate)) {
                out("ERR invalid calibration range\r\n");
                return;
            }
            g_cal->axis[i] = candidate;
            axis_state_set_config(&g_axes[i], &candidate);
            out("OK calibration updated in RAM; use save to persist\r\n");
            return;
        }
    }

    if (strcmp(cmd, "invert") == 0 || strcmp(cmd, "deadzone") == 0 ||
        strcmp(cmd, "filter") == 0 || strcmp(cmd, "expo") == 0) {
        char *name = strtok(NULL, " ");
        char *value = strtok(NULL, " ");
        int i = name ? axis_index(name) : -1;
        if (i < 0 || !value) {
            out("ERR missing axis/value\r\n");
            return;
        }
        unsigned long v = strtoul(value, NULL, 0);
        axis_config_t candidate = g_cal->axis[i];
        if (strcmp(cmd, "invert") == 0) candidate.invert = (uint8_t)v;
        if (strcmp(cmd, "deadzone") == 0) candidate.deadzone = (uint16_t)v;
        if (strcmp(cmd, "filter") == 0) candidate.filter_shift = (uint8_t)v;
        if (strcmp(cmd, "expo") == 0) candidate.expo = (uint8_t)v;
        if (!axis_config_valid(&candidate)) {
            out("ERR invalid value\r\n");
            return;
        }
        g_cal->axis[i] = candidate;
        axis_state_set_config(&g_axes[i], &candidate);
        out("OK updated in RAM; use save to persist\r\n");
        return;
    }

    if (strcmp(cmd, "save") == 0) {
        out(calibration_save(g_cal) ? "OK saved to flash\r\n" : "ERR save failed\r\n");
        return;
    }

    if (strcmp(cmd, "defaults") == 0) {
        calibration_defaults(g_cal);
        for (int i = 0; i < HELI_AXIS_COUNT; ++i)
            axis_state_set_config(&g_axes[i], &g_cal->axis[i]);
        out("OK defaults loaded in RAM; use save to persist\r\n");
        return;
    }

    out("ERR unknown command; type help\r\n");
}

void cli_init(calibration_data_t *cal, axis_state_t axes[HELI_AXIS_COUNT],
              heli_diagnostics_t *diag) {
    g_cal = cal;
    g_axes = axes;
    g_diag = diag;
    line_len = 0;
}

void cli_task(void) {
    while (tud_cdc_available()) {
        char c;
        if (tud_cdc_read(&c, 1) != 1) break;

        if (c == '\r' || c == '\n') {
            if (line_len) {
                line[line_len] = '\0';
                process_line(line);
                line_len = 0;
            }
        } else if (line_len + 1 < sizeof(line)) {
            line[line_len++] = c;
        } else {
            line_len = 0;
            out("ERR line too long\r\n");
        }
    }
}
