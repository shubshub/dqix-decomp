#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally GetField0x397cValue_020100b0 (USA 0x020100b0, EUR 0x020100c0, JPN 0x0200ff0c)
ARM unsigned char GameState_GetLeaderIndex(GameState* gameState) {
#if defined(jpn)
    return gameState->unknownObjectIndex_397c_;
#else
    return gameState->unknownObjectIndex_397c_;
#endif
}
