#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally GetField0x3acValue_020100a8 (USA 0x020100a8, EUR 0x020100b8, JPN 0x0200ff04)
extern "C" ARM int GameState_GetProtagonistIndex(GameState* gameState) {
    return gameState->protagonistObjectIndex_;
}
