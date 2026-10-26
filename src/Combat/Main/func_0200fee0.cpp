#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200fee0
extern "C" ARM GameObject* func_0200fee0(GameState* gameState, int index) {
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
    if ((object->obj3D_.unknown_0_ & 0x200) == 0) {
        object = 0;
    }
    return object;
}
