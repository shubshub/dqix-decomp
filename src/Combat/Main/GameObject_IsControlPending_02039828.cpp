#include <globaldefs.h>

// The pending control-enable byte GameObject_EnableControl sets
#if defined(jpn)
enum { PartyMember_controlPending = 0x247 };
#else
enum { PartyMember_controlPending = 0x253 };
#endif

// Main, originally GetByteField0x253_02039828 (USA 0x02039828, EUR 0x02039838, JPN 0x02039280)
extern "C" ARM unsigned char GameObject_IsControlPending(void* partyMember) {
    return *((unsigned char*)partyMember + PartyMember_controlPending);
}
