#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally GetField0x3f8Address_0200fd0c (USA 0x0200fd0c, EUR 0x0200fd1c, JPN 0x0200fb68)
ARM void* GameState_GetZoneTransition(GameState* gameState) {
    return (char*)gameState + 0x3f8;
}
