#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;
struct Array020278e4;
void MapDisplay_AllocatePlacements(Array020278e4* obj, int capacity, SafeAllocator* alloc);

// Main, originally AllocateArrayWithDecodedCount0201f580 (USA 0x0201f580, EUR 0x0201f590, JPN 0x0201f30c)
ARM int BmmpScript_AllocatePlacements(Variant02030b0c* params) {
    int capacity = ((Script::Parameter*)params)->ToInt();
    MapDisplay_AllocatePlacements((Array020278e4*)data_020fdc4c.currentObject, capacity, data_020fdc4c.allocator);
    return 1;
}
