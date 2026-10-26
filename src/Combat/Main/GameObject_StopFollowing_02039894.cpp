#include <globaldefs.h>

// followFlags bit 0: GameObject_UpdateFollower (the follower step) does nothing while it is set
#if defined(jpn)
enum { PartyMember_followFlags = 0x1c2 };
#else
enum { PartyMember_followFlags = 0x1ce };
#endif
enum { FollowFlag_Stopped = 1 };

// Main, originally SetFlag0x1ceBit0x1_02039894 (USA 0x02039894, EUR 0x020398a4, JPN 0x020392ec)
extern "C" ARM void GameObject_StopFollowing(unsigned char* partyMember) {
    partyMember[PartyMember_followFlags] |= FollowFlag_Stopped;
}
