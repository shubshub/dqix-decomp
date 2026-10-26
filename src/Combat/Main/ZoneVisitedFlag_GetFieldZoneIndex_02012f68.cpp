#include <globaldefs.h>

// The visited-flag indices of zones 20060-20063, which share the flag of an earlier zone (ROM bytes: 8, 13, 14, 31)
extern signed char data_020e6ddc;

enum {
    kFirstVisitedZoneId = 20000,    // zone 20000 + n has visited flag n (Zone3D_SetVisitedFlag: scenario flag 0xa5a + n)
    kVisitedZoneCount = 0x3c,
    kAliasedZoneLast = 0x3f,        // 0x3c-0x3f take their index from data_020e6ddc
};

// Main, originally ConvertIndex_02012f68 (USA 0x02012f68, EUR 0x02012f78, JPN 0x02012d30)
ARM int ZoneVisitedFlag_GetFieldZoneIndex(int zoneId) {
    int index = zoneId - kFirstVisitedZoneId;
    if (index < 0) return -1;
    if (index >= kVisitedZoneCount && index <= kAliasedZoneLast) {
        index = (&data_020e6ddc)[index - kVisitedZoneCount];
    }
    if (index >= kVisitedZoneCount) return -1;
    return index;
}
