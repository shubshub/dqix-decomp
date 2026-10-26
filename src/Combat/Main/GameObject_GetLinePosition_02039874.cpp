#include <globaldefs.h>

// The place in the walking line (func_ov017_02190884: 0 for the leader, then 1, 2, ...)
#if defined(jpn)
enum { PartyMember_linePosition = 0x1bd };
#else
enum { PartyMember_linePosition = 0x1c9 };
#endif

// Main, originally GetSignedByte0x1c9_02039874 (USA 0x02039874, EUR 0x02039884, JPN 0x020392cc)
extern "C" ARM int GameObject_GetLinePosition(void* partyMember) {
    return *(signed char*)((char*)partyMember + PartyMember_linePosition);
}
