#include <globaldefs.h>
#include "GameState/GameState.h"

static inline BaseCombatStats* inline_02069120(GameObject* obj) {
    return obj->baseStats_;
}

// USA: func_0206918c
extern "C" ARM void func_0206918c(void* unused, int* accum) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetProtagonist();
    if (combatant == NULL) {
        return;
    }
    BaseCombatStats* stats = inline_02069120(combatant);
    *accum += sprintf((char*)(*accum), (const char*)stats);
}
