#include <globaldefs.h>

// The place in the walking line (func_ov017_02190884: 0 for the leader, then 1, 2, ...)
#if defined(jpn)
enum { PartyMember_linePosition = 0x1bd };
#else
enum { PartyMember_linePosition = 0x1c9 };
#endif

// Main, originally SetByte0x1c9_0203986c (USA 0x0203986c, EUR 0x0203987c, JPN 0x020392c4)
extern "C" ARM void GameObject_SetLinePosition(unsigned char* partyMember, int position) {
    partyMember[PartyMember_linePosition] = position;
}
