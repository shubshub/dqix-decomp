#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: _Z34GetCombatantWithFlag0x100_0200ff1cP9GameStatei
ARM GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int index) {
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
    if ((object->obj3D_.unknown_0_ & 0x100) == 0) {
        object = 0;
    }
    return object;
}
