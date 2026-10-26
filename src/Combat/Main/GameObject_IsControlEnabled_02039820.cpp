#include <globaldefs.h>

// The control-enabled byte GameObject_DisableControl clears (GameObject_HandleWalkInput ignores the D-pad while it is 0)
#if defined(jpn)
enum { PartyMember_controlEnabled = 0x246 };
#else
enum { PartyMember_controlEnabled = 0x252 };
#endif

// Main, originally GetByteField0x252_02039820 (USA 0x02039820, EUR 0x02039830, JPN 0x02039278)
extern "C" ARM unsigned char GameObject_IsControlEnabled(void* partyMember) {
    return *((unsigned char*)partyMember + PartyMember_controlEnabled);
}
