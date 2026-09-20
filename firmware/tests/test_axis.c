#include <assert.h>
#include <stdio.h>
#include "axis.h"

static axis_config_t bipolar(void) {
    axis_config_t c = {
        .raw_min=100, .raw_center=1000, .raw_max=1900,
        .deadzone=100, .mode=AXIS_BIPOLAR, .invert=0,
        .filter_shift=2, .expo=0
    };
    return c;
}

int main(void) {
    axis_config_t c = bipolar();
    assert(axis_config_valid(&c));

    axis_state_t s;
    axis_state_init(&s, &c);

    // First sample must seed directly: no startup sweep from a fake midpoint.
    assert(axis_filter(&s, 400) == 400);

    axis_state_set_config(&s, &c);
    assert(axis_map(&s, c.raw_min) == 0);
    assert(axis_map(&s, c.raw_center) == 32768);
    assert(axis_map(&s, c.raw_max) == 65535);

    // Center deadzone is centered and rescaled outside.
    assert(axis_map(&s, c.raw_center) == 32768);

    c.invert = 1;
    axis_state_set_config(&s, &c);
    assert(axis_map(&s, c.raw_min) == 65535);
    assert(axis_map(&s, c.raw_max) == 0);

    c.invert = 0;
    c.expo = 50;
    axis_state_set_config(&s, &c);
    assert(axis_map(&s, c.raw_min) == 0);
    assert(axis_map(&s, c.raw_center) == 32768);
    assert(axis_map(&s, c.raw_max) >= 65534);

    c.raw_center = c.raw_min;
    assert(!axis_config_valid(&c));

    puts("axis tests: PASS");
    return 0;
}
