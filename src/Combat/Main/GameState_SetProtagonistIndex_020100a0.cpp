#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally SetField0x3acValue_020100a0 (USA 0x020100a0, EUR 0x020100b0, JPN 0x0200fefc)
ARM void GameState_SetProtagonistIndex(GameState* gameState, int index) {
    gameState->protagonistObjectIndex_ = index;
}
