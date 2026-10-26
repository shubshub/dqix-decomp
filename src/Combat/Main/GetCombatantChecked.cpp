#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200ff94
ARM GameObject* GetCombatantChecked_0200ff94(GameState* gameState, int index) {
    GameObject* object;
    if (index < 0) {
        return 0;
    }
    if (index >= 0xE9) {
        return 0;
    }
    object = gameState->objects_[index];
    if (object == 0) {
        return 0;
    }
    return object;
}
