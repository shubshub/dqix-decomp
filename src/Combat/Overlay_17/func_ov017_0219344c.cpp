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

class Actor0219344c : public Object3D {
public:
    short unknown_ac_;
    unsigned char unknown_ae_[0xc1 - 0xae];
    unsigned char unknown_c1_0_ : 3;
    unsigned char flagC1 : 1;
    unsigned char unknown_c1_4_ : 4;
#if defined(jpn)
    unsigned char unknown_c2_[0x180 - 0xc2];
#else
    unsigned char unknown1_c2_[0x18c - 0xc2];
#endif
    unsigned int unknown_18c_;
};

struct Zone0219344c {
    unsigned short id;
#if defined(jpn)
    unsigned char unknown_2_[0x84c - 0x2];
#else
    unsigned char unknown1_2_[0x82c - 0x2];
#endif
    int unknown_82c_;
    unsigned char unknown_830_[0x23b8 - 0x830];
    unsigned char unknown_23b8_;
};

struct Probe0219344c {
    Vector3i top;
    Vector3i bottom;
};

struct Grid0219344c {
    unsigned char data[0x980];
};

extern "C" void* Zone3D_GetInstance(void);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** head);
extern "C" void GameObject_ClearWallHit(ByteFlags02033f2c* p);
extern "C" int func_ov017_0218df50(void* a, void* b);
extern "C" int func_ov017_0218dfd8(Actor0219344c* self);
extern "C" int GameObject_GetWallHit(BitFlag02033f44* p);
extern "C" int func_02039dcc(unsigned char* p);
extern "C" int func_ov017_02193290(Probe0219344c* probe, Actor0219344c* self, Vector3i* dest, Vector3i* pos, int* y, int* arg5, int hidden);
extern "C" int Zone3D_CollectTerrainPolygons(Zone0219344c* zone, int index, Grid0219344c* grid, Probe0219344c probe, Actor0219344c* self);
extern "C" int func_ov017_02192b48(Grid0219344c* grid, Probe0219344c* probe, int count, Actor0219344c* self, int arg, Vector3i* dest, Vector3i* pos, int* y, int* arg8, int enable, int* reset, int arg11, int index, int hidden);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* gs);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" int GameObject_ForceMotionState(Bytes02033b88* p, int val);
extern "C" void GameObject_DisableControl(Obj020397cc* obj, int val);
extern "C" void func_020531f0(GameObject* obj);
extern "C" unsigned char* Zone3D_GetChest(unsigned char* p, int i);
extern "C" void func_ov017_0218daa8(void* res, Vec3* pos, int speed, int a, unsigned char b);
extern "C" unsigned char* Zone3D_GetLootable(Zone3D* zone, int index);

#define SETUP_PROBE()                                          \
    do {                                                       \
        probe.top = pos;                                       \
        probe.bottom = pos;                                    \
        probe.top.x += self->GetRadius() / 2;                  \
        probe.top.y += self->GetHeight();                      \
        probe.top.z += self->GetRadius() / 2;                  \
        probe.bottom.x -= self->GetRadius() / 2;               \
        probe.bottom.y -= 0xa000;                              \
        probe.bottom.z -= self->GetRadius() / 2;               \
    } while (0)

// USA: func_ov017_0219344c
extern "C" ARM int func_ov017_0219344c(Actor0219344c* self, int arg, Vector3i* target, int mode, int* outA, int* outB) {
    Grid0219344c grid;
    int reset;
    int var2;
    int y;
    GameState* gs;
    Zone0219344c* zone;
    int total;
    int hidden;
    int enable;
    int cell;
    int var10;
    int var11;
    int var12;
    int found;
    int var14;
    int var15;
    int notifyB;
    int zoneId;
    int oldAC;

    gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    zone = (Zone0219344c*)Zone3D_GetInstance();
    total = 0;
    HeadNode02046b24** head = (HeadNode02046b24**)res->fieldTaskQueue_;
    zoneId = zone->id;
    Vector3i var21 = self->position_;
    oldAC = self->unknown_ac_;
    hidden = self->GetFlags() & 0x4000000;
    self->DisableFlag(0x4000000);
    enable = 1;
    if (TestFlags00(res, 0x400) != 0 && g_keyManager.TestKeysHeld(1) != 0) {
        enable = 0;
    }
    if ((self->unknown_0_ & 0x100) && (self->unknown_18c_ & 1)) {
        enable = 0;
    }
    Probe0219344c probe;
    Vector3i pos = self->position_;
    Vector3i step;
    Vector3i saved;
    SETUP_PROBE();
    reset = 1;
    if (FieldTaskQueue_GetCurrentKind(head) != 3 || self->flagC1) {
        self->unknown_ac_ += 0x51;
    }
    if (self->unknown_ac_ > 0x1000) {
        self->unknown_ac_ = 0x1000;
    }
    GameObject_ClearWallHit((ByteFlags02033f2c*)self);
    var10 = 1;
    var11 = zone->unknown_23b8_;
    if (var11 != 0) {
        cell = (int)(((float)(self->position_.x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(self->position_.z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }
    var2 = self->position_.y - 0xa000;
    y = self->position_.y;

    if (mode == 2 && target != NULL) {
        mode = 2;
        Vector3fix_Subtract(&pos, target, &step);
        Vector3fixMultiplyScalar(&step, 0x800, &step);
        Vector3i next = *target;
        Vector3fix_Add(&next, &step, &next);
        self->position_ = next;
        pos = next;
    } else {
        mode = 1;
    }

    Vector3i* dest = target;
    var12 = 0;
    found = 0;
    var15 = 0;
    notifyB = 0;
    for (int i = 0; i < mode; i++) {
        if (mode == 2 && i == 0 && outA != NULL && outB != NULL) {
            saved = self->position_;
            dest = &saved;
            var15 |= func_ov017_0218df50(self, 0);
            notifyB |= var15;
            notifyB |= func_ov017_0218dfd8(self);
            Vector3i cur = self->position_;
            pos = cur;
            *outA = var15;
            *outB = notifyB;
            SETUP_PROBE();
        }
        if (i == 1) {
            saved = self->position_;
            dest = &saved;
            if (outA != NULL && outB != NULL) {
                if (GameObject_GetWallHit((BitFlag02033f44*)self) && !func_02039dcc((unsigned char*)self) && notifyB != 0) {
                    self->position_ = *target;
                    break;
                }
                if (GameObject_GetWallHit((BitFlag02033f44*)self)) {
                    *outA |= func_ov017_0218df50(self, 0);
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
                *outA |= func_ov017_0218df50(self, 0);
                *outB |= *outA;
                *outB |= func_ov017_0218dfd8(self);
                if (GameObject_GetWallHit((BitFlag02033f44*)self) && *outB != 0) {
                    self->position_ = *target;
                    break;
                }
            }
            pos = self->position_;
            SETUP_PROBE();
        }
        var14 = 0;
        var12 = 0;
        if (enable != 0) {
            var12 += func_ov017_02193290(&probe, self, dest, &pos, &y, &var2, hidden);
        }
        for (int j = 0; j < zone->unknown_82c_; j++) {
            if (var11 != 0) {
                if (j == 0x100) {
                    var10 = 0;
                } else if (j != cell) {
                    continue;
                }
            }
            int count = Zone3D_CollectTerrainPolygons(zone, j, &grid, probe, self);
            if (count > 0) {
                total += count;
                var14 += func_ov017_02192b48(&grid, &probe, count, self, arg, dest, &pos, &y, &var2, enable, &reset, var10, j, hidden);
            }
        }
        if (dest != NULL && var14 != 0) {
            short id = self->actorIndex_;
            if (id != GameState_GetLeaderIndex(gs)) {
                continue;
            }
            found = func_ov017_02193290(&probe, self, dest, &pos, &y, &var2, hidden);
            if (found != 0) {
                pos.x = dest->x;
                pos.z = dest->z;
                self->position_ = *target;
                break;
            }
        }
    }

    GameObject* player = gs->GetLeader();
    if (player->obj3D_.GetFlag(0x8000000)) {
        reset = 0;
    }
    if (zoneId == 10000) {
        reset = 1;
    }
    if (reset != 0) {
        if (oldAC != 0 && player->obj3D_.actorIndex_ == self->actorIndex_) {
            GameObject_EnableControl(player);
        }
        self->unknown_ac_ = 0;
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
    Vector3i var37 = self->position_;
    InteractionSelection* link = &res2->interactionSelection;
    if (link != NULL && !(var21.x == var37.x && var21.y == var37.y && var21.z == var37.z)) {
        if (link->kind == 2) {
            unsigned char* elem = Zone3D_GetChest(zone2, link->targetIndex);
            if (elem != NULL) {
                func_ov017_0218daa8(res2, (Vec3*)elem, 0xccc, 0, 0);
            }
        } else if (var12 == 0 && found == 0 && link->kind == 5) {
            unsigned char* actor = Zone3D_GetLootable((Zone3D*)zone2, link->targetIndex);
            if (actor != NULL) {
                func_ov017_0218daa8(res2, (Vec3*)(actor + 0x24), 0xc51, 0, 0);
            }
        }
    }
    return total;
}
