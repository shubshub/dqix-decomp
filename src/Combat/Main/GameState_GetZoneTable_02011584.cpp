#include "Combat/Main/ElementLookup.h"
#include <globaldefs.h>

// Main, originally GetPtrField0x468_02011584 (USA 0x02011584, EUR 0x02011594, JPN 0x020112f4)
extern "C" ARM void *GameState_GetZoneTable(void *gameState) {
    return (char *) gameState + 0x468;
}
