#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// Main, originally GetPointerFromArray0x3c_0201e838 (USA 0x0201e838, EUR 0x0201e848, JPN 0x0201e5c4)
ARM void* ZoneFeatures_GetFirstOfType(unsigned char* features, unsigned int type) {
    return *(void**)(features + type * 4 + offsetof(ZoneFeatures, entries6aByType_));
}
