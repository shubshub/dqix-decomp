#include <globaldefs.h>
#include "NitroSDK/Cache.h"
#include "NitroSDK/Memory.h"

typedef struct Struct_020d4c7c
{
    unsigned char count;
    unsigned char padding[3];
    struct
    {
        unsigned char id;
        unsigned char length;
        unsigned char unknown_2_[2];
        unsigned char* body;
    } element[16];
} Struct_020d4c7c;

typedef struct Struct_020d4c7c_2
{
    unsigned short length;
    unsigned short unknown_2_;
    unsigned char bssid[6];
    unsigned short unknown_a_;
    unsigned char ssid[32];
    unsigned short unknown_2c_;
    unsigned char unknown_2e_[0x3c - 0x2e];
    unsigned short unknown_3c_;
} Struct_020d4c7c_2;

typedef struct Struct_ov031_02235a44_2
{
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short state;
    unsigned short unknown_a_;
    unsigned short reserved;
    unsigned short unknown_e_;
    Struct_020d4c7c_2* unknown_10_[16];
    unsigned short unknown_50_[16];
} Struct_ov031_02235a44_2;

typedef struct Struct_ov031_02235a44
{
    unsigned char ssid[32];
    unsigned char bssid[6];
    unsigned short unknown_26_;
    unsigned char unknown_28_;
    unsigned char pad;
} Struct_ov031_02235a44;

extern "C" int memcmp(const void* a, const void* b, unsigned int n);
extern "C" void func_020d4c7c(Struct_020d4c7c* elements, const Struct_020d4c7c_2* arg1);

extern char* data_ov031_02290cf8;
extern unsigned char data_ov031_022491fc[6];
extern unsigned char data_ov031_022491f8[4];

// USA: func_ov031_02235a44
extern "C" ARM void func_ov031_02235a44(Struct_ov031_02235a44_2* cb) {
    Struct_020d4c7c_2* bss;
    int i, slot, j, count;
    Struct_ov031_02235a44* entry;
    Struct_020d4c7c elems;
    Struct_ov031_02235a44* entries = (Struct_ov031_02235a44*)(data_ov031_02290cf8 + 0x1300);
    InvalidateDataCacheRange(data_ov031_02290cf8 + 0xf00, 0x400);
    for (i = 0; i < cb->unknown_e_; i++) {
        bss = cb->unknown_10_[i];
        if (bss->ssid[0] == 0 || bss->unknown_3c_ != 0) continue;
        for (slot = 0; slot < 20; slot++) {
            if (memcmp(bss->bssid, entries[slot].bssid, 6) == 0) break;
        }
        if (slot == 20) {
            for (slot = 0; slot < 20; slot++) {
                if (memcmp(entries[slot].bssid, data_ov031_022491fc, 6) == 0) break;
            }
            if (slot == 20) return;
        }
        entry = &entries[slot];
        VectorizedInvertedMemcpy(bss->bssid, entry->bssid, 6);
        VectorizedInvertedMemcpy(bss->ssid, entry->ssid, 0x20);
        entry->unknown_26_ = cb->unknown_50_[i];
        if (!(bss->unknown_2c_ & 0x10)) {
            entry->unknown_28_ = 0;
            continue;
        }
        entry->unknown_28_ = 1;
        func_020d4c7c(&elems, bss);
        count = elems.count;
        for (j = 0; j < count; j++) {
            if (elems.element[j].id == 0x30) {
                entry->unknown_28_ = 2;
                break;
            }
            if (elems.element[j].id == 0xdd && elems.element[j].length >= 4
                && memcmp(elems.element[j].body, data_ov031_022491f8, 4) == 0) {
                entry->unknown_28_ = 2;
                break;
            }
        }
    }
}
