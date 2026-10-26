#ifndef SYSTEM_WIRELESS_SCAN_DESCRIPTOR_H
#define SYSTEM_WIRELESS_SCAN_DESCRIPTOR_H

struct Struct_ov031_0220ec04_3 {
    unsigned short length;
    unsigned short unknown_2_;
    unsigned char bssid[6];
    unsigned short unknown_a_;
    unsigned char ssid[32];
    unsigned short unknown_2c_;
    unsigned short unknown_2e_;
    unsigned short unknown_30_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short channel;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
    unsigned short unknown_3c_;
    unsigned short reserved;
    unsigned char unknown_40_[0x80];
};

struct Struct_ov031_0220ec04_2 {
    unsigned char used;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    int index;
    Struct_ov031_0220ec04_2* previous;
    Struct_ov031_0220ec04_2* next;
    Struct_ov031_0220ec04_3 descriptor;
};

extern "C" Struct_ov031_0220ec04_3* func_ov031_0220ec04(int index);
extern "C" Struct_ov031_0220ec04_2* func_ov031_0220ee50(int index);

#endif
