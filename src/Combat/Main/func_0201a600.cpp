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
    Matrix3x3 matrix;
    Vector3i pos;
    int angle;
};

struct Struct_0201a600_8 {
    unsigned char* unknown_0_;
    unsigned char* adjacencyData;
    int width;
    int height;
    unsigned char unknown_10_;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    Struct_0201a600_6 up;
    Struct_0201a600_6 down;
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

struct Opcode68Entry0201a600 {
    int unk_0;
    int bounds[6];
    int unknown_1c_;
    Vector3i unknown_20_[4];
    short unk_50;
    short unk_52;
    int unknown_54_;
    int unknown_58_[3];
    int unk_64[2];
    int unk_6c;
};

struct Struct_0201a600_2 {
    unsigned short id;
};

struct Zone0201a600 {
    unsigned short unknown_0_;
    unsigned short previousZoneID;
    char unknown_4_[4];
    Struct_0201a600_2* info;
    char unknown_c_[REGION_VALUE(0x7c, 0x5c)];
    SafeAllocator* allocator;
    char features[0x88];
    char unknown_f4_[0x23e8 - 0xf4];
    unsigned char unknown_23e8_;
    unsigned char unknown_23e9_;
    char unknown_23ea_[2];
    Struct_0201a600_9 grotto;
};

struct Struct_0201a600_4 {
    char unknown_0_[REGION_VALUE(0x34c0, 0x36d0)];
    void* unknown_36d0_;
};

struct Field3f8_0201a600 {
    char unknown_0_[7];
    unsigned char active;
    char unknown_8_[8];
    Vector3i pos;
    unsigned short angle;
    char unknown_1e_[0x44];
    unsigned char unknown_62_;
    unsigned char unknown_63_;
    char unknown_64_[4];
    unsigned char unknown_68_;
};

extern "C" {
GameState* _ZN9GameState11GetInstanceEv();
Struct_0201a600_10* _ZN9GameState15GetGrottoStructEv(GameState* gs);
int _ZNK19TreasureMapMetadata10GetMapTypeEv(void* arg0);
void* _ZN9GameState9GetLeaderEv(GameState* gs);
void _ZN12ZoneFeatures13AllocateExitsEiP13SafeAllocator(void* features, int count, SafeAllocator* alloc);
void _ZN12ZoneFeatures10CreateExitERKNS_13Opcode68EntryE(void* features, const Opcode68Entry0201a600* entry);
extern "C" int ZoneId_IsGrottoBossFloor(int zoneId);
extern "C" int ZoneId_IsGrotto(int zoneId);
unsigned short _ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(const Struct_0201a600_9* grotto);
int _ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(const Struct_0201a600_9* grotto);
int _ZNK17ActiveGrottoClass13GetFloorCountEv(const Struct_0201a600_9* grotto);
int _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
    void* zone, int tileX, int tileY, int* outX, int* arg4, const void* arg5, bool arg6);
int _ZNK8FloorMap16GetAdjacencyBitsEii(const Struct_0201a600_8* map, int x, int y);
extern "C" Struct_0201a600_6* func_0201ae8c(Struct_0201a600_6* dst, Struct_0201a600_6* src);
extern "C" Field3f8_0201a600* GameState_GetZoneTransition(GameState* gs);
int Zone3D_GetGroundHeight(Zone0201a600* zone, Vector3i* pos);
void __clear(void* buf, int size);
void func_02024d94(void* obj, unsigned short zoneId, Vector3i* pos);
}

extern const unsigned char data_020e6e44[15];

struct Struct_0201a600_7 {
    unsigned char bits;
};

static inline Struct_0201a600_7 inline_0201a600(const Struct_0201a600_8* map, int x, int y) {
    Struct_0201a600_7 result;
    result.bits = _ZNK8FloorMap16GetAdjacencyBitsEii(map, x, y);
    return result;
}

static inline void* inline_0201a600_2(Struct_0201a600_4* res) {
    return res->unknown_36d0_;
}

static inline int inline_0201a600_3(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

// USA: func_0201a600
extern "C" ARM int func_0201a600(Zone0201a600* self) {
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Struct_0201a600_4* res = (Struct_0201a600_4*)GetGameResources();
    Struct_0201a600_9* grotto = &self->grotto;
    void* var3 = inline_0201a600_2(res);
    Struct_0201a600_10* var4 = _ZN9GameState15GetGrottoStructEv(gs);
    SafeAllocator* alloc = self->allocator;
    unsigned char mapType = _ZNK19TreasureMapMetadata10GetMapTypeEv(var4->unknown_6c_);
    _ZN9GameState9GetLeaderEv(gs);
    int zoneId = self->info->id;
    int floor = self->unknown_0_ % 20;
    Opcode68Entry0201a600 entry;
    int y;
    int halfX;
    int var12;
    int halfZ;
    int x;
    int z;
    unsigned char tileX;
    unsigned char tileY;
    int outX;
    int var19;
    Struct_0201a600_7 var20;
    Struct_0201a600_7* var21 = &var20;
    unsigned char key;
    int found;

    _ZN12ZoneFeatures13AllocateExitsEiP13SafeAllocator(self->features, 2, alloc);

    entry.unk_0 = 0;
    entry.unknown_1c_ = -1;
    entry.unk_50 = 0;
    entry.unk_52 = 0;
    entry.unknown_54_ = 0;
    entry.unk_64[0] = 0;
    entry.unk_64[1] = 0;
    entry.unknown_58_[0] = 0;
    entry.unknown_58_[1] = 0;
    entry.unknown_58_[2] = 0;
    entry.unknown_20_[0].x = 0;
    entry.unknown_20_[0].y = 0;
    entry.unknown_20_[0].z = 0;
    entry.unknown_20_[1].x = 0;
    entry.unknown_20_[1].y = 0;
    entry.unknown_20_[1].z = 0;
    entry.unknown_20_[2].x = 0;
    entry.unknown_20_[2].y = 0;
    entry.unknown_20_[2].z = 0;
    entry.unknown_20_[3].x = 0;
    entry.unknown_20_[3].y = 0;
    entry.unknown_20_[3].z = 0;
    entry.unk_6c = -1;

    if (ZoneId_IsGrottoBossFloor(zoneId)) {
        halfX = 0x2000;
        var12 = 0x2000;
        halfZ = 0x2000;
    } else {
        halfX = 0x800;
        var12 = 0x1800;
        halfZ = 0x400;
    }
    {
        int var24 = inline_0201a600_3(halfZ);
        int var25 = inline_0201a600_3(halfX);

        entry.unknown_54_ = var25 + var24;
    }

    found = 0;
    if (ZoneId_IsGrottoBossFloor(zoneId)) {
        x = 0;
        y = 0x1000;
        z = 0x11000;
    } else {
        Struct_0201a600_6 var26;

        tileX = grotto->unknown_1c8_.unknown_10_;
        tileY = grotto->unknown_1c8_.unknown_11_;
        srand(_ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(grotto));
        self->unknown_23e9_ = _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
            self, tileX, tileY, &outX, &var19, 0, true);
        y = 0x1800;
        x = outX;
        z = var19;
        var20 = inline_0201a600(&grotto->unknown_1c8_, tileX, tileY);
        key = var20.bits;
        var26.pos.x = x;
        var26.pos.z = z;
        var26.pos.y = 0;
        if (_ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(grotto) == 2) {
            for (int i = 0; i < 15; i++) {
                if (key == data_020e6e44[i]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            var26.pos.y = 0x666;
        }
        if (self->unknown_23e9_ == 0) {
            var26.angle = 0x3243;
            Mat3x3_WriteRotationY(&var26.matrix, 0, -0x1000);
        } else if (self->unknown_23e9_ == 1) {
            var26.angle = 0x1921;
            Mat3x3_WriteRotationY(&var26.matrix, 0x1000, 0);
        } else if (self->unknown_23e9_ == 2) {
            var26.angle = 0;
            Mat3x3_WriteIdentity(&var26.matrix);
        } else if (self->unknown_23e9_ == 3) {
            var26.angle = 0x4b65;
            Mat3x3_WriteRotationY(&var26.matrix, -0x1000, 0);
        }
        func_0201ae8c(&grotto->unknown_1c8_.up, &var26);
    }

    {
        int xMax = x + halfX;
        int xMin = x - halfX;
        int var30 = y + var12;
        int var31 = y - var12;
        int zMax = z + halfZ;
        int zMin = z - halfZ;

        entry.unknown_58_[1] = y;
        entry.bounds[0] = xMax;
        entry.unknown_58_[0] = x;
        entry.unknown_58_[2] = z;
        entry.bounds[1] = var30;
        entry.bounds[2] = zMax;
        entry.bounds[3] = xMin;
        entry.bounds[4] = var31;
        entry.bounds[5] = zMin;
    }

    if (ZoneId_IsGrottoBossFloor(zoneId) && mapType != 2) {
        entry.unknown_1c_ = _ZNK17ActiveGrottoClass13GetFloorCountEv(grotto) + 40000 + var4->unknown_8_ * 20;
    } else if (floor == 1 || mapType == 2) {
        entry.unknown_1c_ = var4->unknown_c_;
        Vector3i var34 = var4->unknown_10_;
        var34.z += 0x2000;
        entry.unknown_20_[0] = entry.unknown_20_[1] = entry.unknown_20_[2] = entry.unknown_20_[3] = var34;
    } else {
        entry.unknown_1c_ = zoneId - 1;
    }

    {
        Field3f8_0201a600* request = GameState_GetZoneTransition(gs);

        if ((zoneId > self->previousZoneID || !ZoneId_IsGrotto(self->previousZoneID))
            && request->unknown_62_ == 0 && request->unknown_63_ == 0
            && self->previousZoneID != 0 && request->unknown_68_ == 0) {
            request->active = 1;
            if (ZoneId_IsGrottoBossFloor(zoneId)) {
                request->pos.x = 0;
                request->pos.y = 0;
                request->pos.z = 0xc000;
                request->pos.y = Zone3D_GetGroundHeight(self, &request->pos);
                request->angle = 0x323d;
            } else {
                Vector3i pos;
                short angle;

                __clear(&pos, sizeof(pos));
                pos.x = x;
                pos.z = z;
                func_02024d94(var3, zoneId, &pos);
                if (self->unknown_23e9_ == 0) {
                    pos.z -= 0x1800;
                    angle = 0x3243;
                } else if (self->unknown_23e9_ == 1) {
                    pos.x += 0x1800;
                    angle = 0x1921;
                } else if (self->unknown_23e9_ == 2) {
                    pos.z += 0x1800;
                    angle = 0;
                } else if (self->unknown_23e9_ == 3) {
                    pos.x -= 0x1800;
                    angle = 0x4b65;
                }
                pos.y = Zone3D_GetGroundHeight(self, &pos);
                request->angle = angle;
                request->pos = pos;
            }
        }
    }
    _ZN12ZoneFeatures10CreateExitERKNS_13Opcode68EntryE(self->features, &entry);

    if (!ZoneId_IsGrottoBossFloor(zoneId)) {
        Struct_0201a600_6 var38;
        Field3f8_0201a600* request;

        tileX = grotto->unknown_1c8_.unknown_12_;
        tileY = grotto->unknown_1c8_.unknown_13_;
        srand(_ZNK17ActiveGrottoClass19GetActiveGrottoSeedEv(grotto));
        self->unknown_23e8_ = _Z39GenerateGrottoObjectPositionOrientationPviiPiS0_PK24TileFeaturePlacementDatab(
            self, tileX, tileY, &outX, &var19, 0, true);
        x = outX;
        z = var19;
        var38.pos.x = x;
        var38.pos.z = z;
        var38.pos.y = 0;
        var38.angle = 0;
        Mat3x3_WriteIdentity(&var38.matrix);
        var20 = inline_0201a600(&grotto->unknown_1c8_, tileX, tileY);
        key = var20.bits;
        found = 0;
        if (_ZNK17ActiveGrottoClass22GetActiveGrottoEnvironEv(grotto) == 2) {
            for (int i = 0; i < 15; i++) {
                if (key == data_020e6e44[i]) {
                    found = 1;
                    break;
                }
            }
        }
        if (found) {
            var38.pos.y = 0x666;
        }
        func_0201ae8c(&grotto->unknown_1c8_.down, &var38);

        entry.bounds[0] = x + 0xc00;
        entry.bounds[1] = 0x800 + 0x1800;
        entry.bounds[2] = z + 0xc00;
        entry.bounds[3] = x - 0xc00;
        entry.bounds[4] = 0x800 - 0x1800;
        entry.bounds[5] = z - 0xc00;
        entry.unknown_58_[0] = x;
        entry.unknown_58_[1] = 0x800;
        entry.unknown_58_[2] = z;

        if (floor == _ZNK17ActiveGrottoClass13GetFloorCountEv(grotto)) {
            switch (var4->unknown_5_) {
            case 1:
                entry.unknown_1c_ = 41101;
                break;
            case 2:
                entry.unknown_1c_ = 41201;
                break;
            case 3:
                entry.unknown_1c_ = 41301;
                break;
            case 4:
                entry.unknown_1c_ = 41401;
                break;
            case 5:
                entry.unknown_1c_ = 41501;
                break;
            default:
                entry.unknown_1c_ = 41101;
                break;
            }
            entry.unknown_1c_ += var4->unknown_8_;
        } else {
            entry.unknown_1c_ = zoneId + 1;
        }

        request = GameState_GetZoneTransition(gs);
        if (zoneId < self->previousZoneID && request->unknown_62_ == 0 && request->unknown_63_ == 0
            && self->previousZoneID != 0 && request->unknown_68_ == 0) {
            Vector3i pos;
            short angle;

            __clear(&pos, sizeof(pos));
            pos.x = x;
            pos.z = z;
            func_02024d94(var3, zoneId, &pos);
            if (self->unknown_23e8_ == 0) {
                pos.z -= 0x1800;
                angle = 0x3243;
            } else if (self->unknown_23e8_ == 1) {
                pos.x += 0x1800;
                angle = 0x1921;
            } else if (self->unknown_23e8_ == 2) {
                pos.z += 0x1800;
                angle = 0;
            } else if (self->unknown_23e8_ == 3) {
                pos.x -= 0x1800;
                angle = 0x4b65;
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
