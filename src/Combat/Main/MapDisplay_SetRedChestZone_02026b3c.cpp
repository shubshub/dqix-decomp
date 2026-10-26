#include <globaldefs.h>

#include "std_library_functions.h"

// One zone of the MapDisplay's red chest zone list (MapDisplay_AllocateRedChestZones)
struct Entry02026b3c {
    short zoneId;
    char zoneName[0x18];
};

struct Obj02026b3c {
    #if defined(jpn)
    char pad[0x6ce];
#else
    char pad[0x77a];
#endif
    unsigned char zoneCount;
    char pad2[1];
    Entry02026b3c* zones;
};

#if defined(jpn)
extern "C" ARM void MapDisplay_SetRedChestZone(Obj02026b3c* mapDisplay, unsigned int index, short zoneId, const char* zoneName);
#endif

// Main, originally SetEntry02026b3c (USA 0x02026b3c, EUR 0x02026b4c, JPN 0x020264a0)
extern "C" ARM void MapDisplay_SetRedChestZone(Obj02026b3c* mapDisplay, unsigned int index, short zoneId, const char* zoneName) {
    if (index >= mapDisplay->zoneCount) return;
    if (mapDisplay->zones == NULL) return;
    mapDisplay->zones[index].zoneId = zoneId;
    strcpy(mapDisplay->zones[index].zoneName, zoneName);
}
