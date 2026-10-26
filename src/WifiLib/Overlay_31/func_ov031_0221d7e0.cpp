#include "NitroSDK/OverlayResponse.h"

extern char data_ov031_0224b0dc[];
extern "C" int func_ov031_0221e650(const char*);
extern "C" void func_ov031_0221e354(void*, int, const char*, int);
extern "C" int func_ov031_0221e4fc(unsigned char*, unsigned char*, int);
// USA: func_ov031_0221d7e0
extern "C" THUMB int func_ov031_0221d7e0(Struct_ov031_0221d7e0* packet, Struct_ov031_0221d7e0* arg1) {
    int result = 0;
    func_ov031_0221e354(arg1, 8, data_ov031_0224b0dc, func_ov031_0221e650(data_ov031_0224b0dc));
    if (func_ov031_0221e4fc(packet->prefix, arg1->prefix, 6) != 0)
        result--;
    else {
        unsigned short var1 = func_ov031_0221e638(packet->unknown_6_);
        unsigned short var2 = func_ov031_0221e638(arg1->unknown_6_);
        if (var1 + 1 != var2)
            result -= 2;
    }
    return result;
}
