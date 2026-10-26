#include <globaldefs.h>

extern "C" void SpriteContext_DrawSprite(void* a, void* b);

struct Struct_ov006_02158054 {
    unsigned char pad0[0x14];
    int f14;
    unsigned char pad1[0x18 - 0x18];
    int f18;
    unsigned char pad2[0x22 - 0x1c];
    unsigned char f22;
    unsigned char pad3[0x26 - 0x23];
    unsigned char unknown_26_;
};

// USA: func_ov006_02158054
extern "C" ARM void func_ov006_02158054(void* a, struct Struct_ov006_02158054* s, int x, int y, unsigned char arg4, unsigned char arg5) {
    s->f14 = x << 0xc;
    s->f18 = y << 0xc;
    s->f22 = arg4;
    s->unknown_26_ = arg5;
    SpriteContext_DrawSprite(a, s);
}
