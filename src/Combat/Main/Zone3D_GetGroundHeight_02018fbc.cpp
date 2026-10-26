#include <globaldefs.h>

#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"
#include "World/Bounds3D.h"
#include "Graphics/Vector.h"

extern "C" float _fflt(int v);
extern "C" float _fdiv(float a, float b);
extern "C" int _ffix(float v);

// The floor is looked for from 1.0 above the point to 10.0 below it, in a box 1.0 wide; the height returned stands
// 0.1 above the floor
enum {
    kProbeHalfWidth = 0x800,
    kProbeAbove = 0x1000,
    kProbeBelow = 0xa000,
    kGroundClearance = 0x199,
};

// Main, originally func_02018fbc (USA 0x02018fbc, EUR 0x02018fcc, JPN 0x02018d5c)
extern "C" ARM int Zone3D_GetGroundHeight(Zone3D* self, Vector3fix* position) {
    Vector3fix point = *position;
    Bounds3D probe;
    Vector3fix localPoint;
    Vector3fix up;
    Vector3fix down;
    Vector3fix hit;

    probe.maximum = point;
    probe.minimum = point;
    probe.maximum.x += kProbeHalfWidth;
    probe.maximum.y += kProbeAbove;
    probe.maximum.z += kProbeHalfWidth;
    probe.minimum.x -= kProbeHalfWidth;
    probe.minimum.y -= kProbeBelow;
    probe.minimum.z -= kProbeHalfWidth;

    int grottoTile;
    if (self->isInMainGrottoFloor_23b8_ != 0) {
        grottoTile = (int)(((float)(point.x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(point.z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }

    for (int i = 0; i < self->terrainElementCount_; i++) {
        if (self->isInMainGrottoFloor_23b8_ == 0 || grottoTile == i) {
            ZoneTerrainGrid grid;
            ZoneTerrainSample samples[96];
            int polygonCount = Zone3D_CollectTerrainPolygons(self, i, &grid, probe, 0);
            if (polygonCount > 0) {
                ZoneTerrainSample* sample = samples;
                int scale;
                for (int j = 0; j < polygonCount; j++, sample++) {
                    scale = grid.scale << 12;
                    ZoneTerrainSample_Unpack(sample, &grid.cells[j][0]);
                    Vector3fixMultiplyScalar(&sample->vertices[0], scale, &sample->vertices[0]);
                    Vector3fixMultiplyScalar(&sample->vertices[1], scale, &sample->vertices[1]);
                    Vector3fixMultiplyScalar(&sample->vertices[2], scale, &sample->vertices[2]);
                }
                Vector3fix_Subtract(&point, &grid.position, &localPoint);
                up = localPoint;
                up.y += kProbeAbove;
                down = localPoint;
                down.y -= kProbeBelow;
                if (ZoneTerrain_FindFloorHit(samples, polygonCount, &up, &down, &hit) != -1) {
                    hit.y += kGroundClearance;
                    point.y = hit.y;
                    localPoint.y = hit.y;
                }
            }
        }
    }
    return point.y;
}
