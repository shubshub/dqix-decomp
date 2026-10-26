#include <globaldefs.h>

#include "Resource/GameResources.h"

// A zone whose red chests the map shows (the map script's PopulateEntriesFromVariantPairs0201f8d0 lists them):
// func_02026780 loads the chests named zoneName from treasure.nsarc and places them by zoneId
struct NameEntry02026b0c {
    short zoneId;
    char zoneName[24];
};

// The MapDisplay's red chest zone list (header field77a and field77c)
struct Obj02026b0c {
    #if defined(jpn)
    char pad[0x6ce];
#else
    char pad[0x77a];
#endif
    unsigned char zoneCount;
    unsigned char pad2;
    NameEntry02026b0c* zones;
};

// Main, originally AllocateNameBuffer02026b0c (USA 0x02026b0c, EUR 0x02026b1c, JPN 0x02026470)
extern "C" ARM void MapDisplay_AllocateRedChestZones(struct Obj02026b0c* mapDisplay, int zoneCount) {
    GameResources* resources = GetGameResources();
    SafeAllocator* allocator = &resources->allocator_array_38[12];
    mapDisplay->zoneCount = zoneCount;
    mapDisplay->zones = static_cast<NameEntry02026b0c*>(allocator->Allocate((zoneCount & 0xff) * sizeof(NameEntry02026b0c)));
}
