#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void *Zone3D_GetInstance(void);
int IsInRange0201b588(int zoneId);
int IsInRange0201b5b0(int zoneId);
void SetElementFields0202756c(void *receiver, int x, int y, int elementIndex, unsigned char image, unsigned char palette,
                              unsigned short tile, unsigned char flags, int scaleX, int scaleY);

#if defined(jpn)
enum { Enum_02024000_0 = 0x20, Enum_02024000_0_2 = -0xac, Enum_02024000_28620 = 0x6d8c };
#else
enum { Enum_02024000_0 = 0, Enum_02024000_0_2 = 0, Enum_02024000_28620 = 0x6fcc };
#endif

struct Struct_02024000_3 {
    fix32_t unknown_0_[9];
    fix32_t unknown_24_;
    fix32_t unknown_28_;
    fix32_t unknown_2c_;
    fix32_t unknown_30_;
};

struct Struct_02024000_4 {
    unsigned char unknown_0_[0x1c8 + Enum_02024000_0];
    unsigned char *unknown_1c8_;
    unsigned char *unknown_1cc_;
    int unknown_1d0_;
    int unknown_1d4_;
    unsigned char unknown_1d8_;
    unsigned char unknown_1d9_;
    unsigned char unknown_1da_;
    unsigned char unknown_1db_;
    Struct_02024000_3 unknown_1dc_[2];
};

struct Struct_02024000 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[0x23ec + Enum_02024000_0 - 2];
    Struct_02024000_4 unknown_23ec_;
};

struct Struct_02024000_2 {
    unsigned char unknown_0_[0x38];
    fix32_t unknown_38_;
    unsigned char unknown_3c_[8];
    int unknown_44_;
    int unknown_48_;
    unsigned char unknown_4c_[0x9ba + Enum_02024000_0_2 - 0x4c];
    unsigned char unknown_9ba_;
};

static inline fix32_t inline_02024000(fix32_t arg0, fix32_t arg1) {
    return FIX32_MULTIPLY(arg0, arg1);
}

static inline Struct_02024000_3 *inline_02024000_2(Struct_02024000_4 *arg0, int arg1) {
    return arg0->unknown_1dc_ + arg1 - 1;
}

// USA: func_02024000
extern "C" ARM void func_02024000(void *receiver) {
    ElementReceiver *state = static_cast<ElementReceiver *>(receiver);
    GameState *game = GameState::GetInstance();
    ZoneRecord *zone = static_cast<ZoneRecord *>(Zone3D_GetInstance());
    unsigned short zoneId = zone->zoneId;
    if (!IsInRange0201b588(zoneId)) {
        return;
    }
    func_0202756c(arg0, 0xbc000, 0x3000, 26, 0x42, 0, 0xff, 0xff, 0x1000, 0x1000);
    if (!func_0201b5b0(var3)) {
        return;
    }
    unsigned char *var4 = reinterpret_cast<unsigned char *>(var1) + Enum_02024000_28620 + (var3 % 20 - 1) * 32;
    Struct_02024000_4 *var5 = &var2->unknown_23ec_;
    Struct_02024000_3 *var6 = inline_02024000_2(var5, 1);
    unsigned char var7 = var5->unknown_1d8_;
    unsigned char var8 = var5->unknown_1d9_;
    unsigned char var9 = var5->unknown_1da_;
    unsigned char var10 = var5->unknown_1db_;
    bool var11 = false;
    bool var12 = false;
    Struct_02024000_3 *var13 = inline_02024000_2(var5, 2);
    for (int var14 = 0; var14 < 16; var14++) {
        for (int var15 = 0; var15 < 16; var15++) {
            bool var16;
            if (var15 < 8) {
                var16 = (var4[var14 * 2] & (1 << var15)) != 0;
            } else {
                var16 = (var4[var14 * 2 + 1] & (1 << (var15 - 8))) != 0;
            }
            if (var15 == var7 && var14 == var8 && var16) {
                var11 = true;
            }
            if (var15 == var9 && var14 == var10 && var16) {
                var12 = true;
            }
        }
    }
    if (var11) {
        int var17 = inline_02024000(var6->unknown_2c_, var0->unknown_38_) - (var0->unknown_48_ << 12) + 0x5c000;
        int var18 = inline_02024000(var6->unknown_24_, var0->unknown_38_) - (var0->unknown_44_ << 12) + 0x7c000;
        func_0202756c(arg0, var18, var17, 24, 0x40, 1, 0xff, 0xff, 0x1000, 0x1000);
    }
    if (!var12 && !var0->unknown_9ba_) {
        return;
    }
    int var19 = inline_02024000(var13->unknown_2c_, var0->unknown_38_) - (var0->unknown_48_ << 12) + 0x5c000;
    int var20 = inline_02024000(var13->unknown_24_, var0->unknown_38_) - (var0->unknown_44_ << 12) + 0x7c000;
    func_0202756c(arg0, var20, var19, 25, 0x41, 1, 0xff, 0xff, 0x1000, 0x1000);
}
