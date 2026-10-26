#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally func_0200fb8c (USA 0x0200fb8c, EUR 0x0200fb9c, JPN 0x0200f9e8)
extern "C" ARM GameResources* GameState::GetResources() {
    return pResources_;
}
