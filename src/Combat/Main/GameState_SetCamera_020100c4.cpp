#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally SetField0x3b0Value_020100c4 (USA 0x020100c4, EUR 0x020100d4, JPN 0x0200ff20)
ARM void GameState_SetCamera(GameState* battleStruct, int value) {
    *(int*)((char*)battleStruct + 0x3b0) = value;
}
