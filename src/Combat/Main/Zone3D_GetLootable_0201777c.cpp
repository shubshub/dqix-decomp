#include <globaldefs.h>
#include "World/Zone3D.h"

// Main, originally GetActorEntryByIndex_0201777c (USA 0x0201777c, EUR 0x0201778c, JPN 0x0201751c)
extern "C" ARM ZoneLootableRecord* Zone3D_GetLootable(Zone3D* zone, int index) {
    ZoneLootableRecord* lootable;
    if (index < 0 || zone->numLootables_ <= index) {
        lootable = 0;
    } else {
        lootable = &zone->lootables_[index];
    }
    return lootable;
}
