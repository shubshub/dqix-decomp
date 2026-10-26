#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

struct Struct_ov003_0216ef14 {
    unsigned char field0;
    unsigned char field1;
    unsigned char field2;
    char pad0[0x20 - 3];
    unsigned short field20;
    char pad1[0x3b - 0x22];
    unsigned char unknown_3b_;
};

// USA: func_ov003_0216ef14
extern "C" ARM void func_ov003_0216ef14(Struct_ov003_0216ef14* self) {
    GameResources* field4 = GetGameResources();
    unsigned char cur = self->unknown_3b_;
    if (cur >= 0x10) {
        self->unknown_3b_ = 0x10;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 4, 8, 0xc, 4);
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;
        SetFlags04(field4, 0xcce);
        self->field20 |= 0x20;
        self->field1 = 4;
        self->field2 = 0;
    } else {
        self->unknown_3b_ = cur + 4;
        if (self->unknown_3b_ > 0x10) {
            self->unknown_3b_ = 0x10;
            SetFlags04(field4, 0xcce);
        }
        unsigned char c = self->unknown_3b_;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 0x18, 1, c, 0x10 - c);
    }
}
