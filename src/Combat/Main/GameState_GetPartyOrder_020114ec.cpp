#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally CopyOutRegion0x571d_020114ec (USA 0x020114ec, EUR 0x020114fc, JPN 0x0201125c)
ARM unsigned char GameState_GetPartyOrder(char* gameState, void* outIndices) {
#if defined(jpn)
    unsigned char count = *(unsigned char*)(gameState + 0x54c1);
#else
    unsigned char count = *(unsigned char*)(gameState + 0x5721);
#endif
#if defined(jpn)
    memcpy(outIndices, gameState + 0x54bd, count);
#else
    memcpy(outIndices, gameState + 0x571d, count);
#endif
#if defined(jpn)
    return *(unsigned char*)(gameState + 0x54c1);
#else
    return *(unsigned char*)(gameState + 0x5721);
#endif
}
