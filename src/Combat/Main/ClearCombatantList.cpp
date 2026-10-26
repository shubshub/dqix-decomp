#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

// USA: func_0200fd58
ARM void* ClearCombatantList_0200fd58(GameState* gameState) {
    return memset(gameState->objects_, 0, sizeof(gameState->objects_));
}
