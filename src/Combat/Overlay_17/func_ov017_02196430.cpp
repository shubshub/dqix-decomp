#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/Vector.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

struct Struct_ov009_0218aa28;
struct Struct_02015438;
struct Struct_02077788_2;
struct Struct_02048150;
struct Struct_0201bdac_2;
struct Struct_0201bdac;

struct Struct_ov017_02196430_7 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
};

#if defined(jpn)
enum { Enum_ov017_02196430_14072 = 0x34e8, Enum_ov017_02196430_14080 = 0x34f0, Enum_ov017_02196430_14104 = 0x3508,
       Enum_ov017_02196430_17122 = 0x40c2, Enum_ov017_02196430_17126 = 0x40c6, Enum_ov017_02196430_17582 = 0x41fe,
       Enum_ov017_02196430_396 = 0x180 };
#define data_ov017_021d6438 data_ov017_021d6888
#else
enum { Enum_ov017_02196430_14072 = 0x36f8, Enum_ov017_02196430_14080 = 0x3700, Enum_ov017_02196430_14104 = 0x3718,
       Enum_ov017_02196430_17122 = 0x42e2, Enum_ov017_02196430_17126 = 0x42e6, Enum_ov017_02196430_17582 = 0x44ae,
       Enum_ov017_02196430_396 = 0x18c };
#endif

struct Struct_ov017_02196430_8 {
    char unknown_0_[Enum_ov017_02196430_14072];
    Struct_ov017_02196430_7* unknown_36f8_;
    void* unknown_36fc_;
    char unknown_3700_[Enum_ov017_02196430_14104 - Enum_ov017_02196430_14080];
    void* unknown_3718_;
    char unknown_371c_[Enum_ov017_02196430_17122 - (Enum_ov017_02196430_14104 + 4)];
    unsigned char unknown_42e2_;
    char unknown_42e3_[Enum_ov017_02196430_17126 - (Enum_ov017_02196430_17122 + 1)];
    unsigned char unknown_42e6_;
    unsigned char unknown_42e7_;
    unsigned char unknown_42e8_;
    char unknown_42e9_[Enum_ov017_02196430_17582 - (Enum_ov017_02196430_17126 + 3)];
    unsigned short unknown_44ae_;
    unsigned short unknown_44b0_;
};

struct Struct_ov017_02196430 {
    Object3D unknown_0_;
    char unknown_ac_[0xbe - 0xac];
    unsigned char unknown_be_;
    char unknown_bf_[0xc3 - 0xbf];
    unsigned char unknown_c3_;
    char unknown_c4_[0x130 - 0xc4];
    int unknown_130_;
    char unknown_134_[0x166 - 0x134];
    unsigned short unknown_166_;
    char unknown_168_[0x16a - 0x168];
    unsigned short unknown_16a_;
    char unknown_16c_[0x17d - 0x16c];
    unsigned char unknown_17d_;
    char unknown_17e_[Enum_ov017_02196430_396 - 0x17e];
    unsigned int unknown_18c_;

    int inline_ov017_02196430() const { return unknown_c3_; }
};

struct Struct_ov017_02196430_2 {
    char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov017_02196430_3 {
    unsigned short unknown_0_;
};

struct Struct_ov017_02196430_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    short unknown_2_;
    unsigned char unknown_4_;
    char unknown_5_[3];
    int unknown_8_;
    int unknown_c_;
    short unknown_10_;
    short unknown_12_;
};

struct Struct_ov017_02196430_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    unsigned short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    int unknown_14_;
};

struct Struct_ov017_02196430_6 {
    char unknown_0_[4];
    signed char unknown_4_;
};

struct Struct_ov017_021d6438 {
    unsigned char unknown_0_[3];
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" Work02196430* Zone3D_GetInstance(void);
void* GameState_GetZoneTransition(GameState* state);
int FieldTaskQueue_IsEmpty(void** obj);
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24** obj);
int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj);
int GameObject_IsClimbingLadder(char* obj);
int GetIntField0x264_02039760(void* obj);
int GetField0x8OrDefault02077a20(Outer02077a20* p);
void InitObj0219a674(unsigned char* self);
short GetAbsAngleDeltaBetween_021a4754(Vector3fix* p0, int baseAngle, Vector3fix* p2);
extern "C" void func_ov017_0219b33c(Ctx02196430* self, Msg02196430* msg);
int HasMatchingHalfword_0219735c(unsigned char* obj, unsigned short key);
int GetField0x17dBits4To5IfFlag8_020795cc(unsigned char* obj);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* arr, int value);
int CheckProximity_02196fc8(GameObject* self, GameObject* other, int extra);
int GameObject_IsGesturing(signed char* obj);
int GameState_GetProtagonistIndex(GameState* state);
void TrySetMode02076ccc(void* obj, int mode);
extern "C" unsigned short func_ov017_021971c4(Ctx02196430* self);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int LinkSession_IsGuest(void* obj);
struct Entry0207d9bc;
Entry0207d9bc* GetData02108ea8_0207d78c();
EventEntry02196430* FindEntryByHalfword(Entry0207d9bc* table, unsigned short id);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
extern "C" void func_ov017_021b6e70(Event02196430* evt, int index);
extern "C" int func_ov017_021970a0(int mode);
extern "C" void func_ov017_021b7104(void* node, Event02196430* evt);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

extern Struct_ov017_021d6438 data_ov017_021d6438;

// USA: func_ov017_02196430
// JPN: func_ov017_02196ff8
extern "C" ARM int func_ov017_02196430(GameResources* resources) {
    Ctx02196430* self = (Ctx02196430*)resources;
    GameState* game = GameState::GetInstance();
    void* session = LinkSession_GetInstance();
    Entry02196430* entry = self->entry;
    Actor02196430* player = (Actor02196430*)game->GetLeader();
    Ctx02196430* res = (Ctx02196430*)GetGameResources();
    Work02196430* work = Zone3D_GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(game);
    unsigned short tag;
    int special;
    int facing;
    int index;
    int i;
    int allowRepeat = res->allowRepeat;
    Msg02196430 approachMsg;
    Msg02196430 contactMsg;
    Msg02196430 nearbyMsg;
    Event02196430 evt;
    Vector3fix pos;
    Vector3fix offset;
    Vector3fix dir;
    Kinds02196430 kinds;

    if (var0->unknown_42e2_ != 0) {
        return 2;
    }
    if (FieldTaskQueue_IsEmpty((void**)self->list) == 0) {
        return FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)self->list) == 0x45 ? 0 : 2;
    }
    if (var3 == NULL) {
        return 2;
    }
    if (func_02053cdc((int*)var4)) {
        return 2;
    }
    if (var4->unknown_18c_ & 1) {
        return 2;
    }
    if (GameObject_IsClimbingLadder((char*)player) != 0) {
        return 2;
    }
    if (TestFlags04((GameResources*)var0, 0x10)) {
        return 2;
    }
    if (var5->unknown_42e7_ != 0) {
        return 2;
    }
    if (((Zone02196430*)GameState_GetZoneTransition(game))->busy != 0) {
        return 2;
    }
    if (func_02039760(var4) != 0 && var14 == 0) {
        return 0;
    }

    int var23 = 0;
    var10 = 0;
    int var24 = 0;
    int var25 = 0;
    var11 = 0;
    var9 = var3->unknown_0_;
    if (var4->inline_ov017_02196430() > 0 && var14 == 0) {
        var24 = 1;
    }
    unsigned short id = 0;
    index = -1;
    if (skip == 0) {
        for (i = 0; i < 12; i++) {
            direct = 0;
            index = i + (entry->group * 12 + 0x70);
            Actor02196430* other = (Actor02196430*)game->GetFieldMonsterByIndex(index);
            if (other == NULL) {
                continue;
            }
            if (var27->unknown_be_ != 2 && ((var27->unknown_17d_ & 2) || (var27->unknown_17d_ & 4))) {
                int var28;
                int var29 = var4->unknown_0_.GetHeight();
                int var30 = var27->unknown_0_.GetHeight();
                if (var4->unknown_0_.position_.y + var29 < var27->unknown_0_.position_.y ||
                    var27->unknown_0_.position_.y + var30 < var4->unknown_0_.position_.y) {
                    var28 = 0;
                } else {
                    int var31 = (var4->unknown_0_.GetRadius() >> 1) + (func_02077a20((Struct_02077788_2*)var27) >> 1);
                    int var32 = Vector3fix_Distance(&var4->unknown_0_.position_, &var27->unknown_0_.position_);
                    Vector3fix_Subtract(&var4->unknown_0_.position_, &var27->unknown_0_.position_, &var21);
                    Vector3fix_Normalize(&var21, &var21);
                    if (var32 < var31) {
                        Vector3fixMultiplyScalar(&var21, var31, &var20);
                        Vector3fix_Add(&var27->unknown_0_.position_, &var20, &var19);
                        var4->unknown_0_.position_.x = var19.x;
                        var4->unknown_0_.position_.y = var19.y;
                        var4->unknown_0_.position_.z = var19.z;
                    }
                    var28 = var32 < var31 + 0x1000;
                }
                if (touching && LinkSession_IsHostOrSolo(session)) {
                    InitObj0219a674((unsigned char*)&approachMsg);
                    approachMsg.kind = 9;
                    approachMsg.field2 = other->obj3D.actorIndex_;
                    approachMsg.angle = GetAbsAngleDeltaBetween_021a4754(&player->obj3D.position_, (short)player->obj3D.rotation_.y, &other->obj3D.position_);
                    if (approachMsg.angle < 0x1922) {
                        func_ov017_0219b33c(self, &approachMsg);
                    }
                }
                continue;
            }
            if (var27->unknown_be_ != 2) {
                if (var27->unknown_17d_ & 1) {
                    continue;
                }
#if !defined(jpn)
                if (func_ov017_0219735c((unsigned char*)var0, var27->unknown_16a_)) {
                    continue;
                }
#endif
                if (!((unsigned char)(var27->unknown_17d_ & 8) &&
                      func_02086ef0(var8, func_020795cc((unsigned char*)var27)))) {
                    if (var14 != 0) {
                        continue;
                    }
                    if (!func_ov017_02196fc8((GameObject*)var4, (GameObject*)var27, 0)) {
                        continue;
                    }
                }
            } else {
                if (!func_ov017_02196fc8((GameObject*)var4, (GameObject*)var27, 0x1000)) {
                    continue;
                }
                if (!var27->unknown_0_.IsVisible()) {
                    continue;
                }
                func_ov017_0219a674((unsigned char*)&var16);
                var16.unknown_0_ = 0xe;
                func_ov017_0219b33c(var0, &var16);
                if (g_keyManager.TestKeysPressed(1) == 0 && var0->unknown_42e6_ == 0) {
                    continue;
                }
                if (GameObject_IsGesturing((signed char*)player)) {
                    continue;
                }
                var25 = 1;
            }
            if (var27->unknown_0_.GetInheritedAlpha() != 0x1f) {
                continue;
            }
            if (var27->unknown_be_ == 6) {
                continue;
            }
            if (!var27->unknown_0_.IsVisible()) {
                continue;
            }
            if (var9 != var27->unknown_0_.GetField06()) {
                continue;
            }
            if (var25 == 0 && (var27->unknown_17d_ & 8)) {
                if (!func_02086ef0(var8, func_020795cc((unsigned char*)var27))) {
                    continue;
                }
            }
            if (var27->unknown_130_ == 0 && !(var27->unknown_17d_ & 8)) {
                continue;
            }
            if (other->mode != 8 && other->mode != 9 && other->mode != 0) {
                other->field166 = GameState_GetProtagonistIndex(game);
                TrySetMode02076ccc(other, 8);
            }
            var26 = var27->unknown_16a_;
            var23 = 1;
            if (9007.6f < (float)func_ov017_021a4754(&var27->unknown_0_.position_, (short)var27->unknown_0_.rotation_.y, &var4->unknown_0_.position_)) {
                var11 = 1;
                break;
            }
            if (9007.6f < (float)func_ov017_021a4754(&var4->unknown_0_.position_, (short)var4->unknown_0_.rotation_.y, &var27->unknown_0_.position_)) {
                var11 = 2;
            }
            break;
        }
    }

    unsigned short var33 = func_ov017_021971c4(var0);
    if (var33 != 0) {
        func_ov017_0219a674((unsigned char*)&var17);
        var17.unknown_0_ = 0xe;
        func_ov017_0219b33c(var0, &var17);
    }
    if (!GameObject_IsGesturing((signed char*)player) &&
        (g_keyManager.TestKeysPressed(1) != 0 || self->forceEvent != 0) && nearbyId != 0) {
        doEvent = 1;
        direct = 1;
        id = nearbyId;
        if ((unsigned int)(work->mapId - 0x170c) <= 3) {
            special = 1;
        }
    }
    if (var23) {
        if (var26 < 1 || var26 > 0x8004) {
            var23 = 0;
        }
    }
    if (doEvent && direct && LinkSession_IsHostOrSolo(session)) {
        EventEntry02196430* found = FindEntryByHalfword(GetData02108ea8_0207d78c(), id);
        if (found != NULL && found->field4 < 0) {
            doEvent = 0;
        }
    }
    if (LinkSession_IsGuest(session) && FieldTaskQueue_IsEmpty((void**)self->list) && self->pendingId != 0) {
        id = self->pendingId;
        self->pendingId = 0;
        self->pendingArg = 0;
        doEvent = 1;
        direct = 1;
        index = -1;
    }
    if (var23) {
        func_ov017_021b6f18(var0->unknown_3718_);
        func_ov017_02196c08((unsigned char*)&var18);
        var18.unknown_0_ = 1;
        if (var10) {
            var18.unknown_e_ = 1;
        }
        evt.field_0x1 = GameState_GetProtagonistIndex(game);
        evt.id = id;
        evt.tag = index;
        func_ov017_021b6e70(&evt, index);
        if (direct) {
            evt.field_0xf = 0;
        } else {
            var18.unknown_f_ = func_ov017_021970a0(var11);
        }
        GameObject* target = game->GetFieldMonsterByIndex(index);
        if (target != NULL) {
            kinds = data_ov017_021d6438;
            unsigned char* kind = kinds.v;
            for (int k = 0; k < 3; k++, kind++) {
                if (*kind == target->obj3D_.unknown_2_) {
                    evt.field_0xf = 0;
                    break;
                }
            }
        }
        var18.unknown_14_ = var25;
        var18.unknown_12_ = var7->timeOfDayIndex_;
        func_ov017_021b7104(var0->unknown_3718_, &var18);
        func_020469b4((Struct_0201bdac_2*)var0->unknown_36fc_, (Struct_0201bdac*)var0->unknown_3718_);
        return 1;
    }
    return 0;
}
