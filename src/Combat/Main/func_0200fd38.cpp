#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200fd38
extern "C" ARM void func_0200fd38(GameState* gameState, int index, GameObject* object) {
    gameState->objects_[index] = object;
    object->obj3D_.actorIndex_ = index;
}
