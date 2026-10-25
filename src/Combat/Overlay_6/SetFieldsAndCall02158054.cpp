#include <globaldefs.h>

extern "C" void SpriteContext_DrawSprite(void* a, void* b);

struct SetFieldsAndCall02158054Struct {
    unsigned char pad0[0x14];
    int f14;
    unsigned char pad1[0x18 - 0x18];
    int f18;
    unsigned char pad2[0x22 - 0x1c];
    unsigned char f22;
    unsigned char pad3[0x26 - 0x23];
    unsigned char f26;
};

// USA: func_ov006_02158054
ARM void SetFieldsAndCall02158054(void* a, struct SetFieldsAndCall02158054Struct* s, int x, int y, unsigned char arg5, unsigned char arg6) {
    s->f14 = x << 0xc;
    s->f18 = y << 0xc;
    s->f22 = arg5;
    s->f26 = arg6;
    SpriteContext_DrawSprite(a, s);
}
