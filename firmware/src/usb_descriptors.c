#include "tusb.h"
#include "pico/unique_id.h"
#include <string.h>

#define USB_VID 0xCAFE
#define USB_PID 0x1351

tusb_desc_device_t const desc_device = {
    .bLength = sizeof(tusb_desc_device_t),
    .bDescriptorType = TUSB_DESC_DEVICE,
    .bcdUSB = 0x0200,
    .bDeviceClass = TUSB_CLASS_MISC,
    .bDeviceSubClass = MISC_SUBCLASS_COMMON,
    .bDeviceProtocol = MISC_PROTOCOL_IAD,
    .bMaxPacketSize0 = CFG_TUD_ENDPOINT0_SIZE,
    .idVendor = USB_VID,
    .idProduct = USB_PID,
    .bcdDevice = 0x0110,
    .iManufacturer = 1,
    .iProduct = 2,
    .iSerialNumber = 3,
    .bNumConfigurations = 1
};

uint8_t const *tud_descriptor_device_cb(void) { return (uint8_t const *)&desc_device; }

uint8_t const hid_report_desc[] = {
    0x05,0x01, 0x09,0x04, 0xA1,0x01,
    0x15,0x00, 0x26,0xFF,0xFF, 0x75,0x10, 0x95,0x07,
    0x09,0x30, 0x09,0x31, 0x09,0x32, 0x09,0x33, 0x09,0x34, 0x09,0x35, 0x09,0x36,
    0x81,0x02,
    0x05,0x09, 0x19,0x01, 0x29,0x20, 0x15,0x00, 0x25,0x01,
    0x75,0x01, 0x95,0x20, 0x81,0x02,
    0x05,0x01, 0x09,0x39, 0x15,0x00, 0x25,0x07,
    0x35,0x00, 0x46,0x3B,0x01, 0x65,0x14,
    0x75,0x04, 0x95,0x01, 0x81,0x42,
    0x65,0x00, 0x75,0x04, 0x95,0x01, 0x81,0x03,
    0xC0
};

uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance) {
    (void)instance;
    return hid_report_desc;
}

#define ITF_NUM_HID 0
#define ITF_NUM_CDC 1
#define ITF_NUM_CDC_DATA 2
#define ITF_NUM_TOTAL 3
#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN + TUD_HID_DESC_LEN + TUD_CDC_DESC_LEN)

uint8_t const desc_configuration[] = {
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),
    TUD_HID_DESCRIPTOR(ITF_NUM_HID, 4, HID_ITF_PROTOCOL_NONE,
                       sizeof(hid_report_desc), 0x81, 64, 1),
    TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, 5, 0x82, 8, 0x02, 0x83, 64)
};

uint8_t const *tud_descriptor_configuration_cb(uint8_t index) {
    (void)index;
    return desc_configuration;
}

static const char *string_desc_arr[] = {
    "135er OpenSim Hardware",
    "135er Universal Helicopter Controller",
    NULL,
    "Helicopter HID",
    "Heli Control Console"
};
static uint16_t desc_str[64];

static size_t serial_ascii(char *dst, size_t cap) {
    static const char hex[] = "0123456789ABCDEF";
    pico_unique_board_id_t id;
    pico_get_unique_board_id(&id);
    size_t n = 0;
    for (size_t i = 0; i < PICO_UNIQUE_BOARD_ID_SIZE_BYTES && n + 2 < cap; ++i) {
        dst[n++] = hex[id.id[i] >> 4];
        dst[n++] = hex[id.id[i] & 0x0F];
    }
    dst[n] = '\0';
    return n;
}

uint16_t const *tud_descriptor_string_cb(uint8_t index, uint16_t langid) {
    (void)langid;
    uint8_t n = 0;
    if (index == 0) {
        desc_str[1] = 0x0409;
        n = 1;
    } else {
        char serial[2 * PICO_UNIQUE_BOARD_ID_SIZE_BYTES + 1];
        const char *s = NULL;
        if (index == 3) {
            serial_ascii(serial, sizeof(serial));
            s = serial;
        } else {
            if (index < 1 || index > 5) return NULL;
            s = string_desc_arr[index - 1];
        }
        if (!s) return NULL;
        size_t len = strlen(s);
        if (len > 63) len = 63;
        n = (uint8_t)len;
        for (uint8_t i = 0; i < n; ++i) desc_str[1 + i] = (uint8_t)s[i];
    }
    desc_str[0] = (uint16_t)((TUSB_DESC_STRING << 8) | (2u * n + 2u));
    return desc_str;
}

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id,
                           hid_report_type_t report_type,
                           uint8_t const *buffer, uint16_t bufsize) {
    (void)instance; (void)report_id; (void)report_type; (void)buffer; (void)bufsize;
}

uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id,
                               hid_report_type_t report_type,
                               uint8_t *buffer, uint16_t reqlen) {
    (void)instance; (void)report_id; (void)report_type; (void)buffer; (void)reqlen;
    return 0;
}
