#include <globaldefs.h>

// The gesture slot GameObject_UpdatePartyMember stores each frame: 0 B+Up, 1 B+Left, 2 B+Right, 3 B+Down, -1 none
#if defined(jpn)
enum { PartyMember_gestureSlot = 0x254 };
#else
enum { PartyMember_gestureSlot = 0x260 };
#endif

// Main, originally GetIntField0x260_02039750 (USA 0x02039750, EUR 0x02039760, JPN 0x020391a8)
extern "C" ARM int GameObject_GetGestureSlot(void* partyMember) {
    return *(int*)((char*)partyMember + PartyMember_gestureSlot);
}
