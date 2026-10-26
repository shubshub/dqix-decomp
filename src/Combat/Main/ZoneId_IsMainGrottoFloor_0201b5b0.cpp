#include <globaldefs.h>

// The main grotto floor zone ids (maps Z0<env>M01)
enum {
    kFirstMainGrottoFloorZoneId = 40001,
    kLastMainGrottoFloorZoneId = 40096,
};

// Main, originally IsInRange0201b5b0 (USA 0x0201b5b0, EUR 0x0201b5c0, JPN 0x0201b328)
extern "C" ARM int ZoneId_IsMainGrottoFloor(int zoneId) {
    if (zoneId >= kFirstMainGrottoFloorZoneId) {
        if (zoneId <= kLastMainGrottoFloorZoneId) return 1;
    }
    return 0;
}
