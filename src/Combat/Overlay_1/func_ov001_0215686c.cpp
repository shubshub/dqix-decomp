#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "NitroSDK/BGBases.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"


struct Struct_ov001_0215686c {
    char pad[0xd2];
    short v;
};

struct Struct_ov001_0215686c_2 {
    char pad0[0xa];
    unsigned short fa;
    char unknown_c_[0x16 - 0xc];
    unsigned short unknown_16_;
    char pad18[0x50 - 0x18];
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
    unsigned char f109;
    char unknown_10a_[0x120 - 0x10a];
    Struct_ov001_0215686c* q;
};

struct Struct_ov001_0215686c_3 {
#if defined(jpn)
    char pad[0x524];
#else
    char pad[0x734];
#endif
    Struct_ov001_0215686c_2* o;
};

struct Struct_ov001_0215686c_4 {
    char pad[0x2c];
    unsigned char* unknown_2c_;
};

extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_020dc2bc();
extern "C" void Background_Init(struct BackgroundGraphics* obj);

static inline unsigned int inline_ov001_0215686c(Struct_ov001_0215686c_2* o) {
    return o->fa;
}

// USA: func_ov001_0215686c
extern "C" ARM void func_ov001_0215686c(void) {
    struct BackgroundGraphics list;
    char buf[0x20];

    int var2 = (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    int flag = 1;
    if (var2 == 1) {
        flag = 0;
    }

    GameResources* res = GetGameResources();
    int axis = GetBrightness((GameResources*)res, true);
    if (flag == 0) {
        axis = GXx_GetMasterBrightness_((volatile unsigned short*)0x0400006c);
    }

    if (axis != -0x10 && axis != 0x10) {
        return;
    }
    if (flag == 0) {
        return;
    }

    Struct_ov001_0215686c_2* o = ((struct Struct_ov001_0215686c_3*)((char*)res + 0x3000))->o;
    Struct_ov001_0215686c* q = o->q;
    LinkSession_GetInstance();

    if (!(o->unknown_50_ & 0x20)) {
        if (TestFlags00(res, 0x1000) == 0) {
            goto cont;
        }
    }
    if (o->unknown_50_ & 0x100) {
        goto cont;
    }
    if ((o->unknown_50_ & 2) && q != 0) {
        if (q->v < 0) {
            goto cont;
        }
    }
    if (o->fa != 5) {
        return;
    }
cont:
    if (o->unknown_16_ == 0xc69a || o->unknown_16_ == 0xc9e1) {
        return;
    }
    if (o->unknown_16_ == 1 && o->unknown_cf_ == 2) {
        if (o->f109 != 0) {
            return;
        }
    }

    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
    func_020dc2bc();

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

    unsigned char* p = ((struct Struct_ov001_0215686c_4*)res)->unknown_2c_;
    CleanInvalidateCacheRange(p + 0xc, 0x20);
    LoadToSubBGStandardPalette(p + 0xc, 0, 0x20);
    CleanCacheRange(p + 0xc, 0x20);

    memset(buf, 0xff, 0x20);
    if (axis == -0x10) {
        memset(buf, 0x11, 0x20);
    }
    CleanInvalidateCacheRange(buf, 0x20);
    LoadToSubBG3CharacterData(buf, 0x6000, 0x20);
    CleanCacheRange(buf, 0x20);

    unsigned short* var11 = (unsigned short*)GetSubBG3ScreenBase();
    for (unsigned short i = 0; i < 0x300; i++) {
        *var11++ = 0x300;
    }

    o->unknown_104_ = 1;

    unsigned int fa;
    int t = (q == 0 || (q != 0 && q->v < 0)) ? 1 : 0;
    fa = inline_ov001_0215686c(o);
    if (fa >= 3 && t != 0) {
        SetSubBrightness(res, 0, 0);
        o->f109 = 1;
    }
}
