#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

struct Struct_ov003_0216fba0 {
    char pad0[1];
    unsigned char field1;
    unsigned char field2;
    char pad2[0x3b - 3];
    unsigned char unknown_3b_;
    char pad3[0x48 - 0x3c];
};

// USA: func_ov003_0216fba0
extern "C" ARM void func_ov003_0216fba0(Struct_ov003_0216fba0* obj) {
    ClearFlags04(GetGameResources(), 0xc8e);

    volatile unsigned short* var0 = (volatile unsigned short*)0x4000008;
    unsigned int* var1 = (unsigned int*)((char*)var0 + 0x48);
    var0[0] = (var0[0] & ~3) | 3;
    var0[1] = (var0[1] & ~3);
    var0[2] = (var0[2] & ~3) | 1;
    var0[3] = (var0[3] & ~3) | 2;

    unsigned char c = obj->unknown_3b_;
    ColorEffect_ConfigureAlphaBlend(var1, 0x18, 1, c, 0x10 - c);

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0x1f00) | 0xf00;

    obj->unknown_3b_ -= 4;
    if (obj->unknown_3b_ == 0) {
        obj->field1 = 7;
        obj->field2 = 0;
    }
}
