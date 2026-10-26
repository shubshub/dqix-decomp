#include <globaldefs.h>
#include "GameState/GameState.h"

int IsFieldNotPositive_021a4e70(unsigned char* base);
unsigned char GameObject_IsClimbingLadder(char* obj);

struct Struct_ov017_0219b33c {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    char unknown_5_[3];
    int unknown_8_;
    int unknown_c_;
    short unknown_10_;
    short unknown_12_;
};

extern const unsigned char data_ov017_021d64a0[15];

struct Struct_ov017_0219b33c_2 { unsigned int unknown_0_[2]; };
struct Struct_ov017_0219b33c_3 { unsigned char unknown_0_[15]; };

// USA: func_ov017_0219b33c
extern "C" ARM void func_ov017_0219b33c(char* arg0, struct Struct_ov017_0219b33c* arg1) {
#if defined(jpn)
 enum {Enum_ov017_0219b33c_396=0x180, Enum_ov017_0219b33c_14020=0x34b4, Enum_ov017_0219b33c_16512=0x3e60, Enum_ov017_0219b33c_14004=0x34a4, Enum_ov017_0219b33c_14005=0x34a5, Enum_ov017_0219b33c_14006=0x34a6, Enum_ov017_0219b33c_14008=0x34a8, Enum_ov017_0219b33c_14012=0x34ac, Enum_ov017_0219b33c_14022=0x34b6};
#else
 enum {Enum_ov017_0219b33c_396=0x18c, Enum_ov017_0219b33c_14020=0x36c4, Enum_ov017_0219b33c_16512=0x4080, Enum_ov017_0219b33c_14004=0x36b4, Enum_ov017_0219b33c_14005=0x36b5, Enum_ov017_0219b33c_14006=0x36b6, Enum_ov017_0219b33c_14008=0x36b8, Enum_ov017_0219b33c_14012=0x36bc, Enum_ov017_0219b33c_14022=0x36c6};
#endif
    GameObject* combatant = GameState::GetInstance()->GetLeader();

    if (!func_ov017_021a4e70((unsigned char*)arg0)) return;

    if (combatant) {
        if (*(int*)((char*)combatant + regionalOffset0) & 1) return;
        if (GameObject_IsClimbingLadder((char*)combatant) != 0) return;
    }

    if (*(short*)(arg0 + Enum_ov017_0219b33c_14020) < arg1->unknown_10_) return;
    if (*(int*)(arg0 + Enum_ov017_0219b33c_16512) != 0) return;

    *(unsigned char*)(arg0 + Enum_ov017_0219b33c_14004) = arg1->unknown_0_;
    *(unsigned char*)(arg0 + Enum_ov017_0219b33c_14005) = arg1->unknown_1_;
    *(unsigned short*)(arg0 + Enum_ov017_0219b33c_14006) = arg1->unknown_2_;
    *(unsigned char*)(arg0 + Enum_ov017_0219b33c_14008) = arg1->unknown_4_;
    *(struct Struct_ov017_0219b33c_2*)(arg0 + Enum_ov017_0219b33c_14012) = *(struct Struct_ov017_0219b33c_2*)&arg1->unknown_8_;
    *(short*)(arg0 + Enum_ov017_0219b33c_14020) = arg1->unknown_10_;
    *(short*)(arg0 + Enum_ov017_0219b33c_14022) = arg1->unknown_12_;

    if (arg1->unknown_1_ != 0x12) return;

    struct Struct_ov017_0219b33c_3 var1;
    unsigned char* var2 = var1.unknown_0_;
    var1 = *(struct Struct_ov017_0219b33c_3*)data_ov017_021d64a0;

    *(unsigned char*)(arg0 + Enum_ov017_0219b33c_14005) = var2[arg1->unknown_0_];
}
