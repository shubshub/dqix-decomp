#pragma once

#include "NitroSDK/Matrix.h"
#include "World/Bounds3D.h"

class Zone3D;
class Object3D;

// One terrain polygon, unpacked from a ZoneTerrainGrid's 12 shorts (ZoneTerrainSample_Unpack)
struct ZoneTerrainSample {
    Vector3fix vertices[3];
    Vector3fix normal;
};

struct ZoneTerrainGrid {
    short cells[96][12];
    int count;                      // polygons collected (TerrainMesh_CollectPolygons)
    int scale;
    Vector3fix position;
    int unknown914;
    int angle;
    unsigned char unknown91c[4];
    unsigned char attributes[96];   // each polygon's 7-bit attribute, written when the mesh header's type is 3
                                    // (TerrainMesh_CollectPolygons)
};

typedef char ZoneTerrainSampleSizeCheck[sizeof(ZoneTerrainSample) == 0x30 ? 1 : -1];
typedef char ZoneTerrainGridSizeCheck[sizeof(ZoneTerrainGrid) == 0x980 ? 1 : -1];
typedef char ZoneTerrainGridScaleOffsetCheck[offsetof(ZoneTerrainGrid, scale) == 0x904 ? 1 : -1];
typedef char ZoneTerrainGridPositionOffsetCheck[offsetof(ZoneTerrainGrid, position) == 0x908 ? 1 : -1];
typedef char ZoneTerrainGridAttributesOffsetCheck[offsetof(ZoneTerrainGrid, attributes) == 0x920 ? 1 : -1];

extern "C" int Zone3D_CollectTerrainPolygons(Zone3D*, int, ZoneTerrainGrid*, Bounds3D, Object3D*);
extern "C" void ZoneTerrainSample_Unpack(ZoneTerrainSample*, short*);
extern "C" int ZoneTerrain_FindFloorHit(const ZoneTerrainSample*, int, const Vector3fix*, const Vector3fix*, Vector3fix*);
extern "C" int ZoneTerrain_FindWallHit(const ZoneTerrainSample*, int, const Vector3fix*, const Vector3fix*, Vector3fix*);
extern "C" int ZoneTerrain_PushOutOfWalls(const ZoneTerrainSample*, int, const Vector3fix*, fix32_t, Vector3fix*,
                                          const Vector3fix*);

extern "C" Zone3D* Zone3D_GetInstance();
extern "C" int Zone3D_GetGroundHeight(Zone3D* zone, Vector3fix* position);
extern "C" Vector3fix Zone3D_ClipMoveAgainstWalls(Zone3D* zone, const Vector3fix* position,
                                   const Vector3fix* offset, int radius);
