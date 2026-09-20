#include "calibration.h"
#include <string.h>

void calibration_defaults(calibration_data_t *data) {
    memset(data, 0, sizeof(*data));
    data->version = 1;
    for (int i = 0; i < HELI_AXIS_COUNT; ++i) {
        data->axis[i].raw_min = 0;
        data->axis[i].raw_center = 32768;
        data->axis[i].raw_max = 65535;
        data->axis[i].deadzone = 0;
        data->axis[i].filtered = 32768;
    }
}

bool calibration_load(calibration_data_t *data) {
    // TODO: flash-backed storage.
    calibration_defaults(data);
    return false;
}

bool calibration_save(const calibration_data_t *data) {
    // TODO: flash-backed storage.
    (void)data;
    return true;
}
