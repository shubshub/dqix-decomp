#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021f87dc {
    char pad0[4];
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
    char unknown_c_[0x18 - 0xc];
    unsigned int unknown_18_0_ : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int rest18 : 16;
};

extern "C" int func_ov024_021eadfc(GameObject* combatant);
extern "C" unsigned int func_020dd290(void* obj, unsigned int val);

// USA: func_ov024_021f87dc
extern "C" ARM int func_ov024_021f87dc(GameObject* combatant, Struct_ov024_021f87dc* skill, int* arg2) {
    *arg2 = skill->unknown_8_0_;
    if (skill->unknown_19_4_ == 2) {
        if (combatant != 0 && func_ov024_021eadfc(combatant)) {
            *arg2 = 0;
        } else if (skill->id == 0x28) {
            *arg2 = 0x14;
            if (combatant->currentStats_->primaryStats.currMP > *arg2) {
                *arg2 = combatant->currentStats_->primaryStats.currMP;
            }
        } else {
            *arg2 = func_020dd290(combatant, *arg2);
        }
    }
    return *arg2;
}
