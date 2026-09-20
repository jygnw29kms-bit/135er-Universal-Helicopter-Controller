#include "calibration.h"
#include <string.h>
#define CAL_MAGIC 0x48454C49u
static uint32_t crc32(const uint8_t*p,size_t n){uint32_t c=0xFFFFFFFFu;while(n--){c^=*p++;for(int k=0;k<8;k++)c=(c>>1)^(0xEDB88320u&-(int32_t)(c&1));}return ~c;}
void calibration_defaults(calibration_data_t*d){memset(d,0,sizeof(*d));d->magic=CAL_MAGIC;d->version=1;for(int i=0;i<HELI_AXIS_COUNT;i++){d->axis[i].raw_min=300;d->axis[i].raw_center=8192;d->axis[i].raw_max=16000;d->axis[i].filtered_raw=8192;d->axis[i].deadzone=100;d->axis[i].mode=(i==0||i==1||i==4)?AXIS_BIPOLAR:AXIS_UNIPOLAR;}d->crc32=crc32((uint8_t*)d,sizeof(*d)-4);}
bool calibration_load(calibration_data_t*d){calibration_defaults(d);return true;}
bool calibration_save(const calibration_data_t*d){(void)d;return true;}
