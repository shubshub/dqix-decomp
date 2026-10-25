#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"
#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

// Main, originally func_02019210 (USA 0x02019210, EUR 0x02019220, JPN 0x02018fb0)
extern "C" ARM Vector3fix Zone3D_ClipMoveAgainstWalls(Zone3D* zone, const Vector3fix* position,
                                       const Vector3fix* offset, int radius) {
    Vector3fix destination;
    Vector3fix_Add(position, offset, &destination);
    Vector3fix_Length(offset);

    Struct_02018fbc var1;
    if (var0.x < arg1->x) {
        var1.unknown_0_.x = arg1->x;
        var1.unknown_c_.x = var0.x;
    } else {
        var1.unknown_0_.x = var0.x;
        var1.unknown_c_.x = arg1->x;
    }
    if (var0.y < arg1->y) {
        var1.unknown_0_.y = arg1->y;
        var1.unknown_c_.y = var0.y;
    } else {
        var1.unknown_0_.y = var0.y;
        var1.unknown_c_.y = arg1->y;
    }
    if (var0.z < arg1->z) {
        var1.unknown_0_.z = arg1->z;
        var1.unknown_c_.z = var0.z;
    } else {
        var1.unknown_0_.z = var0.z;
        var1.unknown_c_.z = arg1->z;
    }

    Vector3fix var2 = *arg1;
    Vector3fix var3;
    Vector3fix_Add(arg1, arg2, &var3);
    if (arg3 > 0) {
        Vector3fix var4;
        Vector3fix_Normalize(&var3, &var4);
        Vector3fix var5;
        Vector3fixMultiplyScalar(&var4, arg3, &var5);
        Vector3fix_Add(&var3, &var5, &var3);
    }

    int var6;
    if (arg0->isInMainGrottoFloor_23b8_) {
        var6 = (int)(((float)(arg1->x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(arg1->z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }

    for (int i = 0; i < zone->terrainElementCount_; i++) {
        if (!zone->isInMainGrottoFloor_23b8_ || cell == i) {
            ZoneTerrainGrid grid;
            ZoneTerrainSample samples[96];
            int count = Zone3D_CollectTerrainPolygons(zone, i, &grid, probe, 0);
            if (count > 0) {
                ZoneTerrainSample* sample = samples;
                int scale;
                for (int j = 0; j < count; j++, sample++) {
                    scale = grid.scale << 12;
                    ZoneTerrainSample_Unpack(sample, &grid.cells[j][0]);
                    Vector3fixMultiplyScalar(&sample->vertices[0], scale, &sample->vertices[0]);
                    Vector3fixMultiplyScalar(&sample->vertices[1], scale, &sample->vertices[1]);
                    Vector3fixMultiplyScalar(&sample->vertices[2], scale, &sample->vertices[2]);
                }
                Vector3fix localFrom = from;
                Vector3fix localTo = to;
                Vector3fix_Subtract(&from, &grid.position, &localFrom);
                Vector3fix_Subtract(&to, &grid.position, &localTo);
                Vector3fix collision;
                if (ZoneTerrain_FindWallHit(samples, count, &localFrom, &localTo, &collision) >= 0) {
                    if (ZoneTerrain_PushOutOfWalls(samples, count, &collision, radius, &collision, 0) >= 0) {
                        Vector3fix_Add(&collision, &grid.position, &to);
                        destination = to;
                    }
                }
            }
        }
    }
    return var0;
}
