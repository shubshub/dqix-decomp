#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct GeometryTriangle {
    Vector3fix vertices[3];
    Vector3fix normal;
};

struct CopySrc02033edc {
    Vector3fix vertices[3];
    Vector3fix normal;
};

struct CopyDst02033edc;

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

struct Struct_ov017_02192b48_9 {
    unsigned char unknown_0_[0x2c];
    Struct_ov017_02192b48_8* unknown_2c_;
};

struct Struct_ov017_02192b48_10 {
    unsigned char unknown_0_[0x44];
    Struct_ov017_02192b48_9* scene;
};

struct Struct_ov017_02192b48 {
    Struct_ov017_02192b48_10* node;
    unsigned char unknown_4_[0x44];
};

struct Zone02192b48 {
    unsigned short id;
#if defined(jpn)
    unsigned char unknown_2_[0x440 - 0x2];
#else
    unsigned char unknown1_2_[0x420 - 0x2];
#endif
    Struct_ov017_02192b48* unknown_420_;
    unsigned char unknown_424_[0x824 - 0x424];
    Struct_ov017_02192b48_8** unknown_824_;
    unsigned char unknown_828_[0x23b8 - 0x828];
    unsigned char unknown_23b8_;
};

struct Struct_02017d90 {
    short cells[96][12];
    int unknown_900_;
    int scale;
    Vector3i position;
    int unknown_914_;
    int angle;
    int unknown_91c_;
    unsigned char unknown_920_[96];
};

struct Struct_ov017_02192b48_3 {
    Vector3i top;
    Vector3i bottom;
};

class Struct_ov017_02192b48_4 : public Object3D {
public:
    short unknown_ac_;
    unsigned char unknown_ae_[0xd4 - 0xae];
    Vector3i unknown_d4_;
    unsigned char flagsE0;
};

extern int data_ov017_021d62d8[8];
extern int data_ov017_021d62f8[8];

extern "C" void* Zone3D_GetInstance(void);
extern "C" void ZoneTerrainSample_Unpack(GeometryTriangle* dst, short* src);
extern "C" long long fix32_CosFx64c(int);
extern "C" long long fix32_SinFx64c(int);
extern "C" float _ll_sto_f(long long);
extern "C" int ZoneTerrain_FindFloorHit(GeometryTriangle* triangles, int count, Vector3fix* start, Vector3fix* end, Vector3fix* point);
extern "C" int ZoneTerrain_PushOutOfWalls(GeometryTriangle* triangles, int count, Vector3fix* originalPosition, fix32_t radius, Vector3fix* position, Vector3i* backupPosition);
extern "C" void GameObject_SetFloorAttribute(void* obj, FourHalfwords02033f7c* src);
extern "C" void GameObject_SetWallAttribute(void* obj, FourHalfwords02033f7c* src);
extern "C" void GameObject_SetWallHit(CopyDst02033edc* dst, CopySrc02033edc* src);

// USA: func_ov017_02192b48
extern "C" ARM int func_ov017_02192b48(Struct_02017d90* grid, Struct_ov017_02192b48_3* probe, int count, Struct_ov017_02192b48_4* self, unsigned char arg4, Vector3i* dest, Vector3i* pos, int* y, int* arg8, int enable, int* reset, unsigned char arg11, int index, int hidden) {
    GeometryTriangle samples[96];
    GameState* gs;
    Zone02192b48* zone;
    int total;
    int threshold;
    int i;

    gs = GameState::GetInstance();
    GetGameResources();
    zone = (Zone02192b48*)Zone3D_GetInstance();
    total = 0;
    for (i = 0; i < count; i++) {
        ZoneTerrainSample_Unpack(&samples[i], grid->cells[i]);
        Vector3fixMultiplyScalar(&samples[i].vertices[0], grid->scale << 12, &samples[i].vertices[0]);
        Vector3fixMultiplyScalar(&samples[i].vertices[1], grid->scale << 12, &samples[i].vertices[1]);
        Vector3fixMultiplyScalar(&samples[i].vertices[2], grid->scale << 12, &samples[i].vertices[2]);
    }
    Vector3i local = *pos;
    Matrix3x3 rotation;
    Vector3i top;
    Vector3i bottom;
    Vector3i hit;
    Vector3fix_Subtract(&local, &grid->position, &local);
    int rotationAngle = -(grid->angle - 25735);
    int cosine = (int)(4096.0f * (_ll_sto_f(fix32_CosFx64c(rotationAngle)) / 4294967296.0f));
    int sine = (int)(4096.0f * (_ll_sto_f(fix32_SinFx64c(rotationAngle)) / 4294967296.0f));
    Mat3x3_WriteRotationY(&rotation, sine, cosine);
    Mat3x3_ApplyToVector(&local, &rotation, &local);
    top = local;
    top.y += 0x1800;
    bottom = local;
    bottom.y -= 0xa000;

    if (!(self->GetFlags() & 0x100)) {
        int idx = ZoneTerrain_FindFloorHit(samples, count, &top, &bottom, &hit);
        if (idx != -1) {
            hit.y += 0x199;
            Vector3fix_Add(&hit, &grid->position, &hit);
            if (*arg8 < hit.y) {
                threshold = 0x800;
                if (zone->id == 0x1131) {
                    unsigned int ticks = gs->GetTickCount();
                    if (ticks > 10) {
                        ticks = 10;
                    }
                    threshold = (int)(4096.0f * (0.1f + 0.25f * (float)ticks));
                }
                if (*y - hit.y < threshold || (hidden && *y - hit.y < 0x1800)) {
                    if (hit.y < *y || fix32abs(*y - hit.y) < 0x1000 || hidden) {
                        *reset = 1;
                        pos->y = *y;
                        self->position_ = *pos;
                        *arg8 = hit.y;
                        if (fix32abs(*y - hit.y) > 0x28) {
                            pos->y = hit.y;
                            self->position_ = *pos;
                        }
                        if (hidden) {
                            self->unknown_d4_ = *pos;
                            self->flagsE0 |= 0x20;
                        }
                        self->unknown_ac_ = 0;
                        if (arg11) {
                            Struct_ov017_02192b48_8* node;
                            if (zone->unknown_23b8_ == 0) {
                                node = zone->unknown_824_[index];
                            } else {
                                node = zone->unknown_420_[index].node->scene->unknown_2c_;
                            }
                            Struct_ov017_02192b48_7* var17;
                            Struct_ov017_02192b48_6* polygons;
                            if (node != NULL && (var17 = node->unknown_24_) != NULL && (polygons = var17->polygons) != NULL) {
                                if (polygons->header->type == 3) {
                                    FourHalfwords02033f7c material = polygons->unknown_14_[grid->unknown_920_[idx]];
                                    GameObject_SetFloorAttribute(self, &material);
                                }
                            }
                        }
                    }
                } else {
                    int clear = 1;
                    for (int k = 0; k < 8 && clear; k++) {
                        int dx = data_ov017_021d62d8[k];
                        int dz = data_ov017_021d62f8[k];
                        Vector3i stepTop = top;
                        stepTop.x += dx;
                        stepTop.z += dz;
                        Vector3i stepBottom = bottom;
                        stepBottom.x += dx;
                        stepTop.z += dz;
                        Vector3i stepHit;
                        if (ZoneTerrain_FindFloorHit(samples, count, &stepTop, &stepBottom, &stepHit) != -1) {
                            stepHit.y += 0x199;
                            Vector3fix_Add(&stepHit, &grid->position, &stepHit);
                            if (*y > stepHit.y && *y - stepHit.y < threshold) {
                                clear = 0;
                            }
                        }
                    }
                    if (clear) {
                        *reset = 0;
                    }
                }
            }
        }
    }

    if (enable && !(self->GetFlags() & 0x80)) {
        Vector3i center = local;
        center.y += 0x800;
        int radius = 0x800;
        if (self->unknown_0_ & 0x20) {
            int var29 = self->GetRadius() >> 2;
            if (var29 > 0x800) {
                radius = var29;
            }
        }
        int idx = ZoneTerrain_PushOutOfWalls(samples, count, &center, radius, &hit, dest);
        if (idx >= 0) {
            Mat3x3_Invert(&rotation, &rotation);
            Mat3x3_ApplyToVector(&hit, &rotation, &hit);
            pos->x = hit.x + grid->position.x;
            pos->z = hit.z + grid->position.z;
            self->position_ = *pos;
            total++;
            CopySrc02033edc triangle;
            Vector3fix_Add(&samples[idx].vertices[0], &grid->position, &triangle.vertices[0]);
            Vector3fix_Add(&samples[idx].vertices[1], &grid->position, &triangle.vertices[1]);
            Vector3fix_Add(&samples[idx].vertices[2], &grid->position, &triangle.vertices[2]);
            triangle.normal = samples[idx].normal;
            GameObject_SetWallHit((CopyDst02033edc*)self, &triangle);
            if (arg4 && arg11) {
                Struct_ov017_02192b48_8* node;
                if (zone->unknown_23b8_ == 0) {
                    node = zone->unknown_824_[index];
                } else {
                    node = zone->unknown_420_[index].node->scene->unknown_2c_;
                }
                Struct_ov017_02192b48_7* var33;
                Struct_ov017_02192b48_6* polygons;
                if (node != NULL && (var33 = node->unknown_24_) != NULL && (polygons = var33->polygons) != NULL) {
                    if (polygons->header->type == 3) {
                        FourHalfwords02033f7c material = polygons->unknown_14_[grid->unknown_920_[idx]];
                        GameObject_SetWallAttribute(self, &material);
                    }
                }
            }
        }
    }
    return total;
}
