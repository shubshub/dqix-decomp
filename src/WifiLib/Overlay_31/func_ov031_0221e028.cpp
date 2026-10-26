#include "NitroSDK/OverlayResponse.h"

extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221e028
extern "C" THUMB void func_ov031_0221e028(void* buffer, int type, int arg2, int flags, signed char arg4, signed char arg5, const void* arg6) {
    Struct_ov031_0221d3b0* packet = (Struct_ov031_0221d3b0*)buffer;
    packet->unknown_0_ = func_ov031_0221e5f8(1);
    packet->unknown_2_[0] = 0;
    packet->unknown_2_[1] = 0;
    packet->type = func_ov031_0221e5f8(type);
    packet->unknown_8_ = 0;
    packet->unknown_a_ = func_ov031_0221e5f8(arg2);
    packet->flags = func_ov031_0221e5f8(flags);
    packet->unknown_e_ = arg4;
    packet->unknown_f_ = arg5;
    func_ov031_0221e51c(&packet->unknown_10_, arg6, sizeof(packet->unknown_10_));
}
