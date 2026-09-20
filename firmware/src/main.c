#include "pico/stdlib.h"
#include "bsp/board.h"
#include "tusb.h"
#include "axis.h"
#include "calibration.h"
#include "hid_report.h"
#include "mcp3208.h"

static calibration_data_t cal;
static heli_hid_report_t report;

static void sample_axes(void){
    uint16_t v[7];
    for(int i=0;i<7;i++){
        uint16_t raw=mcp3208_read_oversampled((uint8_t)i);
        raw=axis_filter(&cal.axis[i],raw);
        v[i]=axis_map(&cal.axis[i],raw);
    }
    report.cyclic_roll=v[0];
    report.cyclic_pitch=v[1];
    report.collective=v[2];
    report.throttle=v[3];
    report.pedals=v[4];
    report.brake_left=v[5];
    report.brake_right=v[6];
}

int main(void){
    board_init();
    mcp3208_init();
    calibration_load(&cal);
    hid_report_init(&report);
    tusb_init();

    absolute_time_t next=get_absolute_time();
    while(1){
        tud_task();
        if(absolute_time_diff_us(get_absolute_time(),next)<=0){
            next=delayed_by_us(next,1000);
            sample_axes();
            if(tud_hid_ready()) tud_hid_report(0,&report,sizeof(report));
        }
    }
}
