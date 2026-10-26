#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov002_021548c4 {
    char pad[4];
    unsigned short cur;
};

// USA: func_ov002_021548c4
extern "C" ARM short func_ov002_021548c4(void* obj, int combatantId, int delta, unsigned char* status) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 0;
    }

    unsigned short maxHP = combatant->baseStats_->primaryStats.maxHP;
    unsigned short cur = (*(struct Struct_ov002_021548c4**)((char*)combatant + 0x130))->cur;
    int sum = cur + delta;
    int amount;

    if (sum >= maxHP) {
        amount = maxHP - cur;
        if (amount == 0) {
            *status = 0;
        } else {
            *status = 3;
        }
    } else {
        *status = 3;
        amount = sum - cur;
    }

    (*(struct Struct_ov002_021548c4**)((char*)combatant + 0x130))->cur = cur + amount;
    return (short)amount;
}
