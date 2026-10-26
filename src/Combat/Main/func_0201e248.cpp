#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "NitroSDK/Memory.h"

// USA: Reset
// Main, originally ZoneFeatures::Reset_0201e248 (USA 0x0201e248, EUR 0x0201e258, JPN 0x0201dfd4)
ARM void ZoneFeatures::Reset() {
    VectorizedMemset(this, 0, sizeof(*this));
}
