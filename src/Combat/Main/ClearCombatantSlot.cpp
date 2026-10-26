#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200fd48
ARM void ClearCombatantSlot_0200fd48(GameState* gameState, int index) {
    gameState->objects_[index] = NULL;
}
