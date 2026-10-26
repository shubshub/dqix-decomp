#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/ZoneTerrain.h"

extern "C" {
    int Vector3fix_IntersectSegmentTriangle(const Vector3fix*, const Vector3fix*, const Vector3fix*,
                    const Vector3fix*, const Vector3fix*, const Vector3fix*,
                    fix32_t*, fix32_t*, fix32_t*, fix32_t*);
    int Plane_IntersectSegment(const Vector3fix*, const Vector3fix*, const Vector4fix*, fix32_t*, Vector3fix*);
}
// Main, originally func_020312bc (USA 0x020312bc, EUR 0x020312cc, JPN 0x02030df4)
extern "C" ARM int ZoneTerrain_FindFloorHit(const ZoneTerrainSample* triangles, int count,
                                 const Vector3fix* start, const Vector3fix* end, Vector3fix* point)
{
    int best = -1;
    fix32_t var1;
    for (int index = 0; index < count; ++index) {
        const ZoneTerrainSample* triangle = &triangles[index];
        if (triangle->normal.y > 0x800) {
            fix32_t weightA, weightB, weightC, parameter;
            if (Vector3fix_IntersectSegmentTriangle(start, end, &triangle->vertices[0], &triangle->vertices[1],
                             &triangle->vertices[2], &triangle->normal, &weightA, &weightB, &weightC, &parameter) == 1) {
                fix32_t weightedB = FIX32_MULTIPLY(triangle->vertices[1].y, weightB);
                fix32_t weightedA = FIX32_MULTIPLY(triangle->vertices[0].y, weightA);
                fix32_t weightedC = FIX32_MULTIPLY(triangle->vertices[2].y, weightC);
                fix32_t sum = weightedA + weightedB;
                fix32_t height = weightedA + weightedB + weightedC;
                if (best < 0 || var1 < height) {
                    var1 = height;
                    best = index;
                }
            }
        }
    }
    if (best >= 0) {
        const ZoneTerrainSample* triangle = &triangles[best];
        Vector4fix var17;
        Vector3fix var18;
        Vector3fix var19;
        Vector4fix crossPlane;
        fix32_t parameter;
        var17.xyz = triangle->normal;
        var17.w = Vector3fix_InnerProduct(&var17.xyz, &triangle->vertices[0]);
        Vector3fix_Subtract(&triangle->vertices[1], &triangle->vertices[0], &var19);
        Vector3fix_Subtract(&triangle->vertices[2], &triangle->vertices[0], &var18);
        Vector3fix_CrossProduct(&var19, &var18, &crossPlane.xyz);
        crossPlane.w = Vector3fix_InnerProduct(&crossPlane.xyz, &triangle->vertices[0]);
        if (Plane_IntersectSegment(start, end, &crossPlane, &parameter, point) == 0)
            best = -1;
    }
    return best;
}
