#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"
#include "Resource/Brightness.h"

struct GameResources;
struct Struct_020338d4;
struct Struct_ov009_0218aa28;

struct Struct_ov000_021643d4_8 {
    Vector3i unknown_0_;
    short unknown_c_;
    short unknown_e_;
};

struct Struct_ov000_021643d4_9 {
    char unknown_0_[4];
    unsigned char unknown_4_;
    char unknown_5_[2];
    unsigned short unknown_8_;
    int unknown_c_;
    char unknown_10_[0x2a - 0x10];
    signed char unknown_2a_;
};

struct Struct_ov000_0215f7a8 {
    unsigned short unknown_0_;
    char unknown_2_[0x44 - 2];
    Vector3i unknown_44_;
    Vector3i unknown_50_;
#if defined(jpn)
    char unknown_5c_[0x150 - 0x5c];
#else
    char unknown1_5c_[0x15c - 0x5c];
#endif
    int unknown_15c_;
    Vector3i unknown_160_;
    Vector3i unknown_16c_;
};

struct Struct_ov000_021643d4_10 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov000_02183034 {
#if defined(jpn)
    Struct_ov000_021643d4_10 unknown_0_[4];
#else
    Struct_ov000_021643d4_10 unknown_0_[5];
#endif
};

struct Struct_ov000_021643d4 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov000_021643d4_2 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_0201c014 {
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0xb4 - 8];
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    signed char unknown_b6_;
    signed char unknown_b7_;
    signed char unknown_b8_;
    char unknown_b9_;
    unsigned short unknown_ba_;
    signed char unknown_bc_;
    signed char& inline_ov000_021643d4() { return unknown_b6_; }
};

static inline Struct_0201c014& inline_ov000_021643d4_2(Zone3D& arg0) {
    return *(Struct_0201c014*)arg0.unk_2664;
}

struct Struct_ov026_021dd3dc {
    char unknown_0_[0x48];
};

struct Struct_ov000_021643d4_3 {
    char unknown_0_[0x68];
    Struct_ov026_021dd3dc unknown_68_;
};

struct Struct_ov000_021643d4_4 {
    char unknown_0_[0x94];
    float unknown_94_;
    int unknown_98_;
};

struct Struct_01ff91ac_9 {
    char unknown_0_[0x38];
    int unknown_38_;
};

struct Struct_ov000_021643d4_5 {
#if defined(jpn)
    char unknown_0_[0x5000 + 0x4c8];
#else
    char unknown1_0_[0x5000 + 0x728];
#endif
    unsigned char unknown_5728_;
};

struct Struct_ov000_021643d4_6 {
    char unknown_0_[0x14];
};

struct Struct_01ff91ac_10 {
    int unknown_0_[3];
};

struct Struct_ov000_021643d4_7 {
    unsigned int unknown_0_;
    char unknown_4_[4];
#if defined(jpn)
    char unknown_8_[0x210];
#else
    Struct_ov000_021643d4_6 unknown1_8_[0x21];
#endif
    int unknown_29c_;
    Struct_ov000_021643d4_9* unknown_2a0_;
    void* unknown_2a4_;
#if defined(jpn)
    char unknown_224_[0xb94 - 0x224];
    char unknown_c18_[0xd9c - 0xb94];
#else
    char unknown_2a8_[0xc18 - 0x2a8];
    char unknown_c18_[0xe20 - 0xc18];
#endif
    int unknown_e20_;
    unsigned char unknown_e24_;
#if defined(jpn)
    char unknown_da1_[0x5918 - 0xda1];
#else
    char unknown_e25_[0x5728 - 0xe25];
#endif
    Struct_01ff91ac_10 unknown_5728_[4];
#if defined(jpn)
    char unknown_5948_[0x5b00 - 0x5918 - 0x30];
#else
    char unknown_5758_[0x5910 - 0x5728 - 0x30];
#endif
    Struct_ov000_021643d4_8 unknown_5910_[4];
#if defined(jpn)
    char unknown_5b40_[0x79e0 - 0x5b40];
#else
    char unknown_5950_[0x77f0 - 0x5950];
#endif
    int unknown_77f0_;
};

extern "C" int func_0202ae18(BackgroundLoader*);
extern "C" int func_02027cb0();
extern "C" Struct_ov000_0215f7a8* func_ov017_021a278c(void*, int);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" int func_02039d7c(char*);
struct Struct_02039d84;
extern "C" void func_02039d84(Struct_02039d84*);
extern "C" void func_ov017_021d440c(int arg0);
extern "C" void func_0203409c(unsigned char*);
extern "C" void func_02039d58(unsigned char*);
extern "C" int func_02039888(void*);
void Vector3fixMultiplyScalar(const Vector3i* v, int s, Vector3i* out);
void AimAndSetVecY020338d4(Struct020338d4*, Vec3*);
void EnqueueEventTag20_021cee78(int id, unsigned char v);
void SetField0x158_02053ec8(void*, int);
int CheckField0NonZero_0202b7d8(int*);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void TrySetMode02076ccc(void*, int);
extern "C" void func_02076a8c(Actor* a);
void ResetOverlayAndAllocator_0219bf74();
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
struct Field3f8* GetField0x3f8Address_0200fd0c(GameState*);
int GameState_GetProtagonistIndex(GameState*);
void ClearSlotsAndProcess_021a27e8(void* controller);
extern "C" void func_ov017_0219b938(int ov);
int GetGlobalPtr021075f4_0203cf4c();
int GetField0x8c_0203e06c(void*);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
struct Struct_0203cfb4;
void Init0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(int ov);
void GetField02163524(void*);
extern "C" void func_ov000_0216d2d0(void* p);
void SetIntField540_0216f700(void* p, int v);
struct AngleTrig0202e9a4;
void SetAngleAndTrigTable0202e9a4(AngleTrig0202e9a4*, int);
void GameState_SetCamera(GameState*, int);
extern "C" void func_020134e0(void* p);
void ResetTaskAndDestroyAllocators_021a050c(GameResources* resources);
int GetFieldB08_0219e008(void*);
void DestroyAllocatorsFromTable_021a1114(char*);
extern "C" void func_ov017_021a07f4(int ov);
void SetFieldB08_0219dffc(void*, int);
struct Field0x19cData;
void SetAndClearField0x19c_02053da0(char*, Field0x19cData*);
extern "C" void func_ov000_02161300(CombatRoot* c, int i);
void SetFlag0x1ceBit0x1_02039894(unsigned char*);
extern "C" int func_0202c540(int p);
extern "C" void func_ov017_0219c774(int a, int b, int c);
void EnqueueEventTag147_021cdaa0();
void LoadBattleBlock020ac4c0(void*);
struct S_a07e0;
void AddClamped24BitFieldAt0x3c_020a07e0(S_a07e0*, unsigned int);
struct S_a00d4;
void AddClamped16BitFieldAt0x10_020a00d4(S_a00d4*, unsigned int);
void CopyInBattleField0x7540_020ac494(void*);
void SetField0x5729Value_0201075c(char*, unsigned char);
extern "C" void func_ov017_021c894c(int a);
extern "C" void func_ov017_021c8758(int a);
extern "C" void func_ov017_021c8654();
extern "C" void func_ov017_021c847c();
extern "C" void func_02048994();

extern Struct_ov000_02183034 data_ov000_02183034;
extern float data_ov000_021838e8[5];
extern float data_ov000_0218423c[5];

// USA: func_ov000_021643d4
extern "C" ARM void func_ov000_021643d4(CombatRoot* c) {
    GameState* gs = GameState::GetInstance();
    int search = func_0202ae18(BackgroundLoader::GetInstance());
    GameResources* resources = GetGameResources();
    int ov = (int)resources;
    EntryInfo* entry = (EntryInfo*)FindEntryByCurrentId02027cb0();
    Zone3D* obj14 = Zone3D_GetInstance();
    PtrBlock* pb = (PtrBlock*)GameState_GetParty(gs);
    Actor* hero = (Actor*)gs->GetProtagonist();
    Actor* enemy = FindCombatantByField16a_021a278c((void*)ov, c->info->id8);
    gs->GetUnknownGameObject();
    Actor* leader = (Actor*)gs->GetPartyMemberByIndex(c->info->partyIdx);
    c->savedPlanes = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
    {
        volatile unsigned int* var10 = (volatile unsigned int*)0x4001000;
        unsigned int var11 = (*var10 & 0x1f00) >> 8;
        *var10 = (*var10 & ~0x1f00) | ((var11 & ~0x10) << 8);
    }
    for (int var12 = 0; var12 < 4; var12++) {
        if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var12)) continue;
        Struct_ov000_0215f7a8* var13 = (Struct_ov000_0215f7a8*)var0->GetPartyMemberByIndex(var12);
        if (!var13) continue;
        if (func_02039d7c((char*)var13)) {
            func_02039d84((Struct_02039d84*)var13);
            func_ov017_021d440c(var12);
            if (var9) {
                var13->unknown_44_ = var9->unknown_44_;
            }
        }
        arg0->unknown_5910_[var12].unknown_0_ = var13->unknown_44_;
        arg0->unknown_5910_[var12].unknown_c_ = var13->unknown_50_.y;
        func_0203409c((unsigned char*)var13);
        ((Object3D*)var13)->SetInheritedAlpha(0x1f);
        func_02039d58((unsigned char*)var13);
        if (arg0->unknown_2a0_->unknown_c_ == 0x1b) {
            Struct_ov000_0215f7a8* var14 = (Struct_ov000_0215f7a8*)var0->GetPartyMemberByIndex(0);
            if (!var14) continue;
            if (**(unsigned int**)((char*)var14 + 0x130) & 1) {
                var14 = (Struct_ov000_0215f7a8*)var0->GetPartyMemberByIndex((short)func_02039888(var14));
                if (!var14) {
                    var14 = (Struct_ov000_0215f7a8*)var0->GetPartyMemberByIndex(0);
                }
            }
            arg0->unknown_5910_[var12].unknown_0_ = var14->unknown_44_;
            arg0->unknown_5910_[var12].unknown_c_ = var14->unknown_50_.y;
            var13->unknown_44_ = var14->unknown_44_;
            var13->unknown_50_ = var14->unknown_50_;
        }
    }
    if (enemy) {
        Vector3i ep = enemy->pos;
        for (int j = 0; j < pb->count; j++) {
            int id = pb->ids[j];
            Actor* mon = (Actor*)gs->GetMaybeWanderingMonsterByIndex(id);
            if (!mon) continue;
            if (c->info->flag4 == 0) {
                Vector3i mp = mon->pos;
                Vector3i dir, off;
                Vector3fix_Subtract(&ep, &mp, &dir);
                Vector3fix_Normalize(&dir, &dir);
                int dist = Vector3fix_Distance(&ep, &mp);
                int r = ((Object3D*)mon)->GetRadius();
                int half = (r + ((Object3D*)enemy)->GetRadius()) / 2;
                Vector3fixMultiplyScalar(&dir, dist - (half + 0x1000), &off);
                mp = Zone3D_ClipMoveAgainstWalls(obj14, &mp, &off, ((Object3D*)mon)->GetRadius() / 2);
                mp.y = Zone3D_GetGroundHeight(obj14, &mp);
                mon->pos = mp;
            }
            func_020338d4((Struct_020338d4*)var18, (Struct_ov009_0218aa28*)&var15);
            func_ov017_021cee78(var17, 0);
        }
    }
    var7->unknown_160_ = var7->unknown_44_;
    var7->unknown_16c_ = var7->unknown_50_;
    var7->unknown_15c_ = ((Object3D*)var7)->GetField06();
    func_02053ec8(var7, 1);
    if (var8) {
        if (!func_0202b7d8((int*)var1) || !func_0202c1a4((Struct_0202c1a4*)var1)) {
            func_02076ccc(var8, 9);
        } else {
            func_02076a8c(var8);
            ((Object3D*)var8)->MakeHidden();
        }
    }
    func_ov017_0219bf74();
    func_ov017_0219bd1c(0, 4, 1, 0);
    char* f3f8 = (char*)GetField0x3f8Address_0200fd0c(gs);
    int sel = GameState_GetProtagonistIndex(gs);
    *(Vector3i*)(f3f8 + 0x10) = c->party[sel].pos;
    *(short*)(f3f8 + 0x1c) = c->party[sel].angle;
#if defined(jpn)
    unsigned int var27 = *(unsigned short*)(*(char**)((char*)var3 + 0x3000 + 0x508) + 0x600 + 0xc4);
#else
    unsigned int var27 = *(unsigned short*)(*(char**)((char*)var3 + 0x3000 + 0x718) + 0x600 + 0xc4);
#endif
    if (var27) {
        char* var28 = (char*)func_0200fd0c(var0);
        *(unsigned short*)var28 = var27;
        var28[0xa] = 0;
    }
    func_ov017_021a27e8((void*)var3);
    func_ov017_0219b938(var3);
    for (int var29 = 0; var29 < 12; var29++) {
        Struct_ov000_0215f7a8* var30 = (Struct_ov000_0215f7a8*)var0->GetMaybeFieldMonsterByIndex(var29 + (var4->unknown_2_0_ * 12 + 0x70));
        if (var30) ((Object3D*)var30)->Destroy();
    }
    int var31 = func_0203cf4c();
    if (func_0203e06c((void*)var31) > 0) {
        func_ov000_02160fa8(arg0, 0x1000);
    }
    Init0203cfb4((Struct_0203cfb4*)glob);
    func_ov017_021a316c(ov);
    SetFlags04((GameResources*)ov, 0x80);
    SetFlags04((GameResources*)ov, 4);
    SetFlags04((GameResources*)ov, 0x10);
    GetField02163524(c);
    SetFlags04((GameResources*)ov, 2);
    SetFlags00((GameResources*)ov, 4);
    SetFlags00((GameResources*)ov, 0x20);
    SetFlags04((GameResources*)ov, 0x10);
    SetFlags04((GameResources*)ov, 0x40);
    SetFlags04((GameResources*)ov, 0x80);
    GetInitState(*obj14).ByteB6() = 0;
    SetFlags08((GameResources*)ov, 4);
    func_ov000_0216d2d0(c->sub_c18);
    SetIntField540_0216f700(c->sub_c18, c->f29c);
    c->fe20 = 0x800;
    c->fe24 = 1;
    c->f2a4 = gs->GetCamera();
    if (c->f2a4) {
        SetAngleAndTrigTable0202e9a4((AngleTrig0202e9a4*)((int)c->f2a4), 0xf);
    }
    GameState_SetCamera(gs, (int)c->sub_c18);
#if defined(jpn)
    func_020134e0((char*)arg0 + 0x244 + 0xc00);
#else
    func_020134e0((char*)arg0 + 0x2c8 + 0xc00);
#endif
    func_ov017_021a050c(var2);
    if (func_ov017_0219e008((void*)var3) == 4) {
        func_ov017_021a1114((char*)var3);
        func_ov017_021a07f4(var3);
        func_ov017_0219dffc((void*)var3, 1);
    }
    Struct_ov000_02183034 var32 = data_ov000_02183034;
    int var33;
    for (int var34 = 0; (var33 = var32.unknown_0_[var34].unknown_4_) > 0; var34++) {
        int var35 = var32.unknown_0_[var34].unknown_0_;
        int var36 = var32.unknown_0_[var34].unknown_8_;
        void* var37 = var2->allocator_array_38[0].Allocate(var33);
        if (var36 == 0) {
#if defined(jpn)
            ((SafeAllocator*)((Struct_ov000_021643d4_6*)((char*)arg0 + 8) + var35))->CreateTypeA(var37, var33);
#else
            ((SafeAllocator*)&arg0->unknown1_8_[var35])->CreateTypeA(var37, var33);
#endif
        } else if (var36 == 1) {
#if defined(jpn)
            ((SafeAllocator*)((Struct_ov000_021643d4_6*)((char*)arg0 + 8) + var35))->CreateTypeB(var37, var33, 4);
#else
            ((SafeAllocator*)&arg0->unknown1_8_[var35])->CreateTypeB(var37, var33, 4);
#endif
        }
    }
    for (int var38 = 0; var38 < 4; var38++) {
        if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var38)) continue;
        Struct_ov000_0215f7a8* var39 = (Struct_ov000_0215f7a8*)var0->GetPartyMemberByIndex(var38);
        if (!var39) continue;
        var39->unknown_160_ = var39->unknown_44_;
        var39->unknown_16c_ = var39->unknown_50_;
        var39->unknown_15c_ = ((Object3D*)var39)->GetField06();
        func_02053da0((char*)var39, (Struct_02053da0*)&arg0->unknown_5728_[var38]);
        func_ov000_02161300(arg0, var38);
        func_02039894((unsigned char*)var39);
        if (var39->unknown_0_ & 0x1000) {
            func_02053ec8(var39, 1);
        }
    }
    if (!CheckField0NonZero_0202b7d8((int*)search)) {
        SetCombatWorkFlags0x55f4_ov000_02160fa8(c, 2);
    } else if (GameState_GetProtagonistIndex(gs) == c->info->partyIdx) {
        SetCombatWorkFlags0x55f4_ov000_02160fa8(c, 2);
    }
    if (func_0202c540(var1)) {
        func_ov017_0219c774(0, 1, 0);
    }
    Struct_ov000_021643d4_4* var40 = (Struct_ov000_021643d4_4*)LightingManager::GetInstance();
    float var41 = var40->unknown_94_;
    if (data_ov000_0218423c[3] - data_ov000_021838e8[4] < var41 && var41 < data_ov000_0218423c[3]) {
        var40->unknown_94_ = data_ov000_0218423c[3];
        var40->unknown_98_ = 1;
    } else if (data_ov000_0218423c[2] - data_ov000_021838e8[4] < var41 && var41 < data_ov000_0218423c[2]) {
        var40->unknown_94_ = data_ov000_0218423c[2];
        var40->unknown_98_ = 2;
    } else if (data_ov000_0218423c[1] - data_ov000_021838e8[4] < var41 && var41 < data_ov000_0218423c[1]) {
        var40->unknown_94_ = data_ov000_0218423c[1];
        var40->unknown_98_ = 3;
    } else if ((data_ov000_0218423c[1] + data_ov000_021838e8[1]) - data_ov000_021838e8[4] < var41) {
        var40->unknown_94_ = data_ov000_0218423c[0];
        var40->unknown_98_ = 0;
    }
    func_ov017_021cdaa0();
    if (arg0->unknown_2a0_->unknown_c_ == 0x1a) {
        var0->SetTimeOfDay(TimeOfDay_Evening);
        var40->unknown_98_ = 3;
    }
    ClearFlags00((GameResources*)var3, 0x800);
    Struct_ov000_021643d4_3 var42;
    func_020ac4c0(&var42);
    func_020a07e0((Struct_020a07e0*)&var42, 1);
    func_020a00d4((Struct_020a00d4*)&var42.unknown_68_, 1);
    func_020ac494(&var42);
    ((Struct_ov000_021643d4_5*)var0)->unknown_5728_ = 0;
    func_0201075c((char*)var0, 0);
    func_ov017_021c894c(arg0->unknown_2a0_->unknown_8_);
    func_ov017_021c8758(arg0->unknown_2a0_->unknown_8_);
    func_ov017_021c8654();
    func_ov017_021c847c();
    arg0->unknown_77f0_ = -1;
    func_02048994();
    func_ov000_02160fa8(arg0, 1);
}
