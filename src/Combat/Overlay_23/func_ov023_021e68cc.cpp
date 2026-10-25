#include <globaldefs.h>

struct Struct_0205d81c;

struct Struct_ov023_021e68cc_3 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_ov023_021e68cc {
    char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    char unknown_1c_[0x22 - 0x1c];
    unsigned char unknown_22_;
    char unknown_23_[0x25 - 0x23];
    unsigned char unknown_25_;
    char unknown_26_[0x28 - 0x26];
};

#if defined(jpn)
struct Struct_ov023_021e68cc_2 {
    char unknown_0_[0x90];
#else
struct Struct_ov023_021e68cc_2 {
    char unknown_0_[0xac];
#endif

#if defined(jpn)
    char unknown_ac_[0x1334 - 0x90];
#else
    char unknown_ac_[0x135c - 0xac];
#endif

    void* unknown_135c_;
    char unknown_1360_[0x1364 - 0x1360];
    Struct_ov023_021e68cc* unknown_1364_;
#if defined(jpn)

#else
    char unknown_1368_[0x1370 - 0x1368];
#endif

    unsigned char unknown_1370_;
    unsigned char unknown_1371_;
#if defined(jpn)
    char unknown_1342_[0x1370 - 0x1342];
#else
    char unknown_1372_[0x13a8 - 0x1372];
#endif

    signed char unknown_13a8_;
    char unknown_13a9_[0x13ab - 0x13a9];
    unsigned char unknown_13ab_;
};

Element_021e68cc* FindElementByC40205d81c(Struct_0205d81c* s, int key);
extern "C" void SpriteContext_DrawSprite(void* renderer, void* sprite);

// USA: func_ov023_021e68cc
extern "C" ARM void func_ov023_021e68cc(Struct_ov023_021e68cc_2* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021e68cc_19=0x11};
#else
 enum {Enum_ov023_021e68cc_19=0x13};
#endif
    unsigned char var0 = arg0->unknown_1371_;
    if (var0 != 7 && var0 != 8 && var0 != 9)
        return;
    if (arg0->unknown_1370_ != 4)
        return;

    int var1;
    signed char var2 = 0;
    unsigned char var3 = Enum_ov023_021e68cc_19;
    for (int var4 = 0; var4 < 3; var4++) {
        Struct_ov023_021e68cc_3* var5 = func_0205d81c((Struct_0205d81c*)arg0->unknown_ac_, (unsigned char)(var4 + 7));
        var1 = ((short)(var5->unknown_ac_ * 8) + 10) << 12;
        short var6 = var5->unknown_ae_ * 8;
        for (int var7 = 0; var7 < 2; var7++) {
            int var8 = 0x10;
            int var9 = 0xd;
            int var10 = 1;
            if (var7 == 1) {
                var8 = 0x1c;
                var9 = 0xe;
                var10 = -1;
            }
            Struct_ov023_021e68cc* var11 = &arg0->unknown_1364_[var9];
            int var12 = var6 + var8;
            var11->unknown_14_ = var1;
            var11->unknown_18_ = var12 << 12;
            var11->unknown_22_ = var3++;
            var11->unknown_25_ = 7;
            if (var2 == arg0->unknown_13a8_) {
                var11->unknown_14_ = var1;
                var11->unknown_18_ = (var12 - var10) << 12;
            }
            if (!(self->enabledMask_ & (1 << slot)))
                sprite->palette = 0xd;
            SpriteContext_DrawSprite(self->renderer_, sprite);
            slot++;
        }
    }
    arg0->unknown_13a8_ = -1;
}
