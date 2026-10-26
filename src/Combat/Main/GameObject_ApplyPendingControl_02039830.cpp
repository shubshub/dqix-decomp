#include <globaldefs.h>

#if defined(jpn)
enum { PartyMember_controlEnabled = 0x246, PartyMember_controlPending = 0x247 };
#else
enum { PartyMember_controlEnabled = 0x252, PartyMember_controlPending = 0x253 };
#endif

// Main, originally CopyByteField0x253To0x252_02039830 (USA 0x02039830, EUR 0x02039840, JPN 0x02039288)
extern "C" ARM void GameObject_ApplyPendingControl(void* partyMember) {
    *(unsigned char*)((char*)partyMember + PartyMember_controlEnabled) =
        *(unsigned char*)((char*)partyMember + PartyMember_controlPending);
}
