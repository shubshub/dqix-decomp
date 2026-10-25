#include <globaldefs.h>
#include "Graphics/Vector.h"

// Main, originally func_02032090 (USA 0x02032090, EUR 0x020320a0, JPN 0x02031bc8)
extern "C" ARM int Plane_IntersectSegment(const Vector3fix* start, const Vector3fix* end,
                                 const Vector4fix* plane, fix32_t* parameter, Vector3fix* point)
{
    Vector3fix var0;

    Vector3fix_Subtract(arg1, arg0, &var0);
    *arg3 = fix32_Divide(arg2->w - Vector3fix_InnerProduct(&arg2->xyz, arg0),
                              Vector3fix_InnerProduct(&arg2->xyz, &var0));
    if (*arg3 >= 0 && *arg3 <= 0x1000) {
        Vector3fixMultiplyScalar(&var0, *arg3, arg4);
        Vector3fix_Add(arg0, arg4, arg4);
        return 1;
    }
    return 0;
}
