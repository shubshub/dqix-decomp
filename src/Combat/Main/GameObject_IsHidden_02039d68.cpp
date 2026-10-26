#include <globaldefs.h>

// The GameObject's flag byte (+0x1ce, jpn +0x1c2) and its hidden bit (see GameObject_ClearHidden).
#if defined(jpn)
enum { kActorFlagsOffset = 0x1c2 };
#else
enum { kActorFlagsOffset = 0x1ce };
#endif
enum { kActorFlag_Hidden = 4 };

// Main, originally CheckFlag0x1ceBit2Set_02039d68 (USA 0x02039d68, EUR 0x02039d78, JPN 0x020397c0)
ARM int GameObject_IsHidden(unsigned char* actor) {
    return (actor[kActorFlagsOffset] & kActorFlag_Hidden) != 0;
}
