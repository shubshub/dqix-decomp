#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c7b8c {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned int unknown_4_0_:3, unknown_4_3_:3, unknown_4_6_:3, unknown_5_1_:3, unknown_5_4_:3;
    unsigned int unknown_5_7_:3, unknown_6_2_:3, unknown_6_5_:3, unknown_7_0_:3, unknown_7_3_:3;
    unsigned int :0;
    unsigned int unknown_8_0_:3, unknown_8_3_:3, unknown_8_6_:3, unknown_9_1_:3, unknown_9_4_:4;
    unsigned char unknown_a_;
};
struct Struct_ov017_021c7b8c_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    Struct_ov017_021c7b8c unknown_4_;
};
struct Struct_ov017_021c7b8c_3 {
    unsigned char unknown_0_[0x26];
    unsigned char unknown_26_;
    unsigned char unknown_27_[0x70 - 0x27];
    unsigned char unknown_70_[15];
    unsigned char unknown_7f_[0x93 - 0x7f];
    unsigned char unknown_93_[15];
};
struct Struct_ov017_021c7b8c_4 {
    unsigned char unknown_0_[8];
    unsigned short unknown_8_;
};
extern "C" void* func_ov017_021b8478(void*);
void* LinkMessageQueue_GetInstance();
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
extern "C" void func_0205e330(void*, StatMessage021c7b8c*, int);

// USA: func_ov017_021c7b8c
extern "C" ARM void func_ov017_021c7b8c() {
    GameState* game = GameState::GetInstance();
    EventInfo021c7b8c* event = (EventInfo021c7b8c*)func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
    void* queue = LinkMessageQueue_GetInstance();
    StatPayload021c7b8c* payload;
    StatMessage021c7b8c message;
    payload = &message.payload;
    message.kind = 0x73;
    for (int index = 0; index < 4; ++index) {
        if (!TestBitAt0x34_020a35e0((unsigned char*)event, index & 255)) continue;
        GameObject* combatant = game->GetCombatantByIndex(index);
        if (!combatant || !((StatSource021c7b8c*)combatant->currentStats_)->active) continue;
        payload->eventId = event->eventId;
        payload->combatantId = index;
        StatSource021c7b8c* stats = (StatSource021c7b8c*)combatant->currentStats_;
        payload->selector = 1;
        payload->level0 = stats->primary[0];
        payload->level1 = stats->primary[1];
        payload->level2 = stats->primary[2];
        payload->level3 = stats->primary[3];
        payload->level4 = stats->primary[4];
        payload->level5 = stats->primary[5];
        payload->level6 = stats->primary[6];
        payload->level7 = stats->primary[7];
        payload->level8 = stats->primary[8];
        payload->level9 = stats->primary[9];
        payload->level10 = stats->primary[10];
        payload->level11 = stats->primary[11];
        payload->level12 = stats->primary[12];
        payload->level13 = stats->primary[13];
        payload->level14 = stats->primary[14];
        func_0205e330(queue, &message, 0);
        stats = (StatSource021c7b8c*)combatant->currentStats_;
        payload->selector = 0;
        payload->level0 = stats->secondary[0];
        payload->level1 = stats->secondary[1];
        payload->level2 = stats->secondary[2];
        payload->level3 = stats->secondary[3];
        payload->level4 = stats->secondary[4];
        payload->level5 = stats->secondary[5];
        payload->level6 = stats->secondary[6];
        payload->level7 = stats->secondary[7];
        payload->level8 = stats->secondary[8];
        payload->level9 = stats->secondary[9];
        payload->level10 = stats->secondary[10];
        payload->level11 = stats->secondary[11];
        payload->level12 = stats->secondary[12];
        payload->level13 = stats->secondary[13];
        payload->level14 = stats->secondary[14];
        func_0205e330(queue, &message, 0);
    }
}
