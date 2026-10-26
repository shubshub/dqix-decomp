#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c7484 {
    unsigned int unknown_0_0_ : 3, unknown_0_3_ : 3, unknown_0_6_ : 3, unknown_1_1_ : 3, unknown_1_4_ : 3, unknown_1_7_ : 3, unknown_2_2_ : 3, unknown_2_5_ : 3, unknown_3_0_ : 3, unknown_3_3_ : 3;
};

struct Struct_ov017_021c7484_2 {
    char unknown_0_[0x26];
    unsigned char unknown_26_;
    char unknown_27_[0x35];
    unsigned char unknown_5c_[20];
    char unknown_70_[0xf];
    unsigned char unknown_7f_[20];
};

struct Struct_ov017_021c7484_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Struct_ov017_021c7484 unknown_4_;
    Struct_ov017_021c7484 unknown_8_;
    char unknown_c_[2];
    unsigned char unknown_e_;
    char unknown_f_;
};

struct Struct_ov017_021c7484_4 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    Struct_ov017_021c7484_3 unknown_4_;
};

struct Struct_ov017_021c7484_5 { char unknown_0_[8]; unsigned short unknown_8_; };

extern "C" void* func_ov017_021b8478(void*);
void* LinkMessageQueue_GetInstance();
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021c7484
extern "C" ARM void func_ov017_021c7484() {
    GameState* game = GameState::GetInstance();
    LevelSelection_021c7484* selection = (LevelSelection_021c7484*)func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
    void* context = LinkMessageQueue_GetInstance();
    LevelMessage_021c7484 message;
    message.type = 0x72;
    LevelPayload_021c7484* payload = &message.payload;
    for (int i = 0; i < 4; ++i) {
        if (!TestBitAt0x34_020a35e0((unsigned char*)selection, i)) continue;
        GameObject* combatant = game->GetCombatantByIndex(i);
        if (!((LevelStats_021c7484*)combatant->currentStats_)->active) continue;
        payload->event = selection->event;
        payload->index = i;
        LevelStats_021c7484* stats = (LevelStats_021c7484*)combatant->currentStats_;
        payload->selector = 1;
        payload->low.s0 = stats->current[0];
        payload->low.s1 = stats->current[1];
        payload->low.s2 = stats->current[2];
        payload->low.s3 = stats->current[3];
        payload->low.s4 = stats->current[4];
        payload->low.s5 = stats->current[5];
        payload->low.s6 = stats->current[6];
        payload->low.s7 = stats->current[7];
        payload->low.s8 = stats->current[8];
        payload->low.s9 = stats->current[9];
        payload->high.s0 = stats->current[10];
        payload->high.s1 = stats->current[11];
        payload->high.s2 = stats->current[12];
        payload->high.s3 = stats->current[13];
        payload->high.s4 = stats->current[14];
        payload->high.s5 = stats->current[15];
        payload->high.s6 = stats->current[16];
        payload->high.s7 = stats->current[17];
        payload->high.s8 = stats->current[18];
        payload->high.s9 = stats->current[19];
        func_0205e330(context, &message, 0);
        stats = (LevelStats_021c7484*)combatant->currentStats_;
        payload->selector = 0;
        payload->low.s0 = stats->base[0];
        payload->low.s1 = stats->base[1];
        payload->low.s2 = stats->base[2];
        payload->low.s3 = stats->base[3];
        payload->low.s4 = stats->base[4];
        payload->low.s5 = stats->base[5];
        payload->low.s6 = stats->base[6];
        payload->low.s7 = stats->base[7];
        payload->low.s8 = stats->base[8];
        payload->low.s9 = stats->base[9];
        payload->high.s0 = stats->base[10];
        payload->high.s1 = stats->base[11];
        payload->high.s2 = stats->base[12];
        payload->high.s3 = stats->base[13];
        payload->high.s4 = stats->base[14];
        payload->high.s5 = stats->base[15];
        payload->high.s6 = stats->base[16];
        payload->high.s7 = stats->base[17];
        payload->high.s8 = stats->base[18];
        payload->high.s9 = stats->base[19];
        func_0205e330(context, &message, 0);
    }
}
