#include <globaldefs.h>

extern "C" int fix32_Divide(unsigned int numerHi, unsigned int denomLo);
extern "C" void SpriteContext_DrawSprite(void* dst, void* src);

struct Struct_ov000_021741e0 {
    char unknown_0_[0xc];
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x20 - 0x1c];
    unsigned short unknown_20_;
    unsigned char unknown_22_;
    char unknown_23_[0x26 - 0x23];
    unsigned char unknown_26_;
    char unknown_27_[0x28 - 0x27];
};

// USA: func_ov000_021741e0
extern "C" ARM void func_ov000_021741e0(void* arg0, float arg1, float arg2, int arg3, int arg4,
    unsigned char arg5, unsigned char arg6, unsigned char arg7, unsigned char arg8, unsigned char arg9) {
    float var0 = arg1;
    if (arg2 < arg1) var0 = arg2;

    struct Struct_ov000_021741e0* var1 = *(struct Struct_ov000_021741e0**)((char*)arg0 + 0x170);
    struct Struct_ov000_021741e0* var2 = var1 + arg5;
    int var3 = arg3 << 0xc;
    int var4 = arg4 << 0xc;

    int var5 = (int)(4096.0f * var0);
    long long var6 = ((long long)var5 << 16) + 0x800;
    int var7 = (int)(var6 >> 12);
    if (arg9) var7 += 0x1000;
    var7 &= ~0xfff;
    int var8 = fix32_Divide(var7, 0x10000);

    if (var8 < 0x41) {
        if (0.0f < var0) {
            var8 = 0x41;
        } else {
            return;
        }
    }

    e->field14 = fixedX;
    e->field18 = fixedArgE;
    e->field0c = divResult;
    e->field10 = 0x1000;
    e->field20 = byteH;
    e->field22 = byteG;
    e->field26 = byteI;
    SpriteContext_DrawSprite((char*)obj + 0x11c, e);
}
