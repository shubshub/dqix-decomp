#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally GetField0x3b0Value_020100bc (USA 0x020100bc, EUR 0x020100cc, JPN 0x0200ff18)
extern "C" ARM void* GameState::GetCamera() {
    return camera_;
}
