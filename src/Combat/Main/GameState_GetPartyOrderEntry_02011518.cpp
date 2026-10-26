#include <globaldefs.h>

// GameState's party order list (GameState_SetPartyOrder): its count and the object indices
#if defined(jpn)
#define PARTY_ORDER_COUNT 0x54c1
#define PARTY_ORDER_INDICES 0x54bd
#else
#define PARTY_ORDER_COUNT 0x5721
#define PARTY_ORDER_INDICES 0x571d
#endif

// Main, originally GetCheckedSignedByte_02011518 (USA 0x02011518, EUR 0x02011528, JPN 0x02011288)
ARM int GameState_GetPartyOrderEntry(void* gameState, unsigned int position) {
    if (position < ((unsigned char*)gameState)[PARTY_ORDER_COUNT]) {
        return ((signed char*)gameState + position)[PARTY_ORDER_INDICES];
    }
    return -1;
}
