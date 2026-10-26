#include "NitroSDK/OverlayResponse.h"

extern "C" int func_ov031_0221d6a8(Struct_ov031_0221d3b0*);

// USA: func_ov031_0221d3b0
extern "C" THUMB int func_ov031_0221d3b0(int state, Struct_ov031_0221d3b0_2* packet, int* rejected, Struct_ov031_0221d3b0_3* arg3) {
    Struct_ov031_0221d3b0* header = &packet->header;
    if (func_ov031_0221e638(header->unknown_0_) < 1) {
        (*rejected)++;
        return state;
    }
    if (header->unknown_f_ != 0x11) {
        (*rejected)++;
        return state;
    }
    if (func_ov031_0221d6a8(&packet->header) > 0) {
        (*rejected)++;
        return state;
    }
    switch (func_ov031_0221e638(header->type)) {
    case 0x1010:
        state = func_ov031_0221d450(state, packet, rejected, arg3);
        break;
    case 0x2010:
        state = func_ov031_0221d52c(state, packet, rejected, arg3);
        break;
    case 0x3010:
        state = func_ov031_0221d604(state, packet, rejected, arg3);
        break;
    }
    return state;
}
