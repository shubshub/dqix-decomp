#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct Struct_020312bc {
    Vector3fix unknown_0_[3];
    Vector3fix unknown_24_;
};

struct Struct_02033edc {
    Vector3fix unknown_0_[3];
    Vector3fix unknown_24_;
};

struct Struct_02033edc_2;

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

struct Struct_ov017_02192b48_9 {
    unsigned char unknown_0_[0x2c];
    Struct_ov017_02192b48_8* unknown_2c_;
};

struct Struct_ov017_02192b48_10 {
    unsigned char unknown_0_[0x44];
    Struct_ov017_02192b48_9* unknown_44_;
};

struct Struct_ov017_02192b48 {
    Struct_ov017_02192b48_10* unknown_0_;
    unsigned char unknown_4_[0x44];
};

struct Struct_ov017_02192b48_2 {
    unsigned short unknown_0_;
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
    short unknown_0_[96][12];
    int unknown_900_;
    int unknown_904_;
    Vector3i unknown_908_;
    int unknown_914_;
    int unknown_918_;
    int unknown_91c_;
    unsigned char unknown_920_[96];
};

struct Struct_ov017_02192b48_3 {
    Vector3i unknown_0_;
    Vector3i unknown_c_;
};

class Struct_ov017_02192b48_4 : public Object3D {
public:
    short unknown_ac_;
    unsigned char unknown_ae_[0xd4 - 0xae];
    Vector3i unknown_d4_;
    unsigned char unknown_e0_;
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
void CopyFourHalfwordsToField0x114_02033f6c(void* obj, FourHalfwords02033f7c* src);
void SetFlag0x80AndCopyToField0x11c_02033fa8(void* obj, FourHalfwords02033f7c* src);
void CopyBlocksSetFlag0x40(CopyDst02033edc* dst, CopySrc02033edc* src);

// USA: func_ov017_02192b48
extern "C" ARM int func_ov017_02192b48(Struct_02017d90* arg0, Struct_ov017_02192b48_3* arg1, int arg2, Struct_ov017_02192b48_4* arg3, unsigned char arg4, Vector3i* arg5, Vector3i* arg6, int* arg7, int* arg8, int arg9, int* arg10, unsigned char arg11, int arg12, int arg13) {
    Struct_020312bc var0[96];
    GameState* var1;
    Struct_ov017_02192b48_2* var2;
    int var3;
    int var4;
    int var5;

    var1 = GameState::GetInstance();
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
            if (*yLow < hit.y) {
                threshold = 0x800;
                if (zone->id == 0x1131) {
                    unsigned int ticks = gs->GetTickCount();
                    if (ticks > 10) {
                        ticks = 10;
                    }
                    var4 = (int)(4096.0f * (0.1f + 0.25f * (float)var15));
                }
                if (*arg7 - var10.y < var4 || (arg13 && *arg7 - var10.y < 0x1800)) {
                    if (var10.y < *arg7 || fix32abs(*arg7 - var10.y) < 0x1000 || arg13) {
                        *arg10 = 1;
                        arg6->y = *arg7;
                        arg3->position_ = *arg6;
                        *arg8 = var10.y;
                        if (fix32abs(*arg7 - var10.y) > 0x28) {
                            arg6->y = var10.y;
                            arg3->position_ = *arg6;
                        }
                        if (arg13) {
                            arg3->unknown_d4_ = *arg6;
                            arg3->unknown_e0_ |= 0x20;
                        }
                        arg3->unknown_ac_ = 0;
                        if (arg11) {
                            Struct_ov017_02192b48_8* var16;
                            if (var2->unknown_23b8_ == 0) {
                                var16 = var2->unknown_824_[arg12];
                            } else {
                                var16 = var2->unknown_420_[arg12].unknown_0_->unknown_44_->unknown_2c_;
                            }
                            Struct_ov017_02192b48_7* var17;
                            Struct_ov017_02192b48_6* var18;
                            if (var16 != NULL && (var17 = var16->unknown_24_) != NULL && (var18 = var17->unknown_4_) != NULL) {
                                if (var18->unknown_0_->unknown_0_ == 3) {
                                    Struct_02033f6c var19 = var18->unknown_14_[arg0->unknown_920_[var14]];
                                    func_02033f6c(arg3, &var19);
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
                    if (var20) {
                        *arg10 = 0;
                    }
                }
            }
        }
    }

    if (arg9 && !(arg3->GetFlags() & 0x80)) {
        Vector3i var27 = var6;
        var27.y += 0x800;
        int var28 = 0x800;
        if (arg3->unknown_0_ & 0x20) {
            int var29 = arg3->GetRadius() >> 2;
            if (var29 > 0x800) {
                var28 = var29;
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
            CopyBlocksSetFlag0x40((CopyDst02033edc*)self, &triangle);
            if (applyMaterial && inCell) {
                TerrainNode* node;
                if (zone->useScenes == 0) {
                    node = zone->terrain[index];
                } else {
                    var32 = var2->unknown_420_[arg12].unknown_0_->unknown_44_->unknown_2c_;
                }
                Struct_ov017_02192b48_7* var33;
                Struct_ov017_02192b48_6* var34;
                if (var32 != NULL && (var33 = var32->unknown_24_) != NULL && (var34 = var33->unknown_4_) != NULL) {
                    if (var34->unknown_0_->unknown_0_ == 3) {
                        Struct_02033f6c var35 = var34->unknown_14_[arg0->unknown_920_[var30]];
                        func_02033fa8(arg3, &var35);
                    }
                }
            }
        }
    }
    return var3;
}
