#include <globaldefs.h>

#include "World/ZoneWarpScript.h"

extern Script::OpcodeLookupEntry data_020ef388[];

// Main, originally ExecuteZoneWarpScript_0201e1d0 (USA 0x0201e1d0, EUR 0x0201e1e0, JPN 0x0201df5c)
ARM void ZoneFeaturesScript_Run(const void* data, unsigned int length, ZoneFeatures* features, SafeAllocator* allocator) {
    if (length == 0) return;
    data_020fdc20.warp = features;
    data_020fdc20.allocator = allocator;
    data_020fdc20.currentEntry = NULL;
    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_020ef388);
    script.Load(data, length);
    script.Execute();
    data_020fdc20.warp = NULL;
    data_020fdc20.allocator = NULL;
    data_020fdc20.currentEntry = NULL;
}
