#include <globaldefs.h>
#include "World/ZoneChest.h"

// Main, originally InitStruct020133fc (USA 0x020133fc, EUR 0x0201340c, JPN 0x020131c4)
ARM void ZoneChest_Init(ZoneChestRenderRecord* record) {
    StoreThreeWordsAt0x0020130a8(&record->position, 0, 0, 0);
    record->angleY = 0;
    record->lidAngle = 0;
    record->counter = 0;
    record->state = ZoneChestState_Closed;
    record->kind = 0;
    record->recordIndex = -1;
    record->uniqueID = 0;
    record->opener = -1;
    record->icon = NULL;
    record->iconRise = 0;
    record->iconTask = -1;
    record->special = 0;
}
