#include <globaldefs.h>
#include "GameState/GameState.h"

// Main, originally SetBitInArray_020113a8 (USA 0x020113a8, EUR 0x020113b8, JPN 0x02011118)
extern "C" ARM void GameState_SetGrottoChestOpened(void* owner, int floor, int containerSlot) {
    GameState* state = static_cast<GameState*>(owner);
    unsigned int var1 = (floor - 1) * 5 + containerSlot;
    unsigned int var2 = var1 / 8;
    unsigned char* flags = reinterpret_cast<unsigned char*>(
        &state->unk_397d[0x5cd0 - 0x397d]);
    flags[var2] |= static_cast<unsigned char>(1 << (var1 - var2 * 8));
}
