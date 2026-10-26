#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c6d50 {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char bit2 : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char count : 4;
};
struct Struct_ov017_021c71a4 {
    char pad0[0x26];
    unsigned char active;
    char unknown_27_[0x13];
    unsigned char flag;
    Struct_ov017_021c6d50 status;
};
struct Struct_ov017_021c71a4_2 {
    unsigned short event;
    unsigned short index;
    char pad8[9];
    Struct_ov017_021c6d50 status;
    char pad12;
    unsigned char unused : 7;
    unsigned char flag : 1;
};
struct Struct_ov017_021c71a4_3 { unsigned char type; char pad1[3]; unsigned int payload[4]; };
struct Struct_ov017_021c71a4_4 { char pad0[8]; unsigned short event; };
static inline unsigned int inline_ov017_021c71a4_2(Struct_ov017_021c71a4* stats) { return stats->status.bit0; }
static inline unsigned int inline_ov017_021c71a4_3(Struct_ov017_021c71a4* stats) { return stats->status.unknown_0_1_; }
static inline unsigned int inline_ov017_021c71a4_4(Struct_ov017_021c71a4* stats) { return stats->status.bit2; }
static inline unsigned int inline_ov017_021c71a4(Struct_ov017_021c71a4* stats) { return stats->status.unknown_0_3_; }
static inline unsigned int inline_ov003_0216e714(Struct_ov017_021c71a4* stats) { return stats->status.count; }
extern "C" Struct_ov017_021c71a4_4* func_ov017_021b8478(void*);
extern "C" void* LinkMessageQueue_GetInstance();
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021c71a4
extern "C" ARM void func_ov017_021c71a4() {
    GameState* game = GameState::GetInstance();
#if defined(jpn)
    Struct_ov017_021c71a4_4* selection = func_ov017_021b8478(*(void**)((char*)GetGameResources() + 0x3508));
#else
    Struct_ov017_021c71a4_4* selection = func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
#endif
    void* context = LinkMessageQueue_GetInstance();
    Struct_ov017_021c71a4_3 message;
    message.type = 0x71;
    Struct_ov017_021c71a4_2* payload = (Struct_ov017_021c71a4_2*)message.payload;
    for (int i = 0; i < 4; ++i) {
        if (!func_020a35e0((unsigned char*)selection, i)) continue;
        GameObject* combatant = game->GetCombatantByIndex(i);
        if (!combatant || !((Struct_ov017_021c71a4*)combatant->currentStats_)->active) continue;
        payload->event = selection->event;
        payload->index = i;
        payload->status.bit0 = (unsigned char)inline_ov017_021c71a4_2((Struct_ov017_021c71a4*)combatant->currentStats_);
        payload->status.unknown_0_1_ = (unsigned char)inline_ov017_021c71a4_3((Struct_ov017_021c71a4*)combatant->currentStats_);
        payload->status.bit2 = (unsigned char)inline_ov017_021c71a4_4((Struct_ov017_021c71a4*)combatant->currentStats_);
        payload->status.unknown_0_3_ = (unsigned char)inline_ov017_021c71a4((Struct_ov017_021c71a4*)combatant->currentStats_);
        payload->status.count = (unsigned char)inline_ov003_0216e714((Struct_ov017_021c71a4*)combatant->currentStats_);
        payload->flag = ((Struct_ov017_021c71a4*)combatant->currentStats_)->flag;
        func_0205e330(context, &message, 0);
    }
}
