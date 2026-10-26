#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

struct Struct_02033fdc;
struct Struct_02033b58;
struct Struct_02033834;
struct Struct_02038598_4;
struct Struct_02038598_5;
struct Struct_ov017_021bb27c_2 {
    Object3D unknown_0_; char unknown_ac_[0x15]; unsigned char unknown_c1_0_:2, unknown_c1_2_:6;
    char unknown_c2_[0x1e]; unsigned char unknown_e0_;
#if defined(jpn)
    char unknown_e1_[0x180 - 0xe1];
#else
    char unknown1_e1_[0x18c - 0xe1];
#endif
    unsigned int unknown_18c_;
};
struct Struct_ov017_021bb27c_3 { char unknown_0_[0xf78]; unsigned char unknown_f78_[4], unknown_f7c_; };
struct Struct_ov017_021bb27c_4 {
#if defined(jpn)
    char unknown_0_[0x2816];
#else
    char unknown1_0_[0x27d6];
#endif
    unsigned short unknown_27d6_;
};
struct Struct_ov017_021bb27c_5 { unsigned short unknown_0_; unsigned char unknown_2_; char unknown_3_[0xb]; unsigned char unknown_e_; };
struct Struct_ov017_021bb27c_6 { unsigned short unknown_0_; unsigned char unknown_2_; };
struct Struct_ov017_021bb27c_7 {
    char unknown_0_[8]; unsigned short unknown_8_, unknown_a_; char unknown_c_[5]; unsigned char unknown_11_, unknown_12_;
    char unknown_13_[3]; unsigned short unknown_16_, unknown_18_;
#if defined(jpn)
    char unknown_1a_[0x78 - 0x1a];
#else
    char unknown1_1a_[0x7c - 0x1a];
#endif
    SafeAllocator unknown_7c_;
    char unknown_90_[0xa]; unsigned char unknown_9a_; char unknown_9b_[0x34]; unsigned char unknown_cf_;
    char unknown_d0_[0x2d]; unsigned char unknown_fd_; char unknown_fe_; unsigned char unknown_ff_;
    char unknown_100_[4]; unsigned char unknown_104_; char unknown_105_[3]; unsigned char unknown_108_;
    char unknown_109_[3]; unsigned char unknown_10c_; char unknown_10d_[9]; signed char unknown_116_;
    char unknown_117_[0xd]; SafeAllocator unknown_124_; SafeAllocator* unknown_138_;
    char unknown_13c_[0x38]; unsigned char unknown_174_, unknown_175_;
};
struct Struct_ov017_021bb27c {
#if defined(jpn)
    char unknown_0_[0x41fc];
#else
    char unknown1_0_[0x44ac];
#endif
    unsigned short unknown_44ac_;
};
struct Bounds021bb27c { int zone; Vector3fix origin, extent, destination; };
int GameState_GetFollowCamera(char*);
extern "C" int* LinkSession_GetInstance();
extern "C" Zone021bb27c* Zone3D_GetInstance();
void DestroyActiveAllocators_0215aa5c();
void GameObject_ResumeMovement(Flags02033fdc*);
void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
int GameObject_IsClimbingLadder(char*);
void GameObject_SnapFacing(Obj02033874*, int);
int LinkSession_IsActive(int*);
void SetField0x158_02053ec8(void*, int);
void ResetTransformState02053f04(void*);
int GameState_GetLeaderIndex(GameState*);
void AllocatorUnion_Free(AllocatorUnion*, void*);
FlagWord020466f4* GlobalFlags_GetInstance();
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void func_ov017_02191fec(GameResources*, int);
void* GameState_GetZoneTransition(GameState*);
int ListContainsId(ListHead02046b60*, int);
void SetCombatModeFromCase020dc2d0(int);
extern "C" void func_ov017_02190264(GameResources*, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
void GameObject_EnableControl(void*);
void SetField0x23cTrue_020a27ac(void*);
extern "C" void func_ov017_021921fc(const Vector3fix*, int, int);
extern "C" void func_ov017_021d035c(unsigned char, unsigned char, unsigned char);
extern "C" int func_02039790(void*, int);
extern "C" void func_ov017_021bd4d0(Struct_ov017_021bb27c_7*, unsigned char, int, int);
#if defined(jpn)
#define data_ov017_021d7d6c data_ov017_021d8544
#define data_ov017_021d7d72 data_ov017_021d854a
#define data_ov017_021d6c20 data_ov017_021d7018
#endif
extern const char data_ov017_021d7d6c[], data_ov017_021d7d72[];
extern AllocatorUnion g_mainAllocator;
extern const Bounds021bb27c data_ov017_021d6c20[3];

static inline Struct_ov017_021bb27c_6* inline_ov017_021bb27c(GameResources* arg0) {
    return (Struct_ov017_021bb27c_6*)arg0->unknown_ptr_3718;
}

// USA: func_ov017_021bb27c
extern "C" ARM void func_ov017_021bb27c(Event021bb27c* self) {
    int* search;
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
    Detail021bb27c* detail = GetEncounterDetail(resources);
    GameObject* leader = game->GetLeader();
    void* controlled = (void*)GameState_GetFollowCamera((char*)game);
    search = LinkSession_GetInstance();
    Zone021bb27c* zone = Zone3D_GetInstance();
    if (!TestFlags00(resources, 0x1000)) {
        DestroyActiveAllocators_0215aa5c();
    }
    if (self->zone == 0x7343 || self->zone == 0x7346 || self->zone == 0x7349) zone->key = self->zone;
    for (int i = 0; i < 4; i++) {
        GameObject* actor = game->GetPartyMemberByIndex(i);
        if (!actor) continue;
        GameObject_ResumeMovement((Flags02033fdc*)actor);
        GameObject_StoreMotionState((Foo02033b58*)actor, 0);
        if (!GameObject_IsClimbingLadder((char*)actor) || GameObject_GetLadderClimb(actor)->command != 2) {
                actor->obj3D_.SetAnimationByName(data_ov017_021d7d6c, 0x10);
        } else if (self->resetActor) {
                ((Actor021bb27c*)actor)->flags &= ~1;
                actor->obj3D_.DisableFlag(0x1180);
                LadderClimb_Reset(GameObject_GetLadderClimb(actor));
                actor->obj3D_.SetAnimationByName(data_ov017_021d7d6c, 0x10);
        } else actor->obj3D_.SetAnimationByName(data_ov017_021d7d72, 0);
        GameObject_SnapFacing((Obj02033874*)actor, actor->obj3D_.rotation_.y);
        actor->obj3D_.DisableFlag(0x10);
    }
    if (LinkSession_IsActive(search)) {
        PartyState021bb27c* party = (PartyState021bb27c*)GameState_GetParty(game);
        for (int i = 0; i < party->count; i++) {
            Actor021bb27c* actor = (Actor021bb27c*)GetCombatantWithFlag0x100_0200ff1c(game, party->indices[i]);
            if (actor) { SetField0x158_02053ec8(actor, 0); ResetTransformState02053f04(actor); }
        }
        if (self->resetAll) {
            GameState_GetLeaderIndex(game);
            for (int i = 0; i < 4; i++) {
                Actor021bb27c* actor = (Actor021bb27c*)GetCombatantWithFlag0x100_0200ff1c(game, i);
                if (actor) {
                    actor->state &= ~1; actor->state &= ~2; actor->field18c &= ~2;
                }
            }
        }
        if (arg0->unknown_116_ >= 0) {
            Struct_ov017_021bb27c_2* var15 = (Struct_ov017_021bb27c_2*)func_0200ff1c(var1, arg0->unknown_116_);
            if (var15) {
                var15->unknown_c1_0_ &= ~1; var15->unknown_c1_0_ &= ~2; var15->unknown_18c_ &= ~2;
            }
        }
    }
    if (var2) {
        ClearFlags04(var2, 0x1040);
        ClearFlags00(var2, 0x10);
        ClearFlags00(var2, 0x800);
        ClearFlags00(var2, 0x4000);
    }
    void* allocation = self->nestedAllocator.GetSignedAllocator();
    if (allocation) { self->nestedAllocator.Destroy(); self->allocator.Free(allocation); }
    if (!TestFlags00(resources, 0x1000)) {
        allocation = self->allocator.GetSignedAllocator();
        if (allocation) { self->allocator.Destroy(); AllocatorUnion_Free(&g_mainAllocator, allocation); }
    }
    if (self->externalAllocator) {
        allocation = self->externalAllocator->GetSignedAllocator();
        if (allocation) { self->externalAllocator->Destroy(); AllocatorUnion_Free(&g_mainAllocator, allocation); }
        self->externalAllocator = 0;
    }
    FlagWord_ClearBits(GlobalFlags_GetInstance(), 0x20000);
    for (int i = 0; i < 4; i++) func_ov017_02191fec(resources, i);
    FlagWord_ClearBits(GlobalFlags_GetInstance(), 0x400f);
    Encounter021bb27c* encounter = (Encounter021bb27c*)GameState_GetZoneTransition(game);
    if (self->field104 && !detail->field2 && (!encounter->active || self->field10c) &&
        !ListContainsId(list, 10) && !(self->kind == 1 && self->fieldcf == 2)) {
        SetCombatModeFromCase020dc2d0(0);
    }
    arg0->unknown_ff_ = 1;
    for (int var19 = 0; var19 < 4; var19++) {
        if (arg0->unknown_174_ & (1 << var19)) func_ov017_02190264(var2, var19);
        if (arg0->unknown_175_ & (1 << var19)) func_ov017_0218f5a4(var2, var19, 0, 0, 1);
    }
    if (leader) GameObject_EnableControl(leader);
    if (controlled) SetField0x23cTrue_020a27ac(controlled);
    const Bounds021bb27c* bounds = data_ov017_021d6c20;
    for (int i = 0; i < 3; i++, bounds++) {
        if (bounds->zone != self->zone) continue;
        GameObject* actor = game->GetLeader();
        Vector3fix position = actor->obj3D_.position_;
        if (fix32abs(position.x - bounds->origin.x) > bounds->extent.x) break;
        if (fix32abs(position.y - bounds->origin.y) > bounds->extent.y) break;
        if (fix32abs(position.z - bounds->origin.z) > bounds->extent.z) break;
        func_ov017_021921fc(&bounds->destination, actor->obj3D_.rotation_.y, 0); break;
    }
    self->fieldcf = 0xff; self->field9a = 0;
    ResourceKey021bb27c* resourceKey = (ResourceKey021bb27c*)resources;
    if (self->key == resourceKey->key) resourceKey->key = 0;
    if (LinkSession_IsActive(search)) {
        if (self->mode <= 2 && self->fieldfd) return;
        Encounter021bb27c* encounter = (Encounter021bb27c*)GameState_GetZoneTransition(game);
        if (encounter->active && self->field108) encounter->fieldE = 1;
        else EnqueueEventTag150_021d035c(0, GameState_GetLeaderIndex(game), self->field108);
        for (int i = 0; i < 4; i++) {
            GameObject* actor = game->GetPartyMemberByIndex(i);
            if (actor && GetByteFieldMasked0x1ce_02039790(actor, 0x20)) func_ov017_021bd4d0(self, i, 0, 0);
        }
    }
}
