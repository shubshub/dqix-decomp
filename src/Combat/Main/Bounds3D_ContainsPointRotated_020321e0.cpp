#include <globaldefs.h>

#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

static inline int FxSquare(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

// Main, originally func_020321e0 (USA 0x020321e0, EUR 0x020321f0, JPN 0x02031d18)
extern "C" ARM int Bounds3D_ContainsPointRotated(const Vector3fix* point, const Bounds3D* bounds, int angle, const Vector3fix* pivot, int radiusSquared) {
    Vector3fix boxPoint = *point;
    Vector3fix offset;
    Matrix4x3 unrotate;
    int distanceSquared;

    if (angle != 0) {
        int zSquared, xSquared;

        Vector3fix_Subtract(point, pivot, &offset);
        zSquared = FxSquare(offset.z);
        xSquared = FxSquare(offset.x);
        distanceSquared = xSquared + zSquared;
        if (radiusSquared < distanceSquared) {
            return 0;
        }
        unrotate = RotationMatrixY(fix32ReduceAngle0To2Pi(-angle));
        Mat4x3_ApplyToVector(&offset, &unrotate, &offset);
        Vector3fix_Add(&offset, pivot, &boxPoint);
    }
    return Bounds3D_ContainsPoint(&boxPoint, bounds);
}
