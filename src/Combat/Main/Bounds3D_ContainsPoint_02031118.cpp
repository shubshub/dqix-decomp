#include <globaldefs.h>

#include "World/Bounds3D.h"

// Main, originally func_02031118 (USA 0x02031118, EUR 0x02031128, JPN 0x02030c50)
extern "C" ARM int Bounds3D_ContainsPoint(const Vector3fix* point, const Bounds3D* bounds) {
    if (bounds->maximum.x < point->x) return 0;
    if (bounds->maximum.y < point->y) return 0;
    if (bounds->maximum.z < point->z) return 0;
    if (point->x < bounds->minimum.x) return 0;
    if (point->y < bounds->minimum.y) return 0;
    return point->z >= bounds->minimum.z ? 1 : 0;
}
