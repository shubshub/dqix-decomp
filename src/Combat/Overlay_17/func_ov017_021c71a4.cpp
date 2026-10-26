#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c6d50 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 1;
    unsigned char unknown_0_2_ : 1;
    unsigned char unknown_0_3_ : 1;
    unsigned char unknown_0_4_ : 4;
};
struct Struct_ov017_021c71a4 {
    char unknown_0_[0x26];
    unsigned char unknown_26_;
    char unknown_27_[0x13];
    unsigned char unknown_3a_;
    Struct_ov017_021c6d50 unknown_3b_;
};
struct Struct_ov017_021c71a4_2 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[9];
    Struct_ov017_021c6d50 unknown_d_;
    char unknown_e_;
    unsigned char unknown_f_0_ : 7;
    unsigned char unknown_f_7_ : 1;
};
struct StatusMessage { unsigned char type; char pad1[3]; unsigned int payload[4]; };
struct StatusSelection { char pad0[8]; unsigned short event; };
static inline unsigned int GetBit0(StatusStats* stats) { return stats->status.bit0; }
static inline unsigned int GetBit1(StatusStats* stats) { return stats->status.bit1; }
static inline unsigned int GetBit2(StatusStats* stats) { return stats->status.bit2; }
static inline unsigned int GetBit3(StatusStats* stats) { return stats->status.bit3; }
static inline unsigned int GetCount(StatusStats* stats) { return stats->status.count; }
extern "C" StatusSelection* func_ov017_021b8478(void*);
void* LinkMessageQueue_GetInstance();
int TestBitAt0x34_020a35e0(unsigned char*, unsigned char);
extern "C" void func_0205e330(void*, void*, int);

// USA: func_ov017_021c71a4
extern "C" ARM void func_ov017_021c71a4() {
    GameState* var0 = GameState::GetInstance();
#if defined(jpn)
    Struct_ov017_021c71a4_4* var1 = func_ov017_021b8478(*(void**)((char*)GetGameResources() + 0x3508));
#else
    Struct_ov017_021c71a4_4* var1 = func_ov017_021b8478(GetGameResources()->unknown_ptr_3718);
#endif
    void* context = LinkMessageQueue_GetInstance();
    StatusMessage message;
    message.type = 0x71;
    StatusPayload* payload = (StatusPayload*)message.payload;
    for (int i = 0; i < 4; ++i) {
        if (!TestBitAt0x34_020a35e0((unsigned char*)selection, i)) continue;
        GameObject* combatant = game->GetCombatantByIndex(i);
        if (!combatant || !((StatusStats*)combatant->currentStats_)->active) continue;
        payload->event = selection->event;
        payload->index = i;
        payload->status.bit0 = (unsigned char)GetBit0((StatusStats*)combatant->currentStats_);
        payload->status.bit1 = (unsigned char)GetBit1((StatusStats*)combatant->currentStats_);
        payload->status.bit2 = (unsigned char)GetBit2((StatusStats*)combatant->currentStats_);
        payload->status.bit3 = (unsigned char)GetBit3((StatusStats*)combatant->currentStats_);
        payload->status.count = (unsigned char)GetCount((StatusStats*)combatant->currentStats_);
        payload->flag = ((StatusStats*)combatant->currentStats_)->flag;
        func_0205e330(context, &message, 0);
    }
}
