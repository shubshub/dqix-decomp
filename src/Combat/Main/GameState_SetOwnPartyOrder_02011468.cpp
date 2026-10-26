#include <globaldefs.h>
#include "std_library_functions.h"

// Main, originally WriteBlockWithSize02011468 (USA 0x02011468, EUR 0x02011478, JPN 0x020111d8)
ARM void GameState_SetOwnPartyOrder(void* gameState, int count, void* objectIndices) {
#if defined(jpn)
    memcpy((char*)gameState + 0x54b8, objectIndices, count);
#else
    memcpy((char*)gameState + 0x5718, objectIndices, count);
#endif
#if defined(jpn)
    *((char*)gameState + 0x54bc) = (char)count;
#else
    *((char*)gameState + 0x571c) = (char)count;
#endif
}
