#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
struct Struct_01ff91ac_31;
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};

extern "C" int MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance();
extern "C" void* GlobalFlags_GetInstance(void);
#if defined(jpn)
extern "C" void func_ov003_0216d8d4(char* obj, int keyA);
#else
extern "C" void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5);
#endif
extern "C" int func_020457e0(char* obj);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void AllocatorUnion_Free(AllocatorUnion*, void*);
extern "C" void func_ov003_02170d38(char*);
class Struct_ov003_0216c00c;
extern "C" int func_ov003_021714a0(Struct_ov003_0216c00c* obj);
extern "C" void func_ov003_02173c40(char* obj);
extern "C" void func_ov003_021726f8(char* obj, SafeAllocator* allocator);
extern "C" void VectorizedMemset(void*, int, int);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
extern "C" int func_020aad1c(int a, int b, int c, int d);

extern "C" void func_ov003_02170d88(void* p);
extern "C" int func_ov003_021727c8(char* obj);
extern "C" void func_ov003_02173d40(char* obj);

extern "C" void func_020119f8(char*, void*);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_02011a40(char*);
extern "C" void* func_02053c6c(unsigned char*);
struct GameState;
extern "C" int func_02011804(GameState*);
extern "C" void func_020119d8(void*);
extern "C" void func_ov017_021a9ff0(int flag);
extern "C" void func_ov017_021c1798(GameResources* p, unsigned char v);
int IsBrightnessTransitionActive(void* word);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int mask);
void SetMainBrightness(void* obj, int a, int b);
void SetSubBrightness(void* obj, int a, int b);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
struct Struct020a9ea4;
extern "C" void func_020a9ea4(Struct020a9ea4*);
extern "C" void func_0209c2e0(void* obj, int a, int b);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(struct Actor0209c3b4* actor, int val);
struct Struct_02059cfc_2;
struct Struct_02059cfc_3;
extern "C" void func_02059f38(Struct_02059cfc_2*, Struct_02059cfc_3*);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(Obj02033874*, int);
struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" int func_ov017_021b1fa8(void* p);
extern "C" int func_ov017_021b1fb0(void* p);
extern "C" void* func_ov017_021b1fb8(void* p);
extern "C" int func_020ac4c0(void* dst);
struct Struct_020a03f8;
extern "C" void func_020a03f8(Struct_020a03f8*, unsigned int);
extern "C" void func_020ac494(void* p);
extern "C" void func_020ac760(void* p);
extern "C" void func_020ac734(void* p);
extern "C" const char* StandardStrings_Get(int key);
struct Struct_02011818;
extern "C" void func_02011818(void*, Struct_02011818*);
extern "C" void func_02011ab8(char*);
extern "C" void func_02011a74(char*, unsigned int, char const*);

extern int g_bgmPlayer;
extern AllocatorUnion g_mainAllocator;
extern unsigned char g_fileLoadBuffer[];
extern char data_ov003_021801e0[];
extern char data_ov003_021801f8[];
extern char data_ov003_021801fc[];
extern char data_ov003_02180201[];

struct Struct_ov003_0216c00c_2 { char pad[0x414]; unsigned char b0:1; };
struct Struct_01ff91ac_32 { char pad0[0x44]; };
struct Struct_ov003_0216c00c_3 { char pad[0x950]; int unknown_950_; };
struct Struct_ov003_0216c00c_4 { char pad[0x150]; struct Struct_ov003_0216c00c_3* f150; };
struct Struct_ov003_0215d4fc { char pad0[0x44]; struct Struct_01ff91ac_32 blk[2]; };
static inline struct Struct_ov003_0216c00c_2* inline_ov003_0216c00c(struct Struct_ov003_0215d4fc* ent, int i) {
    return (struct Struct_ov003_0216c00c_2*)&ent->blk[i];
}
struct Struct_ov003_0216c00c_5 { unsigned int unknown_0_0_:21, unknown_2_5_:4, unknown_3_1_:1, unknown_3_2_:1; int unknown_4_0_:19, v:11; };
struct Struct_ov003_0216c00c_6 { char pad[0x5400]; struct Struct_ov003_0216c00c_5 rec; };
struct Struct_ov003_0216c00c_7 { char pad[0x29c]; struct Struct_ov003_0216c00c_6 sub; };
static inline struct Struct_ov003_0216c00c_6* inline_ov003_0216c00c_2(void* b) { return &((struct Struct_ov003_0216c00c_7*)b)->sub; }
struct Struct_ov003_0216c00c_8 { char pad[0xd]; unsigned char v:7; };
struct Struct_ov003_0216c00c_9 { char c[10]; };
struct Vec3 { int x, y, z; ~Vec3() {} };
struct Struct_ov003_0216c00c_10 { char pad[0xa64]; struct TreasureMapMetadata unknown_a64_; };
#define META(o) (&((struct Struct_ov003_0216c00c_10*)(o))->unknown_a64_)
static inline int inline_ov003_0216c00c_3(char* obj) {
    return *(unsigned char*)(obj + 0x1000 + 8) == 5;
}

struct Struct_ov003_0216c00c_11 { char pad[0x1b34]; int unknown_1b34_; char unknown_1b38_[0x1b60 - 0x1b38]; unsigned char unknown_1b60_; };
struct Struct_01ff91ac_33 { char pad[0x840]; struct Struct_ov003_0216c00c_11 save; };
static inline struct Struct_ov003_0216c00c_11* inline_ov003_0216c00c_4(void* c) { return &((struct Struct_01ff91ac_33*)c)->save; }
static inline int inline_ov003_0216c00c_5(struct Struct_ov003_0216c00c_11* s) { return s->unknown_1b34_; }
static inline void inline_ov003_0216c00c_6(struct Struct_ov003_0216c00c_11* s, int v) { s->unknown_1b34_ = v; }
static inline unsigned char inline_ov003_0216c00c_7(struct Struct_ov003_0216c00c_11* s) { return s->unknown_1b60_; }
static inline void inline_ov003_0216c00c_8(struct Struct_ov003_0216c00c_11* s, unsigned char v) { s->unknown_1b60_ = v; }
#if defined(jpn)
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct*, int, int);
struct Container020e0310;
extern "C" char* KeyTable_Get(Container020e0310*, int);
extern char data_ov003_0217e99c[];
extern char data_ov003_0217e9b4[];
extern char data_ov003_0217e9b8[];
struct Struct_ov003_0216c00c_12 { char pad[0x8b8]; int unknown_8b8_; };
struct Struct_ov003_0216c00c_13 { char pad[0x144]; struct Struct_ov003_0216c00c_12* unknown_144_; };
struct Struct_ov003_0216c00c_14 { char pad[0x5400]; struct Struct_ov003_0216c00c_5 rec; };
struct Struct_ov003_0216c00c_15 { char pad[0x3c]; struct Struct_ov003_0216c00c_14 sub; };
static inline struct Struct_ov003_0216c00c_14* inline_ov003_0216c00c_9(void* b) { return &((struct Struct_ov003_0216c00c_15*)b)->sub; }
struct Struct_ov003_0216c00c_16 { char pad[0x9c8]; struct TreasureMapMetadata unknown_9c8_; };
#define METAJ(o) (&((struct Struct_ov003_0216c00c_16*)(o))->unknown_9c8_)
static inline int inline_ov003_0216c00c_10(char* obj) {
    return *(unsigned char*)(obj + 0xe88) == 5;
}
static inline struct Struct_ov003_0216c00c_5* inline_ov003_0216c00c_11(void* b) { return &inline_ov003_0216c00c_9(b)->rec; }
struct CtxJ { char pad[0x860]; struct Struct_ov003_0216c00c_11 save; };
// JPN: func_ov003_0216c00c
extern "C" ARM void func_ov003_0216c00c(char* obj) {
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    GameResources* ov17 = GetGameResources();
    char* g = (char*)MessageSystem_GetInstance();
    struct CtxJ* ctx = (struct CtxJ*)Zone3D_GetInstance();
    struct Struct_ov003_0216c00c_11* save = &ctx->save;
    void* w = LinkSession_GetInstance();
    void* dataPtr0 = GlobalFlags_GetInstance();

    short var7 = *(short*)(obj + 0xa);
    if (var7 == 1) {
        func_ov003_0216d8d4(obj, 0x41);
        *(unsigned char*)(g + 0x1000 + 0x7e2) = 1;
        *(int*)(g + 0x86c) = 2;
        *(int*)(g + 0x868) = 1;
        *(short*)(obj + 6) = 3;
        *(short*)(obj + 0xa) = 0;
    } else if (var7 == 2) {
        struct TreasureMapMetadata var8;
        func_020119f8((char*)battle, &var8);
        if (var8.GetMapType() != 0) {
            func_ov003_0216d8d4(obj, 0x4a);
        } else {
            func_ov003_0216d8d4(obj, 0x43);
        }
        *(short*)(obj + 6) = 0x12c;
        *(unsigned char*)(g + 0x1000 + 0x7e2) = 1;
        *(int*)(g + 0x86c) = 2;
        *(int*)(g + 0x868) = 1;
        *(short*)(obj + 0xa) = 0;
    }

    short state = *(short*)(obj + 6);
    if (state == 0) {
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)((char*)((GameState*)battle)->GetLeader() + 0x134));
        if (inline_ov003_0216c00c_7(save) == 0) {
            func_ov003_0216d8d4(obj, 0x47);
            *(short*)(obj + 6) = 0x63;
        } else if (LinkSession_IsActive((int*)w) != 0) {
            func_ov003_0216d8d4(obj, 0x3f);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(obj, 0x2b);
            *(short*)(obj + 6) = 1;
            func_02011a40((char*)battle);
        }
    } else if (state == 1) {
        if (*(int*)(g + 0x870) != 3) return;
        if ((&((struct Struct_ov003_0216c00c_15*)battle)->sub.rec)->unknown_3_2_ != 0) {
            func_ov003_0216d8d4(obj, 0x2d);
            *(short*)(obj + 6) = 3;
        } else {
            func_ov003_0216d8d4(obj, 0x2c);
            *(short*)(obj + 6) = 2;
        }
    } else if (state == 2) {
        if (*(int*)(g + 0x870) != 0) return;
        if (func_020457e0(g) == 1) {
            *(int*)(g + 0x868) = 1;
            func_ov003_0216d8d4(obj, 0x40);
            *(short*)(obj + 6) = 3;
            struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetProtagonist();
            if (c != 0) {
                struct Struct_ov003_0216c00c_2* fp = inline_ov003_0216c00c((struct Struct_ov003_0215d4fc*)func_02053c6c((unsigned char*)c), 1);
                struct Struct_ov003_0216c00c_5* var12 = &((struct Struct_ov003_0216c00c_15*)battle)->sub.rec;
                var12->unknown_3_1_ = fp->b0;
                var12->unknown_2_5_ = fp->b0;
                struct Struct_ov003_0216c00c_5* rec = inline_ov003_0216c00c_11(battle);
                rec->v = ((struct Struct_ov003_0216c00c_13*)c)->unknown_144_->unknown_8b8_ + 700;
            }
        } else {
            MessageSystem_Reset(g);
            *(short*)(obj + 4) = 7;
            *(short*)(obj + 6) = 0;
            func_ov017_021c1798(ov17, 0);
        }
    } else if (state == 3) {
        if (*(int*)(g + 0x870) != 0) return;
        *(int*)(g + 0x868) = 1;
        if (func_020457e0(g) == 1) {
            if (func_02011804((GameState*)battle) != 0) {
                func_ov003_0216d8d4(obj, 0x4c);
                *(short*)(obj + 6) = 0x64;
            } else {
                func_ov003_0216d8d4(obj, 0x5e);
                *(short*)(obj + 6) = 0x12c;
            }
        } else {
            func_ov003_0216d8d4(obj, 0x2f);
            *(short*)(obj + 6) = 0x67;
        }
    } else if (state == 0x67) {
        if (*(int*)(g + 0x870) != 3) return;
        *(int*)(g + 0x868) = 1;
        if (func_02011804((GameState*)battle) != 0) {
            func_ov003_0216d8d4(obj, 0x4d);
            *(short*)(obj + 6) = 0x64;
        } else {
            func_ov003_0216d8d4(obj, 0x5e);
            *(short*)(obj + 6) = 0x12c;
        }
    } else if (state == 0x64) {
        if (*(int*)(g + 0x870) != 0) return;
        *(int*)(g + 0x868) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x48);
            *(short*)(obj + 6) = 0x12c;
        } else {
            func_ov003_0216d8d4(obj, 0x49);
            *(short*)(obj + 6) = 0x65;
        }
    } else if (state == 4) {
        if (*(int*)(g + 0x870) != 0) return;
        *(int*)(g + 0x868) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32);
            *(short*)(obj + 6) = 0x63;
        } else if (func_02011804((GameState*)battle) != 0) {
            func_ov003_0216d8d4(obj, 0x39);
            *(short*)(obj + 6) = 0x65;
        } else {
            func_ov003_0216d8d4(obj, 0x30);
            *(short*)(obj + 6) = 5;
        }
    } else if (state == 0x65) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
        if (*(int*)(g + 0x870) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        func_020119d8(battle);
        func_ov017_021a9ff0(0);
    } else if (state == 0x66) {
        if (*(int*)(g + 0x870) != 0) return;
        *(int*)(g + 0x868) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(obj, 0x30);
            *(short*)(obj + 6) = 5;
        }
    } else if (state == 5) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
        *(int*)(obj + 0x1000 + 0x298) += (int)((GameState*)battle)->GetTickCount();
        if (*(int*)(g + 0x870) != 0) {
            if (*(int*)(obj + 0x1000 + 0x298) < 0x12c) return;
        }
        *(int*)(obj + 0x1000 + 0x298) = 0;
        MessageSystem_Reset(g);
        func_0209c2e0(&g_bgmPlayer, 0, 0x12);
        func_ov003_02170d88(obj + 0x368 + 0x400);
        struct TreasureMapMetadata var14;
        func_020119f8((char*)battle, &var14);
        int mapType = var14.GetMapType();
        if (mapType != 0) {
            *(unsigned char*)(obj + 0x911) = 1;
            METAJ(obj)->DiscoveryStateAndMapTypeAndUnknown = var14.DiscoveryStateAndMapTypeAndUnknown;
            *(struct Struct_ov003_0216c00c_9*)METAJ(obj)->DiscoveredBy = *(struct Struct_ov003_0216c00c_9*)var14.DiscoveredBy;
            *(struct Struct_ov003_0216c00c_9*)METAJ(obj)->ClearedBy = *(struct Struct_ov003_0216c00c_9*)var14.ClearedBy;
            METAJ(obj)->Location = var14.Location;
            METAJ(obj)->TreasureDiscoveryFlags = var14.TreasureDiscoveryFlags;
            METAJ(obj)->QualityOrLegacyBossID = var14.QualityOrLegacyBossID;
            METAJ(obj)->LegacyBossLevel = var14.LegacyBossLevel;
            METAJ(obj)->SeedOrMinTurns = var14.SeedOrMinTurns;
        } else {
            *(unsigned char*)(obj + 0x911) = 0;
        }
        void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x13800);
        ((SafeAllocator*)(obj + 0x164 + 0x1000))->CreateTypeA(mem, 0x13800);
        func_ov003_02173c40(obj + 0xda0);
        func_ov003_021726f8(obj + 0xda0, (SafeAllocator*)(obj + 0x164 + 0x1000));
        Struct_ov003_0216c00c* var17 = (Struct_ov003_0216c00c*)(obj + 0x368 + 0x400);
        if (var17 != 0) {
            *(Struct_ov003_0216c00c**)(obj + 0xe6c) = var17;
        }
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x10080);
        SetMainBrightness(ov17, -16, 0x24);
        SetSubBrightness(ov17, -16, 0x24);
        *(short*)(obj + 6) = 6;
    } else if (state == 6) {
        int r;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        GameObject_DisableControl((Obj020397cc*)c, 1);
        if (IsBrightnessTransitionActive(ov17) != 0) {
            if (inline_ov003_0216c00c_10(obj) == 0) return;
        }
        if (*(int*)(obj + 0x1000 + 0x280) > 0) {
            *(int*)(obj + 0x1000 + 0x280) -= 1;
        }
        if (inline_ov003_0216c00c_10(obj) == 0 && *(int*)(obj + 0x1000 + 0x280) == 0) {
            r = func_ov003_021714a0((Struct_ov003_0216c00c*)(obj + 0x368 + 0x400));
            *(unsigned char*)(obj + 0x1000 + 0x27b) = (unsigned char)r;
            if ((r & 0xff) == 0) {
                *(int*)(obj + 0x1000 + 0x280) = 0xb4;
            }
        }
        if (func_ov003_021727c8(obj + 0xda0) == 0) {
        *(unsigned char*)(obj + 0x1000 + 0x27b) = 1;
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x10080);
        *(unsigned char*)(obj + 0x1000 + 0x27e) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x27e) = *(unsigned char*)(obj + 0xe70);
        int flag = *(unsigned char*)(obj + 0xd97);
        *(unsigned char*)(obj + 0x1000 + 0x27d) = *(unsigned char*)(obj + 0xe62);
        func_ov003_02170d38(obj + 0x368 + 0x400);
        func_ov003_02173d40(obj + 0xda0);
        void* sig = ((SafeAllocator*)(obj + 0x164 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x164 + 0x1000))->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
        }
        int var22[0x2c];
        func_020ac4c0(var22);
        func_020a03f8((Struct_020a03f8*)var22, *(unsigned char*)(obj + 0x1000 + 0x27e));
        func_020ac494(var22);
        { int cur = inline_ov003_0216c00c_5(save); inline_ov003_0216c00c_6(save, *(unsigned char*)(obj + 0x1000 + 0x27d) + cur); }
        if (flag != 0) {
            struct CombatantStruct* cc = (CombatantStruct*)((GameState*)battle)->GetLeader();
            int i;
            for (i = 0; i < 4; i++) {
                if (i == *(short*)((char*)cc + 4)) {
                    Vec3 pos = *(Vec3*)((char*)cc + 0x44);
                    Vec3 rot = *(Vec3*)((char*)cc + 0x50);
                    pos.z += 0x1800;
                    func_02059f38((Struct_02059cfc_2*)cc, (Struct_02059cfc_3*)&pos);
                    GameObject_SnapFacing((Obj02033874*)cc, 0);
                } else {
                    void* r = ((GameState*)battle)->GetPartyMemberByIndex(i);
                    if (r != 0) {
                        ((Object3D*)r)->MakeHidden();
                    }
                }
            }
            *(short*)(obj + 6) = 0xd;
        } else {
            *(short*)(obj + 6) = 0xc;
        }
        }
    } else if (state == 7) {
        if (*(int*)(g + 0x870) != 3) return;
        func_ov003_0216d8d4(obj, 0x35);
        *(short*)(obj + 6) = 0x62;
    } else if (state == 8) {
        if (*(int*)(g + 0x870) != 3) return;
        if (*(unsigned char*)(obj + 0x1000 + 0x27d) != 0) {
            *(unsigned char*)(obj + 0x1000 + 0x27d) = 0;
            func_ov003_0216d8d4(obj, 0x42);
        } else {
            func_ov003_0216d8d4(obj, 0x35);
        }
        *(short*)(obj + 6) = 0x62;
    } else if (state == 9) {
        if (*(int*)(g + 0x870) != 3) return;
        func_ov003_0216d8d4(obj, 0x36);
        *(short*)(obj + 6) = 0x62;
    } else if (state == 0xa) {
        if (*(int*)(g + 0x870) != 3) return;
        func_ov003_0216d8d4(obj, 0x37);
        *(short*)(obj + 6) = 8;
    } else if (state == 0xb) {
        if (*(int*)(g + 0x870) != 3) return;
        func_ov003_0216d8d4(obj, 0x38);
        *(short*)(obj + 6) = 8;
    } else if (state == 0xc) {
        FontBankLoader* actor = FontBankLoader_GetInstance();
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        if (c != 0) {
            GameObject_DisableControl((Obj020397cc*)c, 1);
        }
        func_02094b34(actor, 0x1f5, 0x66, 0, 0);
        if (func_02094b4c(actor) == 0) return;
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        void* p8 = *(void**)((char*)ctx + 8);
        int val = ((struct Struct_ov003_0216c00c_8*)p8)->v;
        func_0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if (*(unsigned char*)(obj + 0x1000 + 0x279) != 0) {
            *(int*)(g + 0x868) = 1;
            func_ov003_0216d8d4(obj, 0x4b);
            *(short*)(obj + 6) = 0x62;
            return;
        }
        *(int*)(g + 0x868) = 1;
        func_ov003_0216d8d4(obj, 0x33);
        unsigned char var33 = *(unsigned char*)(obj + 0x1000 + 0x27e);
        if (var33 == 0) {
            *(short*)(obj + 6) = 9;
            goto phase2;
        }
        if (var33 < 3) {
            inline_ov003_0216c00c_8(save, 0);
            *(short*)(obj + 6) = 0xa;
        } else {
            inline_ov003_0216c00c_8(save, 0);
            *(short*)(obj + 6) = 0xb;
        }
    }

phase2:;
    state = *(short*)(obj + 6);
    if (state == 0x12c) {
        if (*(int*)(g + 0x870) != 0) return;
        *(int*)(g + 0x868) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_020a9ea4((Struct020a9ea4*)(obj + 0x29c + 0x1000));
            func_ov003_0216d8d4(obj, 0xc8);
            *(short*)(obj + 6) = 0x12e;
            FlagWord_SetBits((unsigned int*)dataPtr0, 0x80);
        }
        return;
    } else if (state == 0x12e) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x27c) |= 4;
        BackgroundLoader::AddLockGlobal();
        if (func_020aad1c((int)(obj + 0x29c + 0x1000), (int)g_fileLoadBuffer, 8, 0) == 1) {
            *(unsigned char*)(obj + 0x1000 + 0x27c) &= ~4;
            func_ov003_0216d8d4(obj, 0xc9);
            *(short*)(obj + 6) = 0x12f;
            BackgroundLoader::RemoveLockGlobal();
        }
        return;
    } else if (state == 0x12f) {
        FlagWord_ClearBits((FlagWord020466f4*)dataPtr0, 0x80);
        if (*(int*)(g + 0x870) != 3) return;
        func_ov003_0216d8d4(obj, 0x30);
        *(short*)(obj + 6) = 5;
        return;
    } else if (state == 0x130) {
        func_ov003_0216d8d4(obj, 0x30);
        *(short*)(obj + 6) = 5;
        return;
    } else if (state == 0xd) {
        *(short*)(obj + 8) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x27c) |= 1;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        if (c != 0) {
            GameObject_DisableControl((Obj020397cc*)c, 1);
        }
        *(unsigned char*)(obj + 0x1000 + 0x279) = 1;
        *(short*)(obj + 6) = 0xe;
        return;
    } else if (state == 0xe) {
        ((SafeAllocator*)(obj + 0x178 + 0x1000))->ResetAllocatorPointer();
        void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc800);
        ((SafeAllocator*)(obj + 0x178 + 0x1000))->CreateTypeA(mem, 0xc800);
        ((SafeAllocator*)(obj + 0x178 + 0x1000))->Reset();
        unsigned int fileSize;
        void* fileData = LoadFileIntoNewAllocation(data_ov003_0217e99c, *(SafeAllocator*)(obj + 0x178 + 0x1000), &fileSize);
        if (fileData == 0) {
            *(short*)(obj + 6) = 0xf;
            return;
        }
        struct Foo0207df50* fields = (struct Foo0207df50*)((char (*)[0x70])ov17->vramStates_)[0x1c];
        VramState_Rewind(fields);
        VramState_Restore((char*)fields);
        struct ObjectArchiveLoadInfo loadInfo;
        loadInfo.unk_0 = 0;
        loadInfo.unk_14 = 0;
        loadInfo.unk_18 = 0;
        loadInfo.packageID = 0;
        loadInfo.unk_10 = 0;
        loadInfo.allocator = (SafeAllocator*)(obj + 0x178 + 0x1000);
        loadInfo.fileData = fileData;
        loadInfo.fileSize = fileSize;
        ((Object3D*)(obj + 0x1cc + 0x1000))->LoadFromCHRArchive(&loadInfo);
        VramState_Save((char*)fields);
        *(unsigned char*)(obj + 0x1000 + 0x278) = 1;
        ((Object3D*)(obj + 0x1cc + 0x1000))->SetAnimationByName(data_ov003_0217e9b4, 1);
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        func_02059f38((Struct_02059cfc_2*)(obj + 0x1cc + 0x1000), (Struct_02059cfc_3*)((char*)c + 0x44));
        ((Object3D*)(obj + 0x1cc + 0x1000))->SetScale(&((Object3D*)c)->GetScale());
        SetBrightness(ov17, 0, 0xa);
        *(short*)(obj + 6) = 0xf;
        return;
    } else if (state == 0xf) {
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        ((Object3D*)(obj + 0x1cc + 0x1000))->AdvanceEffects();
        if (((Object3D*)(obj + 0x1cc + 0x1000))->HasAnimationStopped() == 0) return;
        void* sig = ((SafeAllocator*)(obj + 0x178 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x178 + 0x1000))->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
        }
        *(unsigned char*)(obj + 0x1000 + 0x278) = 0;
        void* combatant2 = *(void**)((char*)ov17 + 0x3928);
        func_020465c0((StoreStruct*)g, 1, func_ov017_021b1fb0(combatant2));
        short key = func_ov017_021b1fa8(combatant2) + 0x64;
        MessageSystem_SetStringArgument((Obj02046574*)g, 5, KeyTable_Get((Container020e0310*)(obj + 0x1b4 + 0x1000), key));
        *(int*)(g + 0x868) = 1;
        func_ov003_0216d8d4(obj, 0x4f);
        *(short*)(obj + 6) = 0x10;
        return;
    } else if (state == 0x10) {
        if (*(int*)(g + 0x868) != 0) return;
        SetBrightness(ov17, -16, 0x1e);
        *(short*)(obj + 6) = 0x11;
        return;
    } else if (state == 0x11) {
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        int i;
        for (i = 0; i < 4; i++) {
            if (i == *(short*)((char*)c + 4)) {
                Vec3 pos = *(Vec3*)((char*)c + 0x44);
                Vec3 rot = *(Vec3*)((char*)c + 0x50);
                pos.z -= 0x1800;
                func_02059f38((Struct_02059cfc_2*)c, (Struct_02059cfc_3*)&pos);
                GameObject_SnapFacing((Obj02033874*)c, 0x323d);
            } else {
                void* r = ((GameState*)battle)->GetPartyMemberByIndex(i);
                if (r != 0) {
                    ((Object3D*)r)->MakeVisible();
                }
            }
        }
        SetBrightness(ov17, 0, 0x1e);
        *(short*)(obj + 6) = 0x12;
        return;
    } else if (state == 0x12) {
        void* c2 = Zone3D_GetInstance();
        int val = (*(struct Struct_ov003_0216c00c_8**)((char*)c2 + 8))->v;
        func_0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if ((unsigned int)func_02011804((GameState*)battle) >= 0x63) {
            *(short*)(obj + 6) = 0x13;
            char* g2 = (char*)MessageSystem_GetInstance();
            *(int*)(g2 + 0x868) = 1;
            func_ov003_0216d8d4(obj, 0x72);
            *(int*)(g + 0x218) = 1;
        } else {
            void* var52 = GetGameResources();
            struct CombatantStruct* c3 = *(struct CombatantStruct**)((char*)var52 + 0x3000 + 0x928);
            struct {
                unsigned char count;
                char pad;
                struct TreasureMapMetadata unknown_2_[99];
            } region;
            func_020ac760(&region);
            VectorizedMemset(&region.unknown_2_[region.count], 0, sizeof(struct TreasureMapMetadata));
            int var55 = func_ov017_021b1fa8(c3);
            int var56 = func_ov017_021b1fb0(c3);
            region.unknown_2_[region.count].InitialiseAsLegacyBossMap(var55, var56);
            void* var57 = func_ov017_021b1fb8(c3);
            VectorizedInvertedMemcpy(var57, region.unknown_2_[region.count].DiscoveredBy, 8);
            region.count += 1;
            func_020ac734(&region);
            *(short*)(obj + 6) = 0xc;
        }
        return;
    } else if (state == 0x13) {
        char* g2 = (char*)MessageSystem_GetInstance();
        if (*(int*)(g2 + 0x868) != 0) return;
        int var59 = func_020457e0(g2);
        if (var59 == 0) {
            *(short*)(obj + 6) = 0xc;
            return;
        }
        if (var59 != 1) return;
        void* var60 = GetGameResources();
        struct CombatantStruct* c4 = *(struct CombatantStruct**)((char*)var60 + 0x3000 + 0x928);
        char nameBuf[0x28];
        VectorizedMemset(nameBuf, 0, 0x28);
        nameBuf[7] = 0;
        nameBuf[0x13] = 0;
        nameBuf[6] = 0;
        *(int*)(nameBuf + 0x20) = -1;
        nameBuf[0] = 2;
        nameBuf[1] = (char)func_ov017_021b1fa8(c4);
        nameBuf[2] = (char)func_ov017_021b1fb0(c4);
        *(short*)(nameBuf + 4) = 0;
        nameBuf[6] = 1;
        void* var63 = func_ov017_021b1fb8(c4);
        strcpy(nameBuf + 7, (char*)var63);
        func_02011818(battle, (Struct_02011818*)nameBuf);
        int level = func_ov017_021b1fb0(c4);
        char var65[0x20];
        sprintf(var65, data_ov003_0217e9b8, level);
        func_02011ab8((char*)battle);
        func_02011a74((char*)battle, 0, KeyTable_Get((Container020e0310*)(obj + 0x1b4 + 0x1000), (short)(func_ov017_021b1fa8(c4) + 0x64)));
        func_02011a74((char*)battle, 1, KeyTable_Get((Container020e0310*)(obj + 0x1b4 + 0x1000), 0x64));
        func_02011a74((char*)battle, 3, var65);
        func_ov017_021a9ff0(1);
        *(short*)(obj + 6) = 0x14;
        return;
    } else if (state == 0x14) {
        void* var66 = GetGameResources();
        void* p = *(void**)((char*)var66 + 0x3000 + 0x92c);
        if (*((unsigned char*)p + 2) == 0) {
            *(short*)(obj + 6) = 0xc;
        }
        return;
    } else if (state == 0x63) {
        if (*(int*)(g + 0x870) != 3) return;
        *(int*)(g + 0x868) = 1;
        func_ov003_0216d8d4(obj, 0x29);
        *(short*)(obj + 6) = 0;
        *(short*)(obj + 4) = 2;
        *(short*)(obj + 6) = 0;
        return;
    } else if (state == 0x62) {
        if (*(int*)(g + 0x870) != 0 || *(int*)(g + 0x868) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
    }
}
#else
// USA: func_ov003_0216c00c
extern "C" ARM void func_ov003_0216c00c(char* obj) {
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    GameResources* ov17 = GetGameResources();
    char* g = (char*)MessageSystem_GetInstance();
    void* ctx = Zone3D_GetInstance();
    void* w = LinkSession_GetInstance();
    void* dataPtr0 = GlobalFlags_GetInstance();

    short var74 = *(short*)(obj + 0xa);
    if (var74 == 1) {
        func_ov003_0216d8d4(obj, 0x41, -1, -1, -1);
        *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
        *(int*)(g + 0x99c) = 2;
        *(int*)(g + 0x998) = 1;
        *(short*)(obj + 6) = 3;
        *(short*)(obj + 0xa) = 0;
    } else if (var74 == 2) {
        struct TreasureMapMetadata var75;
        func_020119f8((char*)battle, &var75);
        if (var75.GetMapType() != 0) {
            func_ov003_0216d8d4(obj, 0x4a, -1, -1, -1);
        } else {
            func_ov003_0216d8d4(obj, 0x43, -1, -1, -1);
        }
        *(short*)(obj + 6) = 0x12c;
        *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
        *(int*)(g + 0x99c) = 2;
        *(int*)(g + 0x998) = 1;
        *(short*)(obj + 0xa) = 0;
    }

    short state = *(short*)(obj + 6);
    if (state == 0) {
        if (inline_ov003_0216c00c_7(inline_ov003_0216c00c_4(ctx)) == 0) {
            func_ov003_0216d8d4(obj, 0x47, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else if (LinkSession_IsActive((int*)w) != 0) {
            func_ov003_0216d8d4(obj, 0x3f, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(obj, 0x2b, -1, -1, -1);
            *(short*)(obj + 6) = 1;
            func_02011a40((char*)battle);
        }
    } else if (state == 1) {
        if (*(int*)(g + 0x9a0) != 3) return;
        if ((&((struct Struct_ov003_0216c00c_7*)battle)->sub.rec)->unknown_3_2_ != 0) {
            func_ov003_0216d8d4(obj, 0x2d, -1, -1, -1);
            *(short*)(obj + 6) = 3;
        } else {
            func_ov003_0216d8d4(obj, 0x2c, -1, -1, -1);
            *(short*)(obj + 6) = 2;
        }
    } else if (state == 2) {
        if (*(int*)(g + 0x9a0) != 0) return;
        if (func_020457e0(g) == 1) {
            *(int*)(g + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x40, -1, -1, -1);
            *(short*)(obj + 6) = 3;
            struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetProtagonist();
            if (c != 0) {
                struct Struct_ov003_0216c00c_2* fp = inline_ov003_0216c00c((struct Struct_ov003_0215d4fc*)func_02053c6c((unsigned char*)c), 1);
                struct Struct_ov003_0216c00c_5* var79 = &((struct Struct_ov003_0216c00c_7*)battle)->sub.rec;
                var79->unknown_3_1_ = fp->b0;
                var79->unknown_2_5_ = fp->b0;
                struct Struct_ov003_0216c00c_5* rec = &inline_ov003_0216c00c_2(battle)->rec;
                int base = 20700;
                if (fp->b0 == 1) base += 50;
                rec->v = base - 20000 + ((struct Struct_ov003_0216c00c_4*)c)->f150->unknown_950_;
            }
        } else {
            MessageSystem_Reset(g);
            *(short*)(obj + 4) = 7;
            *(short*)(obj + 6) = 0;
            func_ov017_021c1798(ov17, 0);
        }
    } else if (state == 3) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            if (func_02011804((GameState*)battle) != 0) {
                func_ov003_0216d8d4(obj, 0x4c, -1, -1, -1);
                *(short*)(obj + 6) = 0x64;
            } else {
                func_ov003_0216d8d4(obj, 0x5e, -1, -1, -1);
                *(short*)(obj + 6) = 0x12c;
            }
        } else {
            func_ov003_0216d8d4(obj, 0x2f, -1, -1, -1);
            *(short*)(obj + 6) = 0x67;
        }
    } else if (state == 0x67) {
        if (*(int*)(g + 0x9a0) != 3) return;
        *(int*)(g + 0x998) = 1;
        if (func_02011804((GameState*)battle) != 0) {
            func_ov003_0216d8d4(obj, 0x4d, -1, -1, -1);
            *(short*)(obj + 6) = 0x64;
        } else {
            func_ov003_0216d8d4(obj, 0x5e, -1, -1, -1);
            *(short*)(obj + 6) = 0x12c;
        }
    } else if (state == 0x64) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x48, -1, -1, -1);
            *(short*)(obj + 6) = 0x12c;
        } else {
            func_ov003_0216d8d4(obj, 0x49, -1, -1, -1);
            *(short*)(obj + 6) = 0x65;
        }
    } else if (state == 4) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else if (func_02011804((GameState*)battle) != 0) {
            func_ov003_0216d8d4(obj, 0x39, -1, -1, -1);
            *(short*)(obj + 6) = 0x65;
        } else {
            func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
            *(short*)(obj + 6) = 5;
        }
    } else if (state == 0x65) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        if (*(int*)(g + 0x9a0) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        func_020119d8(battle);
        func_ov017_021a9ff0(0);
    } else if (state == 0x66) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
            *(short*)(obj + 6) = 5;
        }
    } else if (state == 5) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        *(int*)(obj + 0x1000 + 0x408) += (int)((GameState*)battle)->GetTickCount();
        if (*(int*)(g + 0x9a0) != 0) {
            if (*(int*)(obj + 0x1000 + 0x408) < 0x12c) return;
        }
        *(int*)(obj + 0x1000 + 0x408) = 0;
        MessageSystem_Reset(g);
        func_0209c2e0(&g_bgmPlayer, 0, 0x12);
        func_ov003_02170d88(obj + 0x7e0);
        struct TreasureMapMetadata var82;
        func_020119f8((char*)battle, &var82);
        int mapType = var82.GetMapType();
        if (mapType != 0) {
            *(unsigned char*)(obj + 0x9ad) = 1;
            META(obj)->DiscoveryStateAndMapTypeAndUnknown = var82.DiscoveryStateAndMapTypeAndUnknown;
            *(struct Struct_ov003_0216c00c_9*)META(obj)->DiscoveredBy = *(struct Struct_ov003_0216c00c_9*)var82.DiscoveredBy;
            *(struct Struct_ov003_0216c00c_9*)META(obj)->ClearedBy = *(struct Struct_ov003_0216c00c_9*)var82.ClearedBy;
            META(obj)->Location = var82.Location;
            META(obj)->TreasureDiscoveryFlags = var82.TreasureDiscoveryFlags;
            META(obj)->QualityOrLegacyBossID = var82.QualityOrLegacyBossID;
            META(obj)->LegacyBossLevel = var82.LegacyBossLevel;
            META(obj)->SeedOrMinTurns = var82.SeedOrMinTurns;
        } else {
            *(unsigned char*)(obj + 0x9ad) = 0;
        }
        void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x13800);
        ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->CreateTypeA(mem, 0x13800);
        func_ov003_02173c40(obj + 0x31c + 0xc00);
        func_ov003_021726f8(obj + 0x31c + 0xc00, (SafeAllocator*)(obj + 0x2d4 + 0x1000));
        Struct_ov003_0216c00c* var85 = (Struct_ov003_0216c00c*)(obj + 0x7e0);
        if (var85 != 0) {
            *(Struct_ov003_0216c00c**)(obj + 0xfec) = var85;
        }
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x10080);
        SetMainBrightness(ov17, -16, 0x24);
        SetSubBrightness(ov17, -16, 0x24);
        *(short*)(obj + 6) = 6;
    } else if (state == 6) {
        int r;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        GameObject_DisableControl((Obj020397cc*)c, 1);
        if (IsBrightnessTransitionActive(ov17) != 0) {
            if (inline_ov003_0216c00c_3(obj) == 0) return;
        }
        if (*(int*)(obj + 0x1000 + 0x3f0) > 0) {
            *(int*)(obj + 0x1000 + 0x3f0) -= 1;
        }
        if (inline_ov003_0216c00c_3(obj) == 0 && *(int*)(obj + 0x1000 + 0x3f0) == 0) {
            r = func_ov003_021714a0((Struct_ov003_0216c00c*)(obj + 0x7e0));
            *(unsigned char*)(obj + 0x1000 + 0x3eb) = (unsigned char)r;
            if ((r & 0xff) == 0) {
                *(int*)(obj + 0x1000 + 0x3f0) = 0xb4;
            }
        }
        if (func_ov003_021727c8(obj + 0x31c + 0xc00) == 0) {
        *(unsigned char*)(obj + 0x1000 + 0x3eb) = 1;
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x10080);
        *(unsigned char*)(obj + 0x1000 + 0x3ee) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ee) = *(unsigned char*)(obj + 0xff0);
        int flag = *(unsigned char*)(obj + 0xf13);
        *(unsigned char*)(obj + 0x1000 + 0x3ed) = *(unsigned char*)(obj + 0xfe0);
        func_ov003_02170d38(obj + 0x7e0);
        func_ov003_02173d40(obj + 0x31c + 0xc00);
        void* sig = ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
        }
        int var90[0x2c];
        func_020ac4c0(var90);
        func_020a03f8((Struct_020a03f8*)var90, *(unsigned char*)(obj + 0x1000 + 0x3ee));
        func_020ac494(var90);
        inline_ov003_0216c00c_6(inline_ov003_0216c00c_4(ctx), *(unsigned char*)(obj + 0x1000 + 0x3ed) + inline_ov003_0216c00c_5(inline_ov003_0216c00c_4(ctx)));
        if (flag != 0) {
            struct CombatantStruct* cc = (CombatantStruct*)((GameState*)battle)->GetLeader();
            int i;
            for (i = 0; i < 4; i++) {
                if (i == *(short*)((char*)cc + 4)) {
                    Vec3 pos = *(Vec3*)((char*)cc + 0x44);
                    Vec3 rot = *(Vec3*)((char*)cc + 0x50);
                    pos.z += 0x1800;
                    func_02059f38((Struct_02059cfc_2*)cc, (Struct_02059cfc_3*)&pos);
                    GameObject_SnapFacing((Obj02033874*)cc, 0);
                } else {
                    void* r = ((GameState*)battle)->GetPartyMemberByIndex(i);
                    if (r != 0) {
                        ((Object3D*)r)->MakeHidden();
                    }
                }
            }
            *(short*)(obj + 6) = 0xd;
        } else {
            *(short*)(obj + 6) = 0xc;
        }
        }
    } else if (state == 7) {
        if (*(int*)(g + 0x9a0) != 3) return;
        unsigned char var96 = *(unsigned char*)(obj + 0x1000 + 0x3ee);
        func_ov003_0216d8d4(obj, 0x35, -1, -1, var96);
        *(short*)(obj + 6) = 0x62;
    } else if (state == 8) {
        if (*(int*)(g + 0x9a0) != 3) return;
        if (*(unsigned char*)(obj + 0x1000 + 0x3ed) != 0) {
            *(unsigned char*)(obj + 0x1000 + 0x3ed) = 0;
            func_ov003_0216d8d4(obj, 0x42, -1, -1, -1);
        } else {
            unsigned char var97 = *(unsigned char*)(obj + 0x1000 + 0x3ee);
            func_ov003_0216d8d4(obj, 0x35, -1, -1, var97);
        }
        *(short*)(obj + 6) = 0x62;
    } else if (state == 9) {
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x36, -1, -1, -1);
        *(short*)(obj + 6) = 0x62;
    } else if (state == 0xa) {
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x37, -1, -1, -1);
        *(short*)(obj + 6) = 8;
    } else if (state == 0xb) {
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x38, -1, -1, -1);
        *(short*)(obj + 6) = 8;
    } else if (state == 0xc) {
        FontBankLoader* actor = FontBankLoader_GetInstance();
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        if (c != 0) {
            GameObject_DisableControl((Obj020397cc*)c, 1);
        }
        func_02094b34(actor, 0x1f5, 0x66, 0, 0);
        if (func_02094b4c(actor) == 0) return;
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        void* p8 = *(void**)((char*)ctx + 8);
        int val = ((struct Struct_ov003_0216c00c_8*)p8)->v;
        func_0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if (*(unsigned char*)(obj + 0x1000 + 0x3e9) != 0) {
            *(int*)(g + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x4b, -1, -1, -1);
            *(short*)(obj + 6) = 0x62;
            return;
        }
        *(int*)(g + 0x998) = 1;
        func_ov003_0216d8d4(obj, 0x33, -1, -1, -1);
        unsigned char var102 = *(unsigned char*)(obj + 0x1000 + 0x3ee);
        if (var102 == 0) {
            *(short*)(obj + 6) = 9;
            goto phase2;
        }
        if (var102 < 3) {
            inline_ov003_0216c00c_8(inline_ov003_0216c00c_4(ctx), 0);
            *(short*)(obj + 6) = 0xa;
        } else {
            inline_ov003_0216c00c_8(inline_ov003_0216c00c_4(ctx), 0);
            *(short*)(obj + 6) = 0xb;
        }
    }

phase2:;
    state = *(short*)(obj + 6);
    if (state == 0x12c) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_020a9ea4((Struct020a9ea4*)(obj + 0xc + 0x1400));
            func_ov003_0216d8d4(obj, 0xc8, -1, -1, -1);
            *(short*)(obj + 6) = 0x12e;
            FlagWord_SetBits((unsigned int*)dataPtr0, 0x80);
        }
        return;
    } else if (state == 0x12e) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ec) |= 4;
        BackgroundLoader::AddLockGlobal();
        if (func_020aad1c((int)(obj + 0xc + 0x1400), (int)g_fileLoadBuffer, 8, 0) == 1) {
            *(unsigned char*)(obj + 0x1000 + 0x3ec) &= ~4;
            func_ov003_0216d8d4(obj, 0xc9, -1, -1, -1);
            *(short*)(obj + 6) = 0x12f;
            BackgroundLoader::RemoveLockGlobal();
        }
        return;
    } else if (state == 0x12f) {
        FlagWord_ClearBits((FlagWord020466f4*)dataPtr0, 0x80);
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
        *(short*)(obj + 6) = 5;
        return;
    } else if (state == 0x130) {
        func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
        *(short*)(obj + 6) = 5;
        return;
    } else if (state == 0xd) {
        *(short*)(obj + 8) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ec) |= 1;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        if (c != 0) {
            GameObject_DisableControl((Obj020397cc*)c, 1);
        }
        *(unsigned char*)(obj + 0x1000 + 0x3e9) = 1;
        *(short*)(obj + 6) = 0xe;
        return;
    } else if (state == 0xe) {
        ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->ResetAllocatorPointer();
        void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xc800);
        ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->CreateTypeA(mem, 0xc800);
        ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->Reset();
        unsigned int fileSize;
        void* fileData = LoadFileIntoNewAllocation(data_ov003_021801e0, *(SafeAllocator*)(obj + 0x2e8 + 0x1000), &fileSize);
        if (fileData == 0) {
            *(short*)(obj + 6) = 0xf;
            return;
        }
        struct Foo0207df50* fields = (struct Foo0207df50*)((char (*)[0x70])ov17->vramStates_)[0x1c];
        VramState_Rewind(fields);
        VramState_Restore((char*)fields);
        struct ObjectArchiveLoadInfo loadInfo;
        loadInfo.unk_0 = 0;
        loadInfo.unk_14 = 0;
        loadInfo.unk_18 = 0;
        loadInfo.packageID = 0;
        loadInfo.unk_10 = 0;
        loadInfo.allocator = (SafeAllocator*)(obj + 0x2e8 + 0x1000);
        loadInfo.fileData = fileData;
        loadInfo.fileSize = fileSize;
        ((Object3D*)(obj + 0x33c + 0x1000))->LoadFromCHRArchive(&loadInfo);
        VramState_Save((char*)fields);
        *(unsigned char*)(obj + 0x1000 + 0x3e8) = 1;
        ((Object3D*)(obj + 0x33c + 0x1000))->SetAnimationByName(data_ov003_021801f8, 1);
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        func_02059f38((Struct_02059cfc_2*)(obj + 0x33c + 0x1000), (Struct_02059cfc_3*)((char*)c + 0x44));
        ((Object3D*)(obj + 0x33c + 0x1000))->SetScale(&((Object3D*)c)->GetScale());
        SetBrightness(ov17, 0, 0xa);
        *(short*)(obj + 6) = 0xf;
        return;
    } else if (state == 0xf) {
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        ((Object3D*)(obj + 0x33c + 0x1000))->AdvanceEffects();
        if (((Object3D*)(obj + 0x33c + 0x1000))->HasAnimationStopped() == 0) return;
        void* sig = ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
        }
        *(unsigned char*)(obj + 0x1000 + 0x3e8) = 0;
        void* combatant2 = *(void**)((char*)ov17 + 0x3b48);
        *(int*)(g + 0x998) = 1;
        int var112 = func_ov017_021b1fa8(combatant2);
        int var113 = func_ov017_021b1fb0(combatant2);
        func_ov003_0216d8d4(obj, 0x4f, var112 + 0x64, var113, -1);
        *(short*)(obj + 6) = 0x10;
        return;
    } else if (state == 0x10) {
        if (*(int*)(g + 0x998) != 0) return;
        SetBrightness(ov17, -16, 0x1e);
        *(short*)(obj + 6) = 0x11;
        return;
    } else if (state == 0x11) {
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        int i;
        for (i = 0; i < 4; i++) {
            if (i == *(short*)((char*)c + 4)) {
                Vec3 pos = *(Vec3*)((char*)c + 0x44);
                Vec3 rot = *(Vec3*)((char*)c + 0x50);
                pos.z -= 0x1800;
                func_02059f38((Struct_02059cfc_2*)c, (Struct_02059cfc_3*)&pos);
                GameObject_SnapFacing((Obj02033874*)c, 0x323d);
            } else {
                void* r = ((GameState*)battle)->GetPartyMemberByIndex(i);
                if (r != 0) {
                    ((Object3D*)r)->MakeVisible();
                }
            }
        }
        SetBrightness(ov17, 0, 0x1e);
        *(short*)(obj + 6) = 0x12;
        return;
    } else if (state == 0x12) {
        void* c2 = Zone3D_GetInstance();
        int val = (*(struct Struct_ov003_0216c00c_8**)((char*)c2 + 8))->v;
        func_0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if ((unsigned int)func_02011804((GameState*)battle) >= 0x63) {
            *(short*)(obj + 6) = 0x13;
            char* g2 = (char*)MessageSystem_GetInstance();
            *(int*)(g2 + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x72, -1, -1, -1);
            *(int*)(g + 0x2c8) = 1;
        } else {
            void* var122 = GetGameResources();
            struct CombatantStruct* c3 = *(struct CombatantStruct**)((char*)var122 + 0x3000 + 0xb48);
            struct {
                unsigned char count;
                char pad;
                struct TreasureMapMetadata unknown_2_[99];
            } region;
            func_020ac760(&region);
            unsigned char idx = region.count;
            struct TreasureMapMetadata* slot = &region.unknown_2_[idx];
            VectorizedMemset(slot, 0, sizeof(struct TreasureMapMetadata));
            int var127 = func_ov017_021b1fa8(c3);
            int var128 = func_ov017_021b1fb0(c3);
            slot->InitialiseAsLegacyBossMap(var127, var128);
            void* var129 = func_ov017_021b1fb8(c3);
            VectorizedInvertedMemcpy(var129, (char*)slot + 1, 8);
            region.count += 1;
            func_020ac734(&region);
            *(short*)(obj + 6) = 0xc;
        }
        return;
    } else if (state == 0x13) {
        char* g2 = (char*)MessageSystem_GetInstance();
        if (*(int*)(g2 + 0x998) != 0) return;
        int var131 = func_020457e0(g2);
        if (var131 == 0) {
            *(short*)(obj + 6) = 0xc;
            return;
        }
        if (var131 != 1) return;
        void* var132 = GetGameResources();
        struct CombatantStruct* c4 = *(struct CombatantStruct**)((char*)var132 + 0x3000 + 0xb48);
        char nameBuf[0x28];
        VectorizedMemset(nameBuf, 0, 0x28);
        nameBuf[7] = 0;
        nameBuf[0x13] = 0;
        nameBuf[6] = 0;
        *(int*)(nameBuf + 0x20) = -1;
        nameBuf[0] = 2;
        nameBuf[1] = (char)func_ov017_021b1fa8(c4);
        nameBuf[2] = (char)func_ov017_021b1fb0(c4);
        *(short*)(nameBuf + 4) = 0;
        nameBuf[6] = 1;
        void* var135 = func_ov017_021b1fb8(c4);
        strcpy(nameBuf + 7, (char*)var135);
        func_02011818(battle, (Struct_02011818*)nameBuf);
        const char* lvPrefix = StandardStrings_Get(1011);
        int level = func_ov017_021b1fb0(c4);
        char var138[0x20];
        sprintf(var138, data_ov003_021801fc, lvPrefix, level);
        func_02011ab8((char*)battle);
        short itemID = (short)(func_ov017_021b1fa8(c4) + 0x45);
        const char* itemName = StandardStrings_Get(itemID);
        char popup[0x40];
        sprintf(popup, data_ov003_02180201, itemName, var138);
        func_02011a74((char*)battle, 0, popup);
        func_ov017_021a9ff0(1);
        *(short*)(obj + 6) = 0x14;
        return;
    } else if (state == 0x14) {
        void* var142 = GetGameResources();
        void* p = *(void**)((char*)var142 + 0x3000 + 0xb4c);
        if (*((unsigned char*)p + 2) == 0) {
            *(short*)(obj + 6) = 0xc;
        }
        return;
    } else if (state == 0x63) {
        if (*(int*)(g + 0x9a0) != 3) return;
        *(int*)(g + 0x998) = 1;
        func_ov003_0216d8d4(obj, 0x29, -1, -1, -1);
        *(short*)(obj + 6) = 0;
        *(short*)(obj + 4) = 2;
        *(short*)(obj + 6) = 0;
        return;
    } else if (state == 0x62) {
        if (*(int*)(g + 0x9a0) != 0 || *(int*)(g + 0x998) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
    }
}
#endif
