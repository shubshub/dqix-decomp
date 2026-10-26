#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// Main, originally GetElementStride0x70_0201e548 (USA 0x0201e548, EUR 0x0201e558, JPN 0x0201e2d4)
ARM void* ZoneFeatures_GetExit(ZoneFeatures* features, int index) {
    if (index < 0 || features->arraySize68_ <= index) {
        return NULL;
    }
    return &features->entries68_[index];
}
