#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

#if defined(jpn)
#define func_020c39c8 func_020c5494
#endif

struct Struct_ov001_0215686c {
    char unknown_0_[0xd2];
    short unknown_d2_;
};

struct Struct_ov001_0215686c_2 {
    char unknown_0_[0xa];
    unsigned short unknown_a_;
    char unknown_c_[0x16 - 0xc];
    unsigned short unknown_16_;
    char unknown_18_[0x50 - 0x18];
    unsigned short unknown_50_;
#if defined(jpn)
    char unknown_52_[0xcb - 0x52];
#else
    char unknown1_52_[0xcf - 0x52];
#endif
    unsigned char unknown_cf_;
    char unknown_d0_[0x104 - 0xd0];
    unsigned char unknown_104_;
    char unknown_105_[4];
    unsigned char unknown_109_;
    char unknown_10a_[0x120 - 0x10a];
    Struct_ov001_0215686c* unknown_120_;
};

struct Struct_ov001_0215686c_3 {
#if defined(jpn)
    char unknown_0_[0x524];
#else
    char unknown1_0_[0x734];
#endif
    Struct_ov001_0215686c_2* unknown_734_;
};

struct Struct_ov001_0215686c_4 {
    char unknown_0_[0x2c];
    unsigned char* unknown_2c_;
};

extern "C" int func_020c39c8(volatile unsigned short* arg0);
extern "C" void* func_0202ae18(void);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40_020dc2bc();
void Background_Init(struct BackgroundGraphics* obj);

static inline unsigned int inline_ov001_0215686c(Struct_ov001_0215686c_2* arg0) {
    return arg0->unknown_a_;
}

// USA: func_ov001_0215686c
extern "C" ARM void func_ov001_0215686c(void) {
    struct BackgroundGraphics list;
    char buf[0x20];

    int var2 = (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    int var3 = 1;
    if (var2 == 1) {
        var3 = 0;
    }

    GameResources* var4 = GetGameResources();
    int var5 = GetBrightness((GameResources*)var4, true);
    if (var3 == 0) {
        var5 = func_020c39c8((volatile unsigned short*)0x0400006c);
    }

    if (var5 != -0x10 && var5 != 0x10) {
        return;
    }
    if (var3 == 0) {
        return;
    }

    Struct_ov001_0215686c_2* var6 = ((struct Struct_ov001_0215686c_3*)((char*)var4 + 0x3000))->unknown_734_;
    Struct_ov001_0215686c* var7 = var6->unknown_120_;
    func_0202ae18();

    if (!(var6->unknown_50_ & 0x20)) {
        if (TestFlags00(var4, 0x1000) == 0) {
            goto cont;
        }
    }
    if (var6->unknown_50_ & 0x100) {
        goto cont;
    }
    if ((var6->unknown_50_ & 2) && var7 != 0) {
        if (var7->unknown_d2_ < 0) {
            goto cont;
        }
    }
    if (var6->unknown_a_ != 5) {
        return;
    }
cont:
    if (var6->unknown_16_ == 0xc69a || var6->unknown_16_ == 0xc9e1) {
        return;
    }
    if (var6->unknown_16_ == 1 && var6->unknown_cf_ == 2) {
        if (var6->unknown_109_ != 0) {
            return;
        }
    }

    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
    OrGlobalFlag0x40_020dc2bc();

    volatile unsigned int* var8 = (volatile unsigned int*)0x4001000;
    volatile unsigned short* var9 = (volatile unsigned short*)0x4001000;
    *var8 = (*var8 & ~0x1f00) | 0x1800;
    var9[7] = (var9[7] & 0x43) | 0xd00;
    var9[4] = var9[4] & ~3;
    var9[5] = (var9[5] & ~3) | 2;
    var9[6] = (var9[6] & ~3) | 3;
    var9[7] = (var9[7] & ~3) | 1;
    var8[4] = 0;
    var8[5] = 0;
    var8[6] = 0;
    var8[7] = 0;
    var9[0x28] = 0;

    Background_Init(&list);
    list.subScreen_ = 3;

    unsigned char* var10 = ((struct Struct_ov001_0215686c_4*)var4)->unknown_2c_;
    CleanInvalidateCacheRange(var10 + 0xc, 0x20);
    LoadToSubBGStandardPalette(var10 + 0xc, 0, 0x20);
    CleanCacheRange(var10 + 0xc, 0x20);

    memset(var1, 0xff, 0x20);
    if (var5 == -0x10) {
        memset(var1, 0x11, 0x20);
    }
    CleanInvalidateCacheRange(var1, 0x20);
    LoadToSubBG3CharacterData(var1, 0x6000, 0x20);
    CleanCacheRange(var1, 0x20);

    unsigned short* var11 = (unsigned short*)GetSubBG3ScreenBase();
    for (unsigned short var12 = 0; var12 < 0x300; var12++) {
        *var11++ = 0x300;
    }

    var6->unknown_104_ = 1;

    unsigned int var13;
    int var14 = (var7 == 0 || (var7 != 0 && var7->unknown_d2_ < 0)) ? 1 : 0;
    var13 = inline_ov001_0215686c(var6);
    if (var13 >= 3 && var14 != 0) {
        SetSubBrightness(var4, 0, 0);
        var6->unknown_109_ = 1;
    }
}
