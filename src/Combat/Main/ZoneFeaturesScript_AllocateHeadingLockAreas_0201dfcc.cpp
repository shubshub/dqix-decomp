#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_7b_0201dfcc (USA 0x0201dfcc, EUR 0x0201dfdc, JPN 0x0201dd58)
extern "C" ARM int ZoneFeaturesScript_AllocateHeadingLockAreas(Script::Parameter* params, int) {
    unsigned int count = params->ToInt();
    ZoneFeatures::Opcode7bEntry* areas = (ZoneFeatures::Opcode7bEntry*)data_020fdc20.allocator->Allocate(count * sizeof(ZoneFeatures::Opcode7bEntry));
    if (areas == NULL) return 0;
    data_020fdc20.warp->SetHeadingLockAreas(areas, count);
    return 1;
}
