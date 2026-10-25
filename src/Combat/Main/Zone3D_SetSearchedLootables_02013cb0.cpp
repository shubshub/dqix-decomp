#include <globaldefs.h>
#include "World/ZoneChest.h"

struct Entry_02028bd0;
Entry_02028bd0* ZoneRecords_GetInstance();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* base, int key);

// Main, originally SetElementFlagsFromMask02013cb0 (USA 0x02013cb0, EUR 0x02013cc0, JPN 0x02013a7c)
ARM void Zone3D_SetSearchedLootables(Zone3D* zone, unsigned int mask) {
    int i;
    for (i = 0; i < zone->numLootables_; i++) {
        if (mask & (1 << i)) {
            zone->lootables_[i].state = ZoneLootableState_Searched;
        }
    }
    Entry_02028bd0* base = ZoneRecords_GetInstance();
    Entry_02028bd0* result = FindInlineEntryById(base, zone->currentZoneID_);
    if (result == NULL) {
        return;
    }
    unsigned short* fieldPtr = (unsigned short*)((unsigned char*)result + 2);
    unsigned int cur = *fieldPtr;
    *fieldPtr = (cur & 0xffff000f) | ((mask << 20) >> 16);
}
