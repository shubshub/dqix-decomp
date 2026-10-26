#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/ZoneTerrain.h"
#include "NitroSDK/Matrix.h"

extern "C" int Vector3fix_IntersectSegmentTriangle(const Vector3fix*, const Vector3fix*, const Vector3fix*,
                              const Vector3fix*, const Vector3fix*, const Vector3fix*,
                              fix32_t*, fix32_t*, fix32_t*, fix32_t*);
extern "C" Vector3fix Vector3fix_ClosestPointOnTriangle(const Vector3fix*, const Vector3fix*,
                                    const Vector3fix*, const Vector3fix*);

// Main, originally func_020315b8 (USA 0x020315b8, EUR 0x020315c8, JPN 0x020310f0)
extern "C" ARM int ZoneTerrain_PushOutOfWalls(const ZoneTerrainSample* triangles, int count,
                                  const Vector3fix* originalPosition, fix32_t radius,
                                  Vector3fix* position, const Vector3fix* backupPosition)
{
    int best = -1;
    fix32_t var1;
    bool var2, var3;
    int64_t var4 = (int64_t)radius * radius + 0x800;
    fix32_t radiusSquared = (fix32_t)(var4 >> 12);
    *position = *originalPosition;
    Vector3fix previous = *originalPosition;
    Vector3fix initial = *originalPosition;
    Vector3fix var8;
    for (int pass = 0; pass < 2; ++pass) {
        int var10 = 0;
        var1 = -radius;
        int minusOne = -1;
        for (int index = 0; index < count; ++index) {
            var2 = false;
            var3 = false;
            const ZoneTerrainSample* triangle = &triangles[index];
            Vector3fix var14 = *position;
            if (triangle->normal.y > 0x800)
                continue;
            Vector3fix start, end, a, b, c, normal, var21;
            start = *position;
            Vector3fixMultiplyScalar(&triangle->normal, var1, &var21);
            Vector3fix_Add(&start, &var21, &end);
            a = triangle->vertices[0];
            b = triangle->vertices[1];
            c = triangle->vertices[2];
            normal = triangle->normal;
            fix32_t weightA, weightB, weightC, parameter;
            int result = Vector3fix_IntersectSegmentTriangle(&start, &end, &a, &b, &c, &normal,
                                        &weightA, &weightB, &weightC, &parameter);
            if (result == 1 && pass == 0) {
                Vector3fix displacement;
                Vector3fix_Subtract(&end, &start, &displacement);
                Vector3fixMultiplyScalar(&displacement, parameter, &displacement);
                Vector3fix_Add(&start, &displacement, position);
                Vector3fixMultiplyScalar(&normal, radius, &displacement);
                Vector3fix_Add(position, &displacement, position);
                var2 = true;
                best = index;
                var3 = true;
                ++var10;
            } else if (result == minusOne && pass >= 1) {
                Vector3fix closest;
                closest = Vector3fix_ClosestPointOnTriangle(position, &a, &b, &c);
                Vector3fix delta;
                Vector3fix_Subtract(position, &closest, &delta);
                fix32_t var30 = FIX32_MULTIPLY(delta.y, delta.y);
                fix32_t xSquared = FIX32_MULTIPLY(delta.x, delta.x);
                fix32_t zSquared = FIX32_MULTIPLY(delta.z, delta.z);
                fix32_t sum = xSquared + var30;
                fix32_t var34 = xSquared + var30 + zSquared;
                if (var34 < radiusSquared) {
                    fix32_t scale = fix32_Divide(radius, fix32_Sqrt(var34));
                    Vector3fixMultiplyScalar(&delta, scale, &delta);
                    Vector3fix_Add(&closest, &delta, position);
                    var2 = true;
                    if (best == minusOne)
                        best = index;
                }
            }
            if (!var2)
                continue;
            normal = triangle->normal;
            if (backupPosition) {
                Vector3fix var36 = *backupPosition;
                var36.y = originalPosition->y;
                if (Vector3fix_Distance(position, &previous) > 4) {
                    fix32_t alignment = Vector3fix_InnerProduct(&normal, &var8);
                    if (alignment < 0xfd7 && alignment > 0x800) {
                        Vector3fix var38, var39;
                        Vector3fix_Subtract(&var36, &previous, &var38);
                        Vector3fix_Subtract(&var36, position, &var39);
                        fix32_t dot = Vector3fix_InnerProduct(&var38, &var39);
                        fix32_t distance = Vector3fix_Distance(&var38, &var39);
                        if (dot < distance * 0x4cc) {
                            Vector3fix var42;
                            Vector3fix_Subtract(&var36, &initial, &var42);
                            fix32_t var43 = Vector3fix_InnerProduct(&var38, &var42);
                            fix32_t var44 = Vector3fix_InnerProduct(&var39, &var42);
                            if (var43 < 0 || var44 < 0) {
                                position->z = backupPosition->z;
                                position->x = backupPosition->x;
                                return best;
                            }
                        }
                    }
                }
            }
            if (var3 || var10 == 0)
                var8 = normal;
            previous = var14;
        }
    }
    return best;
}
