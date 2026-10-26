#include <globaldefs.h>
#include "NitroSDK/OverlayResponse.h"

struct Struct_ov031_0221db48_3 {
    unsigned char type;
    unsigned char flags;
    unsigned short length;
};
struct Struct_ov031_0221c5ac_8 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned char name[40];
    unsigned char keys[4][64];
};
struct Struct_ov031_0221c5ac_9 {
    int unknown_0_;
    int unknown_4_;
    char name[40];
    unsigned char data[64];
};
struct Struct_ov031_0221db48 {
    unsigned char unknown_0_[8];
    Struct_ov031_0221c5ac_8 first;
    Struct_ov031_0221c5ac_8 second;
    Struct_ov031_0221c5ac_9 third;
    Struct_ov031_0221c5ac_9 unknown_2d8_;
    unsigned char unknown_348_[8];
};
struct Struct_ov031_0221db48_2 { unsigned char data[128]; };

struct Struct_ov031_0224e6e0_7 {
    char unknown_0_[0x30];
    unsigned int decoded;
};
extern unsigned char data_ov031_0224b06c[];
extern Struct_ov031_0224e6e0_7 data_ov031_0224e6e0;
extern "C" int func_ov031_0221d90c(Struct_ov031_0221db48_3*, Struct_ov031_0221c5ac_8*);
extern "C" int func_ov031_0221da60(Struct_ov031_0221db48_3*, Struct_ov031_0221c5ac_9*);
extern "C" int func_ov031_0221db18(Struct_ov031_0221db48_3*, void*);

// USA: func_ov031_0221db48
extern "C" THUMB int func_ov031_0221db48(int index, Struct_ov031_0221db48_3* packet, int size, Struct_ov031_0221db48* arg3, void* extra) {
    unsigned int decoded = 0;
    Struct_ov031_0221db48_3* record;
    if (size <= 0) return -2;
    do {
        record = packet;
        if (record->type == data_ov031_0224b06c[index]) goto found;
        int var2 = func_ov031_0221e638(packet->length) + 4;
        size -= var2;
        packet = (Struct_ov031_0221db48_3*)((char*)packet + var2);
    } while (size > 0);
    return -4;
found:
    packet = record + 1;
    int remaining = func_ov031_0221e638(record->length);
    Struct_ov031_0221db48* destination = &arg3[index];
    unsigned char* blocks = (unsigned char*)extra;
    unsigned int var6 = (index + 3) * sizeof(Struct_ov031_0221db48_2);
    do {
        int result;
        switch (packet->type) {
        case 3:
            result = func_ov031_0221d90c(packet, &destination->first);
            decoded |= 1;
            break;
        case 4:
            result = func_ov031_0221d90c(packet, &destination->second);
            decoded |= 2;
            break;
        case 5:
            result = func_ov031_0221da60(packet, &destination->third);
            decoded |= 4;
            break;
        case 6:
            result = func_ov031_0221da60(packet, &destination->unknown_2d8_);
            decoded |= 8;
            break;
        case 10:
            result = func_ov031_0221db18(packet, blocks + var6);
            break;
        default:
            result = -3;
            break;
        }
        if (result) return result;
        int var8 = func_ov031_0221e638(packet->length) + 4;
        remaining -= var8;
        packet = (Struct_ov031_0221db48_3*)((char*)packet + var8);
    } while (remaining > 0);
    data_ov031_0224e6e0.decoded |= decoded;
    return 0;
}
