#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;
struct Struct020277c4;
void MapDisplay_AllocateImages(Struct020277c4* obj, int count, SafeAllocator* alloc);

// Main, originally InitEntryListWithDecodedCount0201f500 (USA 0x0201f500, EUR 0x0201f510, JPN 0x0201f28c)
ARM int BmmpScript_AllocateImages(Variant02030b0c* params) {
    int count = ((Script::Parameter*)params)->ToInt();
    MapDisplay_AllocateImages((Struct020277c4*)data_020fdc4c.currentObject, count, data_020fdc4c.allocator);
    return 1;
}
