#include <globaldefs.h>
// The MapDisplay's member recheck bits sit at kBaseOffset + kFlagsOffset (0xa96, jpn 0x9ca): bit i makes
// MapDisplay_PlaceMembers look up again where party member i is shown on the map (MapDisplay_RecheckMember sets one)
#if defined(jpn)
enum { kBaseOffset = 0xca };
enum { kFlagsOffset = 0x900 };
#else
enum { kBaseOffset = 0x96 };
enum { kFlagsOffset = 0xa00 };
#endif

#include "GameState/GameState.h"


// Sets the recheck bit of every party member object (slots 0-3) that exists
// Main, originally MarkActiveCombatantSlots02026b7c (USA 0x02026b7c, EUR 0x02026b8c, JPN 0x020264e0)
extern "C" ARM void MapDisplay_RecheckAllMembers(unsigned char* mapDisplay) {
    GameState* game = GameState::GetInstance();
    int memberIndex;
    mapDisplay += kBaseOffset;
    for (memberIndex = 0; memberIndex < 4; memberIndex++) {
        if (game->GetGameObjectByIndex(memberIndex)) {
            mapDisplay[kFlagsOffset] |= (1 << memberIndex);
        }
    }
}
