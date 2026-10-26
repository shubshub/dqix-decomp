#include <globaldefs.h>
#include "Combat/MapDisplay.h"

enum { kAllMembers = 0xf };     // one bit per party member 0-3

// Main, originally SetFlagBits0x55e_0202006c (USA 0x0202006c, EUR 0x0202007c, JPN 0x0201fd90)
extern "C" ARM void MapDisplay_RequestMemberRedraw(unsigned char* displayIn, int memberId) {
    int mask;
    if (memberId < 0) mask = kAllMembers;
    else mask = 1 << memberId;
    ((MapDisplay*)displayIn)->field55e = mask;
}
