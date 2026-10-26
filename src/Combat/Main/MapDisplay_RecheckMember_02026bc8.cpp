#include <globaldefs.h>

// The MapDisplay's member recheck bits (MapDisplay_RecheckAllMembers, MapDisplay_PlaceMembers)
#if defined(jpn)
enum { kRecheckMembersOffset = 0x9ca };
#else
enum { kRecheckMembersOffset = 0xa96 };
#endif

// Has MapDisplay_PlaceMembers look up again where party member memberIndex is shown on the map
// Main, originally SetBit02026bc8 (USA 0x02026bc8, EUR 0x02026bd8, JPN 0x0202652c)
extern "C" ARM void MapDisplay_RecheckMember(unsigned char* mapDisplay, int memberIndex) {
    mapDisplay[kRecheckMembersOffset] |= 1 << memberIndex;
}
