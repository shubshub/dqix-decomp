#include <globaldefs.h>
#include "Combat/ActorAction.h"

// The GameObject's SubBlock02038508 (+0x26c, jpn +0x260): the block GameObject_PlaceInZone fills from two zone path nodes and
// LadderClimb_Reset resets.
#if defined(jpn)
enum { kActorPathBlockOffset = 0x260 };
#else
enum { kActorPathBlockOffset = 0x26c };
#endif

// Main, originally GetByte0x26c_02039d7c (USA 0x02039d7c, EUR 0x02039d8c, JPN 0x020397d4)
ARM unsigned char GameObject_IsClimbingLadder(char* actor) {
    return ((SubBlock02038508*)(actor + kActorPathBlockOffset))->active;
}
