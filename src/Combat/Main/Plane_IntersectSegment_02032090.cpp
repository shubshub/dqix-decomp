#include <globaldefs.h>
#include "Graphics/Vector.h"

// Main, originally func_02032090 (USA 0x02032090, EUR 0x020320a0, JPN 0x02031bc8)
extern "C" ARM int Plane_IntersectSegment(const Vector3fix* start, const Vector3fix* end,
                                 const Vector4fix* plane, fix32_t* parameter, Vector3fix* point)
{
    Vector3fix direction;

    Vector3fix_Subtract(end, start, &direction);
    *parameter = fix32_Divide(plane->w - Vector3fix_InnerProduct(&plane->xyz, start),
                              Vector3fix_InnerProduct(&plane->xyz, &direction));
    if (*parameter >= 0 && *parameter <= 0x1000) {
        Vector3fixMultiplyScalar(&direction, *parameter, point);
        Vector3fix_Add(start, point, point);
        return 1;
    }
    return 0;
}
