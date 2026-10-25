#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/PlacementNew.h"

// Main, originally ResetHeaderAndSubStructs_020133cc (USA 0x020133cc, EUR 0x020133dc, JPN 0x02013194)
ARM void ZoneLootable_Init(ZoneLootableRecord* base)
{
    ZoneLootableRecord* record = new (static_cast<void*>(base)) ZoneLootableRecord;
    record->id = 0;
    record->state = ZoneLootableState_Searched;
    record->field4 = 0;
    SprSprite_Init(&record->primary[0]);
    SprSprite_Init(&record->primary[1]);
}
