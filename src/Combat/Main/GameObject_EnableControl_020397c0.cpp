#include <globaldefs.h>

// The pending control-enable byte: CopyByteField0x253To0x252 copies it to the control-enabled byte (+0x252)
#if defined(jpn)
enum { PartyMember_controlPending = 0x247 };
#else
enum { PartyMember_controlPending = 0x253 };
#endif

// Main, originally SetByteField0x253_020397c0 (USA 0x020397c0, EUR 0x020397d0, JPN 0x02039218)
extern "C" ARM void GameObject_EnableControl(void* partyMember) {
    *(unsigned char*)((char*)partyMember + PartyMember_controlPending) = 1;
}
