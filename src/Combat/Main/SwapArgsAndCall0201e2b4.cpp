#include <globaldefs.h>
#include "World/ZoneWarpScript.h"

// USA: func_0201e2b4
// Main, originally ZoneFeatures::LoadFromScript_0201e2b4 (USA 0x0201e2b4, EUR 0x0201e2c4, JPN 0x0201e040)
ARM void ZoneFeatures::LoadFromScript(SafeAllocator* allocator, const void* script, unsigned int length) {
    ZoneFeaturesScript_Run(script, length, this, allocator);
}
