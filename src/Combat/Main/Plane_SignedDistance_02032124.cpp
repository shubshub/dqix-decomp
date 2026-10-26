#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern "C" fix32_t Vector3fix_InnerProduct(const Vector3fix *a, const Vector3fix *b);

// Main, originally func_02032124 (USA 0x02032124, EUR 0x02032134, JPN 0x02031c5c)
extern "C" ARM int Plane_SignedDistance(const Vector3fix *point, const Vector4fix *plane) {
    return Vector3fix_InnerProduct(&plane->xyz, point) - plane->w;
}
