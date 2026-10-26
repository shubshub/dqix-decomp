#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021ea584_3 {
    unsigned char unknown_0_[0x8e50];
    short target;
    short skill;
    unsigned char unknown_8e54_[4];
    int action;
    unsigned char unknown_8e5c_[0x26];
    signed char unknown_8e82_;
    signed char count;
};
struct Struct_ov024_021ea584 {
    unsigned char unknown_0_[4];
    int action;
    unsigned char unknown_8_[8];
    Struct_ov024_021ea584_3* battle;
    unsigned char unknown_14_[4];
    int state;
    unsigned char unknown_1c_[0x5c];
    unsigned char unknown_78_;
};
struct Struct_ov024_021ea584_2 {
    unsigned int unknown_0_;
    unsigned int skill : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned char unknown_8_[8];
    unsigned int flags;
    unsigned char unknown_14_[8];
    unsigned int field_1c : 14;
    unsigned int unknown_1d_6_ : 5;
    unsigned int unknown_1e_3_ : 13;
    unsigned char unknown_20_[0xc];
    unsigned int unknown_2c_0_ : 27;
    unsigned int unknown_2f_3_ : 1;
    unsigned int unknown_2f_4_ : 4;
};
struct Struct_ov024_021ea584_4 : GameObject {
#if defined(jpn)
    unsigned char unknown_13c_[8];
#else
    unsigned char unknown1_13c_[0x14];
#endif
    unsigned char* unknown_150_;
};
extern "C" int func_020850d0(unsigned char*);
extern "C" void func_ov000_0215cd80(void*);
static inline int IsPartyMember(int id) { return id >= 0 && id <= 3; }

// USA: func_ov024_021ea584
extern "C" ARM void func_ov024_021ea584(Struct_ov024_021ea584* action, int actor, int target, Struct_ov024_021ea584_2* parameters) {
    if (parameters->skill == 0x61 && action->state > 0) return;
    if (parameters->unknown_1d_6_ && action->state > 0) return;
    if (action->unknown_78_ && action->state > 0) return;
    if (IsPartyMember(actor)) {
        Struct_ov024_021ea584_4* combatant = (Struct_ov024_021ea584_4*)func_0200ff1c(GameState::GetInstance(), actor);
        if (combatant && (parameters->flags & 0x100000) && func_020850d0(combatant->unknown_150_) && action->state > 0) return;
    }
    if (parameters->unknown_2f_3_) {
        if (IsPartyMember(actor)) {
            if (action->battle->unknown_8e82_ != 1) action->battle->count = 0;
            else if (action->battle->action != action->action) action->battle->count++;
            action->battle->unknown_8e82_ = 1;
        } else {
            if (action->battle->unknown_8e82_ != 2) action->battle->count = 0;
            else if (action->battle->action != action->action) action->battle->count++;
            action->battle->unknown_8e82_ = 2;
        }
        if (parameters->skill != action->battle->skill) action->battle->count = 0;
        action->battle->skill = parameters->skill;
        if (target != action->battle->target) action->battle->count = 0;
        action->battle->target = target;
        action->battle->action = action->action;
    } else func_ov000_0215cd80(action->battle);
}
