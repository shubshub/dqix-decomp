#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c7b8c {
    unsigned short unknown_0_;
    unsigned short combatantId;
    unsigned int unknown_4_0_:3, unknown_4_3_:3, unknown_4_6_:3, unknown_5_1_:3, unknown_5_4_:3;
    unsigned int unknown_5_7_:3, unknown_6_2_:3, unknown_6_5_:3, unknown_7_0_:3, unknown_7_3_:3;
    unsigned int :0;
    unsigned int unknown_8_0_:3, unknown_8_3_:3, unknown_8_6_:3, unknown_9_1_:3, unknown_9_4_:4;
    unsigned char selector;
};
struct Struct_ov017_021c7b8c_2 {
    unsigned char kind;
    unsigned char padding[3];
    Struct_ov017_021c7b8c payload;
};
struct Struct_ov017_021c7b8c_3 {
    unsigned char padding0[0x26];
    unsigned char active;
    unsigned char unknown_27_[0x70 - 0x27];
    unsigned char primary[15];
    unsigned char unknown_7f_[0x93 - 0x7f];
    unsigned char unknown_93_[15];
};
struct Struct_ov017_021c7b8c_4 {
    unsigned char padding0[8];
    unsigned short unknown_8_;
};
extern "C" void* func_ov017_021b8478(void*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_0205e330(void*, Struct_ov017_021c7b8c_2*, int);

// USA: func_ov017_021c7b8c
extern "C" ARM void func_ov017_021c7b8c() {
    GameState* game = GameState::GetInstance();
    Struct_ov017_021c7b8c_4* event = (Struct_ov017_021c7b8c_4*)func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
    void* queue = LinkMessageQueue_GetInstance();
    Struct_ov017_021c7b8c* payload;
    Struct_ov017_021c7b8c_2 message;
    payload = &message.payload;
    message.kind = 0x73;
    for (int index = 0; index < 4; ++index) {
        if (!func_020a35e0((unsigned char*)event, index & 255)) continue;
        GameObject* combatant = game->GetCombatantByIndex(index);
        if (!combatant || !((Struct_ov017_021c7b8c_3*)combatant->currentStats_)->active) continue;
        payload->unknown_0_ = event->unknown_8_;
        payload->combatantId = index;
        Struct_ov017_021c7b8c_3* stats = (Struct_ov017_021c7b8c_3*)combatant->currentStats_;
        payload->selector = 1;
        payload->unknown_4_0_ = stats->primary[0];
        payload->unknown_4_3_ = stats->primary[1];
        payload->unknown_4_6_ = stats->primary[2];
        payload->unknown_5_1_ = stats->primary[3];
        payload->unknown_5_4_ = stats->primary[4];
        payload->unknown_5_7_ = stats->primary[5];
        payload->unknown_6_2_ = stats->primary[6];
        payload->unknown_6_5_ = stats->primary[7];
        payload->unknown_7_0_ = stats->primary[8];
        payload->unknown_7_3_ = stats->primary[9];
        payload->unknown_8_0_ = stats->primary[10];
        payload->unknown_8_3_ = stats->primary[11];
        payload->unknown_8_6_ = stats->primary[12];
        payload->unknown_9_1_ = stats->primary[13];
        payload->unknown_9_4_ = stats->primary[14];
        func_0205e330(queue, &message, 0);
        stats = (Struct_ov017_021c7b8c_3*)combatant->currentStats_;
        payload->selector = 0;
        payload->unknown_4_0_ = stats->unknown_93_[0];
        payload->unknown_4_3_ = stats->unknown_93_[1];
        payload->unknown_4_6_ = stats->unknown_93_[2];
        payload->unknown_5_1_ = stats->unknown_93_[3];
        payload->unknown_5_4_ = stats->unknown_93_[4];
        payload->unknown_5_7_ = stats->unknown_93_[5];
        payload->unknown_6_2_ = stats->unknown_93_[6];
        payload->unknown_6_5_ = stats->unknown_93_[7];
        payload->unknown_7_0_ = stats->unknown_93_[8];
        payload->unknown_7_3_ = stats->unknown_93_[9];
        payload->unknown_8_0_ = stats->unknown_93_[10];
        payload->unknown_8_3_ = stats->unknown_93_[11];
        payload->unknown_8_6_ = stats->unknown_93_[12];
        payload->unknown_9_1_ = stats->unknown_93_[13];
        payload->unknown_9_4_ = stats->unknown_93_[14];
        func_0205e330(queue, &message, 0);
    }
}
