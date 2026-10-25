#if defined(jpn)
enum {Enum_ov017_021b7104_744=0xc8, Enum_ov017_021b7104_17408=0x4200, Enum_ov017_021b7104_194=0x12};
#else
enum {Enum_ov017_021b7104_744=0x2e8, Enum_ov017_021b7104_17408=0x4400, Enum_ov017_021b7104_194=0xc2};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

int GameState_GetProtagonistIndex(GameState* battleStruct);

struct Struct_ov017_021b7104 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    unsigned int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_[1];
    unsigned int unknown_14_;
};

struct Struct_ov017_021b7104_2 {
    unsigned char unknown_0_[0x20];
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned short unknown_22_;
    unsigned short unknown_24_;
    unsigned short unknown_26_;
    unsigned int unknown_28_;
    unsigned char unknown_2c_[0x40 - 0x2c];
    unsigned char unknown_40_;
    unsigned char unknown_41_;
    unsigned char unknown_42_;
    unsigned char unknown_43_[1];
    unsigned short unknown_44_;
    unsigned char unknown_46_;
    unsigned char unknown_47_[1];
    unsigned int unknown_48_;
    unsigned char unknown_4c_[0x51 - 0x4c];
    unsigned char unknown_51_;
};

// USA: func_ov017_021b7104
extern "C" ARM void func_ov017_021b7104(Struct_ov017_021b7104_2* arg0, Struct_ov017_021b7104* arg1) {
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();

    arg0->unknown_22_ = arg1->unknown_1_;
    arg0->unknown_24_ = arg1->unknown_4_;
    arg0->unknown_26_ = arg1->unknown_2_;
    arg0->unknown_20_ = arg1->unknown_0_;
    int var2;
    if (arg1->unknown_0_ == 0) {
        var2 = -1;
    } else {
        val = GameState_GetProtagonistIndex(battle);
    }
    arg0->unknown_46_ = (unsigned char)var2;
    arg0->unknown_28_ = arg1->unknown_8_;
    arg0->unknown_41_ = arg1->unknown_d_;
    arg0->unknown_40_ = arg1->unknown_c_;
    arg0->unknown_42_ = arg1->unknown_e_;
    arg0->unknown_44_ = (unsigned short)arg1->unknown_10_;
    arg0->unknown_51_ = arg1->unknown_f_;
    arg0->unknown_48_ = arg1->unknown_14_;
    arg0->unknown_21_ = arg1->unknown_12_;

    if (arg1->unknown_0_ != 0 && arg1->unknown_14_ == 0) {
        SetFlags00(var1, 0x800);
    }

    *((unsigned char*)var1 + 0x4000 + Enum_ov017_021b7104_744) = 0;
    *(unsigned short*)((char*)var1 + Enum_ov017_021b7104_17408 + Enum_ov017_021b7104_194) = 0;
}
