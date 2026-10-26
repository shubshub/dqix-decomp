#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"


struct Struct_0202c1a4;
struct Struct_02048150;

struct Struct_ov017_02192700_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
};

struct Struct_ov017_02192700_3 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
};

struct Struct_ov017_02192700_4 {
    unsigned int unknown_0_;
#if defined(jpn)
    char unknown_4_[0x34e8 - 0x4];
    Struct_ov017_02192700_3* unknown_36f8_;
    char unknown_34ec_[0x3994 - 0x34ec];
#else
    char unknown1_4_[0x36f8 - 0x4];
    Struct_ov017_02192700_3* unknown_36f8_;
    char unknown_36fc_[0x3bb4 - 0x36fc];
#endif
    Struct_ov017_02192700_2* unknown_3bb4_;
};

struct Struct_ov017_02192700_5 {
    Object3D unknown_0_;
    short unknown_ac_;
    char unknown_ae_[0xb2 - 0xae];
    unsigned short unknown_b2_;
    char unknown_b4_[0xc2 - 0xb4];
    unsigned char unknown_c2_0_ : 4;
#if defined(jpn)
    char unknown1_c3_[0x180 - 0xc3];
#else
    char unknown_c3_[0x18c - 0xc3];
#endif
    unsigned int unknown_18c_;
};

extern "C" void func_ov017_0219a674(unsigned char* arg0);

struct Struct_01ff91ac_18 {
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

struct Struct_ov017_02192700 {
    char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};

extern "C" SearchStruct0202c1a4* LinkSession_GetInstance(void);
extern "C" Save0205ec34* Scenario_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
int LinkSession_IsActive(int* p);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);
extern "C" int func_ov017_02194140(Actor02192700* self, Actor02192700* other);
int GameObject_IsHidden(unsigned char* obj);
void* GameState_GetParty(GameState* state);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct* arr, int value);
extern "C" void func_ov017_0219b33c(Ctx02192700* self, Msg02192700* msg);
void InitState71WithFlag_021c316c(Struct021c316c* p, int flag);
int HasFlagBit_0218d4ec(void* obj, int bit);
int Scenario_TestFlag(int base, unsigned char* bits, int index);
int GetSignedByte0x1c8_02039860(void* obj);
extern "C" void func_ov017_0219344c(Actor02192700* actor, int a, int b, int c, int d, int e);

static inline Struct_ov017_02192700_4* inline_ov017_02192700() {
    Struct_ov017_02192700_4* var0 = (Struct_ov017_02192700_4*)GetGameResources();
    Struct_01ff91ac_18 var1;
    func_ov017_0219a674((unsigned char*)&var1);
    var1.unknown_0_ = 1;
    func_ov017_0219b33c(var0, &var1);
    return var0;
}

static inline void inline_ov017_02192700_2(Struct_01ff91ac_18* arg0) {
    func_ov017_0219a674((unsigned char*)arg0);
    arg0->unknown_0_ = 0xd;
    arg0->unknown_1_ = 0x11;
}

static inline void PostNotice(Ctx02192700* res, Actor02192700* member) {
    Msg02192700 msg;
    InitNotice(&msg);
    msg.field2 = member->obj3D.actorIndex_;
    func_ov017_0219b33c(res, &msg);
}

// USA: func_ov017_02192700
extern "C" ARM void func_ov017_02192700(Struct_ov017_02192700_4* arg0) {
    if ((TestFlags00((GameResources*)(&arg0->unknown_0_), 0x20) != 0 && g_keyManager.TestKeysHeld(1) != 0) ||
        TestFlags00((GameResources*)(&arg0->unknown_0_), 0x2000) != 0) {
        return;
    }
    GameState* game = GameState::GetInstance();
    SearchStruct0202c1a4* search = LinkSession_GetInstance();
    Save0205ec34* save = Scenario_GetInstance();
    Actor02192700* leader = (Actor02192700*)game->GetLeader();
    if (leader == NULL) {
        return;
    }
    unsigned short leaderMap = leader->obj3D.GetField06();
    ZoneRecords_GetInstance();
    Entry02192700* entry = ctx->entry;
    if (LinkSession_IsActive((int*)search)) {
        for (int i = 0; i <= 3; i++) {
            Actor02192700* member = (Actor02192700*)game->GetPartyMemberByIndex(i);
            if (member == NULL || member == leader) {
                continue;
            }
            if (var4 != var7->unknown_0_.GetField06()) {
                continue;
            }
            if ((var7->unknown_18c_ & 1) && var7->unknown_0_.GetInheritedAlpha() > 0) {
                if (!func_ov017_02194140(var3, var7)) {
                    continue;
                }
                GameState* state = GameState::GetInstance();
                Actor02192700* other = (Actor02192700*)state->GetPartyMemberByIndex(member->obj3D.actorIndex_);
                if (other->obj3D.GetField06() != member->obj3D.GetField06()) {
                    continue;
                }
                if (var9->unknown_0_.GetInheritedAlpha() <= 0) {
                    continue;
                }
                if (var9->unknown_0_.GetAlphaScaleFactor() <= 0) {
                    continue;
                }
                if (!var9->unknown_0_.IsVisible()) {
                    continue;
                }
                if (GameObject_IsHidden((unsigned char*)other)) {
                    continue;
                }
                ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GameState_GetParty(state);
                if (party == NULL) {
                    continue;
                }
                if (ArrayContainsByte_02086ef0(party, member->obj3D.actorIndex_)) {
                    continue;
                }
                Ctx02192700* res = PostFound();
                if (res->state->busy == 0) {
                    InitState71WithFlag_021c316c(res->state, member->obj3D.actorIndex_ & 0xff);
                }
                continue;
            }
            if (HasFlagBit_0218d4ec(ctx, member->obj3D.actorIndex_) &&
                Scenario_TestFlag((int)save, save->flags, 0x799) &&
                func_ov017_02194140(leader, member)) {
                PostNotice((Ctx02192700*)GetGameResources(), member);
            }
            if (func_02039860(var7) >= 0) {
                continue;
            }
            if (!var7->unknown_0_.IsVisible()) {
                continue;
            }
            int id = member->obj3D.actorIndex_;
            if (func_ov017_02194140(leader, member)) {
                if (!(leader->nearMask & (1 << id))) {
                    leader->nearMask |= 1 << id;
                    leader->fieldb2 = 0;
                }
            } else {
                var3->unknown_c2_0_ &= ~(1 << var12);
            }
        }
    }
    if (!LinkSession_IsActive((int*)search) || !LinkSession_GetOwnSlot(search)) {
        for (int i = 0x70; i <= 0x9f; i++) {
            Actor02192700* monster = (Actor02192700*)GameState::GetInstance()->GetFieldMonsterByIndex(i);
            if (monster == NULL || monster->obj3D.unknown_2_ < 0) {
                continue;
            }
            Vector3i var15 = var14->unknown_0_.position_;
            var15.y -= var14->unknown_ac_;
            if (var15.y < -0x1e000) {
                var15.y = 0x1e000;
            }
            var14->unknown_0_.position_ = var15;
            if (var14->unknown_0_.GetField06() == var3->unknown_0_.GetField06()) {
                func_ov017_0219344c(var14, 0, 0, 0, 0, 0);
            }
        }
    } else if (entry != NULL) {
        for (int i = 0; i <= 12; i++) {
            Actor02192700* monster = (Actor02192700*)GameState::GetInstance()->GetFieldMonsterByIndex(i + (entry->group * 12 + 0x70));
            if (monster == NULL || monster->obj3D.unknown_2_ < 0) {
                continue;
            }
            func_ov017_0219344c(var17, 0, 0, 0, 0, 0);
        }
    }
}
