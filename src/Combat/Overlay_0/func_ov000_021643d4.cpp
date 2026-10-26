#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"
#include "Resource/Brightness.h"

struct GameResources;
struct Struct_020338d4;
struct Vec3;

struct Struct_ov000_021643d4_8 {
    Vector3i pos;
    short angle;
    short pad;
};

struct Struct_ov000_021643d4_9 {
    char pad0[4];
    unsigned char flag4;
    char pad1[2];
    unsigned short unknown_8_;
    int unknown_c_;
    char pad2[0x2a - 0x10];
    signed char partyIdx;
};

struct Actor {
    unsigned short flags;
    char pad0[0x44 - 2];
    Vector3i pos;
    Vector3i rot;
#if defined(jpn)
    char pad1[0x150 - 0x5c];
#else
    char pad1[0x15c - 0x5c];
#endif
    int unknown_15c_;
    Vector3i savedPos;
    Vector3i unknown_16c_;
};

struct Struct_ov000_021643d4_10 {
    int idx;
    int size;
    int type;
};

struct Struct_ov000_02183034 {
#if defined(jpn)
    Struct_ov000_021643d4_10 e[4];
#else
    Struct_ov000_021643d4_10 e[5];
#endif
};

struct EntryInfo {
    unsigned short unknown_0_;
    unsigned short kind : 2;
    unsigned short pad : 14;
};

struct PtrBlock {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct InitState0208f7ecStruct {
    int field0;
    int field4;
    char pad8[0xb4 - 8];
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    signed char unknown_b6_;
    signed char unknown_b7_;
    signed char b8;
    char unknown_b9_;
    unsigned short unknown_ba_;
    signed char unknown_bc_;
    signed char& inline_ov000_021643d4() { return unknown_b6_; }
};

static inline InitState0208f7ecStruct& inline_ov000_021643d4_2(Zone3D& zone) {
    return *(InitState0208f7ecStruct*)zone.unk_2664;
}

struct Struct_ov026_021dd3dc {
    char data[0x48];
};

struct Struct_ov000_021643d4_3 {
    char data[0x68];
    Struct_ov026_021dd3dc sub;
};

struct Struct_ov000_021643d4_4 {
    char pad[0x94];
    float value;
    int mode;
};

struct Overlay {
    char pad0[0x38];
    int alloc;
};

struct Struct_ov000_021643d4_5 {
#if defined(jpn)
    char pad[0x5000 + 0x4c8];
#else
    char pad[0x5000 + 0x728];
#endif
    unsigned char unknown_5728_;
};

struct Struct_ov000_021643d4_6 {
    char b[0x14];
};

struct Struct_01ff91ac_10 {
    int w[3];
};

struct Struct_ov000_021643d4_7 {
    unsigned int unknown_0_;
    char pad0[4];
#if defined(jpn)
    char unknown_8_[0x210];
#else
    Struct_ov000_021643d4_6 allocs[0x21];
#endif
    int unknown_29c_;
    Struct_ov000_021643d4_9* info;
    void* f2a4;
#if defined(jpn)
    char pad1[0xb94 - 0x224];
    char sub_c18[0xd9c - 0xb94];
#else
    char pad1[0xc18 - 0x2a8];
    char sub_c18[0xe20 - 0xc18];
#endif
    int unknown_e20_;
    unsigned char unknown_e24_;
#if defined(jpn)
    char pad2[0x5918 - 0xda1];
#else
    char pad2[0x5728 - 0xe25];
#endif
    Struct_01ff91ac_10 unknown_5728_[4];
#if defined(jpn)
    char pad3[0x5b00 - 0x5918 - 0x30];
#else
    char pad3[0x5910 - 0x5728 - 0x30];
#endif
    Struct_ov000_021643d4_8 party[4];
#if defined(jpn)
    char pad4[0x79e0 - 0x5b40];
#else
    char pad4[0x77f0 - 0x5950];
#endif
    int unknown_77f0_;
};

extern "C" int LinkSession_GetInstance(BackgroundLoader*);
extern "C" int ZoneRecords_FindCurrent();
extern "C" Actor* func_ov017_021a278c(void*, int);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" int GameObject_IsClimbingLadder(char*);
struct Struct_02039d84;
extern "C" void func_02039d84(Struct_02039d84*);
extern "C" void func_ov017_021d440c(int i);
extern "C" void GameObject_StopSinking(unsigned char*);
extern "C" void GameObject_ClearHidden(unsigned char*);
extern "C" int GameObject_GetLineLeader(void*);
void Vector3fixMultiplyScalar(const Vector3i* v, int s, Vector3i* out);
extern "C" void func_020338d4(Struct_020338d4*, Vec3*);
extern "C" void func_ov017_021cee78(int id, unsigned char v);
extern "C" void func_02053ec8(void*, int);
extern "C" int LinkSession_IsActive(int*);
struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_02076ccc(void*, int);
extern "C" void FieldMonsterState_Init(Actor* a);
extern "C" void func_ov017_0219bf74();
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" struct Field3f8* GameState_GetZoneTransition(GameState*);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_ov017_021a27e8(void* controller);
extern "C" void func_ov017_0219b938(int ov);
extern "C" int func_0203cf4c();
extern "C" int func_0203e06c(void*);
extern "C" void func_ov000_02160fa8(void*, int);
struct Struct_0203cfb4;
extern "C" void func_0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(int ov);
extern "C" void func_ov000_02163524(void*);
extern "C" void func_ov000_0216d2d0(void* p);
extern "C" void func_ov000_0216f700(void* p, int v);
struct AngleTrig0202e9a4;
extern "C" void Camera_SetFieldOfView(AngleTrig0202e9a4*, int);
extern "C" void GameState_SetCamera(GameState*, int);
extern "C" void Zone3D_Reset(void* p);
extern "C" void func_ov017_021a050c(GameResources* resources);
extern "C" int func_ov017_0219e008(void*);
extern "C" void func_ov017_021a1114(char*);
extern "C" void func_ov017_021a07f4(int ov);
extern "C" void func_ov017_0219dffc(void*, int);
struct Struct_02053da0;
extern "C" void func_02053da0(char*, Struct_02053da0*);
extern "C" void func_ov000_02161300(Struct_ov000_021643d4_7* c, int i);
extern "C" void GameObject_StopFollowing(unsigned char*);
extern "C" int LinkSession_IsGuest(int p);
extern "C" void func_ov017_0219c774(int a, int b, int c);
extern "C" void func_ov017_021cdaa0();
extern "C" void func_020ac4c0(void*);
struct Struct_020a07e0;
extern "C" void func_020a07e0(Struct_020a07e0*, unsigned int);
struct Struct_020a00d4;
extern "C" void func_020a00d4(Struct_020a00d4*, unsigned int);
extern "C" void func_020ac494(void*);
extern "C" void func_0201075c(char*, unsigned char);
extern "C" void func_ov017_021c894c(int a);
extern "C" void func_ov017_021c8758(int a);
extern "C" void func_ov017_021c8654();
extern "C" void func_ov017_021c847c();
extern "C" void func_02048994();

extern Struct_ov000_02183034 data_ov000_02183034;
extern float data_ov000_021838e8[5];
extern float data_ov000_0218423c[5];

// USA: func_ov000_021643d4
extern "C" ARM void func_ov000_021643d4(Struct_ov000_021643d4_7* c) {
    GameState* gs = GameState::GetInstance();
    int search = LinkSession_GetInstance(BackgroundLoader::GetInstance());
    GameResources* resources = GetGameResources();
    int ov = (int)resources;
    EntryInfo* entry = (EntryInfo*)ZoneRecords_FindCurrent();
    Zone3D* obj14 = Zone3D_GetInstance();
    PtrBlock* pb = (PtrBlock*)GameState_GetParty(gs);
    Actor* hero = (Actor*)gs->GetProtagonist();
    Actor* enemy = func_ov017_021a278c((void*)ov, c->info->unknown_8_);
    gs->GetLeader();
    Actor* leader = (Actor*)gs->GetPartyMemberByIndex(c->info->partyIdx);
    c->unknown_0_ = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
    {
        volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
        unsigned int var11 = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((var11 & ~0x10) << 8);
    }
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0((unsigned char*)c->info, i)) continue;
        Actor* m = (Actor*)gs->GetPartyMemberByIndex(i);
        if (!m) continue;
        if (GameObject_IsClimbingLadder((char*)m)) {
            func_02039d84((Struct_02039d84*)m);
            func_ov017_021d440c(i);
            if (leader) {
                m->pos = leader->pos;
            }
        }
        c->party[i].pos = m->pos;
        c->party[i].angle = m->rot.y;
        GameObject_StopSinking((unsigned char*)m);
        ((Object3D*)m)->SetInheritedAlpha(0x1f);
        GameObject_ClearHidden((unsigned char*)m);
        if (c->info->unknown_c_ == 0x1b) {
            Actor* o = (Actor*)gs->GetPartyMemberByIndex(0);
            if (!o) continue;
            if (**(unsigned int**)((char*)o + 0x130) & 1) {
                o = (Actor*)gs->GetPartyMemberByIndex((short)GameObject_GetLineLeader(o));
                if (!o) {
                    o = (Actor*)gs->GetPartyMemberByIndex(0);
                }
            }
            c->party[i].pos = o->pos;
            c->party[i].angle = o->rot.y;
            m->pos = o->pos;
            m->rot = o->rot;
        }
    }
    if (enemy) {
        Vector3i var15 = enemy->pos;
        for (int j = 0; j < pb->count; j++) {
            int id = pb->ids[j];
            Actor* mon = (Actor*)gs->GetWanderingMonsterByIndex(id);
            if (!mon) continue;
            if (c->info->flag4 == 0) {
                Vector3i mp = mon->pos;
                Vector3i dir, off;
                Vector3fix_Subtract(&var15, &mp, &dir);
                Vector3fix_Normalize(&dir, &dir);
                int dist = Vector3fix_Distance(&var15, &mp);
                int r = ((Object3D*)mon)->GetRadius();
                int half = (r + ((Object3D*)enemy)->GetRadius()) / 2;
                Vector3fixMultiplyScalar(&dir, dist - (half + 0x1000), &off);
                mp = Zone3D_ClipMoveAgainstWalls(obj14, &mp, &off, ((Object3D*)mon)->GetRadius() / 2);
                mp.y = Zone3D_GetGroundHeight(obj14, &mp);
                mon->pos = mp;
            }
            func_020338d4((Struct_020338d4*)mon, (Vec3*)&var15);
            func_ov017_021cee78(id, 0);
        }
    }
    hero->savedPos = hero->pos;
    hero->unknown_16c_ = hero->rot;
    hero->unknown_15c_ = ((Object3D*)hero)->GetField06();
    func_02053ec8(hero, 1);
    if (enemy) {
        if (!LinkSession_IsActive((int*)search) || !LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search)) {
            func_02076ccc(enemy, 9);
        } else {
            FieldMonsterState_Init(enemy);
            ((Object3D*)enemy)->MakeHidden();
        }
    }
    func_ov017_0219bf74();
    func_ov017_0219bd1c(0, 4, 1, 0);
    char* f3f8 = (char*)GameState_GetZoneTransition(gs);
    int sel = GameState_GetProtagonistIndex(gs);
    *(Vector3i*)(f3f8 + 0x10) = c->party[sel].pos;
    *(short*)(f3f8 + 0x1c) = c->party[sel].angle;
#if defined(jpn)
    unsigned int w = *(unsigned short*)(*(char**)((char*)ov + 0x3000 + 0x508) + 0x600 + 0xc4);
#else
    unsigned int w = *(unsigned short*)(*(char**)((char*)ov + 0x3000 + 0x718) + 0x600 + 0xc4);
#endif
    if (w) {
        char* p = (char*)GameState_GetZoneTransition(gs);
        *(unsigned short*)p = w;
        p[0xa] = 0;
    }
    func_ov017_021a27e8((void*)ov);
    func_ov017_0219b938(ov);
    for (int k = 0; k < 12; k++) {
        Actor* fm = (Actor*)gs->GetFieldMonsterByIndex(k + (entry->kind * 12 + 0x70));
        if (fm) ((Object3D*)fm)->Destroy();
    }
    int var31 = func_0203cf4c();
    if (func_0203e06c((void*)var31) > 0) {
        func_ov000_02160fa8(c, 0x1000);
    }
    func_0203cfb4((Struct_0203cfb4*)var31);
    func_ov017_021a316c(ov);
    SetFlags04((GameResources*)ov, 0x80);
    SetFlags04((GameResources*)ov, 4);
    SetFlags04((GameResources*)ov, 0x10);
    func_ov000_02163524(c);
    SetFlags04((GameResources*)ov, 2);
    SetFlags00((GameResources*)ov, 4);
    SetFlags00((GameResources*)ov, 0x20);
    SetFlags04((GameResources*)ov, 0x10);
    SetFlags04((GameResources*)ov, 0x40);
    SetFlags04((GameResources*)ov, 0x80);
    inline_ov000_021643d4_2(*obj14).inline_ov000_021643d4() = 0;
    SetFlags08((GameResources*)ov, 4);
    func_ov000_0216d2d0(c->sub_c18);
    func_ov000_0216f700(c->sub_c18, c->unknown_29c_);
    c->unknown_e20_ = 0x800;
    c->unknown_e24_ = 1;
    c->f2a4 = gs->GetCamera();
    if (c->f2a4) {
        Camera_SetFieldOfView((AngleTrig0202e9a4*)((int)c->f2a4), 0xf);
    }
    GameState_SetCamera(gs, (int)c->sub_c18);
#if defined(jpn)
    Zone3D_Reset((char*)c + 0x244 + 0xc00);
#else
    Zone3D_Reset((char*)c + 0x2c8 + 0xc00);
#endif
    func_ov017_021a050c(resources);
    if (func_ov017_0219e008((void*)ov) == 4) {
        func_ov017_021a1114((char*)ov);
        func_ov017_021a07f4(ov);
        func_ov017_0219dffc((void*)ov, 1);
    }
    Struct_ov000_02183034 tbl = data_ov000_02183034;
    int size;
    for (int n = 0; (size = tbl.e[n].size) > 0; n++) {
        int idx = tbl.e[n].idx;
        int type = tbl.e[n].type;
        void* buf = resources->allocator_array_38[0].Allocate(size);
        if (type == 0) {
#if defined(jpn)
            ((SafeAllocator*)((Struct_ov000_021643d4_6*)((char*)c + 8) + idx))->CreateTypeA(buf, size);
#else
            ((SafeAllocator*)&c->allocs[idx])->CreateTypeA(buf, size);
#endif
        } else if (type == 1) {
#if defined(jpn)
            ((SafeAllocator*)((Struct_ov000_021643d4_6*)((char*)c + 8) + idx))->CreateTypeB(buf, size, 4);
#else
            ((SafeAllocator*)&c->allocs[idx])->CreateTypeB(buf, size, 4);
#endif
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0((unsigned char*)c->info, i)) continue;
        Actor* m = (Actor*)gs->GetPartyMemberByIndex(i);
        if (!m) continue;
        m->savedPos = m->pos;
        m->unknown_16c_ = m->rot;
        m->unknown_15c_ = ((Object3D*)m)->GetField06();
        func_02053da0((char*)m, (Struct_02053da0*)&c->unknown_5728_[i]);
        func_ov000_02161300(c, i);
        GameObject_StopFollowing((unsigned char*)m);
        if (m->flags & 0x1000) {
            func_02053ec8(m, 1);
        }
    }
    if (!LinkSession_IsActive((int*)search)) {
        func_ov000_02160fa8(c, 2);
    } else if (GameState_GetProtagonistIndex(gs) == c->info->partyIdx) {
        func_ov000_02160fa8(c, 2);
    }
    if (LinkSession_IsGuest(search)) {
        func_ov017_0219c774(0, 1, 0);
    }
    Struct_ov000_021643d4_4* var40 = (Struct_ov000_021643d4_4*)LightingManager::GetInstance();
    float cur = var40->value;
    if (data_ov000_0218423c[3] - data_ov000_021838e8[4] < cur && cur < data_ov000_0218423c[3]) {
        var40->value = data_ov000_0218423c[3];
        var40->mode = 1;
    } else if (data_ov000_0218423c[2] - data_ov000_021838e8[4] < cur && cur < data_ov000_0218423c[2]) {
        var40->value = data_ov000_0218423c[2];
        var40->mode = 2;
    } else if (data_ov000_0218423c[1] - data_ov000_021838e8[4] < cur && cur < data_ov000_0218423c[1]) {
        var40->value = data_ov000_0218423c[1];
        var40->mode = 3;
    } else if ((data_ov000_0218423c[1] + data_ov000_021838e8[1]) - data_ov000_021838e8[4] < cur) {
        var40->value = data_ov000_0218423c[0];
        var40->mode = 0;
    }
    func_ov017_021cdaa0();
    if (c->info->unknown_c_ == 0x1a) {
        gs->SetTimeOfDay(TimeOfDay_Evening);
        var40->mode = 3;
    }
    ClearFlags00((GameResources*)ov, 0x800);
    Struct_ov000_021643d4_3 blk;
    func_020ac4c0(&blk);
    func_020a07e0((Struct_020a07e0*)&blk, 1);
    func_020a00d4((Struct_020a00d4*)&blk.sub, 1);
    func_020ac494(&blk);
    ((Struct_ov000_021643d4_5*)gs)->unknown_5728_ = 0;
    func_0201075c((char*)gs, 0);
    func_ov017_021c894c(c->info->unknown_8_);
    func_ov017_021c8758(c->info->unknown_8_);
    func_ov017_021c8654();
    func_ov017_021c847c();
    c->unknown_77f0_ = -1;
    func_02048994();
    func_ov000_02160fa8(c, 1);
}
