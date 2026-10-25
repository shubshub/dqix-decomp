#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void*);
extern "C" void* func_ov017_021b8468(void*);
void* GetField6b0_021b8470(void*);
int GameState_GetProtagonistIndex(GameState*);

struct Struct_ov017_021c787c {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
    unsigned char unknown_a_[0x20];
    signed char unknown_2a_;
};
struct Struct_ov017_021c787c_2 {
    unsigned int unknown_0_0_:3, unknown_0_3_:3, unknown_0_6_:3, unknown_1_1_:3, unknown_1_4_:3;
    unsigned int unknown_1_7_:3, unknown_2_2_:3, unknown_2_5_:3, unknown_3_0_:3, unknown_3_3_:3;
};
struct Struct_ov017_021c787c_3 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned short unknown_10_;
    unsigned char unknown_12_;
};
struct Struct_ov017_021c787c_4 {
    unsigned char unknown_0_[0x5c];
    unsigned char unknown_5c_[20];
    unsigned char unknown_70_[15];
    unsigned char unknown_7f_[20];
};

// USA: func_ov017_021c787c
extern "C" ARM void func_ov017_021c787c(int unused, StatPacket021c787c* packet, GameState* game, GameResources* resources) {
    void* handle = resources->unknown_ptr_3718;
    EventInfo021c787c* event = (EventInfo021c787c*)func_ov017_021b8478(handle);
    if (!event) return;
    if (!func_ov017_021b8468(handle)) return;
    if (!GetField6b0_021b8470(handle)) return;
    int index = GameState_GetProtagonistIndex(game);
    if (event->combatantIndex == index) return;
    if (event->eventId != packet->eventId) return;
    GameObject* combatant = game->GetCombatantByIndex(packet->combatantId);
    if (!combatant) return;
    StatLevels021c787c* low = (StatLevels021c787c*)&packet->lowLevels;
    StatLevels021c787c* high = (StatLevels021c787c*)&packet->highLevels;
    StatDisplay021c787c* stats = (StatDisplay021c787c*)combatant->currentStats_;
    switch (packet->selector) {
    case 1: {
        var6->unknown_5c_[0] = var4->unknown_0_0_;
        var6->unknown_5c_[1] = var4->unknown_0_3_;
        var6->unknown_5c_[2] = var4->unknown_0_6_;
        var6->unknown_5c_[3] = var4->unknown_1_1_;
        var6->unknown_5c_[4] = var4->unknown_1_4_;
        var6->unknown_5c_[5] = var4->unknown_1_7_;
        var6->unknown_5c_[6] = var4->unknown_2_2_;
        var6->unknown_5c_[7] = var4->unknown_2_5_;
        var6->unknown_5c_[8] = var4->unknown_3_0_;
        var6->unknown_5c_[9] = var4->unknown_3_3_;
        var6->unknown_5c_[10] = var5->unknown_0_0_;
        var6->unknown_5c_[11] = var5->unknown_0_3_;
        var6->unknown_5c_[12] = var5->unknown_0_6_;
        var6->unknown_5c_[13] = var5->unknown_1_1_;
        var6->unknown_5c_[14] = var5->unknown_1_4_;
        var6->unknown_5c_[15] = var5->unknown_1_7_;
        var6->unknown_5c_[16] = var5->unknown_2_2_;
        var6->unknown_5c_[17] = var5->unknown_2_5_;
        var6->unknown_5c_[18] = var5->unknown_3_0_;
        var6->unknown_5c_[19] = var5->unknown_3_3_;
        break;
    }
    default: {
        var6->unknown_7f_[0] = var4->unknown_0_0_;
        var6->unknown_7f_[1] = var4->unknown_0_3_;
        var6->unknown_7f_[2] = var4->unknown_0_6_;
        var6->unknown_7f_[3] = var4->unknown_1_1_;
        var6->unknown_7f_[4] = var4->unknown_1_4_;
        var6->unknown_7f_[5] = var4->unknown_1_7_;
        var6->unknown_7f_[6] = var4->unknown_2_2_;
        var6->unknown_7f_[7] = var4->unknown_2_5_;
        var6->unknown_7f_[8] = var4->unknown_3_0_;
        var6->unknown_7f_[9] = var4->unknown_3_3_;
        var6->unknown_7f_[10] = var5->unknown_0_0_;
        var6->unknown_7f_[11] = var5->unknown_0_3_;
        var6->unknown_7f_[12] = var5->unknown_0_6_;
        var6->unknown_7f_[13] = var5->unknown_1_1_;
        var6->unknown_7f_[14] = var5->unknown_1_4_;
        var6->unknown_7f_[15] = var5->unknown_1_7_;
        var6->unknown_7f_[16] = var5->unknown_2_2_;
        var6->unknown_7f_[17] = var5->unknown_2_5_;
        var6->unknown_7f_[18] = var5->unknown_3_0_;
        var6->unknown_7f_[19] = var5->unknown_3_3_;
    }
    }
}
