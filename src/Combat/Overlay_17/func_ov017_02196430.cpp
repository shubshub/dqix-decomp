#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Vec3;
struct HeadNode02046b24;
struct Struct_02077788_2;
struct ArrayContainsByteStruct;
struct TailList020469b4;
struct TailNode020469b4;

struct Struct_ov017_02196430_7 {
    unsigned short tag;
    unsigned short group : 2;
};

#if defined(jpn)
enum { Enum_ov017_02196430_14072 = 0x34e8, Enum_ov017_02196430_14080 = 0x34f0, Enum_ov017_02196430_14104 = 0x3508,
       BusyOffset = 0x40c2, Enum_ov017_02196430_17126 = 0x40c6, Enum_ov017_02196430_17582 = 0x41fe,
       Enum_ov017_02196430_396 = 0x180 };
#define data_ov017_021d6438 data_ov017_021d6888
#else
enum { Enum_ov017_02196430_14072 = 0x36f8, Enum_ov017_02196430_14080 = 0x3700, Enum_ov017_02196430_14104 = 0x3718,
       BusyOffset = 0x42e2, Enum_ov017_02196430_17126 = 0x42e6, Enum_ov017_02196430_17582 = 0x44ae,
       Enum_ov017_02196430_396 = 0x18c };
#endif

struct Struct_ov017_02196430_8 {
    char pad0[Enum_ov017_02196430_14072];
    Struct_ov017_02196430_7* entry;
    void* list;
    char unknown_3700_[Enum_ov017_02196430_14104 - Enum_ov017_02196430_14080];
    void* node;
    char unknown_371c_[BusyOffset - (Enum_ov017_02196430_14104 + 4)];
    unsigned char busy;
    char unknown_42e3_[Enum_ov017_02196430_17126 - (BusyOffset + 1)];
    unsigned char unknown_42e6_;
    unsigned char locked;
    unsigned char unknown_42e8_;
    char unknown_42e9_[Enum_ov017_02196430_17582 - (Enum_ov017_02196430_17126 + 3)];
    unsigned short pendingId;
    unsigned short unknown_44b0_;
};

struct Actor02196430 {
    Object3D obj3D;
    char unknown_ac_[0xbe - 0xac];
    unsigned char kind;
    char unknown_bf_[0xc3 - 0xbf];
    unsigned char unknown_c3_;
    char unknown_c4_[0x130 - 0xc4];
    int mode;
    char unknown_134_[0x166 - 0x134];
    unsigned short field166;
    char unknown_168_[0x16a - 0x168];
    unsigned short unknown_16a_;
    char pad16c[0x17d - 0x16c];
    unsigned char unknown_17d_;
    char unknown_17e_[Enum_ov017_02196430_396 - 0x17e];
    unsigned int unknown_18c_;

    int inline_ov017_02196430() const { return unknown_c3_; }
};

struct Zone02196430 {
    char pad0[2];
    unsigned char busy;
};

struct Work02196430 {
    unsigned short mapId;
};

struct Struct_ov017_02196430_4 {
    unsigned char kind;
    unsigned char field1;
    short field2;
    unsigned char field4;
    char pad5[3];
    int field8;
    int fieldc;
    short angle;
    short field12;
};

struct Struct_ov017_02196430_5 {
    unsigned char kind;
    unsigned char field_0x1;
    unsigned short tag;
    unsigned short id;
    unsigned char pad6[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned short color;
    unsigned char timeOfDay;
    unsigned char unknown_13_;
    int unknown_14_;
};

struct Struct_ov017_02196430_6 {
    char pad0[4];
    signed char field4;
};

struct Struct_ov017_021d6438 {
    unsigned char v[3];
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" Work02196430* Zone3D_GetInstance(void);
extern "C" void* GameState_GetZoneTransition(GameState* state);
extern "C" int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** obj);
extern "C" int func_02053cdc(int* obj);
extern "C" int GameObject_IsClimbingLadder(char* obj);
extern "C" int func_02039760(void* obj);
extern "C" int func_02077a20(Struct_02077788_2* p);
extern "C" void func_ov017_0219a674(unsigned char* self);
extern "C" short func_ov017_021a4754(Vector3fix* p0, int arg1, Vector3fix* p2);
extern "C" void func_ov017_0219b33c(Struct_ov017_02196430_8* self, Struct_ov017_02196430_4* msg);
extern "C" int func_ov017_0219735c(unsigned char* obj, unsigned short key);
extern "C" int func_020795cc(unsigned char* obj);
extern "C" int func_02086ef0(ArrayContainsByteStruct* arr, int value);
extern "C" int func_ov017_02196fc8(GameObject* self, GameObject* other, int extra);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* state);
extern "C" void func_02076ccc(void* obj, int mode);
extern "C" unsigned short func_ov017_021971c4(Struct_ov017_02196430_8* self);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);
struct Entry0207d9bc;
extern "C" Entry0207d9bc* func_0207d78c();
extern "C" Struct_ov017_02196430_6* func_0207d9bc(Entry0207d9bc* table, unsigned short id);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_02196c08(unsigned char* obj);
extern "C" void func_ov017_021b6e70(Struct_ov017_02196430_5* evt, int index);
extern "C" int func_ov017_021970a0(int mode);
extern "C" void func_ov017_021b7104(void* node, Struct_ov017_02196430_5* evt);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);

extern Struct_ov017_021d6438 data_ov017_021d6438;

// USA: func_ov017_02196430
// JPN: func_ov017_02196ff8
extern "C" ARM int func_ov017_02196430(GameResources* resources) {
    Struct_ov017_02196430_8* self = (Struct_ov017_02196430_8*)resources;
    GameState* game = GameState::GetInstance();
    void* session = LinkSession_GetInstance();
    Struct_ov017_02196430_7* entry = self->entry;
    Actor02196430* player = (Actor02196430*)game->GetLeader();
    Struct_ov017_02196430_8* res = (Struct_ov017_02196430_8*)GetGameResources();
    Work02196430* work = Zone3D_GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(game);
    unsigned short tag;
    int special;
    int facing;
    int index;
    int i;
    int var14 = res->unknown_42e8_;
    Struct_ov017_02196430_4 approachMsg;
    Struct_ov017_02196430_4 var16;
    Struct_ov017_02196430_4 var17;
    Struct_ov017_02196430_5 evt;
    Vector3fix pos;
    Vector3fix offset;
    Vector3fix dir;
    Struct_ov017_021d6438 kinds;

    if (self->busy != 0) {
        return 2;
    }
    if (FieldTaskQueue_IsEmpty((void**)self->list) == 0) {
        return FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->list) == 0x45 ? 0 : 2;
    }
    if (entry == NULL) {
        return 2;
    }
    if (func_02053cdc((int*)player)) {
        return 2;
    }
    if (player->unknown_18c_ & 1) {
        return 2;
    }
    if (GameObject_IsClimbingLadder((char*)player) != 0) {
        return 2;
    }
    if (TestFlags04((GameResources*)self, 0x10)) {
        return 2;
    }
    if (res->locked != 0) {
        return 2;
    }
    if (((Zone02196430*)GameState_GetZoneTransition(game))->busy != 0) {
        return 2;
    }
    if (func_02039760(player) != 0 && var14 == 0) {
        return 0;
    }

    int doEvent = 0;
    special = 0;
    int var24 = 0;
    int direct = 0;
    facing = 0;
    tag = entry->tag;
    if (player->inline_ov017_02196430() > 0 && var14 == 0) {
        var24 = 1;
    }
    unsigned short id = 0;
    index = -1;
    if (var24 == 0) {
        for (i = 0; i < 12; i++) {
            direct = 0;
            index = i + (entry->group * 12 + 0x70);
            Actor02196430* other = (Actor02196430*)game->GetFieldMonsterByIndex(index);
            if (other == NULL) {
                continue;
            }
            if (other->kind != 2 && ((other->unknown_17d_ & 2) || (other->unknown_17d_ & 4))) {
                int touching;
                int var29 = player->obj3D.GetHeight();
                int var30 = other->obj3D.GetHeight();
                if (player->obj3D.position_.y + var29 < other->obj3D.position_.y ||
                    other->obj3D.position_.y + var30 < player->obj3D.position_.y) {
                    touching = 0;
                } else {
                    int var31 = (player->obj3D.GetRadius() >> 1) + (func_02077a20((Struct_02077788_2*)other) >> 1);
                    int dist = Vector3fix_Distance(&player->obj3D.position_, &other->obj3D.position_);
                    Vector3fix_Subtract(&player->obj3D.position_, &other->obj3D.position_, &dir);
                    Vector3fix_Normalize(&dir, &dir);
                    if (dist < var31) {
                        Vector3fixMultiplyScalar(&dir, var31, &offset);
                        Vector3fix_Add(&other->obj3D.position_, &offset, &pos);
                        player->obj3D.position_.x = pos.x;
                        player->obj3D.position_.y = pos.y;
                        player->obj3D.position_.z = pos.z;
                    }
                    touching = dist < var31 + 0x1000;
                }
                if (touching && LinkSession_IsHostOrSolo(session)) {
                    func_ov017_0219a674((unsigned char*)&approachMsg);
                    approachMsg.kind = 9;
                    approachMsg.field2 = other->obj3D.actorIndex_;
                    approachMsg.angle = func_ov017_021a4754(&player->obj3D.position_, (short)player->obj3D.rotation_.y, &other->obj3D.position_);
                    if (approachMsg.angle < 0x1922) {
                        func_ov017_0219b33c(self, &approachMsg);
                    }
                }
                continue;
            }
            if (other->kind != 2) {
                if (other->unknown_17d_ & 1) {
                    continue;
                }
#if !defined(jpn)
                if (func_ov017_0219735c((unsigned char*)self, other->unknown_16a_)) {
                    continue;
                }
#endif
                if (!((unsigned char)(other->unknown_17d_ & 8) &&
                      func_02086ef0(party, func_020795cc((unsigned char*)other)))) {
                    if (var14 != 0) {
                        continue;
                    }
                    if (!func_ov017_02196fc8((GameObject*)player, (GameObject*)other, 0)) {
                        continue;
                    }
                }
            } else {
                if (!func_ov017_02196fc8((GameObject*)player, (GameObject*)other, 0x1000)) {
                    continue;
                }
                if (!other->obj3D.IsVisible()) {
                    continue;
                }
                func_ov017_0219a674((unsigned char*)&var16);
                var16.kind = 0xe;
                func_ov017_0219b33c(self, &var16);
                if (g_keyManager.TestKeysPressed(1) == 0 && self->unknown_42e6_ == 0) {
                    continue;
                }
                if (GameObject_IsGesturing((signed char*)player)) {
                    continue;
                }
                direct = 1;
            }
            if (other->obj3D.GetInheritedAlpha() != 0x1f) {
                continue;
            }
            if (other->kind == 6) {
                continue;
            }
            if (!other->obj3D.IsVisible()) {
                continue;
            }
            if (tag != other->obj3D.GetField06()) {
                continue;
            }
            if (direct == 0 && (other->unknown_17d_ & 8)) {
                if (!func_02086ef0(party, func_020795cc((unsigned char*)other))) {
                    continue;
                }
            }
            if (other->mode == 0 && !(other->unknown_17d_ & 8)) {
                continue;
            }
            if (other->mode != 8 && other->mode != 9 && other->mode != 0) {
                other->field166 = GameState_GetProtagonistIndex(game);
                func_02076ccc(other, 8);
            }
            id = other->unknown_16a_;
            doEvent = 1;
            if (9007.6f < (float)func_ov017_021a4754(&other->obj3D.position_, (short)other->obj3D.rotation_.y, &player->obj3D.position_)) {
                facing = 1;
                break;
            }
            if (9007.6f < (float)func_ov017_021a4754(&player->obj3D.position_, (short)player->obj3D.rotation_.y, &other->obj3D.position_)) {
                facing = 2;
            }
            break;
        }
    }

    unsigned short var33 = func_ov017_021971c4(self);
    if (var33 != 0) {
        func_ov017_0219a674((unsigned char*)&var17);
        var17.kind = 0xe;
        func_ov017_0219b33c(self, &var17);
    }
    if (!GameObject_IsGesturing((signed char*)player) &&
        (g_keyManager.TestKeysPressed(1) != 0 || self->unknown_42e6_ != 0) && var33 != 0) {
        doEvent = 1;
        direct = 1;
        id = var33;
        if ((unsigned int)(work->mapId - 0x170c) <= 3) {
            special = 1;
        }
    }
    if (doEvent) {
        if (id < 1 || id > 0x8004) {
            doEvent = 0;
        }
    }
    if (doEvent && direct && LinkSession_IsHostOrSolo(session)) {
        Struct_ov017_02196430_6* found = func_0207d9bc(func_0207d78c(), id);
        if (found != NULL && found->field4 < 0) {
            doEvent = 0;
        }
    }
    if (LinkSession_IsGuest(session) && FieldTaskQueue_IsEmpty((void**)self->list) && self->pendingId != 0) {
        id = self->pendingId;
        self->pendingId = 0;
        self->unknown_44b0_ = 0;
        doEvent = 1;
        direct = 1;
        index = -1;
    }
    if (doEvent) {
        func_ov017_021b6f18(self->node);
        func_ov017_02196c08((unsigned char*)&evt);
        evt.kind = 1;
        if (special) {
            evt.unknown_e_ = 1;
        }
        evt.field_0x1 = GameState_GetProtagonistIndex(game);
        evt.id = id;
        evt.tag = index;
        func_ov017_021b6e70(&evt, index);
        if (direct) {
            evt.unknown_f_ = 0;
        } else {
            evt.unknown_f_ = func_ov017_021970a0(facing);
        }
        GameObject* target = game->GetFieldMonsterByIndex(index);
        if (target != NULL) {
            kinds = data_ov017_021d6438;
            unsigned char* kind = kinds.v;
            for (int k = 0; k < 3; k++, kind++) {
                if (*kind == target->obj3D_.unknown_2_) {
                    evt.unknown_f_ = 0;
                    break;
                }
            }
        }
        evt.unknown_14_ = direct;
        evt.timeOfDay = lighting->timeOfDayIndex_;
        func_ov017_021b7104(self->node, &evt);
        func_020469b4((TailList020469b4*)self->list, (TailNode020469b4*)self->node);
        return 1;
    }
    return 0;
}
