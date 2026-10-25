#include <globaldefs.h>
#include "World/Bounds3D.h"

// True when the two boxes overlap (touching counts).
// Main, originally func_0203109c (USA 0x0203109c, EUR 0x020310ac, JPN 0x02030bd4)
extern "C" ARM bool Bounds3D_Overlap(const Bounds3D* a, const Bounds3D* b) {
    if (a->maximum.x < b->minimum.x) {
        return false;
    }
    if (a->maximum.y < b->minimum.y) {
        return false;
    }
    if (a->maximum.z < b->minimum.z) {
        return false;
    }
    if (b->maximum.x < a->minimum.x) {
        return false;
    }
    if (b->maximum.y < a->minimum.y) {
        return false;
    }
    return b->maximum.z >= a->minimum.z;
}
