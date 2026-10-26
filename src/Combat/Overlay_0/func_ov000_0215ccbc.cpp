#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215ccbc {
    unsigned short unknown_0_0_:2;
    unsigned short unknown_0_2_:4;
    unsigned short rest:10;
};

struct Struct_ov000_021584e8 {
    int word0;
    int unknown_4_;
    char pad1[0xc - 8];
    short unknown_c_;
    short unknown_e_;
    short unknown_10_;
    short unknown_12_;
    short unknown_14_;
    char pad2[0x18 - 0x16];
    int unknown_18_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
};

// USA: func_ov000_0215ccbc
extern "C" ARM void func_ov000_0215ccbc(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                                 short arg3, short valA, short valB, unsigned long long words, unsigned char arg7) {
    if (out == NULL) return;
    out->unknown_c_ = arg3;
    out->unknown_e_ = valA;
    out->unknown_10_ = valB;
    out->unknown_12_ = combatant->currentStats_->primaryStats.maxHP;
    out->unknown_14_ = combatant->currentStats_->primaryStats.maxMP;
    out->unknown_18_ = *(int*)((char*)combatant->currentStats_->unk1 + 0);
    out->unknown_1d_ = ((struct Struct_ov000_0215ccbc*)((char*)combatant->currentStats_->unk1 + 0xe))->unknown_0_2_;
    out->unknown_1e_ = ((struct Struct_ov000_0215ccbc*)((char*)combatant->currentStats_->unk1 + 0xe))->unknown_0_0_;
    out->word0 = words;
    out->unknown_4_ = words >> 32;
    out->unknown_1c_ = arg7;
}
