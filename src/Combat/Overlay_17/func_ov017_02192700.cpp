#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"


struct SearchStruct0202c1a4;
struct ArrayContainsByteStruct;

struct Struct_ov017_02192700_2 {
    unsigned char byte0;
    unsigned char unknown_1_;
    unsigned char busy;
};

struct Struct_ov017_02192700_3 {
    unsigned short tag;
    unsigned short group : 2;
};

struct Struct_ov017_02192700_4 {
    unsigned int flags;
#if defined(jpn)
    char pad4[0x34e8 - 0x4];
    Struct_ov017_02192700_3* entry;
    char unknown_34ec_[0x3994 - 0x34ec];
#else
    char pad4[0x36f8 - 0x4];
    Struct_ov017_02192700_3* entry;
    char unknown_36fc_[0x3bb4 - 0x36fc];
#endif
    Struct_ov017_02192700_2* state;
};

struct Actor02192700 {
    Object3D obj3D;
    short unknown_ac_;
    char unknown_ae_[0xb2 - 0xae];
    unsigned short unknown_b2_;
    char unknown_b4_[0xc2 - 0xb4];
    unsigned char unknown_c2_0_ : 4;
#if defined(jpn)
    char padc3[0x180 - 0xc3];
#else
    char padc3[0x18c - 0xc3];
#endif
    unsigned int unknown_18c_;
};

extern "C" void func_ov017_0219a674(unsigned char* self);

struct Struct_01ff91ac_18 {
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

struct Save0205ec34 {
    char pad0[0x8c];
    unsigned char flags[1];
};

extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
extern "C" Save0205ec34* Scenario_GetInstance(void);
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
extern "C" int LinkSession_IsActive(int* p);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" int func_ov017_02194140(Actor02192700* self, Actor02192700* other);
extern "C" int GameObject_IsHidden(unsigned char* obj);
extern "C" void* GameState_GetParty(GameState* state);
extern "C" int func_02086ef0(ArrayContainsByteStruct* arr, int value);
extern "C" void func_ov017_0219b33c(Struct_ov017_02192700_4* self, Struct_01ff91ac_18* msg);
extern "C" void func_ov017_021c316c(Struct_ov017_02192700_2* p, int flag);
extern "C" int func_ov017_0218d4ec(void* obj, int bit);
extern "C" int Scenario_TestFlag(int base, unsigned char* bits, int index);
extern "C" int func_02039860(void* obj);
extern "C" void func_ov017_0219344c(Actor02192700* actor, int a, int b, int c, int d, int e);

static inline Struct_ov017_02192700_4* inline_ov017_02192700() {
    Struct_ov017_02192700_4* res = (Struct_ov017_02192700_4*)GetGameResources();
    Struct_01ff91ac_18 msg;
    func_ov017_0219a674((unsigned char*)&msg);
    msg.kind = 1;
    func_ov017_0219b33c(res, &msg);
    return res;
}

static inline void inline_ov017_02192700_2(Struct_01ff91ac_18* msg) {
    func_ov017_0219a674((unsigned char*)msg);
    msg->kind = 0xd;
    msg->field1 = 0x11;
}

static inline void inline_ov017_02192700_3(Struct_ov017_02192700_4* res, Actor02192700* member) {
    Struct_01ff91ac_18 msg;
    inline_ov017_02192700_2(&msg);
    msg.field2 = member->obj3D.actorIndex_;
    func_ov017_0219b33c(res, &msg);
}

// USA: func_ov017_02192700
extern "C" ARM void func_ov017_02192700(Struct_ov017_02192700_4* ctx) {
    if ((TestFlags00((GameResources*)(&ctx->flags), 0x20) != 0 && g_keyManager.TestKeysHeld(1) != 0) ||
        TestFlags00((GameResources*)(&ctx->flags), 0x2000) != 0) {
        return;
    }
    GameState* game = GameState::GetInstance();
    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    Save0205ec34* save = Scenario_GetInstance();
    Actor02192700* leader = (Actor02192700*)game->GetLeader();
    if (leader == NULL) {
        return;
    }
    unsigned short var4 = leader->obj3D.GetField06();
    ZoneRecords_GetInstance();
    Struct_ov017_02192700_3* entry = ctx->entry;
    if (LinkSession_IsActive((int*)search)) {
        for (int i = 0; i <= 3; i++) {
            Actor02192700* member = (Actor02192700*)game->GetPartyMemberByIndex(i);
            if (member == NULL || member == leader) {
                continue;
            }
            if (var4 != member->obj3D.GetField06()) {
                continue;
            }
            if ((member->unknown_18c_ & 1) && member->obj3D.GetInheritedAlpha() > 0) {
                if (!func_ov017_02194140(leader, member)) {
                    continue;
                }
                GameState* state = GameState::GetInstance();
                Actor02192700* other = (Actor02192700*)state->GetPartyMemberByIndex(member->obj3D.actorIndex_);
                if (other->obj3D.GetField06() != member->obj3D.GetField06()) {
                    continue;
                }
                if (other->obj3D.GetInheritedAlpha() <= 0) {
                    continue;
                }
                if (other->obj3D.GetAlphaScaleFactor() <= 0) {
                    continue;
                }
                if (!other->obj3D.IsVisible()) {
                    continue;
                }
                if (GameObject_IsHidden((unsigned char*)other)) {
                    continue;
                }
                ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(state);
                if (party == NULL) {
                    continue;
                }
                if (func_02086ef0(party, member->obj3D.actorIndex_)) {
                    continue;
                }
                Struct_ov017_02192700_4* res = inline_ov017_02192700();
                if (res->state->busy == 0) {
                    func_ov017_021c316c(res->state, member->obj3D.actorIndex_ & 0xff);
                }
                continue;
            }
            if (func_ov017_0218d4ec(ctx, member->obj3D.actorIndex_) &&
                Scenario_TestFlag((int)save, save->flags, 0x799) &&
                func_ov017_02194140(leader, member)) {
                inline_ov017_02192700_3((Struct_ov017_02192700_4*)GetGameResources(), member);
            }
            if (func_02039860(member) >= 0) {
                continue;
            }
            if (!member->obj3D.IsVisible()) {
                continue;
            }
            int id = member->obj3D.actorIndex_;
            if (func_ov017_02194140(leader, member)) {
                if (!(leader->unknown_c2_0_ & (1 << id))) {
                    leader->unknown_c2_0_ |= 1 << id;
                    leader->unknown_b2_ = 0;
                }
            } else {
                leader->unknown_c2_0_ &= ~(1 << id);
            }
        }
    }
    if (!LinkSession_IsActive((int*)search) || !LinkSession_GetOwnSlot(search)) {
        for (int i = 0x70; i <= 0x9f; i++) {
            Actor02192700* monster = (Actor02192700*)GameState::GetInstance()->GetFieldMonsterByIndex(i);
            if (monster == NULL || monster->obj3D.unknown_2_ < 0) {
                continue;
            }
            Vector3i pos = monster->obj3D.position_;
            pos.y -= monster->unknown_ac_;
            if (pos.y < -0x1e000) {
                pos.y = 0x1e000;
            }
            monster->obj3D.position_ = pos;
            if (monster->obj3D.GetField06() == leader->obj3D.GetField06()) {
                func_ov017_0219344c(monster, 0, 0, 0, 0, 0);
            }
        }
    } else if (entry != NULL) {
        for (int i = 0; i <= 12; i++) {
            Actor02192700* monster = (Actor02192700*)GameState::GetInstance()->GetFieldMonsterByIndex(i + (entry->group * 12 + 0x70));
            if (monster == NULL || monster->obj3D.unknown_2_ < 0) {
                continue;
            }
            func_ov017_0219344c(monster, 0, 0, 0, 0, 0);
        }
    }
}
