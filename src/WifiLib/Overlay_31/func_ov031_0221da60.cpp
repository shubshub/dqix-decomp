#include "NitroSDK/OverlayResponse.h"

struct Struct_ov031_0221da60_3 {
    unsigned char type;
    unsigned char flags;
    unsigned short length;
    unsigned short next;
    unsigned char data[1];
};
struct Struct_ov031_0221da60 { unsigned char prefix[6]; Struct_ov031_0221da60_3 header; };
struct Struct_ov031_0221da60_2 {
    int unknown_0_;
    int unknown_4_;
    char name[0x28];
    unsigned char data[0x40];
};
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221da60
extern "C" THUMB int func_ov031_0221da60(Struct_ov031_0221da60* packet, Struct_ov031_0221da60_2* fields) {
    Struct_ov031_0221da60_3* entry = &packet->header;
    for (;;) {
        unsigned int length = func_ov031_0221e638(entry->length);
        switch (entry->type) {
        case 0x30:
        case 0x40:
            if (length > 0x40) return -1;
            break;
        case 0x35:
        case 0x45:
            if (length > 0x21) return -1;
            break;
        }
        switch (entry->type) {
        case 0x30:
        case 0x40:
            func_ov031_0221e51c(fields->data, entry->data, length);
            fields->unknown_4_ = length;
            break;
        case 0x35:
        case 0x45:
            if (length != 0 && *(entry->data + length - 1) != 0) return -1;
            func_ov031_0221e51c(fields->name, entry->data, length);
            break;
        default:
            return -1;
        }
        if (entry->next == 0) break;
        entry = (Struct_ov031_0221da60_3*)((unsigned char*)&packet->header + func_ov031_0221e638(entry->next));
    }
    return 0;
}
