#include <globaldefs.h>

// The zones outside func_0201bb78's numbered ranges that still have a visited flag, and the index
// each one's flag has among the 20000-range zones' (0xa5a + index): one entry, zone 15800 -> 56 in the usa ROM
extern short data_020e6dc2;
extern signed char data_020e6dc0;

enum { kExtraZoneCount = 1 };

// Main, originally LookupKeyValue_02012f24 (USA 0x02012f24, EUR 0x02012f34, JPN 0x02012cec)
extern "C" ARM int ZoneVisitedFlag_FindExtraZoneIndex(int zoneId) {
    short* zoneIds = &data_020e6dc2;
    signed char* flagIndexes = &data_020e6dc0;
    unsigned int i;
    for (i = 0; i < kExtraZoneCount; i++, zoneIds++, flagIndexes++) {
        if (*zoneIds == zoneId) return *flagIndexes;
    }
    return -1;
}
