#include "hid_report.h"
#include <string.h>
void hid_report_init(heli_hid_report_t*r){memset(r,0,sizeof(*r));r->cyclic_roll=r->cyclic_pitch=r->pedals=32768;r->hat=8;}
