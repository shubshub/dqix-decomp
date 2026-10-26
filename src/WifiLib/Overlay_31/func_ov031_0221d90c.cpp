#include <globaldefs.h>
#include "NitroSDK/OverlayResponse.h"
struct Struct_ov031_0221d90c_3 {
    unsigned char type, reserved;
    unsigned short length, next;
    unsigned char payload[1];
};
struct Struct_ov031_0221d90c { unsigned char header[6]; Struct_ov031_0221d90c_3 first; };
struct Struct_ov031_0221d90c_2 {
    unsigned int unknown0, unknown_4_;
    unsigned char name[40];
    unsigned char keys[4][64];
};
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);
// USA: func_ov031_0221d90c
extern "C" THUMB int func_ov031_0221d90c(Struct_ov031_0221d90c* packet, Struct_ov031_0221d90c_2* settings) {
    Struct_ov031_0221d90c_3* entry = &packet->first;
    Struct_ov031_0221d90c_3* first;
    unsigned char* name = settings->name;
    unsigned char* key3 = settings->keys[3];
    unsigned char* key2 = settings->keys[2];
    unsigned char* key1 = settings->keys[1];
    unsigned char* key0 = settings->keys[0];
    first = entry;
    unsigned long length;
    do {
        length = func_ov031_0221e638(entry->length);
        switch (entry->type) {
        case 0x10: case 0x11: case 0x12: case 0x13:
            if (length > 5) return -1;
            break;
        case 0x20: case 0x21: case 0x22: case 0x23:
            if (length > 13) return -1;
            break;
        case 0x15: case 0x25:
            if (length > 33) return -1;
            break;
        }
        switch (entry->type) {
        case 0x10: case 0x20:
            func_ov031_0221e51c(key0, entry->payload, length);
            settings->unknown_4_ = length;
            break;
        case 0x11: case 0x21:
            func_ov031_0221e51c(key1, entry->payload, length);
            settings->unknown_4_ = length;
            break;
        case 0x12: case 0x22:
            func_ov031_0221e51c(key2, entry->payload, length);
            settings->unknown_4_ = length;
            break;
        case 0x13: case 0x23:
            func_ov031_0221e51c(key3, entry->payload, length);
            settings->unknown_4_ = length;
            break;
        case 0x15: case 0x25:
            if (length != 0 && entry->payload[length - 1] != 0) return -1;
            func_ov031_0221e51c(name, entry->payload, length);
            break;
        default: return -1;
        }
        if (entry->next == 0) break;
        entry = (Struct_ov031_0221d90c_3*)((unsigned char*)first + func_ov031_0221e638(entry->next));
    } while (1);
    return 0;
}
