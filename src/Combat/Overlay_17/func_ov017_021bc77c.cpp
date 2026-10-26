#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021bc77c_29156 = 0x6fa4, Enum_ov017_021bc77c_29168 = 0x6fb0, Enum_ov017_021bc77c_29172 = 0x6fb4, Enum_ov017_021bc77c_14104 = 0x3508, Enum_ov017_021bc77c_17580 = 0x41fc, Enum_ov017_021bc77c_268 = 0x108, Enum_ov017_021bc77c_276 = 0x110, Enum_ov017_021bc77c_17122 = 0x40c2 };
#else
enum { Enum_ov017_021bc77c_29156 = 0x71e4, Enum_ov017_021bc77c_29168 = 0x71f0, Enum_ov017_021bc77c_29172 = 0x71f4, Enum_ov017_021bc77c_14104 = 0x3718, Enum_ov017_021bc77c_17580 = 0x44ac, Enum_ov017_021bc77c_268 = 0x10c, Enum_ov017_021bc77c_276 = 0x114, Enum_ov017_021bc77c_17122 = 0x42e2 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/LightingManager.h"
#include "Resource/Brightness.h"



enum { Enum_ov017_021bc77c_m1 = -1 };

struct AllocatorUnion;

extern "C" void* LinkSession_GetInstance();
void* GameState_GetFollowCamera(char*);
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" unsigned char* Scenario_GetInstance();
unsigned int* GlobalFlags_GetInstance();
extern "C" void Zone3D_RestoreElementVisibility(unsigned short* p, int v);
void ClearCombatantSlot_0200fd48(GameState* gs, int idx);
Object3D* GetField4334_021bdbc0(unsigned char*);
int Zone3D_IsFieldTaskPending(unsigned char*, int);
void InitContext020e1154(void*);
void FollowCamera_EnableFollow(void* p);
void ApplyVecFromField0x21e_020a2744(char*);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_ov017_0219b624(void* res);
void AllocatorUnion_Free(AllocatorUnion* a, void* p);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* a, unsigned int size);
extern "C" void func_ov017_021a2fa0(void* res);
int LinkSession_IsActive(int*);
struct FieldBlock63d6_11590;
int GameState_HasMovieId(FieldBlock63d6_11590*);
void SetHalfword0x63d8_020115f4(void*, unsigned short);
extern "C" void func_ov017_021bb27c(void* self);
void ClearFields_021bb0c4(unsigned char*);
int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void* node);
extern "C" int LinkSession_IsGuest(void* p);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" unsigned char* func_ov017_021b8478(unsigned char* p);
extern "C" void func_02046a8c(void* a, unsigned char* b);
int GetState0209ca68(char*);
extern "C" void func_0209c530(void* p);
unsigned char* GameState_GetZoneTransition(GameState* gs);
void* GetData02153660_020e3808();
int GameState_GetProtagonistIndex(GameState* gs);
struct TagValueEntry020e385c;
void SetOrClearEntryBitAndNotify020e3a50(TagValueEntry020e385c*, int, int, int);
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
struct Fields020407b4;
void SetFields0x44(Fields020407b4*, int, int, int);
struct Obj02033874;
void GameObject_SnapFacing(Obj02033874*, int);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
void SetBrightness(GameResources*, int, int);
extern "C" int func_0209cd50(unsigned short arg0);
struct Struct_0209c3b4_2;
extern "C" void func_0209c3b4(Struct_0209c3b4_2*, int);
extern "C" void func_ov017_021bd704(void* arg0);
void SetMainBrightness(GameResources*, int, int);
void EnqueueEventTag107_021cdd70(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f, unsigned char g);
extern "C" void func_ov017_021b6728(void* res, int a, int b);
void GameObject_EnableControl(void*);
void GameObject_ApplyPendingControl(void*);
extern "C" int func_ov017_0219bddc(unsigned char* p);
extern "C" void func_ov017_0219bf04(int a, int b);
void SetByte1True_021c178c(unsigned char* p);
extern "C" void func_ov017_021b8bb0(unsigned short id);
void InitStruct02070378(char*);
void SetFlagBytes02017d68(void* p);
int PeekInputLogA_020a1eb0();
#if defined(jpn)
extern "C" void func_ov001_02156b20(void*);
#else
extern "C" void func_ov000_02156b20(GameObject*);
#endif
extern "C" void func_ov017_021a01bc(unsigned char*);
extern "C" void func_0209c2e0(void* arg0, int arg1, int arg2);
extern "C" void func_ov017_0219bcac(unsigned char arg0);

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer[];

struct Struct_ov017_021bc77c {
    int unknown_0_[0x11];
    unsigned short unknown_44_;
    short unknown_46_;
    unsigned char unknown_48_[0x20];
};

struct Struct_ov017_021bc77c_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    unsigned char unknown_c_[0x28];
};

struct Struct_ov017_021bc77c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[6];
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    Struct_ov017_021bc77c unknown_c_;
    #if defined(jpn)
    unsigned char unknown_74_[0x18];
#else
    unsigned char unknown1_74_[0x1c];
#endif
    int unknown_90_;
    unsigned char unknown_94_[6];
    unsigned char unknown_9a_;
    unsigned char unknown_9b_;
    unsigned char unknown_9c_;
    unsigned char unknown_9d_[3];
    signed char unknown_a0_;
    unsigned char unknown_a1_;
    unsigned short unknown_a2_;
    unsigned char unknown_a4_[0x18];
    Vector3i unknown_bc_;
    short unknown_c8_;
    unsigned char unknown_ca_[2];
    unsigned char unknown_cc_;
    unsigned char unknown_cd_[2];
    unsigned char unknown_cf_;
    unsigned char unknown_d0_[0x2d];
    unsigned char unknown_fd_;
    unsigned char unknown_fe_[0xd];
    unsigned char unknown_10b_;
    unsigned char unknown_10c_[8];
    unsigned short unknown_114_;
    unsigned char unknown_116_[4];
    unsigned short unknown_11a_;
    unsigned char unknown_11c_[0x1c];
    SafeAllocator* unknown_138_;
    unsigned char unknown_13c_;
    unsigned char unknown_13d_[3];
    unsigned short unknown_140_;
    unsigned short unknown_142_;
    unsigned char unknown_144_;
    unsigned char unknown_145_;
    unsigned short unknown_146_;
    unsigned short unknown_148_;
    unsigned char unknown_14a_[2];
    unsigned short unknown_14c_;
    unsigned short unknown_14e_;
    unsigned char unknown_150_[0x34];
    unsigned short unknown_184_;
};

struct Struct_ov017_021bc77c_4 {
    #if defined(jpn)
    unsigned char unknown_0_[0x420];
#else
    unsigned char unknown1_0_[0x630];
#endif
    int unknown_630_;
    unsigned char unknown_634_[0xd8];
    unsigned char* unknown_70c_;
    unsigned char* unknown_710_;
    unsigned char unknown_714_[4];
    unsigned char* unknown_718_;
    unsigned char unknown_71c_[0x18];
    unsigned char* unknown_734_;
    #if defined(jpn)
    unsigned char unknown_528_[0x410];
#else
    unsigned char unknown_738_[0x420];
#endif
    unsigned char* unknown_b58_;
};

struct Struct_01ff91ac_25 {
    unsigned char unknown_0_[0xc4];
    SafeAllocator unknown_c4_;
};

struct Struct_ov017_021bc77c_5 {
    unsigned char unknown_0_[0x3000];
    Struct_ov017_021bc77c_4 unknown_3000_;
};

#define RES_PTR(res, off) (((Struct_ov017_021bc77c_5*)(res))->unknown_3000_.unknown_##off##_)

static inline SafeAllocator* inline_ov017_021bc77c(GameResources* arg0, int arg1) {
    return &arg0->allocator_array_38[arg1];
}

static inline void InitAllocator_021bc77c(SafeAllocator* sa, unsigned int size) {
    sa->CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, size), size);
}

static inline Vector3i inline_ov017_021bc77c_2(GameState* arg0) {
    return *(Vector3i*)((unsigned char*)arg0 + Enum_ov017_021bc77c_29156);
}

// USA: func_ov017_021bc77c
extern "C" ARM int func_ov017_021bc77c(Struct_ov017_021bc77c_3* arg0, void* arg1) {
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
        return arg0->unknown_a_;
    }
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* x34 = LinkSession_GetInstance();
    GameObject* unk = gs->GetLeader();
    GameObject* party0 = gs->GetPartyMemberByIndex(0);
    void* f28 = GameState_GetFollowCamera((char*)gs);
    unsigned short* p2;
    GameState* gs2;
    GameResources* res3;
    unsigned char* bits3;
    unsigned char* p14;
    unsigned char* p10;
    unsigned short* p = Zone3D_GetInstance();
    unsigned char* bits = Scenario_GetInstance();
    p14 = RES_PTR(res, 710);
    unsigned char* r8 = RES_PTR(res, 718);
    p10 = RES_PTR(res, b58);
    GlobalFlags_GetInstance();
    {
        Block_021bc77c blk = self->blk;
        unsigned char b9c = self->b9c;
        gs2 = GameState::GetInstance();
        GameResources* res2 = GetGameResources();
        p2 = Zone3D_GetInstance();
        LinkSession_GetInstance();
        if (!(blk.flags & 0x400)) {
            Zone3D_RestoreElementVisibility(p2, b9c);
        }
        for (int var18 = 0; var18 < 0x20; var18++) {
            GameObject* var19 = var7->GetGameObjectByIndex(var18 + 0xa0);
            if (var19 != 0) {
                var19->obj3D_.Destroy();
                func_0200fd48(var7, var18 + 0xa0);
            }
        }
        ((Struct_ov017_021bc77c_5*)var17)->unknown_3000_.unknown_630_ = 0;
        Object3D* var20 = func_ov017_021bdbc0((unsigned char*)var17);
        if (var20 != 0) {
            var20->MakeVisible();
        }
        if (Zone3D_IsFieldTaskPending((unsigned char*)p2, 1) || Zone3D_IsFieldTaskPending((unsigned char*)p2, 0)) {
            InitContext020e1154((void*)0x1388);
        }
    }
    FollowCamera_EnableFollow(f28);
    ApplyVecFromField0x21e_020a2744((char*)f28);
    if (self->blk.s46 > kInvalidId) {
        Scenario_SetFlag(bits, bits + 0x8c, self->blk.s46 + 0x38e, 1);
    }
    if (self->sa0 > kInvalidId && self->b9c) {
        Scenario_SetFlag(bits, bits + 0x8c, self->sa0 + 0xbea, 1);
    }
    if (arg0->unknown_9a_) {
        func_ov017_0219b624(var1);
    }
    if (self->alloc138) {
        SignedAllocatorHeader* h = self->alloc138->GetSignedAllocator();
        if (h) {
            self->alloc138->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, h);
        }
        arg0->unknown_138_ = 0;
    }
    if (!TestFlags00(res, 0x1000) || self->u11a == 0) {
        int size = self->i90;
        if (size) {
            SafeAllocator* sa = GetAllocator_021bc77c(res, 7);
            sa->CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, size), size);
            func_ov017_021a2fa0(res);
            self->i90 = 0;
        } else if (self->blk.flags & 4) {
            func_ov017_021a2fa0(res);
        }
    }
    if (!LinkSession_IsActive((int*)x34) && GameState_HasMovieId((FieldBlock63d6_11590*)gs)) {
        if (self->u11a) {
            SetHalfword0x63d8_020115f4(gs, self->u11a);
        }
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }
    if (arg0->unknown_11a_) {
        arg0->unknown_8_ = arg0->unknown_11a_;
        arg0->unknown_fd_ = 1;
        func_ov017_021bb0c4((unsigned char*)arg0);
        return 0;
    }
    if (*((unsigned char*)res + kResourceFlagOffset) == 0) {
        Node_021bc77c node;
        node.id = self->f8;
        if (Scenario_RunTrigger(bits, 0xb, &node)) {
            EventQuery_RunQueuedCommands(&node);
        }
        if (LinkSession_IsGuest(x34)) {
            int flag = 0;
            if (self->b13c == 2) {
                if (r8[2]) flag = 1;
            } else if (self->b13c == 1) {
                if (r8[2] && !Scenario_TestFlag((int)bits, bits + 0x8c, self->u148 + 0x38e)) {
                    if (self->u148 == 0xffff) {
                        if (self->u14c != *(unsigned short*)((unsigned char*)self + 0x18)) flag = 1;
                    } else {
                        var25 = 1;
                    }
                }
            } else if (arg0->unknown_13c_ == 0) {
                if (var14[2]) {
                    int var26 = *(int*)(func_ov017_021b8478(var14) + 0xc);
                    if (var26 != (short)arg0->unknown_146_) var25 = 1;
                }
            }
            if (flag) {
                func_02046a8c(arg, r8);
                if (GetState0209ca68((char*)g_bgmPlayer) == 2) {
                    func_0209c530(g_bgmPlayer);
                }
                ClearFlags04(var1, 4);
                ClearFlags04(var1, 0x10);
                ClearFlags04(var1, 2);
                ClearFlags00(var1, 4);
                ClearFlags00(var1, 0x800);
            }
        }
    } else {
        arg0->unknown_13c_ = 2;
    }
    unsigned char* f = GameState_GetZoneTransition(gs);
    void* tags = GetData02153660_020e3808();
    if (r8[2]) {
        SetOrClearEntryBitAndNotify020e3a50((TagValueEntry020e385c*)tags, GameState_GetProtagonistIndex(gs), 1, *(unsigned short*)((unsigned char*)self + 0x18));
    } else if (*(int*)(f + 0x20) <= 0 || f[2] == 0) {
        ResetTaggedEntryAndNotifyOverlay020e3994((TagValueEntry020e385c*)tags, 1, *(unsigned short*)((unsigned char*)self + 0x18));
    }
    if (self->bcc && self->bcf == 3) {
        SetFields0x44((Fields020407b4*)unk, 0x48cc, 0x199, -0x733);
        GameObject_SnapFacing((Obj02033874*)unk, 0);
        for (int i = 1; i < 4; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(i);
            if (m) {
                SetFields0x44((Fields020407b4*)m, 0x48cc, 0x199, -0x733);
                GameObject_SnapFacing((Obj02033874*)m, 0x3244);
                SetFlag0x1ceBit0x4_02039d48((unsigned char*)m);
            }
        }
    }
    if (f[2]) {
        SetBrightness(res, -16, 0);
    } else if (p14[2]) {
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)g_bgmPlayer, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        SetMainBrightness(res, 0, 0x28);
    } else if (r8[2]) {
        SetBrightness(res, -16, 0);
        *(unsigned short*)(r8 + 0x6c4) = self->u184;
        if (LinkSession_IsGuest(x34)) {
            self->u14e = *(int*)(func_ov017_021b8478(*(unsigned char**)((unsigned char*)res + kResourceNodeOffset)) + 0xc);
            EnqueueEventTag107_021cdd70(self->u14e, 0, 0, 0, 0, 0, 0);
            unsigned char* q = RES_PTR(res, 70c);
            if (q[2]) {
                func_02046a8c(arg, q);
            }
            return 5;
        }
    } else if (arg0->unknown_cc_) {
        if (arg0->unknown_cc_ == 1) {
            func_ov017_021b6728(var1, arg0->unknown_cf_, -1);
        }
        if (self->bcf == 2) {
            GameObject_EnableControl(unk);
            GameObject_ApplyPendingControl(unk);
        }
        SetMainBrightness(var1, 0, 0x28);
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    } else {
        int var32;
        unsigned short var33;
        {
            unsigned short* p3;
            unsigned short id = self->f8;
            void* x = LinkSession_GetInstance();
            p3 = Zone3D_GetInstance();
            bits3 = Scenario_GetInstance();
            res3 = GetGameResources();
            unsigned char* o = RES_PTR(res3, 734);
            unsigned char buf = 0;
            unsigned short cur = *p3;
            if (!LinkSession_IsGuest(x)) { ok = 0; goto checked; }
            if (self->b13c != 1) { ok = 0; goto checked; }
            if (self->u140 != cur && self->u142 != cur) { ok = 0; goto checked; }
            if (!self->b144) { ok = 0; goto checked; }
            if (Scenario_TestFlag((int)bits3, bits3 + 0x8c, self->u148 + 0x38e)) { ok = 0; goto checked; }
            unsigned short v = self->u146;
            if (v == id) { ok = 0; goto checked; }
            if (id == 0x733c || id == 0x733f || id == 0x7342 || id == 0x7345 || id == 0x7348) {
                if (v == 0x733d || v == 0x7340 || v == 0x7343 || v == 0x7346 || v == 0x7349 || v == 0x721a ||
                    v == 0x7080) {
                    ok = 0;
                    goto checked;
                }
            }
            int var41 = func_ov017_0219bddc(&var38);
            if (var41) {
                func_ov017_0219bf04(0, 1);
                var37[Enum_ov017_021bc77c_268] = 1;
            }
            unsigned char* var42 = RES_PTR(var8, b58);
            if (var42[2]) {
                if (var41) {
                    func_ov017_021c178c(var42);
                    var32 = 0;
                    goto checked;
                }
                if (arg0->unknown_14c_) {
                    *(unsigned short*)(var37 + Enum_ov017_021bc77c_276) = arg0->unknown_14c_;
                } else {
                    *(unsigned short*)(var37 + Enum_ov017_021bc77c_276) = arg0->unknown_146_;
                }
                var32 = 0;
                goto checked;
            }
            if (!var41) {
                ClearFlags00(var8, 0x10);
            }
            var32 = var41 == 0;
        }
    checked:
        if (var32) {
        if (arg0->unknown_14c_) {
            arg0->unknown_8_ = arg0->unknown_14c_;
        } else {
            arg0->unknown_8_ = arg0->unknown_146_;
        }
        func_ov017_021bb0c4((unsigned char*)arg0);
        return 0;
    } else if (LinkSession_IsActive((int*)x34) && LinkSession_IsGuest(x34) && party0 && (mapId = *p, mapId == party0->obj3D_.GetField06()) &&
               self->b13c == 0 && (short)self->u146 >= 0) {
        func_ov017_021b8bb0((short)self->u146);
    } else if (self->b9c && self->ua2 != *p) {
        InitStruct02070378((char*)f);
        f[2] = 1;
        *(unsigned short*)f = self->ua2;
        f[7] = 1;
        *(Vector3i*)(f + 0x10) = self->vbc;
        *(short*)(f + 0x1c) = self->sc8;
        SetBrightness(res, -16, 0);
    } else if (*(int*)((unsigned char*)gs + kGamePositionState) > 0) {
        InitStruct02070378((char*)f);
        f[2] = 1;
        *(unsigned short*)f = *(int*)((unsigned char*)gs + kGamePositionState);
        f[7] = 1;
        *(Vector3i*)(f + 0x10) = GetPos_021bc77c(gs);
        *(short*)(f + 0x1c) = *(int*)((unsigned char*)gs + kGamePositionY);
        *(int*)((unsigned char*)gs + kGamePositionState) = 0;
        SetBrightness(res, -16, 0);
        SetFlagBytes02017d68(Zone3D_GetInstance());
    } else {
        if (func_020a1eb0() == 1) {
#if defined(jpn)
            func_ov001_02156b20(arg0);
#else
            func_ov000_02156b20((GameObject*)arg0);
#endif
        }
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)g_bgmPlayer, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        SetByteIfDataAndCheckClear_021a01bc((unsigned char*)res);
        if (p10[2]) {
            SetBrightness(res, -16, 0);
        } else if (!self->b10b) {
            SetMainBrightness(res, 0, 0x28);
        }
        GameObject_EnableControl(unk);
        GameObject_ApplyPendingControl(unk);
        func_0209c2e0(g_bgmPlayer, 0x7f, 0);
        if (self->u114) {
            *(unsigned short*)((unsigned char*)res + kResourceHalfwordOffset) = self->u114;
            self->u114 = 0;
        }
        if (arg0->unknown_8_ == 0x6013) {
            LightingManager* var43 = LightingManager::GetInstance();
            int var44 = var0->GetTimeOfDay();
            if (var44 != var43->timeOfDayIndex_) {
                if (var11[2]) {
                    var11[9] = 1;
                }
                SetBrightness(var1, -16, 0);
                func_ov017_0219bcac(0);
            }
        }
    }
    }
    *(int*)((unsigned char*)var0 + Enum_ov017_021bc77c_29172) = 0;
    func_ov017_021bb27c(arg0);
    arg0->unknown_1_ = 1;
    return arg0->unknown_a_;
}
