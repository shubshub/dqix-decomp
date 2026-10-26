#include <globaldefs.h>
#include "Graphics/Vector.h"

// Main, originally func_02031468 (USA 0x02031468, EUR 0x02031478, JPN 0x02030fa0)
extern "C" ARM fix32_t Vector3fix_DistanceToSegment(const Vector3fix* start, const Vector3fix* end,
                                     const Vector3fix* point, Vector3fix* closest)
{
    fix32_t length = Vector3fix_Distance(start, end);
    fix32_t startDistance = Vector3fix_Distance(start, point);
    if (length == 0) {
        *closest = *point;
        return startDistance;
    }
    if (startDistance == 0) {
        *closest = *point;
        return 0;
    }
    Vector3fix direction;
    Vector3fix toPoint;
    Vector3fix_Subtract(end, start, &direction);
    Vector3fixMultiplyScalar(&direction, fix32_Divide(0x1000, length), &direction);
    Vector3fix_Subtract(point, start, &toPoint);
    Vector3fixMultiplyScalar(&toPoint, fix32_Divide(0x1000, startDistance), &toPoint);
    fix32_t cosine = Vector3fix_InnerProduct(&direction, &toPoint);
    if (cosine <= 0) {
        *closest = *start;
        return startDistance;
    }
    fix32_t projectedLength = FIX32_MULTIPLY(startDistance, cosine);
    if (length < projectedLength) {
        *closest = *end;
        return Vector3fix_Distance(point, end);
    }
    Vector3fixMultiplyScalar(&direction, projectedLength, closest);
    Vector3fix_Add(closest, start, closest);
    return Vector3fix_Distance(point, closest);
}
