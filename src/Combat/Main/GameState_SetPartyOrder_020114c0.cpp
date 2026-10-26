#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally CopyInRegion0x571d_020114c0 (USA 0x020114c0, EUR 0x020114d0, JPN 0x02011230)
extern "C" ARM void GameState_SetPartyOrder(char* gameState, int count, void* objectIndices) {
#if defined(jpn)
    memcpy(gameState + 0x54bd, objectIndices, count);
#else
    memcpy(gameState + 0x571d, objectIndices, count);
#endif
#if defined(jpn)
    *(unsigned char*)(gameState + 0x54c1) = (unsigned char)count;
#else
    *(unsigned char*)(gameState + 0x5721) = (unsigned char)count;
#endif
}
