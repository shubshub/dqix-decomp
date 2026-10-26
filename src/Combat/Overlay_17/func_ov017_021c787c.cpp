#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void*);
extern "C" void* func_ov017_021b8468(void*);
extern "C" void* func_ov017_021b8470(void*);
extern "C" int GameState_GetProtagonistIndex(GameState*);

struct Struct_ov017_021c787c {
    unsigned char padding0[8];
    unsigned short unknown_8_;
    unsigned char unknown_a_[0x20];
    signed char unknown_2a_;
};
struct Struct_ov017_021c787c_2 {
    unsigned int unknown_0_0_:3, unknown_0_3_:3, unknown_0_6_:3, unknown_1_1_:3, unknown_1_4_:3;
    unsigned int unknown_1_7_:3, unknown_2_2_:3, unknown_2_5_:3, unknown_3_0_:3, unknown_3_3_:3;
};
struct Struct_ov017_021c787c_3 {
    unsigned int field0;
    unsigned short unknown_4_;
    unsigned short combatantId;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned short field10;
    unsigned char selector;
};
struct Struct_ov017_021c787c_4 {
    unsigned char padding0[0x5c];
    unsigned char unknown_5c_[20];
    unsigned char padding70[15];
    unsigned char unknown_7f_[20];
};

// USA: func_ov017_021c787c
extern "C" ARM void func_ov017_021c787c(int unused, Struct_ov017_021c787c_3* packet, GameState* game, GameResources* resources) {
    void* handle = resources->unknown_ptr_3718;
    Struct_ov017_021c787c* event = (Struct_ov017_021c787c*)func_ov017_021b8478(handle);
    if (!event) return;
    if (!func_ov017_021b8468(handle)) return;
    if (!func_ov017_021b8470(handle)) return;
    int index = GameState_GetProtagonistIndex(game);
    if (event->unknown_2a_ == index) return;
    if (event->unknown_8_ != packet->unknown_4_) return;
    GameObject* combatant = game->GetCombatantByIndex(packet->combatantId);
    if (!combatant) return;
    Struct_ov017_021c787c_2* low = (Struct_ov017_021c787c_2*)&packet->unknown_8_;
    Struct_ov017_021c787c_2* high = (Struct_ov017_021c787c_2*)&packet->unknown_c_;
    Struct_ov017_021c787c_4* stats = (Struct_ov017_021c787c_4*)combatant->currentStats_;
    switch (packet->selector) {
    case 1: {
        stats->unknown_5c_[0] = low->unknown_0_0_;
        stats->unknown_5c_[1] = low->unknown_0_3_;
        stats->unknown_5c_[2] = low->unknown_0_6_;
        stats->unknown_5c_[3] = low->unknown_1_1_;
        stats->unknown_5c_[4] = low->unknown_1_4_;
        stats->unknown_5c_[5] = low->unknown_1_7_;
        stats->unknown_5c_[6] = low->unknown_2_2_;
        stats->unknown_5c_[7] = low->unknown_2_5_;
        stats->unknown_5c_[8] = low->unknown_3_0_;
        stats->unknown_5c_[9] = low->unknown_3_3_;
        stats->unknown_5c_[10] = high->unknown_0_0_;
        stats->unknown_5c_[11] = high->unknown_0_3_;
        stats->unknown_5c_[12] = high->unknown_0_6_;
        stats->unknown_5c_[13] = high->unknown_1_1_;
        stats->unknown_5c_[14] = high->unknown_1_4_;
        stats->unknown_5c_[15] = high->unknown_1_7_;
        stats->unknown_5c_[16] = high->unknown_2_2_;
        stats->unknown_5c_[17] = high->unknown_2_5_;
        stats->unknown_5c_[18] = high->unknown_3_0_;
        stats->unknown_5c_[19] = high->unknown_3_3_;
        break;
    }
    default: {
        stats->unknown_7f_[0] = low->unknown_0_0_;
        stats->unknown_7f_[1] = low->unknown_0_3_;
        stats->unknown_7f_[2] = low->unknown_0_6_;
        stats->unknown_7f_[3] = low->unknown_1_1_;
        stats->unknown_7f_[4] = low->unknown_1_4_;
        stats->unknown_7f_[5] = low->unknown_1_7_;
        stats->unknown_7f_[6] = low->unknown_2_2_;
        stats->unknown_7f_[7] = low->unknown_2_5_;
        stats->unknown_7f_[8] = low->unknown_3_0_;
        stats->unknown_7f_[9] = low->unknown_3_3_;
        stats->unknown_7f_[10] = high->unknown_0_0_;
        stats->unknown_7f_[11] = high->unknown_0_3_;
        stats->unknown_7f_[12] = high->unknown_0_6_;
        stats->unknown_7f_[13] = high->unknown_1_1_;
        stats->unknown_7f_[14] = high->unknown_1_4_;
        stats->unknown_7f_[15] = high->unknown_1_7_;
        stats->unknown_7f_[16] = high->unknown_2_2_;
        stats->unknown_7f_[17] = high->unknown_2_5_;
        stats->unknown_7f_[18] = high->unknown_3_0_;
        stats->unknown_7f_[19] = high->unknown_3_3_;
    }
    }
}
