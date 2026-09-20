#include "tusb.h"
#include <string.h>
#define USB_VID 0xCAFE
#define USB_PID 0x1351
tusb_desc_device_t const desc_device={.bLength=sizeof(tusb_desc_device_t),.bDescriptorType=TUSB_DESC_DEVICE,.bcdUSB=0x0200,.bDeviceClass=0,.bDeviceSubClass=0,.bDeviceProtocol=0,.bMaxPacketSize0=CFG_TUD_ENDPOINT0_SIZE,.idVendor=USB_VID,.idProduct=USB_PID,.bcdDevice=0x0100,.iManufacturer=1,.iProduct=2,.iSerialNumber=3,.bNumConfigurations=1};
uint8_t const*tud_descriptor_device_cb(void){return (uint8_t const*)&desc_device;}
uint8_t const hid_report_desc[]={0x05,0x01,0x09,0x04,0xA1,0x01,0x15,0x00,0x26,0xFF,0xFF,0x75,0x10,0x95,0x07,0x09,0x30,0x09,0x31,0x09,0x32,0x09,0x33,0x09,0x34,0x09,0x35,0x09,0x36,0x81,0x02,0x05,0x09,0x19,0x01,0x29,0x20,0x15,0x00,0x25,0x01,0x75,0x01,0x95,0x20,0x81,0x02,0x05,0x01,0x09,0x39,0x15,0x00,0x25,0x07,0x35,0x00,0x46,0x3B,0x01,0x65,0x14,0x75,0x04,0x95,0x01,0x81,0x42,0x65,0x00,0x75,0x04,0x95,0x01,0x81,0x03,0xC0};
uint8_t const*tud_hid_descriptor_report_cb(uint8_t instance){(void)instance;return hid_report_desc;}
#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN+TUD_HID_DESC_LEN)
uint8_t const desc_configuration[]={TUD_CONFIG_DESCRIPTOR(1,1,0,CONFIG_TOTAL_LEN,0x00,100),TUD_HID_DESCRIPTOR(0,4,HID_ITF_PROTOCOL_NONE,sizeof(hid_report_desc),0x81,64,1)};
uint8_t const*tud_descriptor_configuration_cb(uint8_t index){(void)index;return desc_configuration;}
char const*string_desc_arr[]={"OpenSim Hardware","135er Universal Helicopter Controller","V1-RC1","Helicopter HID"};static uint16_t _desc_str[64];
uint16_t const*tud_descriptor_string_cb(uint8_t index,uint16_t langid){(void)langid;uint8_t n;if(index==0){_desc_str[1]=0x0409;n=1;}else{if(index>4)return NULL;char const*s=string_desc_arr[index-1];n=(uint8_t)strlen(s);if(n>63)n=63;for(uint8_t i=0;i<n;i++)_desc_str[1+i]=s[i];}_desc_str[0]=(uint16_t)((TUSB_DESC_STRING<<8)|(2*n+2));return _desc_str;}
void tud_hid_set_report_cb(uint8_t i,uint8_t id,hid_report_type_t t,uint8_t const*b,uint16_t n){(void)i;(void)id;(void)t;(void)b;(void)n;}
uint16_t tud_hid_get_report_cb(uint8_t i,uint8_t id,hid_report_type_t t,uint8_t*b,uint16_t n){(void)i;(void)id;(void)t;(void)b;(void)n;return 0;}
