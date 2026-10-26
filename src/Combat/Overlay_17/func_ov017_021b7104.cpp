#if defined(jpn)
enum {regionalOffset0=0xc8, regionalOffset1=0x4200, regionalOffset2=0x12};
#else
enum {regionalOffset0=0x2e8, regionalOffset1=0x4400, regionalOffset2=0xc2};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021b7104 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned short f4;
    unsigned char pad6[2];
    unsigned int f8;
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char unknown_13_[1];
    unsigned int f14;
};

struct Struct_ov017_021b7104_2 {
    unsigned char pad0[0x20];
    unsigned char f20;
    unsigned char unknown_21_;
    unsigned short f22;
    unsigned short f24;
    unsigned short unknown_26_;
    unsigned int f28;
    unsigned char pad2c[0x40 - 0x2c];
    unsigned char f40;
    unsigned char unknown_41_;
    unsigned char unknown_42_;
    unsigned char unknown_43_[1];
    unsigned short unknown_44_;
    unsigned char f46;
    unsigned char unknown_47_[1];
    unsigned int unknown_48_;
    unsigned char unknown_4c_[0x51 - 0x4c];
    unsigned char unknown_51_;
};

// USA: func_ov017_021b7104
extern "C" ARM void func_ov017_021b7104(Struct_ov017_021b7104_2* dst, Struct_ov017_021b7104* src) {
    GameState* battle = GameState::GetInstance();
    GameResources* ov = GetGameResources();

    dst->f22 = src->f1;
    dst->f24 = src->f4;
    dst->unknown_26_ = src->f2;
    dst->f20 = src->f0;
    int val;
    if (src->f0 == 0) {
        val = -1;
    } else {
        val = GameState_GetProtagonistIndex(battle);
    }
    dst->f46 = (unsigned char)val;
    dst->f28 = src->f8;
    dst->unknown_41_ = src->unknown_d_;
    dst->f40 = src->fc;
    dst->unknown_42_ = src->fe;
    dst->unknown_44_ = (unsigned short)src->f10;
    dst->unknown_51_ = src->ff;
    dst->unknown_48_ = src->f14;
    dst->unknown_21_ = src->f12;

    if (src->f0 != 0 && src->f14 == 0) {
        SetFlags00(ov, 0x800);
    }

    *((unsigned char*)ov + 0x4000 + regionalOffset0) = 0;
    *(unsigned short*)((char*)ov + regionalOffset1 + regionalOffset2) = 0;
}
