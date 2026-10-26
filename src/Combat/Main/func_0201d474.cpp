#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: CopyFrom
// Main, originally MaybeVector4fix::CopyFrom_0201d474 (USA 0x0201d474, EUR 0x0201d484, JPN 0x0201d200)
ARM MaybeVector4fix& MaybeVector4fix::CopyFrom(const MaybeVector4fix& other) {
    vec3 = other.vec3;
    w = other.w;
    return *this;
}
