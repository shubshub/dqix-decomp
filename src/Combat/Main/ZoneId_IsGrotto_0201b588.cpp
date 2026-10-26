#include <globaldefs.h>

// Grotto zone ids: the floors (40001-40096, ZoneId_IsMainGrottoFloor) through the boss floors (41101-41505,
// ZoneId_IsGrottoBossFloor), "Grotto" and "... Level Boss Floor" in maplist9.bin
enum {
    kFirstGrottoZoneId = 40001,
    kLastGrottoZoneId = 41505,
};

// Main, originally IsInRange0201b588 (USA 0x0201b588, EUR 0x0201b598, JPN 0x0201b300)
ARM int ZoneId_IsGrotto(int zoneId) {
    if (zoneId >= kFirstGrottoZoneId) {
        if (zoneId <= kLastGrottoZoneId) return 1;
    }
    return 0;
}
