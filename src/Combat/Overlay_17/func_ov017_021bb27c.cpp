#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

struct Flags02033fdc;
struct Foo02033b58;
struct Obj02033874;
struct FlagWord020466f4;
struct ListHead02046b60;
struct Struct_ov017_021bb27c_2 {
    Object3D object; char unknown_ac_[0x15]; unsigned char state:2, rest:6;
    char unknown_c2_[0x1e]; unsigned char flags;
#if defined(jpn)
    char unknown_e1_[0x180 - 0xe1];
#else
    char unknown1_e1_[0x18c - 0xe1];
#endif
    unsigned int unknown_18c_;
};
struct PartyState021bb27c { char pad0[0xf78]; unsigned char indices[4], count; };
struct Zone021bb27c {
#if defined(jpn)
    char pad0[0x2816];
#else
    char pad0[0x27d6];
#endif
    unsigned short key;
};
struct Encounter021bb27c { unsigned short key; unsigned char active; char pad3[0xb]; unsigned char unknown_e_; };
struct Struct_ov017_021bb27c_6 { unsigned short field0; unsigned char field2; };
struct Struct_ov017_021bb27c_7 {
    char pad0[8]; unsigned short zone, mode; char unknown_c_[5]; unsigned char unknown_11_, unknown_12_;
    char unknown_13_[3]; unsigned short kind, key;
#if defined(jpn)
    char pad1a[0x78 - 0x1a];
#else
    char pad1a[0x7c - 0x1a];
#endif
    SafeAllocator allocator;
    char unknown_90_[0xa]; unsigned char unknown_9a_; char unknown_9b_[0x34]; unsigned char unknown_cf_;
    char unknown_d0_[0x2d]; unsigned char unknown_fd_; char unknown_fe_; unsigned char unknown_ff_;
    char unknown_100_[4]; unsigned char unknown_104_; char unknown_105_[3]; unsigned char field108;
    char unknown_109_[3]; unsigned char unknown_10c_; char unknown_10d_[9]; signed char actorIndex;
    char unknown_117_[0xd]; SafeAllocator unknown_124_; SafeAllocator* externalAllocator;
    char unknown_13c_[0x38]; unsigned char unknown_174_, unknown_175_;
};
struct Struct_ov017_021bb27c {
#if defined(jpn)
    char pad0[0x41fc];
#else
    char pad0[0x44ac];
#endif
    unsigned short key;
};
struct Struct_ov017_021d6c20 { int zone; Vector3fix origin, unknown_10_, destination; };
extern "C" int GameState_GetFollowCamera(char*);
extern "C" int* LinkSession_GetInstance();
extern "C" Zone021bb27c* Zone3D_GetInstance();
extern "C" void func_ov001_0215aa5c();
extern "C" void GameObject_ResumeMovement(Flags02033fdc*);
extern "C" void GameObject_StoreMotionState(Foo02033b58*, unsigned char);
extern "C" int GameObject_IsClimbingLadder(char*);
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_02053ec8(void*, int);
extern "C" void func_02053f04(void*);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" FlagWord020466f4* GlobalFlags_GetInstance();
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void func_ov017_02191fec(GameResources*, int);
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov017_02190264(GameResources*, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" void GameObject_EnableControl(void*);
extern "C" void func_020a27ac(void*);
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
extern const Struct_ov017_021d6c20 data_ov017_021d6c20[3];

static inline Struct_ov017_021bb27c_6* inline_ov017_021bb27c(GameResources* resources) {
    return (Struct_ov017_021bb27c_6*)resources->unknown_ptr_3718;
}

// USA: func_ov017_021bb27c
extern "C" ARM void func_ov017_021bb27c(Struct_ov017_021bb27c_7* self) {
    int* search;
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    ListHead02046b60* list = (ListHead02046b60*)resources->fieldTaskQueue_;
    Struct_ov017_021bb27c_6* detail = inline_ov017_021bb27c(resources);
    GameObject* leader = game->GetLeader();
    void* controlled = (void*)GameState_GetFollowCamera((char*)game);
    search = LinkSession_GetInstance();
    Zone021bb27c* zone = Zone3D_GetInstance();
    if (!TestFlags00(resources, 0x1000)) {
        func_ov001_0215aa5c();
    }
    if (self->zone == 0x7343 || self->zone == 0x7346 || self->zone == 0x7349) zone->key = self->zone;
    for (int i = 0; i < 4; i++) {
        GameObject* actor = game->GetPartyMemberByIndex(i);
        if (!actor) continue;
        GameObject_ResumeMovement((Flags02033fdc*)actor);
        GameObject_StoreMotionState((Foo02033b58*)actor, 0);
        if (!GameObject_IsClimbingLadder((char*)actor) || GameObject_GetLadderClimb(actor)->command != 2) {
                actor->obj3D_.SetAnimationByName(data_ov017_021d7d6c, 0x10);
        } else if (self->unknown_11_) {
                ((Struct_ov017_021bb27c_2*)actor)->flags &= ~1;
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
            Struct_ov017_021bb27c_2* actor = (Struct_ov017_021bb27c_2*)func_0200ff1c(game, party->indices[i]);
            if (actor) { func_02053ec8(actor, 0); func_02053f04(actor); }
        }
        if (self->unknown_12_) {
            GameState_GetLeaderIndex(game);
            for (int i = 0; i < 4; i++) {
                Struct_ov017_021bb27c_2* actor = (Struct_ov017_021bb27c_2*)func_0200ff1c(game, i);
                if (actor) {
                    actor->state &= ~1; actor->state &= ~2; actor->unknown_18c_ &= ~2;
                }
            }
        }
        if (self->actorIndex >= 0) {
            Struct_ov017_021bb27c_2* actor = (Struct_ov017_021bb27c_2*)func_0200ff1c(game, self->actorIndex);
            if (actor) {
                actor->state &= ~1; actor->state &= ~2; actor->unknown_18c_ &= ~2;
            }
        }
    }
    if (resources) {
        ClearFlags04(resources, 0x1040);
        ClearFlags00(resources, 0x10);
        ClearFlags00(resources, 0x800);
        ClearFlags00(resources, 0x4000);
    }
    void* allocation = self->unknown_124_.GetSignedAllocator();
    if (allocation) { self->unknown_124_.Destroy(); self->allocator.Free(allocation); }
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
    if (self->unknown_104_ && !detail->field2 && (!encounter->active || self->unknown_10c_) &&
        !func_02046b60(list, 10) && !(self->kind == 1 && self->unknown_cf_ == 2)) {
        func_020dc2d0(0);
    }
    self->unknown_ff_ = 1;
    for (int i = 0; i < 4; i++) {
        if (self->unknown_174_ & (1 << i)) func_ov017_02190264(resources, i);
        if (self->unknown_175_ & (1 << i)) func_ov017_0218f5a4(resources, i, 0, 0, 1);
    }
    if (leader) GameObject_EnableControl(leader);
    if (controlled) func_020a27ac(controlled);
    const Struct_ov017_021d6c20* bounds = data_ov017_021d6c20;
    for (int i = 0; i < 3; i++, bounds++) {
        if (bounds->zone != self->zone) continue;
        GameObject* actor = game->GetLeader();
        Vector3fix position = actor->obj3D_.position_;
        if (fix32abs(position.x - bounds->origin.x) > bounds->unknown_10_.x) break;
        if (fix32abs(position.y - bounds->origin.y) > bounds->unknown_10_.y) break;
        if (fix32abs(position.z - bounds->origin.z) > bounds->unknown_10_.z) break;
        func_ov017_021921fc(&bounds->destination, actor->obj3D_.rotation_.y, 0); break;
    }
    self->unknown_cf_ = 0xff; self->unknown_9a_ = 0;
    Struct_ov017_021bb27c* var24 = (Struct_ov017_021bb27c*)resources;
    if (self->key == var24->key) var24->key = 0;
    if (LinkSession_IsActive(search)) {
        if (self->mode <= 2 && self->unknown_fd_) return;
        Encounter021bb27c* encounter = (Encounter021bb27c*)GameState_GetZoneTransition(game);
        if (encounter->active && self->field108) encounter->unknown_e_ = 1;
        else func_ov017_021d035c(0, GameState_GetLeaderIndex(game), self->field108);
        for (int i = 0; i < 4; i++) {
            GameObject* actor = game->GetPartyMemberByIndex(i);
            if (actor && func_02039790(actor, 0x20)) func_ov017_021bd4d0(self, i, 0, 0);
        }
    }
}
