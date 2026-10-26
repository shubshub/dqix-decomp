#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e878
// Main, originally ZoneFeatures::SetOpcode7bAllocation_0201e878 (USA 0x0201e878, EUR 0x0201e888, JPN 0x0201e604)
ARM void ZoneFeatures::SetHeadingLockAreas(ZoneFeatures::Opcode7bEntry* areas, unsigned short capacity) {
    entries7b_ = areas;
    arrayCapacity7b_ = capacity;
    arraySize7b_ = 0;
}
