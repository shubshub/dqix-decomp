#include <globaldefs.h>

// The member this one walks behind (func_ov017_02190884: -1 for the line's leader, else the member before it)
#if defined(jpn)
enum { PartyMember_followedIndex = 0x1bc };
#else
enum { PartyMember_followedIndex = 0x1c8 };
#endif

// Main, originally SetByte0x1c8_02039858 (USA 0x02039858, EUR 0x02039868, JPN 0x020392b0)
extern "C" ARM void GameObject_SetFollowedMember(unsigned char* partyMember, int index) {
    partyMember[PartyMember_followedIndex] = index;
}
