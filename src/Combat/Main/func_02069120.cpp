#include <globaldefs.h>
#include "GameState/GameState.h"

static inline BaseCombatStats* inline_02069120(GameObject* obj) {
    return obj->baseStats_;
}

// USA: func_02069120
extern "C" ARM void func_02069120(void* unused, int* accum) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(0);
    if (combatant == NULL) {
        return;
    }
    BaseCombatStats* stats = inline_02069120(combatant);
    *accum += sprintf((char*)(*accum), stats->name);
}
