#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally CopyOutRegion0x5718_02011494 (USA 0x02011494, EUR 0x020114a4, JPN 0x02011204)
ARM unsigned char GameState_GetOwnPartyOrder(char* gameState, void* outIndices) {
#if defined(jpn)
    unsigned char count = *(unsigned char*)(gameState + 0x54bc);
#else
    unsigned char count = *(unsigned char*)(gameState + 0x571c);
#endif
#if defined(jpn)
    memcpy(outIndices, gameState + 0x54b8, count);
#else
    memcpy(outIndices, gameState + 0x5718, count);
#endif
#if defined(jpn)
    return *(unsigned char*)(gameState + 0x54bc);
#else
    return *(unsigned char*)(gameState + 0x571c);
#endif
}
