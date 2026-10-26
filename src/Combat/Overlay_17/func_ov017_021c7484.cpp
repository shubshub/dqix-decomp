#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c7484 {
    unsigned int s0 : 3, s1 : 3, s2 : 3, s3 : 3, unknown_1_4_ : 3, unknown_1_7_ : 3, unknown_2_2_ : 3, unknown_2_5_ : 3, unknown_3_0_ : 3, unknown_3_3_ : 3;
};

struct Struct_ov017_021c7484_2 {
    char pad0[0x26];
    unsigned char active;
    char unknown_27_[0x35];
    unsigned char current[20];
    char unknown_70_[0xf];
    unsigned char base[20];
};

struct Struct_ov017_021c7484_3 {
    unsigned short event;
    unsigned short index;
    Struct_ov017_021c7484 low;
    Struct_ov017_021c7484 high;
    char unknown_c_[2];
    unsigned char selector;
    char unknown_f_;
};

struct Struct_ov017_021c7484_4 {
    unsigned char type;
    char pad1[3];
    Struct_ov017_021c7484_3 payload;
};

struct Struct_ov017_021c7484_5 { char pad0[8]; unsigned short event; };

extern "C" void* func_ov017_021b8478(void*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021c7484
extern "C" ARM void func_ov017_021c7484() {
    GameState* game = GameState::GetInstance();
    Struct_ov017_021c7484_5* selection = (Struct_ov017_021c7484_5*)func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
    void* context = LinkMessageQueue_GetInstance();
    Struct_ov017_021c7484_4 message;
    message.type = 0x72;
    Struct_ov017_021c7484_3* payload = &message.payload;
    for (int i = 0; i < 4; ++i) {
        if (!func_020a35e0((unsigned char*)selection, i)) continue;
        GameObject* combatant = game->GetCombatantByIndex(i);
        if (!((Struct_ov017_021c7484_2*)combatant->currentStats_)->active) continue;
        payload->event = selection->event;
        payload->index = i;
        Struct_ov017_021c7484_2* stats = (Struct_ov017_021c7484_2*)combatant->currentStats_;
        payload->selector = 1;
        payload->low.s0 = stats->current[0];
        payload->low.s1 = stats->current[1];
        payload->low.s2 = stats->current[2];
        payload->low.s3 = stats->current[3];
        payload->low.unknown_1_4_ = stats->current[4];
        payload->low.unknown_1_7_ = stats->current[5];
        payload->low.unknown_2_2_ = stats->current[6];
        payload->low.unknown_2_5_ = stats->current[7];
        payload->low.unknown_3_0_ = stats->current[8];
        payload->low.unknown_3_3_ = stats->current[9];
        payload->high.s0 = stats->current[10];
        payload->high.s1 = stats->current[11];
        payload->high.s2 = stats->current[12];
        payload->high.s3 = stats->current[13];
        payload->high.unknown_1_4_ = stats->current[14];
        payload->high.unknown_1_7_ = stats->current[15];
        payload->high.unknown_2_2_ = stats->current[16];
        payload->high.unknown_2_5_ = stats->current[17];
        payload->high.unknown_3_0_ = stats->current[18];
        payload->high.unknown_3_3_ = stats->current[19];
        func_0205e330(context, &message, 0);
        stats = (Struct_ov017_021c7484_2*)combatant->currentStats_;
        payload->selector = 0;
        payload->low.s0 = stats->base[0];
        payload->low.s1 = stats->base[1];
        payload->low.s2 = stats->base[2];
        payload->low.s3 = stats->base[3];
        payload->low.unknown_1_4_ = stats->base[4];
        payload->low.unknown_1_7_ = stats->base[5];
        payload->low.unknown_2_2_ = stats->base[6];
        payload->low.unknown_2_5_ = stats->base[7];
        payload->low.unknown_3_0_ = stats->base[8];
        payload->low.unknown_3_3_ = stats->base[9];
        payload->high.s0 = stats->base[10];
        payload->high.s1 = stats->base[11];
        payload->high.s2 = stats->base[12];
        payload->high.s3 = stats->base[13];
        payload->high.unknown_1_4_ = stats->base[14];
        payload->high.unknown_1_7_ = stats->base[15];
        payload->high.unknown_2_2_ = stats->base[16];
        payload->high.unknown_2_5_ = stats->base[17];
        payload->high.unknown_3_0_ = stats->base[18];
        payload->high.unknown_3_3_ = stats->base[19];
        func_0205e330(context, &message, 0);
    }
}
