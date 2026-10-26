#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct HeadNode02046b24;
struct ByteFlags02033f2c;
struct BitFlag02033f44;
struct Bytes02033b88;
struct Obj020397cc;
class Zone3D;
struct Vec3;

class Struct_ov017_0219344c_2 : public Object3D {
public:
    short unknown_ac_;
    unsigned char unknown_ae_[0xc1 - 0xae];
    unsigned char unknown_c1_0_ : 3;
    unsigned char unknown_c1_3_ : 1;
    unsigned char unknown_c1_4_ : 4;
#if defined(jpn)
    unsigned char unknown_c2_[0x180 - 0xc2];
#else
    unsigned char unknown1_c2_[0x18c - 0xc2];
#endif
    unsigned int unknown_18c_;
};

struct Struct_ov017_0219344c_3 {
    unsigned short unknown_0_;
#if defined(jpn)
    unsigned char unknown_2_[0x84c - 0x2];
#else
    unsigned char unknown1_2_[0x82c - 0x2];
#endif
    int unknown_82c_;
    unsigned char unknown_830_[0x23b8 - 0x830];
    unsigned char unknown_23b8_;
};

struct Struct_ov017_0219344c_4 {
    Vector3i unknown_0_;
    Vector3i unknown_c_;
};

struct Struct_ov017_0219344c_5 {
    unsigned char unknown_0_[0x980];
};

extern "C" void* Zone3D_GetInstance(void);
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** head);
void GameObject_ClearWallHit(ByteFlags02033f2c* p);
int NotifyEntriesFlag256_0218df50(void* a, void* b);
extern "C" int func_ov017_0218dfd8(Actor0219344c* self);
int GameObject_GetWallHit(BitFlag02033f44* p);
int IsFlag0x1ceBit0x8Set_02039dcc(unsigned char* p);
extern "C" int func_ov017_02193290(Probe0219344c* probe, Actor0219344c* self, Vector3i* dest, Vector3i* pos, int* y, int* yLow, int hidden);
extern "C" int Zone3D_CollectTerrainPolygons(Zone0219344c* zone, int index, Grid0219344c* grid, Probe0219344c probe, Actor0219344c* self);
extern "C" int func_ov017_02192b48(Grid0219344c* grid, Probe0219344c* probe, int count, Actor0219344c* self, int arg, Vector3i* dest, Vector3i* pos, int* y, int* yLow, int enable, int* reset, int inCell, int index, int hidden);
unsigned char GameState_GetLeaderIndex(GameState* gs);
void GameObject_EnableControl(void* obj);
int GameObject_ForceMotionState(Bytes02033b88* p, int val);
void GameObject_DisableControl(Obj020397cc* obj, int val);
extern "C" void func_020531f0(GameObject* obj);
unsigned char* Zone3D_GetChest(unsigned char* p, int i);
void GetDeltaAndForward_0218daa8(void* res, Vec3* pos, int speed, int a, unsigned char b);
unsigned char* Zone3D_GetLootable(Zone3D* zone, int index);

#define SETUP_PROBE()                                          \
    do {                                                       \
        var22.unknown_0_ = var23;                                       \
        var22.unknown_c_ = var23;                                    \
        var22.unknown_0_.x += arg0->GetRadius() / 2;                  \
        var22.unknown_0_.y += arg0->GetHeight();                      \
        var22.unknown_0_.z += arg0->GetRadius() / 2;                  \
        var22.unknown_c_.x -= arg0->GetRadius() / 2;               \
        var22.unknown_c_.y -= 0xa000;                              \
        var22.unknown_c_.z -= arg0->GetRadius() / 2;               \
    } while (0)

// USA: func_ov017_0219344c
extern "C" ARM int func_ov017_0219344c(Struct_ov017_0219344c_2* arg0, int arg1, Vector3i* arg2, int arg3, int* arg4, int* arg5) {
    Struct_ov017_0219344c_5 var0;
    int var1;
    int var2;
    int var3;
    GameState* var4;
    Struct_ov017_0219344c_3* var5;
    int var6;
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    int var12;
    int var13;
    int var14;
    int var15;
    int var16;
    int var17;
    int var18;

    gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    zone = (Zone0219344c*)Zone3D_GetInstance();
    total = 0;
    HeadNode02046b24** head = (HeadNode02046b24**)res->fieldTaskQueue_;
    zoneId = zone->id;
    Vector3i startPos = self->position_;
    oldAC = self->fieldAC;
    hidden = self->GetFlags() & 0x4000000;
    self->DisableFlag(0x4000000);
    enable = 1;
    if (TestFlags00(res, 0x400) != 0 && g_keyManager.TestKeysHeld(1) != 0) {
        enable = 0;
    }
    if ((arg0->unknown_0_ & 0x100) && (arg0->unknown_18c_ & 1)) {
        var8 = 0;
    }
    Struct_ov017_0219344c_4 var22;
    Vector3i var23 = arg0->position_;
    Vector3i var24;
    Vector3i var25;
    SETUP_PROBE();
    reset = 1;
    if (FieldTaskQueue_GetCurrentKind(head) != 3 || self->flagC1) {
        self->fieldAC += 0x51;
    }
    if (arg0->unknown_ac_ > 0x1000) {
        arg0->unknown_ac_ = 0x1000;
    }
    GameObject_ClearWallHit((ByteFlags02033f2c*)self);
    inCell = 1;
    useCell = zone->useCell;
    if (useCell != 0) {
        cell = (int)(((float)(self->position_.x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(self->position_.z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }
    var2 = arg0->position_.y - 0xa000;
    var3 = arg0->position_.y;

    if (arg3 == 2 && arg2 != NULL) {
        arg3 = 2;
        Vector3fix_Subtract(&var23, arg2, &var24);
        Vector3fixMultiplyScalar(&var24, 0x800, &var24);
        Vector3i var26 = *arg2;
        Vector3fix_Add(&var26, &var24, &var26);
        arg0->position_ = var26;
        var23 = var26;
    } else {
        arg3 = 1;
    }

    Vector3i* var27 = arg2;
    var12 = 0;
    var13 = 0;
    var15 = 0;
    var16 = 0;
    for (int var28 = 0; var28 < arg3; var28++) {
        if (arg3 == 2 && var28 == 0 && arg4 != NULL && arg5 != NULL) {
            var25 = arg0->position_;
            var27 = &var25;
            var15 |= func_ov017_0218df50(arg0, 0);
            var16 |= var15;
            var16 |= func_ov017_0218dfd8(arg0);
            Vector3i var29 = arg0->position_;
            var23 = var29;
            *arg4 = var15;
            *arg5 = var16;
            SETUP_PROBE();
        }
        if (i == 1) {
            saved = self->position_;
            dest = &saved;
            if (outA != NULL && outB != NULL) {
                if (GameObject_GetWallHit((BitFlag02033f44*)self) && !IsFlag0x1ceBit0x8Set_02039dcc((unsigned char*)self) && notifyB != 0) {
                    self->position_ = *target;
                    break;
                }
                if (GameObject_GetWallHit((BitFlag02033f44*)self)) {
                    *outA |= NotifyEntriesFlag256_0218df50(self, 0);
                    *outB |= *outA;
                    *outB |= func_ov017_0218dfd8(self);
                    if (*outB != 0) {
                        self->position_ = *target;
                        break;
                    }
                }
            }
            Vector3i next = self->position_;
            Vector3fix_Add(&next, &step, &next);
            self->position_ = next;
            if (outA != NULL && outB != NULL) {
                *outA |= NotifyEntriesFlag256_0218df50(self, 0);
                *outB |= *outA;
                *outB |= func_ov017_0218dfd8(self);
                if (GameObject_GetWallHit((BitFlag02033f44*)self) && *outB != 0) {
                    self->position_ = *target;
                    break;
                }
            }
            var23 = arg0->position_;
            SETUP_PROBE();
        }
        var14 = 0;
        var12 = 0;
        if (var8 != 0) {
            var12 += func_ov017_02193290(&var22, arg0, var27, &var23, &var3, &var2, var7);
        }
        for (int var31 = 0; var31 < var5->unknown_82c_; var31++) {
            if (var11 != 0) {
                if (var31 == 0x100) {
                    var10 = 0;
                } else if (var31 != var9) {
                    continue;
                }
            }
            int count = Zone3D_CollectTerrainPolygons(zone, j, &grid, probe, self);
            if (count > 0) {
                total += count;
                pathHits += func_ov017_02192b48(&grid, &probe, count, self, arg, dest, &pos, &y, &yLow, enable, &reset, inCell, j, hidden);
            }
        }
        if (dest != NULL && pathHits != 0) {
            short id = self->actorIndex_;
            if (id != GameState_GetLeaderIndex(gs)) {
                continue;
            }
            var13 = func_ov017_02193290(&var22, arg0, var27, &var23, &var3, &var2, var7);
            if (var13 != 0) {
                var23.x = var27->x;
                var23.z = var27->z;
                arg0->position_ = *arg2;
                break;
            }
        }
    }

    GameObject* player = gs->GetLeader();
    if (player->obj3D_.GetFlag(0x8000000)) {
        reset = 0;
    }
    if (var17 == 10000) {
        var1 = 1;
    }
    if (reset != 0) {
        if (oldAC != 0 && player->obj3D_.actorIndex_ == self->actorIndex_) {
            GameObject_EnableControl(player);
        }
        self->fieldAC = 0;
    } else if (oldAC == 0) {
        GameObject_ForceMotionState((Bytes02033b88*)self, 0);
        if (player->obj3D_.actorIndex_ == self->actorIndex_) {
            GameObject_DisableControl((Obj020397cc*)player, 1);
            if (!player->obj3D_.GetFlag(0x1000)) {
                func_020531f0(player);
            }
        }
    }

    GameResources* res2 = GetGameResources();
    unsigned char* zone2 = (unsigned char*)Zone3D_GetInstance();
    Vector3i endPos = self->position_;
    InteractionSelection* link = &res2->interactionSelection;
    if (link != NULL && !(startPos.x == endPos.x && startPos.y == endPos.y && startPos.z == endPos.z)) {
        if (link->kind == 2) {
            unsigned char* elem = Zone3D_GetChest(zone2, link->targetIndex);
            if (elem != NULL) {
                GetDeltaAndForward_0218daa8(res2, (Vec3*)elem, 0xccc, 0, 0);
            }
        } else if (hits == 0 && found == 0 && link->kind == 5) {
            unsigned char* actor = Zone3D_GetLootable((Zone3D*)zone2, link->targetIndex);
            if (actor != NULL) {
                GetDeltaAndForward_0218daa8(res2, (Vec3*)(actor + 0x24), 0xc51, 0, 0);
            }
        }
    }
    return var6;
}
