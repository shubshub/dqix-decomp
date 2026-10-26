#include <globaldefs.h>

// The index of the walking line's leader (func_ov017_02190884 gives every member out[0])
#if defined(jpn)
enum { PartyMember_lineLeader = 0x1be };
#else
enum { PartyMember_lineLeader = 0x1ca };
#endif

// Main, originally SetByte0x1ca_02039880 (USA 0x02039880, EUR 0x02039890, JPN 0x020392d8)
ARM void GameObject_SetLineLeader(unsigned char* partyMember, int index) {
    partyMember[PartyMember_lineLeader] = index;
}
