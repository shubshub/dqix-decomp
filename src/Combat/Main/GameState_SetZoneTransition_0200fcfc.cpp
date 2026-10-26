#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"

// Main, originally CallFunc0200fbb4AtField0x3f8_0200fcfc (USA 0x0200fcfc, EUR 0x0200fd0c, JPN 0x0200fb58)
ARM void* GameState_SetZoneTransition(void* gameState, const void* settings) {
    return ZoneTransitionSettings_Copy(
        (CopyRecord0200fbb4*)((char*)gameState + 0x3f8),
        (const CopyRecord0200fbb4*)settings);
}
