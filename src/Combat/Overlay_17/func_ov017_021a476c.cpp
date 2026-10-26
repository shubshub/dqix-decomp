#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Graphics/Vector.h"
#include "World/ZoneFeatures.h"
#include "Resource/Brightness.h"

struct Struct_0203dce4_2;
struct Struct_0203e0a0;
struct Struct_0203de84;
struct Struct_0203de84_2;
struct Struct_0203402c;
struct Struct_ov009_0218aa28 {
    int unknown_0_, unknown_4_, unknown_8_;
};

#if defined(jpn)
enum { Enum_ov017_021a476c_22308 = 0x54c4 };
#else
enum { Enum_ov017_021a476c_22308 = 0x5724 };
#endif

struct Struct_ov017_021a476c_8 {
    unsigned char unknown_0_;
};

struct Struct_ov017_021a476c_9 {
#if defined(jpn)
    char unknown_0_[0x34ec];
    void* unknown_36fc_;
    char unknown_34f0_[0x416c - 0x34f0];
    Struct_ov017_021a476c_8* unknown_441c_;
    char unknown_4170_[0x41e1 - 0x4170];
#else
    char unknown1_0_[0x36fc];
    void* unknown_36fc_;
    char unknown_3700_[0x441c - 0x3700];
    Struct_ov017_021a476c_8* unknown_441c_;
    char unknown_4420_[0x4491 - 0x4420];
#endif
    unsigned char unknown_4491_;
};

struct Struct_ov017_021a476c_10 {
    Object3D unknown_0_;
#if defined(jpn)
    char unknown_ac_[0x180 - 0xac];
    unsigned int unknown_18c_;
    char unknown_184_[0x1a6 - 0x184];
#else
    char unknown1_ac_[0x18c - 0xac];
    unsigned int unknown_18c_;
    char unknown_190_[0x1b2 - 0x190];
#endif
    unsigned short unknown_1b2_;
};

struct Struct_ov017_021a476c {
    char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 1;
};

struct Struct_ov017_021a476c_2 {
    unsigned short unknown_0_;
    char unknown_2_[0x8 - 0x2];
    Struct_ov017_021a476c* unknown_8_;
};

struct Struct_ov017_021a476c_3 {
    unsigned int unknown_0_;
};

struct Struct_ov017_021a476c_4 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
};

struct Struct_ov017_021a476c_5 {
    char unknown_0_[0xa];
    unsigned char unknown_a_0_ : 3;
    unsigned char unknown_a_3_ : 3;
    char unknown_b_[0x10 - 0xb];
    Vector3fix unknown_10_;
};

struct Struct_ov017_021a476c_6 {
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

struct Struct_ov017_021a476c_7 {
    char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};

signed char data_ov017_021d76d8 = -1;
short data_ov017_021d76da = -1;
unsigned short data_ov017_021d83a8;

void* GetGlobalPtr021075f4_0203cf4c(void);
int MessageSystem_GetInstance(void);
extern "C" Work021a476c* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
int FieldTaskQueue_IsEmpty(void** obj);
extern "C" int func_ov017_021a4e88(int checkKind, unsigned short* outId);
int LinkSession_IsActive(int* obj);
Entry021a476c* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4* list, int id);
Data021a476c* GetField0x8_02040528(int* obj);
Info021a476c* GetField0xc02040538(S02040538* p);
unsigned char GameObject_IsClimbingLadder(char* obj);
int GameObject_IsGesturing(signed char* obj);
int GameObject_IsSinking(BitField0203402c* p);
void InitObj0219a674(unsigned char* self);
void SelectVec3FromSources020406f8(Vec3_020406f8* out, Node020406f8* n);
short GetAngleDeltaBetween_021a4700(Vec3* p0, int baseAngle, Vec3* p2);
int GetDeltaAndForward_0218daa8(void* obj, Vec3* otherVec, int c, int d, unsigned char e);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_0219b33c(Ctx021a476c* self, Msg021a476c* msg);
int GetSignedByte0x1c8_02039860(void* obj);
unsigned int IsFlag0x1ceBit0x10Set_02039de8(unsigned char* obj);
extern "C" Save021a476c* Scenario_GetInstance(void);
int HasFlagBit_0218d4ec(void* obj, int bit);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);

// USA: func_ov017_021a476c
extern "C" ARM void func_ov017_021a476c(Ctx021a476c* self) {
    Msg021a476c msg;
    Msg021a476c near;
    Vector3fix pos;
    GameState* game = GameState::GetInstance();
    void* list = GetGlobalPtr021075f4_0203cf4c();
    game->GetCamera();
    MessageSystem_GetInstance();
    Actor021a476c* player = (Actor021a476c*)game->GetLeader();
    GameResources* res = GetGameResources();
    Work021a476c* work = Zone3D_GetInstance();
    void* session = LinkSession_GetInstance();

    data_ov017_021d76da = -1;
    data_ov017_021d83a8 = 0;
    data_ov017_021d76d8 = -1;
    *(int*)((char*)var3 + Enum_ov017_021a476c_22308) = -1;

    if (self->active == 0 && !FieldTaskQueue_IsEmpty((void**)self->list)) {
        func_ov017_021a4e88(0, &data_ov017_021d83a8);
        return;
    }
    if (LinkSession_IsActive((int*)session) && self->holder->busy != 0) {
        return;
    }
    data_ov017_021d76da = func_ov017_021a4e88(1, &data_ov017_021d83a8);
    if (data_ov017_021d76da >= 0) {
        Struct_ov017_021a476c_3* var9 = func_0203dce4((Struct_0203dce4_2*)var4, data_ov017_021d76da);
        if (var9 != NULL) {
            Struct_ov017_021a476c_4* var10 = func_02040528((int*)var9);
            Struct_ov017_021a476c_5* var11 = func_02040538((Struct_0203e0a0*)var9);
            if (var9->unknown_0_ & 0x200) {
                return;
            }
            if (GameObject_IsClimbingLadder((char*)player) != 0 || res->unknown_4080 != 0) {
                return;
            }
            if (IsScreenFullyFaded(res, false)) {
                return;
            }
            if (GameObject_IsGesturing((signed char*)player)) {
                return;
            }
            if (GameObject_IsSinking((BitField0203402c*)player)) {
                return;
            }
            if (var10 != NULL && var11 != NULL) {
                int var12 = 0x1922;
                func_ov017_0219a674((unsigned char*)&var0);
                var0.unknown_0_ = 0;
                func_020406f8((Struct_0203de84*)&var2, (Struct_0203de84_2*)var9);
                var0.unknown_10_ = fix32abs(func_ov017_021a4700((Struct_ov009_0218aa28*)&var5->unknown_0_.position_, (short)var5->unknown_0_.rotation_.y, (Struct_ov009_0218aa28*)&var2));
                if (var7->unknown_0_ == 0x1901 && var10->unknown_0_ == 0x6a) {
                    var12 = 0x25b3;
                    func_ov017_0218daa8(arg0, (Struct_ov009_0218aa28*)&var11->unknown_10_, 0xccc, -0x199, 0);
                }
                if (var0.unknown_10_ < var12) {
                    int var13 = 0;
                    int var14 = 0;
                    int var15 = var11->unknown_a_3_;
                    if (var15 == 0) {
                        if (var10->unknown_2_ == 1) {
                            var0.unknown_1_ = 3;
                            var13 = 1;
                        }
                    } else if (mode == 1) {
                        msg.field1 = 3;
                        set = 1;
                    } else if (mode == 2) {
                        msg.field1 = 4;
                        set = 1;
                    } else if (mode == 3) {
                        if (LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
                            msg.field1 = 0xf;
                        } else {
                            var0.unknown_1_ = 2;
                        }
                    } else if (var15 == 4) {
                        var14 = 1;
                    }
                    if (!var13) {
                        var0.unknown_2_ = data_ov017_021d76da;
                    }
                    if (!var14) {
                        func_ov017_0219b33c(arg0, &var0);
                    }
                }
            }
        }
    } else {
        Actor021a476c* mem;
        Save021a476c* save;
        int sum;
        int ay;
        int az;
        int ax;
        Actor021a476c* member;
        int i;
        int dy;
        int dz;
        int dx;
        int best;
        int found;
        Actor021a476c* leader;
        GameState* game2;
        Work021a476c* work2;
        void* list2;
        GameResources* res2;
        if (!LinkSession_IsActive((int*)LinkSession_GetInstance())) {
            goto none;
        }
        res2 = GetGameResources();
        list2 = res2->fieldTaskQueue_;
        work2 = Zone3D_GetInstance();
        if (IsScreenFullyFaded(res2, false)) {
            found = -1;
            goto done;
        }
        if (var31->unknown_8_->unknown_c_4_) {
            var28 = -1;
            goto done;
        }
        if (FieldTaskQueue_IsEmpty((void**)list2) == 0) {
            found = -1;
            goto done;
        }
        game2 = GameState::GetInstance();
        leader = (Actor021a476c*)game2->GetLeader();
        found = -1;
        best = -1;
        dx = 0;
        dz = 0;
        dy = 0;
        for (i = 0; i <= 3; i++) {
            member = (Actor021a476c*)game2->GetPartyMemberByIndex(i);
            if (member == NULL || member == leader) {
                continue;
            }
            if (var29->unknown_0_.GetField06() != var22->unknown_0_.GetField06()) {
                continue;
            }
            if (var22->unknown_0_.unknown_0_ & 0x1000) {
                continue;
            }
            if (var22->unknown_18c_ & 1) {
                continue;
            }
            if (func_02039860(var22) >= 0) {
                continue;
            }
            if (func_02039de8((unsigned char*)var22)) {
                continue;
            }
            if (!var22->unknown_0_.IsVisible()) {
                continue;
            }
            WrappedVector3fix memberPos;
            WrappedVector3fix leaderPos;
            leaderPos = *(WrappedVector3fix*)&leader->obj3D.position_;
            memberPos = *(WrappedVector3fix*)&member->obj3D.position_;
            ax = fix32abs(leaderPos.vec.x - memberPos.vec.x);
            az = fix32abs(leaderPos.vec.z - memberPos.vec.z);
            ay = fix32abs(leaderPos.vec.y - memberPos.vec.y);
            sum = ax + az;
            if (best == -1 || sum < best) {
                found = member->obj3D.actorIndex_;
                best = sum;
                dx = ax;
                dz = az;
                dy = ay;
            }
        }
        if (var26 < 0x1800 && var25 < 0x1800 && var24 < 0xb33) {
            goto done;
        }
    none:
        var28 = -1;
    done:
        data_ov017_021d76d8 = var28;
        if (data_ov017_021d76d8 >= 0) {
            mem = (Actor021a476c*)game->GetPartyMemberByIndex(data_ov017_021d76d8);
            save = Scenario_GetInstance();
            if (mem->field1b2 == 0) {
                if (!HasFlagBit_0218d4ec(self, data_ov017_021d76d8) ||
                    !Scenario_TestFlag((int)save, save->flags, 0x799)) {
                    InitObj0219a674((unsigned char*)&near);
                    near.kind = 0xa;
                    near.angle = fix32abs(GetAngleDeltaBetween_021a4700((Vec3*)&player->obj3D.position_, (short)player->obj3D.rotation_.y, (Vec3*)&mem->obj3D.position_));
                    if (near.angle < 0x1922) {
                        near.field2 = data_ov017_021d76d8;
                        func_ov017_0219b33c(self, &near);
                    }
                }
            }
        }
    }
    arg0->unknown_4491_ = 0;
}
