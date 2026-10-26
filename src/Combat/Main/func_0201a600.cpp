#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct GameState;
struct SafeAllocator;

struct Struct_0201a600_6 {
    Matrix3x3 unknown_0_;
    Vector3i unknown_24_;
    int unknown_30_;
};

struct Struct_0201a600_8 {
    unsigned char* unknown_0_;
    unsigned char* unknown_4_;
    int unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    Struct_0201a600_6 unknown_14_;
    Struct_0201a600_6 unknown_48_;
};

struct Struct_0201a600_9 {
    char unknown_0_[REGION_VALUE(0x1e8, 0x1c8)];
    Struct_0201a600_8 unknown_1c8_;
};

struct Struct_0201a600_10 {
    char unknown_0_[5];
    unsigned char unknown_5_;
    char unknown_6_[2];
    signed char unknown_8_;
    char unknown_9_[3];
    int unknown_c_;
    Vector3i unknown_10_;
    char unknown_1c_[REGION_VALUE(0x30, 0x50)];
    char unknown_6c_[1];
};

struct Struct_0201a600 {
    int unknown_0_;
    int unknown_4_[6];
    int unknown_1c_;
    Vector3i unknown_20_[4];
    short unknown_50_;
    short unknown_52_;
    int unknown_54_;
    int unknown_58_[3];
    int unknown_64_[2];
    int unknown_6c_;
};

struct Struct_0201a600_2 {
    unsigned short unknown_0_;
};

struct Struct_0201a600_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    char unknown_4_[4];
    Struct_0201a600_2* unknown_8_;
    char unknown_c_[REGION_VALUE(0x7c, 0x5c)];
    SafeAllocator* unknown_68_;
    char unknown_6c_[0x88];
    char unknown_f4_[0x23e8 - 0xf4];
    unsigned char unknown_23e8_;
    unsigned char unknown_23e9_;
    char unknown_23ea_[2];
    Struct_0201a600_9 unknown_23ec_;
};

struct Struct_0201a600_4 {
    char unknown_0_[REGION_VALUE(0x34c0, 0x36d0)];
    void* unknown_36d0_;
};

struct Struct_0201a600_5 {
    char unknown_0_[7];
    unsigned char unknown_7_;
    char unknown_8_[8];
    Vector3i unknown_10_;
    unsigned short unknown_1c_;
    char unknown_1e_[0x44];
    unsigned char unknown_62_;
    unsigned char unknown_63_;
    char unknown_64_[4];
    unsigned char unknown_68_;
};

extern "C" {
GameState* _ZN9GameState11GetInstanceEv();
GrottoStruct0201a600* _ZN9GameState15GetGrottoStructEv(GameState* gs);
int _ZNK19TreasureMapMetadata10GetMapTypeEv(void* metadata);
void* _ZN9GameState9GetLeaderEv(GameState* gs);
void _ZN12ZoneFeatures13AllocateExitsEiP13SafeAllocator(void* features, int count, SafeAllocator* alloc);
void _ZN12ZoneFeatures10CreateExitERKNS_13Opcode68EntryE(void* features, const Opcode68Entry0201a600* entry);
int _Z24ZoneId_IsGrottoBossFloori(int zoneId);
int _Z15ZoneId_IsGrottoi(int zoneId);
unsigned short _ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(const ActiveGrotto0201a600* grotto);
int _ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(const ActiveGrotto0201a600* grotto);
int _ZNK17ActiveGrottoClass13GetFloorCountEv(const ActiveGrotto0201a600* grotto);
int _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
    void* zone, int tileX, int tileY, int* outX, int* outZ, const void* tileData, bool preferFaceDown);
int _ZNK8FloorMap16GetAdjacencyBitsEii(const FloorMap0201a600* map, int x, int y);
Struct0201ae8c* _Z18CopyStruct0201ae8cP14Struct0201ae8cS0_(Struct0201ae8c* dst, Struct0201ae8c* src);
Field3f8_0201a600* _Z27GameState_GetZoneTransitionP9GameState(GameState* gs);
int Zone3D_GetGroundHeight(Zone0201a600* zone, Vector3i* pos);
void __clear(void* buf, int size);
void func_02024d94(void* obj, unsigned short zoneId, Vector3i* pos);
}

extern const unsigned char data_020e6e44[15];

struct Struct_0201a600_7 {
    unsigned char unknown_0_;
};

static inline Struct_0201a600_7 inline_0201a600(const Struct_0201a600_8* arg0, int arg1, int arg2) {
    Struct_0201a600_7 var0;
    var0.unknown_0_ = _ZNK8FloorMap16GetAdjacencyBitsEii(arg0, arg1, arg2);
    return var0;
}

static inline void* inline_0201a600_2(Struct_0201a600_4* arg0) {
    return arg0->unknown_36d0_;
}

static inline int inline_0201a600_3(int arg0) {
    return (int)(((long long)arg0 * arg0 + 0x800) >> 12);
}

// USA: func_0201a600
extern "C" ARM int func_0201a600(Zone0201a600* self) {
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Resources0201a600* res = (Resources0201a600*)GetGameResources();
    ActiveGrotto0201a600* grotto = &self->grotto;
    void* spawner = GetSpawner0201a600(res);
    GrottoStruct0201a600* grottoData = _ZN9GameState15GetGrottoStructEv(gs);
    SafeAllocator* alloc = self->allocator;
    unsigned char mapType = _ZNK19TreasureMapMetadata10GetMapTypeEv(grottoData->activeMapData);
    _ZN9GameState9GetLeaderEv(gs);
    int zoneId = self->info->id;
    int floor = self->currentZoneID % 20;
    Opcode68Entry0201a600 entry;
    int y;
    int halfX;
    int halfY;
    int halfZ;
    int x;
    int z;
    unsigned char tileX;
    unsigned char tileY;
    int outX;
    int outZ;
    AdjacencyBits0201a600 adjacency;
    AdjacencyBits0201a600* adjacencyPtr = &adjacency;
    unsigned char key;
    int found;

    _ZN12ZoneFeatures13AllocateExitsEiP13SafeAllocator(self->features, 2, alloc);

    var9.unknown_0_ = 0;
    var9.unknown_1c_ = -1;
    var9.unknown_50_ = 0;
    var9.unknown_52_ = 0;
    var9.unknown_54_ = 0;
    var9.unknown_64_[0] = 0;
    var9.unknown_64_[1] = 0;
    var9.unknown_58_[0] = 0;
    var9.unknown_58_[1] = 0;
    var9.unknown_58_[2] = 0;
    var9.unknown_20_[0].x = 0;
    var9.unknown_20_[0].y = 0;
    var9.unknown_20_[0].z = 0;
    var9.unknown_20_[1].x = 0;
    var9.unknown_20_[1].y = 0;
    var9.unknown_20_[1].z = 0;
    var9.unknown_20_[2].x = 0;
    var9.unknown_20_[2].y = 0;
    var9.unknown_20_[2].z = 0;
    var9.unknown_20_[3].x = 0;
    var9.unknown_20_[3].y = 0;
    var9.unknown_20_[3].z = 0;
    var9.unknown_6c_ = -1;

    if (_Z24ZoneId_IsGrottoBossFloori(zoneId)) {
        halfX = 0x2000;
        halfY = 0x2000;
        halfZ = 0x2000;
    } else {
        var11 = 0x800;
        var12 = 0x1800;
        var13 = 0x400;
    }
    {
        int var24 = inline_0201a600_3(var13);
        int var25 = inline_0201a600_3(var11);

        var9.unknown_54_ = var25 + var24;
    }

    found = 0;
    if (_Z24ZoneId_IsGrottoBossFloori(zoneId)) {
        x = 0;
        y = 0x1000;
        z = 0x11000;
    } else {
        Struct_0201a600_6 var26;

        var16 = var2->unknown_1c8_.unknown_10_;
        var17 = var2->unknown_1c8_.unknown_11_;
        srand(_ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(var2));
        arg0->unknown_23e9_ = _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
            arg0, var16, var17, &var18, &var19, 0, true);
        var10 = 0x1800;
        var14 = var18;
        var15 = var19;
        var20 = inline_0201a600(&var2->unknown_1c8_, var16, var17);
        var22 = var20.unknown_0_;
        var26.unknown_24_.x = var14;
        var26.unknown_24_.z = var15;
        var26.unknown_24_.y = 0;
        if (_ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(var2) == 2) {
            for (int var27 = 0; var27 < 15; var27++) {
                if (var22 == data_020e6e44[var27]) {
                    var23 = 1;
                    break;
                }
            }
        }
        if (var23) {
            var26.unknown_24_.y = 0x666;
        }
        if (arg0->unknown_23e9_ == 0) {
            var26.unknown_30_ = 0x3243;
            Mat3x3_WriteRotationY(&var26.unknown_0_, 0, -0x1000);
        } else if (arg0->unknown_23e9_ == 1) {
            var26.unknown_30_ = 0x1921;
            Mat3x3_WriteRotationY(&var26.unknown_0_, 0x1000, 0);
        } else if (arg0->unknown_23e9_ == 2) {
            var26.unknown_30_ = 0;
            Mat3x3_WriteIdentity(&var26.unknown_0_);
        } else if (arg0->unknown_23e9_ == 3) {
            var26.unknown_30_ = 0x4b65;
            Mat3x3_WriteRotationY(&var26.unknown_0_, -0x1000, 0);
        }
        func_0201ae8c(&var2->unknown_1c8_.unknown_14_, &var26);
    }

    {
        int var28 = var14 + var11;
        int var29 = var14 - var11;
        int var30 = var10 + var12;
        int var31 = var10 - var12;
        int var32 = var15 + var13;
        int var33 = var15 - var13;

        var9.unknown_58_[1] = var10;
        var9.unknown_4_[0] = var28;
        var9.unknown_58_[0] = var14;
        var9.unknown_58_[2] = var15;
        var9.unknown_4_[1] = var30;
        var9.unknown_4_[2] = var32;
        var9.unknown_4_[3] = var29;
        var9.unknown_4_[4] = var31;
        var9.unknown_4_[5] = var33;
    }

    if (_Z24ZoneId_IsGrottoBossFloori(zoneId) && mapType != 2) {
        entry.targetZone = _ZNK17ActiveGrottoClass13GetFloorCountEv(grotto) + 40000 + grottoData->unknown_8 * 20;
    } else if (floor == 1 || mapType == 2) {
        entry.targetZone = grottoData->entranceZoneId;
        Vector3i exitPos = grottoData->entrance;
        exitPos.z += 0x2000;
        entry.targetPos[0] = entry.targetPos[1] = entry.targetPos[2] = entry.targetPos[3] = exitPos;
    } else {
        var9.unknown_1c_ = var7 - 1;
    }

    {
        Field3f8_0201a600* request = _Z27GameState_GetZoneTransitionP9GameState(gs);

        if ((zoneId > self->previousZoneID || !_Z15ZoneId_IsGrottoi(self->previousZoneID))
            && request->unk_62 == 0 && request->unk_63 == 0
            && self->previousZoneID != 0 && request->unk_68 == 0) {
            request->active = 1;
            if (_Z24ZoneId_IsGrottoBossFloori(zoneId)) {
                request->pos.x = 0;
                request->pos.y = 0;
                request->pos.z = 0xc000;
                request->pos.y = Zone3D_GetGroundHeight(self, &request->pos);
                request->angle = 0x323d;
            } else {
                Vector3i var36;
                short var37;

                __clear(&var36, sizeof(var36));
                var36.x = var14;
                var36.z = var15;
                func_02024d94(var3, var7, &var36);
                if (arg0->unknown_23e9_ == 0) {
                    var36.z -= 0x1800;
                    var37 = 0x3243;
                } else if (arg0->unknown_23e9_ == 1) {
                    var36.x += 0x1800;
                    var37 = 0x1921;
                } else if (arg0->unknown_23e9_ == 2) {
                    var36.z += 0x1800;
                    var37 = 0;
                } else if (arg0->unknown_23e9_ == 3) {
                    var36.x -= 0x1800;
                    var37 = 0x4b65;
                }
                pos.y = Zone3D_GetGroundHeight(self, &pos);
                request->angle = angle;
                request->pos = pos;
            }
        }
    }
    _ZN12ZoneFeatures10CreateExitERKNS_13Opcode68EntryE(self->features, &entry);

    if (!_Z24ZoneId_IsGrottoBossFloori(zoneId)) {
        Struct0201ae8c placement;
        Field3f8_0201a600* request;

        var16 = var2->unknown_1c8_.unknown_12_;
        var17 = var2->unknown_1c8_.unknown_13_;
        srand(_ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(var2));
        arg0->unknown_23e8_ = _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
            arg0, var16, var17, &var18, &var19, 0, true);
        var14 = var18;
        var15 = var19;
        var38.unknown_24_.x = var14;
        var38.unknown_24_.z = var15;
        var38.unknown_24_.y = 0;
        var38.unknown_30_ = 0;
        Mat3x3_WriteIdentity(&var38.unknown_0_);
        var20 = inline_0201a600(&var2->unknown_1c8_, var16, var17);
        var22 = var20.unknown_0_;
        var23 = 0;
        if (_ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(var2) == 2) {
            for (int var40 = 0; var40 < 15; var40++) {
                if (var22 == data_020e6e44[var40]) {
                    var23 = 1;
                    break;
                }
            }
        }
        if (var23) {
            var38.unknown_24_.y = 0x666;
        }
        func_0201ae8c(&var2->unknown_1c8_.unknown_48_, &var38);

        var9.unknown_4_[0] = var14 + 0xc00;
        var9.unknown_4_[1] = 0x800 + 0x1800;
        var9.unknown_4_[2] = var15 + 0xc00;
        var9.unknown_4_[3] = var14 - 0xc00;
        var9.unknown_4_[4] = 0x800 - 0x1800;
        var9.unknown_4_[5] = var15 - 0xc00;
        var9.unknown_58_[0] = var14;
        var9.unknown_58_[1] = 0x800;
        var9.unknown_58_[2] = var15;

        if (var8 == _ZNK17ActiveGrottoClass13GetFloorCountEv(var2)) {
            switch (var4->unknown_5_) {
            case 1:
                var9.unknown_1c_ = 41101;
                break;
            case 2:
                var9.unknown_1c_ = 41201;
                break;
            case 3:
                var9.unknown_1c_ = 41301;
                break;
            case 4:
                var9.unknown_1c_ = 41401;
                break;
            case 5:
                var9.unknown_1c_ = 41501;
                break;
            default:
                var9.unknown_1c_ = 41101;
                break;
            }
            var9.unknown_1c_ += var4->unknown_8_;
        } else {
            var9.unknown_1c_ = var7 + 1;
        }

        request = _Z27GameState_GetZoneTransitionP9GameState(gs);
        if (zoneId < self->previousZoneID && request->unk_62 == 0 && request->unk_63 == 0
            && self->previousZoneID != 0 && request->unk_68 == 0) {
            Vector3i pos;
            short angle;

            __clear(&var41, sizeof(var41));
            var41.x = var14;
            var41.z = var15;
            func_02024d94(var3, var7, &var41);
            if (arg0->unknown_23e8_ == 0) {
                var41.z -= 0x1800;
                var42 = 0x3243;
            } else if (arg0->unknown_23e8_ == 1) {
                var41.x += 0x1800;
                var42 = 0x1921;
            } else if (arg0->unknown_23e8_ == 2) {
                var41.z += 0x1800;
                var42 = 0;
            } else if (arg0->unknown_23e8_ == 3) {
                var41.x -= 0x1800;
                var42 = 0x4b65;
            }
            pos.y = Zone3D_GetGroundHeight(self, &pos);
            request->angle = angle;
            request->pos = pos;
            request->active = 1;
        }
        _ZN12ZoneFeatures10CreateExitERKNS_13Opcode68EntryE(self->features, &entry);
    }
    return 1;
}
