#pragma once
#include <stdint.h>
#include "axis.h"
#include "calibration.h"

typedef struct {
    uint32_t report_count;
    uint32_t loop_overruns;
    uint16_t latest_raw[HELI_AXIS_COUNT];
} heli_diagnostics_t;

void cli_init(calibration_data_t *cal, axis_state_t axes[HELI_AXIS_COUNT],
              heli_diagnostics_t *diag);
void cli_task(void);
