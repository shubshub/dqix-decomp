#include <globaldefs.h>

// followFlags bit 0: GameObject_UpdateFollower (the follower step) does nothing while it is set
#if defined(jpn)
enum { PartyMember_followFlags = 0x1c2 };
#else
enum { PartyMember_followFlags = 0x1ce };
#endif
enum { FollowFlag_Stopped = 1 };

// Main, originally ClearFlag0x1ceBit0x1_020398a4 (USA 0x020398a4, EUR 0x020398b4, JPN 0x020392fc)
extern "C" ARM void GameObject_ResumeFollowing(unsigned char* partyMember) {
    partyMember[PartyMember_followFlags] &= ~FollowFlag_Stopped;
}
