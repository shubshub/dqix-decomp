#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// Main, originally GetElementStride0x74_0201e664 (USA 0x0201e664, EUR 0x0201e674, JPN 0x0201e3f0)
ARM ZoneFeatures::Opcode6aEntry* ZoneFeatures_GetEntry(ZoneFeatures* features, int index) {
    if (index < 0 || features->arraySize6a_ <= index) return NULL;
    return &features->entries6a_[index];
}
