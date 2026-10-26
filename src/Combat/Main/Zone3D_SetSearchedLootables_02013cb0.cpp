#include <globaldefs.h>
#include "World/ZoneChest.h"

struct Entry_02028bd0;
Entry_02028bd0* ZoneRecords_GetInstance();
Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0* base, int key);

// Main, originally SetElementFlagsFromMask02013cb0 (USA 0x02013cb0, EUR 0x02013cc0, JPN 0x02013a7c)
ARM void Zone3D_SetSearchedLootables(Zone3D* zone, unsigned int mask) {
    int i;
    for (i = 0; i < zone->numLootables_; i++) {
        if (mask & (1 << i)) {
            zone->lootables_[i].state = ZoneLootableState_Searched;
        }
    }
    Entry_02028bd0* zoneRecords = ZoneRecords_GetInstance();
    Entry_02028bd0* zoneRecord = ZoneRecords_Find(zoneRecords, zone->currentZoneID_);
    if (zoneRecord == NULL) {
        return;
    }
    // the zone record's halfword at +2 keeps the 12 searched flags in bits 4-15
    unsigned short* searchedFlags = (unsigned short*)((unsigned char*)zoneRecord + 2);
    unsigned int flags = *searchedFlags;
    *searchedFlags = (flags & 0xffff000f) | ((mask << 20) >> 16);
}
