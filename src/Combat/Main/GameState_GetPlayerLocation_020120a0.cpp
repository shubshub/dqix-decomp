#include <globaldefs.h>

enum { kPlayerCount = 4, kPlayerLocationSize = 8 };

// Main, originally GetField0x74deForValidIndex_020120a0 (USA 0x020120a0, EUR 0x020120b0, JPN 0x02011e1c)
extern "C" ARM void* GameState_GetPlayerLocation(char* gameState, unsigned int playerIndex) {
    if (playerIndex < kPlayerCount) {
#if defined(jpn)
        return gameState + 0x729e + playerIndex * kPlayerLocationSize;
#else
        return gameState + 0x74de + playerIndex * kPlayerLocationSize;
#endif
    }
    return NULL;
}
