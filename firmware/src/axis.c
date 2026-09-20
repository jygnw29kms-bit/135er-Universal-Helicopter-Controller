#include "axis.h"
static uint16_t clamp16(int32_t v){return v<0?0:(v>65535?65535:(uint16_t)v);}
uint16_t axis_filter(axis_state_t*a,uint16_t s){a->filtered_raw=(uint16_t)(((uint32_t)a->filtered_raw*3u+s)/4u);return a->filtered_raw;}
uint16_t axis_map(axis_state_t*a,uint16_t raw){
 uint32_t out=0;if(raw<a->raw_min)raw=a->raw_min;if(raw>a->raw_max)raw=a->raw_max;
 if(a->mode==AXIS_UNIPOLAR){uint32_t span=a->raw_max-a->raw_min;out=span?((uint32_t)(raw-a->raw_min)*65535u/span):0;}
 else if(raw<=a->raw_center){uint32_t span=a->raw_center-a->raw_min;out=span?((uint32_t)(raw-a->raw_min)*32768u/span):32768u;}
 else {uint32_t span=a->raw_max-a->raw_center;out=span?32768u+((uint32_t)(raw-a->raw_center)*32767u/span):32768u;}
 if(a->mode==AXIS_BIPOLAR&&a->deadzone){int32_t d=(int32_t)out-32768;if(d<0)d=-d;if((uint32_t)d<=a->deadzone)out=32768;}
 if(a->invert)out=65535u-out;return clamp16((int32_t)out);
}
