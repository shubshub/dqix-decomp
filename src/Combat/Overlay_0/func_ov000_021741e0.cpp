#include <globaldefs.h>

extern "C" int fix32_Divide(unsigned int arg0, unsigned int arg1);
extern "C" void SpriteContext_DrawSprite(void* dst, void* src);

struct Struct_ov000_021741e0 {
    char pad0[0xc];
    int field0c;
    int field10;
    int field14;
    int field18;
    char pad1[0x20 - 0x1c];
    unsigned short field20;
    unsigned char field22;
    char pad2[0x26 - 0x23];
    unsigned char field26;
    char pad3[0x28 - 0x27];
};

// USA: func_ov000_021741e0
extern "C" ARM void func_ov000_021741e0(void* obj, float maxSpeed, float speed, int x, int arg4,
    unsigned char arg5, unsigned char arg6, unsigned char arg7, unsigned char arg8, unsigned char arg9) {
    float var0 = maxSpeed;
    if (speed < maxSpeed) var0 = speed;

    struct Struct_ov000_021741e0* base = *(struct Struct_ov000_021741e0**)((char*)obj + 0x170);
    struct Struct_ov000_021741e0* e = base + arg5;
    int var3 = x << 0xc;
    int var4 = arg4 << 0xc;

    int var5 = (int)(4096.0f * var0);
    long long var6 = ((long long)var5 << 16) + 0x800;
    int val2 = (int)(var6 >> 12);
    if (arg9) val2 += 0x1000;
    val2 &= ~0xfff;
    int var8 = fix32_Divide(val2, 0x10000);

    if (var8 < 0x41) {
        if (0.0f < var0) {
            var8 = 0x41;
        } else {
            return;
        }
    }

    e->field14 = var3;
    e->field18 = var4;
    e->field0c = var8;
    e->field10 = 0x1000;
    e->field20 = arg7;
    e->field22 = arg6;
    e->field26 = arg8;
    SpriteContext_DrawSprite((char*)obj + 0x11c, e);
}
