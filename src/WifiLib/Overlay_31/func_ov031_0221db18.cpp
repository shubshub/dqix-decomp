#include "NitroSDK/OverlayResponse.h"

struct Struct_ov031_0221da60_3 {
    unsigned char type;
    unsigned char flags;
    unsigned short length;
    unsigned short unknown_4_;
};
struct Struct_ov031_0221da60 { unsigned char prefix[6]; Struct_ov031_0221da60_3 header; };
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221db18
extern "C" THUMB int func_ov031_0221db18(Struct_ov031_0221da60* packet, void* destination) {
    Struct_ov031_0221da60_3* header = &packet->header;
    int length = func_ov031_0221e638(header->length);
    if (length <= 0) return -1;
    if (header->type != 0x70) return -1;
    func_ov031_0221e51c(destination, header + 1, length);
    return 0;
}
