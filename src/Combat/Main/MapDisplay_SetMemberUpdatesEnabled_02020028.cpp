#include <globaldefs.h>
#include "Combat/MapDisplay.h"

enum { kAllMembers = 0xf };     // one bit per party member 0-3

// Main, originally SetOrClearFlagBit0x55d_02020028 (USA 0x02020028, EUR 0x02020038, JPN 0x0201fd4c)
extern "C" ARM void MapDisplay_SetMemberUpdatesEnabled(unsigned char* displayIn, int enabled, int memberId) {
    MapDisplay* display = (MapDisplay*)displayIn;
    if (memberId < 0) {
        if (enabled) display->mask55d = kAllMembers;
        else display->mask55d = 0;
    } else {
        if (enabled) display->mask55d |= (1 << memberId);
        else display->mask55d &= ~(1 << memberId);
    }
}
