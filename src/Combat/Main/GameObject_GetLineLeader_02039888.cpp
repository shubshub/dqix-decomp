#include <globaldefs.h>

// The index of the walking line's leader (func_ov017_02190884 gives every member out[0])
#if defined(jpn)
enum { PartyMember_lineLeader = 0x1be };
#else
enum { PartyMember_lineLeader = 0x1ca };
#endif

// Main, originally GetSignedByte0x1ca_02039888 (USA 0x02039888, EUR 0x02039898, JPN 0x020392e0)
extern "C" ARM int GameObject_GetLineLeader(void* partyMember) {
    return *(signed char*)((char*)partyMember + PartyMember_lineLeader);
}
