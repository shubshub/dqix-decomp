#include <globaldefs.h>

// The GameObject's flag byte (+0x1ce, jpn +0x1c2) and its hidden bit: set, the actor is faded out and skipped by the
// shadow pass (func_ov017_0218eafc); GameObject_UpdatePartyMember clears it and fades the actor back in.
#if defined(jpn)
enum { kActorFlagsOffset = 0x1c2 };
#else
enum { kActorFlagsOffset = 0x1ce };
#endif
enum { kActorFlag_Hidden = 4 };

// Main, originally ClearFlag0x1ceBit0x4_02039d58 (USA 0x02039d58, EUR 0x02039d68, JPN 0x020397b0)
ARM void GameObject_ClearHidden(unsigned char* actor) {
    actor[kActorFlagsOffset] &= ~kActorFlag_Hidden;
}
