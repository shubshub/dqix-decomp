#include <globaldefs.h>
#include "Combat/ActorAction.h"

// The ladder climb GameObject_UpdateLadderClimb runs ("hasigo_in", "hasigo_loop", "hasigo_out")
#if defined(jpn)
enum { PartyMember_ladderClimb = 0x260 };
#else
enum { PartyMember_ladderClimb = 0x26c };
#endif

// Main, originally GetFieldPtrAt0x26c_020399a8 (USA 0x020399a8, EUR 0x020399b8, JPN 0x02039400)
ARM SubBlock02038508* GameObject_GetLadderClimb(void* partyMember) {
    return (SubBlock02038508*)((char*)partyMember + PartyMember_ladderClimb);
}
