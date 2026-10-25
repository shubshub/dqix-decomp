#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct Struct_020312bc {
    Vector3fix unknown_0_[3];
    Vector3fix unknown_24_;
};

struct Struct_02033f6c {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

struct Struct_ov017_02192b48_5 {
    int unknown_0_;
};

struct Struct_ov017_02192b48_6 {
    Struct_ov017_02192b48_5* unknown_0_;
    unsigned char unknown_4_[0x10];
    Struct_02033f6c* unknown_14_;
};

struct Struct_ov017_02192b48_7 {
    int unknown_0_;
    Struct_ov017_02192b48_6* unknown_4_;
};

struct Struct_ov017_02192b48_8 {
    unsigned char unknown_0_[0x24];
    Struct_ov017_02192b48_7* unknown_24_;
};

struct Struct_ov017_02193dc4_3 {
#if defined(jpn)
    unsigned char unknown_0_[0x844];
#else
    unsigned char unknown1_0_[0x824];
#endif
    Struct_ov017_02192b48_8** unknown_824_;
    unsigned char unknown_828_[0x4];
    int unknown_82c_;
};

struct Struct_ov017_02193dc4_4 {
    short unknown_0_[96][12];
    int unknown_900_;
    int unknown_904_;
    Vector3i unknown_908_;
    int unknown_914_;
    int unknown_918_;
    int unknown_91c_;
    unsigned char unknown_920_[96];
};

struct Struct_ov017_02193dc4 {
    Vector3i unknown_0_;
    Vector3i unknown_c_;
};

class Struct_ov017_02193dc4_2 : public Object3D {
public:
    short unknown_ac_;
};

extern "C" void* Zone3D_GetInstance(void);
extern "C" void ZoneTerrainSample_Unpack(GeometryTriangle* dst, short* src);
extern "C" long long fix32_CosFx64c(int);
extern "C" long long fix32_SinFx64c(int);
extern "C" float _ll_sto_f(long long);
extern "C" int ZoneTerrain_FindFloorHit(GeometryTriangle* triangles, int count, Vector3fix* start, Vector3fix* end, Vector3fix* point);
extern "C" int Zone3D_CollectTerrainPolygons(Zone02193dc4* zone, int index, TerrainGrid02193dc4* grid, Probe02193dc4 probe, Actor02193dc4* self);
void ClearFlags0x40And0x80At0xe0(struct ByteFlags02033f2c* p);
void CopyFourHalfwordsToField0x114_02033f6c(void* obj, FourHalfwords02033f7c* src);

// USA: func_ov017_02193dc4
extern "C" ARM int func_ov017_02193dc4(Struct_ov017_02193dc4_2* arg0) {
    Struct_ov017_02193dc4_4 var0;
    Struct_020312bc var1[96];
    Struct_ov017_02193dc4_3* var2;
    int var3;
    int var4;

    GameState::GetInstance();
    GetGameResources();
    zone = (Zone02193dc4*)Zone3D_GetInstance();
    Probe02193dc4 probe;
    Vector3i pos = self->position_;
    total = 0;
    probe.top = pos;
    probe.bottom = pos;
    probe.top.x += self->GetRadius() / 2;
    probe.top.y += self->GetHeight();
    probe.top.z += self->GetRadius() / 2;
    probe.bottom.x -= self->GetRadius() / 2;
    probe.bottom.y -= 0x28000;
    probe.bottom.z -= self->GetRadius() / 2;
    ClearFlags0x40And0x80At0xe0((ByteFlags02033f2c*)self);
    for (i = 0; i < zone->terrainCount; i++) {
        int count = Zone3D_CollectTerrainPolygons(zone, i, &grid, probe, self);
        if (count > 0) {
            total += count;
            for (int k = 0; k < count; k++) {
                ZoneTerrainSample_Unpack(&samples[k], grid.cells[k]);
                Vector3fixMultiplyScalar(&samples[k].vertices[0], grid.scale << 12, &samples[k].vertices[0]);
                Vector3fixMultiplyScalar(&samples[k].vertices[1], grid.scale << 12, &samples[k].vertices[1]);
                Vector3fixMultiplyScalar(&samples[k].vertices[2], grid.scale << 12, &samples[k].vertices[2]);
            }
            Vector3i local = pos;
            Matrix3x3 rotation;
            Vector3i top;
            Vector3i bottom;
            Vector3i hit;
            Vector3fix_Subtract(&local, &grid.position, &local);
            int rotationAngle = -(grid.angle - 25735);
            int cosine = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(rotationAngle)) / 4294967296.0f));
            int sine = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(rotationAngle)) / 4294967296.0f));
            Mat3x3_WriteRotationY(&rotation, sine, cosine);
            Mat3x3_ApplyToVector(&local, &rotation, &local);
            top = local;
            top.y += 0x800;
            bottom = local;
            bottom.y -= 0x28000;
            int idx = ZoneTerrain_FindFloorHit(samples, count, &top, &bottom, &hit);
            if (idx != -1) {
                hit.y += 0x199;
                Vector3fix_Add(&hit, &grid.position, &hit);
                TerrainNode* node = zone->terrain[i];
                GeometryData* geometry;
                PolygonData* polygons;
                if (node != NULL && (geometry = node->geometry) != NULL && (polygons = geometry->polygons) != NULL) {
                    if (polygons->header->type == 3) {
                        FourHalfwords02033f7c material = polygons->materials[grid.materialIndex[idx]];
                        CopyFourHalfwordsToField0x114_02033f6c(self, &material);
                    }
                }
            }
        }
    }
    arg0->unknown_ac_ = 0;
    return var3;
}
