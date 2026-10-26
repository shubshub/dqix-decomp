#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct GeometryTriangle {
    Vector3fix vertices[3];
    Vector3fix normal;
};

struct FourHalfwords02033f7c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
};

struct Struct_ov017_02192b48_5 {
    int type;
};

struct Struct_ov017_02192b48_6 {
    Struct_ov017_02192b48_5* header;
    unsigned char unknown_4_[0x10];
    FourHalfwords02033f7c* unknown_14_;
};

struct Struct_ov017_02192b48_7 {
    int unused;
    Struct_ov017_02192b48_6* polygons;
};

struct Struct_ov017_02192b48_8 {
    unsigned char unknown_0_[0x24];
    Struct_ov017_02192b48_7* unknown_24_;
};

struct Zone02193dc4 {
#if defined(jpn)
    unsigned char unknown0[0x844];
#else
    unsigned char unknown0[0x824];
#endif
    Struct_ov017_02192b48_8** unknown_824_;
    unsigned char unknown_828_[0x4];
    int unknown_82c_;
};

struct TerrainGrid02193dc4 {
    short cells[96][12];
    int unknown_900_;
    int scale;
    Vector3i position;
    int unknown_914_;
    int angle;
    int unknown_91c_;
    unsigned char unknown_920_[96];
};

struct Probe02193dc4 {
    Vector3i top;
    Vector3i bottom;
};

class Actor02193dc4 : public Object3D {
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
extern "C" void GameObject_ClearWallHit(struct ByteFlags02033f2c* p);
extern "C" void GameObject_SetFloorAttribute(void* obj, FourHalfwords02033f7c* src);

// USA: func_ov017_02193dc4
extern "C" ARM int func_ov017_02193dc4(Actor02193dc4* self) {
    TerrainGrid02193dc4 grid;
    GeometryTriangle samples[96];
    Zone02193dc4* zone;
    int total;
    int i;

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
    GameObject_ClearWallHit((ByteFlags02033f2c*)self);
    for (i = 0; i < zone->unknown_82c_; i++) {
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
                Struct_ov017_02192b48_8* node = zone->unknown_824_[i];
                Struct_ov017_02192b48_7* var19;
                Struct_ov017_02192b48_6* polygons;
                if (node != NULL && (var19 = node->unknown_24_) != NULL && (polygons = var19->polygons) != NULL) {
                    if (polygons->header->type == 3) {
                        FourHalfwords02033f7c material = polygons->unknown_14_[grid.unknown_920_[idx]];
                        GameObject_SetFloorAttribute(self, &material);
                    }
                }
            }
        }
    }
    self->unknown_ac_ = 0;
    return total;
}
