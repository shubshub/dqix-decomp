#include <globaldefs.h>

// The grotto boss floors: maplist9.bin calls 41101-41505 "<environment> Level Boss Floor" (maps Z0<env>M99,
// Format0201403c); FieldTask_EnterZone sets up the treasure map's boss there
enum {
    kFirstGrottoBossFloorZoneId = 41101,
    kLastGrottoBossFloorZoneId = 41505,
};

// Main, originally IsValueInRange0201b5d8 (USA 0x0201b5d8, EUR 0x0201b5e8, JPN 0x0201b350)
extern "C" ARM int ZoneId_IsGrottoBossFloor(int zoneId) {
    if (zoneId >= kFirstGrottoBossFloorZoneId) {
        if (zoneId <= kLastGrottoBossFloorZoneId) return 1;
    }
    return 0;
}
