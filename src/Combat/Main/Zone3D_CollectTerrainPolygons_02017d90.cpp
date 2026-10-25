#include <globaldefs.h>
#include "World/Object3D.h"
#include "NitroSDK/Matrix.h"
#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"

extern "C" long long fix32_CosFx64c(int);
extern "C" long long fix32_SinFx64c(int);
extern "C" float _ll_sto_f(long long);
extern "C" int TerrainMesh_CollectPolygons(void*, ZoneTerrainGrid*, Bounds3D);

// Main, originally func_02017d90 (USA 0x02017d90, EUR 0x02017da0, JPN 0x02017b30)
extern "C" ARM int Zone3D_CollectTerrainPolygons(Zone3D* self, int index, ZoneTerrainGrid* grid, Bounds3D probe, Object3D* object) {
    if (self->isInMainGrottoFloor_23b8_) {
        if (!object) return 0;
        FloorMap* floor = &self->grotto_.floorMap_;
        BmdjSceneElement* node;
        int x, z, angle;
        if (index < 256) {
            GrottoTileMapRecord* entry = &self->grottoTileMapData_420_[index];
            if (entry->node) node = entry->node->elements->linkedElement2c;
            else return 0;
            x = entry->position.x;
            z = entry->position.z;
            angle = entry->angle;
        } else {
            if (Zone3D_GetScriptNode(self, 4))
                node = Zone3D_GetScriptNode(self, 4)->elements->linkedElement2c;
            else return 0;
            x = floor->upStairWorldX;
            z = floor->upStairWorldZ;
            angle = floor->fpUpStairRotation;
        }
        if (!node) return 0;
        if (!node->resource) return 0;
        if (node->flags & BmdjElementFlag_Hidden) return 0;
        BmdjSceneElement* parent = node->parent;
        while (parent) {
            if (parent->flags & BmdjElementFlag_Hidden) return 0;
            parent = parent->parent;
        }
        void* polygons = node->resource->polygons;
        if (!polygons) return 0;
        Bounds3D localProbe;
        Vector3i origin;
        Matrix3x3 rotation;
        localProbe.maximum = object->position_;
        StoreThreeWordsAt0x0020130a8(&origin, x, 0, z);
        Vector3fix_Subtract(&localProbe.maximum, &origin, &localProbe.maximum);
        int rotationAngle = -(angle - 25735);
        int cosine = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(rotationAngle)) / 4294967296.0f));
        int sine = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(rotationAngle)) / 4294967296.0f));
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        Mat3x3_ApplyToVector(&localProbe.maximum, &rotation, &localProbe.maximum);
        localProbe.minimum = localProbe.maximum;
        localProbe.maximum.x += object->GetRadius() / 2;
        localProbe.maximum.y += object->GetHeight();
        localProbe.maximum.z += object->GetRadius() / 2;
        localProbe.minimum.x -= object->GetRadius() / 2;
        localProbe.minimum.y -= 0xa000;
        localProbe.minimum.z -= object->GetRadius() / 2;
        int count = TerrainMesh_CollectPolygons(polygons, grid, localProbe);
        grid->position = origin;
        grid->angle = angle;
        return count;
    }
    BmdjSceneElement* node = self->terrainElements_[index];
    if (!node->resource) return 0;
    if (node->flags & BmdjElementFlag_Hidden) return 0;
    BmdjSceneElement* parent = node->parent;
    while (parent) {
        if (parent->flags & BmdjElementFlag_Hidden) return 0;
        parent = parent->parent;
    }
    if (node->flags & BmdjElementFlag_Open) return 0;
    void* polygons = node->resource->polygons;
    if (!polygons) return 0;
    Vector3i origin = node->position;
    Vector3fix_Subtract(&probe.maximum, &origin, &probe.maximum);
    Vector3fix_Subtract(&probe.minimum, &origin, &probe.minimum);
    probe.minimum.x -= node->lowerMargins.x;
    probe.minimum.y -= node->lowerMargins.y;
    probe.minimum.z -= node->lowerMargins.z;
    probe.maximum.x += node->upperMargins.x;
    probe.maximum.y += node->upperMargins.y;
    probe.maximum.z += node->upperMargins.z;
    int count = TerrainMesh_CollectPolygons(polygons, grid, probe);
    Vector3fix_Add(&grid->position, &origin, &grid->position);
    int angle = node->angle;
    float adjustedAngle;
    if ((float)angle / 4096.0f > 0) adjustedAngle = 0.5f + 4096.0f * ((float)angle / 4096.0f);
    else adjustedAngle = 4096.0f * ((float)angle / 4096.0f) - 0.5f;
    grid->angle = (int)adjustedAngle;
    return count;
}
