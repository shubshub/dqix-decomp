#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0200fd48
extern "C" ARM void func_0200fd48(GameState* gameState, int index) {
    gameState->objects_[index] = NULL;
}
