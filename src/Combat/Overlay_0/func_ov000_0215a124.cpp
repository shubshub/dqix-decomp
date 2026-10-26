#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215a124
extern "C" ARM int func_ov000_0215a124(void* unused, int id, int amount) {
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
    if (c == 0) {
        return 0;
    }
    int var1;
    struct ModifiableCombatStats* stats = c->currentStats_;
    var1 = stats->primaryStats.currMP - amount;
    if (var1 <= 0) {
        var1 = 0;
    }
    stats->primaryStats.currMP = (unsigned short)var1;
    return (short)var1;
}
