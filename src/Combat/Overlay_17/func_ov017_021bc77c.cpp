#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021bc77c_29156 = 0x6fa4, Enum_ov017_021bc77c_29168 = 0x6fb0, Enum_ov017_021bc77c_29172 = 0x6fb4, kResourceNodeOffset = 0x3508, Enum_ov017_021bc77c_17580 = 0x41fc, Enum_ov017_021bc77c_268 = 0x108, Enum_ov017_021bc77c_276 = 0x110, Enum_ov017_021bc77c_17122 = 0x40c2 };
#else
enum { Enum_ov017_021bc77c_29156 = 0x71e4, Enum_ov017_021bc77c_29168 = 0x71f0, Enum_ov017_021bc77c_29172 = 0x71f4, kResourceNodeOffset = 0x3718, Enum_ov017_021bc77c_17580 = 0x44ac, Enum_ov017_021bc77c_268 = 0x10c, Enum_ov017_021bc77c_276 = 0x114, Enum_ov017_021bc77c_17122 = 0x42e2 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/LightingManager.h"
#include "Resource/Brightness.h"



enum { Enum_ov017_021bc77c_m1 = -1 };

struct AllocatorUnion;

extern "C" void* LinkSession_GetInstance();
extern "C" void* GameState_GetFollowCamera(char*);
extern "C" unsigned short* Zone3D_GetInstance();
extern "C" unsigned char* Scenario_GetInstance();
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void Zone3D_RestoreElementVisibility(unsigned short* p, int v);
extern "C" void func_0200fd48(GameState* gs, int idx);
extern "C" Object3D* func_ov017_021bdbc0(unsigned char*);
extern "C" int Zone3D_IsFieldTaskPending(unsigned char*, int);
extern "C" void func_020e1154(void*);
extern "C" void FollowCamera_EnableFollow(void* p);
extern "C" void func_020a2744(char*);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_ov017_0219b624(void* res);
extern "C" void AllocatorUnion_Free(AllocatorUnion* a, void* p);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* a, unsigned int size);
extern "C" void func_ov017_021a2fa0(void* res);
extern "C" int LinkSession_IsActive(int*);
struct FieldBlock63d6_11590;
extern "C" int GameState_HasMovieId(FieldBlock63d6_11590*);
extern "C" void func_020115f4(void*, unsigned short);
extern "C" void func_ov017_021bb27c(void* self);
extern "C" void func_ov017_021bb0c4(unsigned char*);
extern "C" int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void* node);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" unsigned char* func_ov017_021b8478(unsigned char* p);
extern "C" void func_02046a8c(void* a, unsigned char* b);
extern "C" int func_0209ca68(char*);
extern "C" void func_0209c530(void* p);
extern "C" unsigned char* GameState_GetZoneTransition(GameState* gs);
extern "C" void* func_020e3808();
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
struct TagValueEntry020e385c;
extern "C" void func_020e3a50(TagValueEntry020e385c*, int, int, int);
extern "C" void func_020e3994(TagValueEntry020e385c*, int, int);
struct Fields020407b4;
extern "C" void func_020407b4(Fields020407b4*, int, int, int);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
extern "C" void func_02039d48(unsigned char*);
void SetBrightness(GameResources*, int, int);
extern "C" int func_0209cd50(unsigned short id);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(Actor0209c3b4*, int);
extern "C" void func_ov017_021bd704(void* p);
void SetMainBrightness(GameResources*, int, int);
extern "C" void func_ov017_021cdd70(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f, unsigned char g);
extern "C" void func_ov017_021b6728(void* res, int a, int b);
extern "C" void GameObject_EnableControl(void*);
extern "C" void GameObject_ApplyPendingControl(void*);
extern "C" int func_ov017_0219bddc(unsigned char* p);
extern "C" void func_ov017_0219bf04(int a, int b);
extern "C" void func_ov017_021c178c(unsigned char* p);
extern "C" void func_ov017_021b8bb0(unsigned short id);
extern "C" void func_02070378(char*);
extern "C" void func_02017d68(void* p);
extern "C" int func_020a1eb0();
#if defined(jpn)
extern "C" void func_ov001_02156b20(void*);
#else
extern "C" void func_ov000_02156b20(GameObject*);
#endif
extern "C" void func_ov017_021a01bc(unsigned char*);
extern "C" void func_0209c2e0(void* p, int a, int b);
extern "C" void func_ov017_0219bcac(unsigned char v);

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer[];

struct Struct_ov017_021bc77c {
    int pad0[0x11];
    unsigned short flags;
    short s46;
    unsigned char unknown_48_[0x20];
};

struct Struct_ov017_021bc77c_2 {
    int a;
    int b;
    int id;
    unsigned char pad[0x28];
};

struct Struct_ov017_021bc77c_3 {
    unsigned char unk0;
    unsigned char done;
    unsigned char pad2[6];
    unsigned short f8;
    unsigned short fa;
    Struct_ov017_021bc77c blk;
    #if defined(jpn)
    unsigned char unknown_74_[0x18];
#else
    unsigned char unknown1_74_[0x1c];
#endif
    int unknown_90_;
    unsigned char unknown_94_[6];
    unsigned char unknown_9a_;
    unsigned char unknown_9b_;
    unsigned char b9c;
    unsigned char unknown_9d_[3];
    signed char sa0;
    unsigned char unknown_a1_;
    unsigned short unknown_a2_;
    unsigned char unknown_a4_[0x18];
    Vector3i vbc;
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
    unsigned short u148;
    unsigned char unknown_14a_[2];
    unsigned short unknown_14c_;
    unsigned short unknown_14e_;
    unsigned char unknown_150_[0x34];
    unsigned short unknown_184_;
};

struct Struct_ov017_021bc77c_4 {
    #if defined(jpn)
    unsigned char pad0[0x420];
#else
    unsigned char pad0[0x630];
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
    unsigned char pad0[0xc4];
    SafeAllocator alloc;
};

struct Struct_ov017_021bc77c_5 {
    unsigned char pad0[0x3000];
    Struct_ov017_021bc77c_4 sub;
};

#define RES_PTR(res, off) (((Struct_ov017_021bc77c_5*)(res))->sub.unknown_##off##_)

static inline SafeAllocator* inline_ov017_021bc77c(GameResources* r, int i) {
    return &r->allocator_array_38[i];
}

static inline void inline_01ff91ac_2(SafeAllocator* sa, unsigned int size) {
    sa->CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, size), size);
}

static inline Vector3i inline_ov017_021bc77c_2(GameState* gs) {
    return *(Vector3i*)((unsigned char*)gs + Enum_ov017_021bc77c_29156);
}

// USA: func_ov017_021bc77c
extern "C" ARM int func_ov017_021bc77c(Struct_ov017_021bc77c_3* self, void* arg) {
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
        return self->fa;
    }
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* x34 = LinkSession_GetInstance();
    GameObject* unk = gs->GetLeader();
    GameObject* party0 = gs->GetPartyMemberByIndex(0);
    void* f28 = GameState_GetFollowCamera((char*)gs);
    unsigned short* p2;
    GameState* gs2;
    GameResources* var8;
    unsigned char* bits3;
    unsigned char* var10;
    unsigned char* p10;
    unsigned short* p = Zone3D_GetInstance();
    unsigned char* bits = Scenario_GetInstance();
    var10 = RES_PTR(res, 710);
    unsigned char* r8 = RES_PTR(res, 718);
    p10 = RES_PTR(res, b58);
    GlobalFlags_GetInstance();
    {
        Struct_ov017_021bc77c blk = self->blk;
        unsigned char b9c = self->b9c;
        gs2 = GameState::GetInstance();
        GameResources* res2 = GetGameResources();
        p2 = Zone3D_GetInstance();
        LinkSession_GetInstance();
        if (!(blk.flags & 0x400)) {
            Zone3D_RestoreElementVisibility(p2, b9c);
        }
        for (int i = 0; i < 0x20; i++) {
            GameObject* o = gs2->GetGameObjectByIndex(i + 0xa0);
            if (o != 0) {
                o->obj3D_.Destroy();
                func_0200fd48(gs2, i + 0xa0);
            }
        }
        ((Struct_ov017_021bc77c_5*)res2)->sub.unknown_630_ = 0;
        Object3D* obj = func_ov017_021bdbc0((unsigned char*)res2);
        if (obj != 0) {
            obj->MakeVisible();
        }
        if (Zone3D_IsFieldTaskPending((unsigned char*)p2, 1) || Zone3D_IsFieldTaskPending((unsigned char*)p2, 0)) {
            func_020e1154((void*)0x1388);
        }
    }
    FollowCamera_EnableFollow(f28);
    func_020a2744((char*)f28);
    if (self->blk.s46 > Enum_ov017_021bc77c_m1) {
        Scenario_SetFlag(bits, bits + 0x8c, self->blk.s46 + 0x38e, 1);
    }
    if (self->sa0 > Enum_ov017_021bc77c_m1 && self->b9c) {
        Scenario_SetFlag(bits, bits + 0x8c, self->sa0 + 0xbea, 1);
    }
    if (self->unknown_9a_) {
        func_ov017_0219b624(res);
    }
    if (self->unknown_138_) {
        SignedAllocatorHeader* h = self->unknown_138_->GetSignedAllocator();
        if (h) {
            self->unknown_138_->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, h);
        }
        self->unknown_138_ = 0;
    }
    if (!TestFlags00(res, 0x1000) || self->unknown_11a_ == 0) {
        int size = self->unknown_90_;
        if (size) {
            SafeAllocator* sa = inline_ov017_021bc77c(res, 7);
            sa->CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, size), size);
            func_ov017_021a2fa0(res);
            self->unknown_90_ = 0;
        } else if (self->blk.flags & 4) {
            func_ov017_021a2fa0(res);
        }
    }
    if (!LinkSession_IsActive((int*)x34) && GameState_HasMovieId((FieldBlock63d6_11590*)gs)) {
        if (self->unknown_11a_) {
            func_020115f4(gs, self->unknown_11a_);
        }
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->fa;
    }
    if (self->unknown_11a_) {
        self->f8 = self->unknown_11a_;
        self->unknown_fd_ = 1;
        func_ov017_021bb0c4((unsigned char*)self);
        return 0;
    }
    if (*((unsigned char*)res + Enum_ov017_021bc77c_17122) == 0) {
        Struct_ov017_021bc77c_2 node;
        node.id = self->f8;
        if (Scenario_RunTrigger(bits, 0xb, &node)) {
            EventQuery_RunQueuedCommands(&node);
        }
        if (LinkSession_IsGuest(x34)) {
            int flag = 0;
            if (self->unknown_13c_ == 2) {
                if (r8[2]) flag = 1;
            } else if (self->unknown_13c_ == 1) {
                if (r8[2] && !Scenario_TestFlag((int)bits, bits + 0x8c, self->u148 + 0x38e)) {
                    if (self->u148 == 0xffff) {
                        if (self->unknown_14c_ != *(unsigned short*)((unsigned char*)self + 0x18)) flag = 1;
                    } else {
                        flag = 1;
                    }
                }
            } else if (self->unknown_13c_ == 0) {
                if (r8[2]) {
                    int v = *(int*)(func_ov017_021b8478(r8) + 0xc);
                    if (v != (short)self->unknown_146_) flag = 1;
                }
            }
            if (flag) {
                func_02046a8c(arg, r8);
                if (func_0209ca68((char*)g_bgmPlayer) == 2) {
                    func_0209c530(g_bgmPlayer);
                }
                ClearFlags04(res, 4);
                ClearFlags04(res, 0x10);
                ClearFlags04(res, 2);
                ClearFlags00(res, 4);
                ClearFlags00(res, 0x800);
            }
        }
    } else {
        self->unknown_13c_ = 2;
    }
    unsigned char* f = GameState_GetZoneTransition(gs);
    void* tags = func_020e3808();
    if (r8[2]) {
        func_020e3a50((TagValueEntry020e385c*)tags, GameState_GetProtagonistIndex(gs), 1, *(unsigned short*)((unsigned char*)self + 0x18));
    } else if (*(int*)(f + 0x20) <= 0 || f[2] == 0) {
        func_020e3994((TagValueEntry020e385c*)tags, 1, *(unsigned short*)((unsigned char*)self + 0x18));
    }
    if (self->unknown_cc_ && self->unknown_cf_ == 3) {
        func_020407b4((Fields020407b4*)unk, 0x48cc, 0x199, -0x733);
        GameObject_SnapFacing((Obj02033874*)unk, 0);
        for (int i = 1; i < 4; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(i);
            if (m) {
                func_020407b4((Fields020407b4*)m, 0x48cc, 0x199, -0x733);
                GameObject_SnapFacing((Obj02033874*)m, 0x3244);
                func_02039d48((unsigned char*)m);
            }
        }
    }
    if (f[2]) {
        SetBrightness(res, -16, 0);
    } else if (var10[2]) {
        func_0209c3b4((Actor0209c3b4*)g_bgmPlayer, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        SetMainBrightness(res, 0, 0x28);
    } else if (r8[2]) {
        SetBrightness(res, -16, 0);
        *(unsigned short*)(r8 + 0x6c4) = self->unknown_184_;
        if (LinkSession_IsGuest(x34)) {
            self->unknown_14e_ = *(int*)(func_ov017_021b8478(*(unsigned char**)((unsigned char*)res + kResourceNodeOffset)) + 0xc);
            func_ov017_021cdd70(self->unknown_14e_, 0, 0, 0, 0, 0, 0);
            unsigned char* q = RES_PTR(res, 70c);
            if (q[2]) {
                func_02046a8c(arg, q);
            }
            return 5;
        }
    } else if (self->unknown_cc_) {
        if (self->unknown_cc_ == 1) {
            func_ov017_021b6728(res, self->unknown_cf_, -1);
        }
        if (self->unknown_cf_ == 2) {
            GameObject_EnableControl(unk);
            GameObject_ApplyPendingControl(unk);
        }
        SetMainBrightness(res, 0, 0x28);
        func_ov017_021bb27c(self);
        self->done = 1;
        return self->fa;
    } else {
        int ok;
        unsigned short mapId;
        {
            unsigned short* p3;
            unsigned short id = self->f8;
            void* x = LinkSession_GetInstance();
            p3 = Zone3D_GetInstance();
            bits3 = Scenario_GetInstance();
            var8 = GetGameResources();
            unsigned char* o = RES_PTR(var8, 734);
            unsigned char buf = 0;
            unsigned short cur = *p3;
            if (!LinkSession_IsGuest(x)) { ok = 0; goto checked; }
            if (self->unknown_13c_ != 1) { ok = 0; goto checked; }
            if (self->unknown_140_ != cur && self->unknown_142_ != cur) { ok = 0; goto checked; }
            if (!self->unknown_144_) { ok = 0; goto checked; }
            if (Scenario_TestFlag((int)bits3, bits3 + 0x8c, self->u148 + 0x38e)) { ok = 0; goto checked; }
            unsigned short v = self->unknown_146_;
            if (v == id) { ok = 0; goto checked; }
            if (id == 0x733c || id == 0x733f || id == 0x7342 || id == 0x7345 || id == 0x7348) {
                if (v == 0x733d || v == 0x7340 || v == 0x7343 || v == 0x7346 || v == 0x7349 || v == 0x721a ||
                    v == 0x7080) {
                    ok = 0;
                    goto checked;
                }
            }
            int r = func_ov017_0219bddc(&buf);
            if (r) {
                func_ov017_0219bf04(0, 1);
                o[Enum_ov017_021bc77c_268] = 1;
            }
            unsigned char* q = RES_PTR(var8, b58);
            if (q[2]) {
                if (r) {
                    func_ov017_021c178c(q);
                    ok = 0;
                    goto checked;
                }
                if (self->unknown_14c_) {
                    *(unsigned short*)(o + Enum_ov017_021bc77c_276) = self->unknown_14c_;
                } else {
                    *(unsigned short*)(o + Enum_ov017_021bc77c_276) = self->unknown_146_;
                }
                ok = 0;
                goto checked;
            }
            if (!r) {
                ClearFlags00(var8, 0x10);
            }
            ok = r == 0;
        }
    checked:
        if (ok) {
        if (self->unknown_14c_) {
            self->f8 = self->unknown_14c_;
        } else {
            self->f8 = self->unknown_146_;
        }
        func_ov017_021bb0c4((unsigned char*)self);
        return 0;
    } else if (LinkSession_IsActive((int*)x34) && LinkSession_IsGuest(x34) && party0 && (mapId = *p, mapId == party0->obj3D_.GetField06()) &&
               self->unknown_13c_ == 0 && (short)self->unknown_146_ >= 0) {
        func_ov017_021b8bb0((short)self->unknown_146_);
    } else if (self->b9c && self->unknown_a2_ != *p) {
        func_02070378((char*)f);
        f[2] = 1;
        *(unsigned short*)f = self->unknown_a2_;
        f[7] = 1;
        *(Vector3i*)(f + 0x10) = self->vbc;
        *(short*)(f + 0x1c) = self->unknown_c8_;
        SetBrightness(res, -16, 0);
    } else if (*(int*)((unsigned char*)gs + Enum_ov017_021bc77c_29172) > 0) {
        func_02070378((char*)f);
        f[2] = 1;
        *(unsigned short*)f = *(int*)((unsigned char*)gs + Enum_ov017_021bc77c_29172);
        f[7] = 1;
        *(Vector3i*)(f + 0x10) = inline_ov017_021bc77c_2(gs);
        *(short*)(f + 0x1c) = *(int*)((unsigned char*)gs + Enum_ov017_021bc77c_29168);
        *(int*)((unsigned char*)gs + Enum_ov017_021bc77c_29172) = 0;
        SetBrightness(res, -16, 0);
        func_02017d68(Zone3D_GetInstance());
    } else {
        if (func_020a1eb0() == 1) {
#if defined(jpn)
            func_ov001_02156b20(self);
#else
            func_ov000_02156b20((GameObject*)self);
#endif
        }
        func_0209c3b4((Actor0209c3b4*)g_bgmPlayer, func_0209cd50(*p));
        func_ov017_021bd704(&self->blk);
        func_ov017_021a01bc((unsigned char*)res);
        if (p10[2]) {
            SetBrightness(res, -16, 0);
        } else if (!self->unknown_10b_) {
            SetMainBrightness(res, 0, 0x28);
        }
        GameObject_EnableControl(unk);
        GameObject_ApplyPendingControl(unk);
        func_0209c2e0(g_bgmPlayer, 0x7f, 0);
        if (self->unknown_114_) {
            *(unsigned short*)((unsigned char*)res + Enum_ov017_021bc77c_17580) = self->unknown_114_;
            self->unknown_114_ = 0;
        }
        if (self->f8 == 0x6013) {
            LightingManager* var43 = LightingManager::GetInstance();
            int var44 = gs->GetTimeOfDay();
            if (var44 != var43->timeOfDayIndex_) {
                if (p10[2]) {
                    p10[9] = 1;
                }
                SetBrightness(res, -16, 0);
                func_ov017_0219bcac(0);
            }
        }
    }
    }
    *(int*)((unsigned char*)gs + Enum_ov017_021bc77c_29172) = 0;
    func_ov017_021bb27c(self);
    self->done = 1;
    return self->fa;
}
