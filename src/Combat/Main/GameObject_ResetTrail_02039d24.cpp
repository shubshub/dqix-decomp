#include <globaldefs.h>
#include "std_library_functions.h"

// The trail GameObject_UpdateFollower keeps of the member it follows: write/read indices, started flag, 16 x/z points
#if defined(jpn)
enum { PartyMember_trailWriteIndex = 0x1bf, PartyMember_trailReadIndex = 0x1c0, PartyMember_trailStarted = 0x1c1,
       PartyMember_trail = 0x1c4 };
#else
enum { PartyMember_trailWriteIndex = 0x1cb, PartyMember_trailReadIndex = 0x1cc, PartyMember_trailStarted = 0x1cd,
       PartyMember_trail = 0x1d0 };
#endif

// Main, originally ClearBytesAndZeroBlock02039d24 (USA 0x02039d24, EUR 0x02039d34, JPN 0x0203977c)
ARM void GameObject_ResetTrail(unsigned char* partyMember) {
    partyMember[PartyMember_trailWriteIndex] = 0;
    partyMember[PartyMember_trailReadIndex] = 0;
    partyMember[PartyMember_trailStarted] = 0;
    memset(partyMember + PartyMember_trail, 0, 16 * 8);
}
