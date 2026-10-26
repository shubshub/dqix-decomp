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
struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
};
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};

int MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance();
void* GlobalFlags_GetInstance(void);
#if defined(jpn)
extern "C" void func_ov003_0216d8d4(char* arg0, int arg1);
#else
extern "C" void func_ov003_0216d8d4(char* arg0, int arg1, int arg2, int arg3, int arg4);
#endif
extern "C" int func_020457e0(char* obj);
void MessageSystem_Reset(char* obj);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion*, void*);
void ResetState02170d38(char*);
class Base021714a0;
extern "C" int func_ov003_021714a0(Base021714a0* obj);
extern "C" void func_ov003_02173c40(char* obj);
extern "C" void func_ov003_021726f8(char* obj, SafeAllocator* allocator);
extern "C" void VectorizedMemset(void*, int, int);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
extern "C" int func_020aad1c(int arg0, int arg1, int arg2, int arg3);

extern "C" void func_ov003_02170d88(void* arg0);
extern "C" int func_ov003_021727c8(char* arg0);
extern "C" void func_ov003_02173d40(char* arg0);

void CopyToRegion0x6482IfDst_020119f8(char*, void*);
int LinkSession_IsActive(int*);
void StoreInvalidTreasureMapMetadata_02011a40(char*);
void* GetFieldAt0x150_02053c6c(unsigned char*);
struct GameState;
extern "C" int func_02011804(GameState*);
extern "C" void func_020119d8(void*);
extern "C" void func_ov017_021a9ff0(int arg0);
extern "C" void func_ov017_021c1798(GameResources* arg0, unsigned char arg1);
int IsBrightnessTransitionActive(void* word);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);
void FlagWord_SetBits(unsigned int* word, unsigned int mask);
void SetMainBrightness(void* obj, int a, int b);
void SetSubBrightness(void* obj, int a, int b);
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
struct Struct020a9ea4;
void ClearStruct020a9ea4(Struct020a9ea4*);
extern "C" void func_0209c2e0(void* obj, int a, int b);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(Target02059f38*, Vec3_02059f38*);
struct Obj02033874;
void GameObject_SnapFacing(Obj02033874*, int);
struct Foo0207df50;
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);
int GetByteField28_021b1fa8(void* p);
int GetByteField29_021b1fb0(void* p);
void* GetPtrField2a_021b1fb8(void* p);
int LoadBattleBlock020ac4c0(void* dst);
struct S_a03f8;
void AddClamped14BitFieldMidAt0x10_020a03f8(S_a03f8*, unsigned int);
void CopyInBattleField0x7540_020ac494(void* p);
void CopyOutBattleRegion0x64f4_020ac760(void* p);
void CopyToBattleRegion0x64f4_020ac734(void* p);
const char* StandardStrings_Get(int key);
struct Src02011818;
void SetNameEntries02011818(void*, Src02011818*);
void ClearRegion0x649e_02011ab8(char*);
void CopyStringToField0x649e_02011a74(char*, unsigned int, char const*);

extern int g_bgmPlayer;
extern AllocatorUnion g_mainAllocator;
extern unsigned char g_fileLoadBuffer[];
extern char data_ov003_021801e0[];
extern char data_ov003_021801f8[];
extern char data_ov003_021801fc[];
extern char data_ov003_02180201[];

struct Struct_ov003_0216c00c_2 { char unknown_0_[0x414]; unsigned char unknown_414_0_:1; };
struct Struct_01ff91ac_32 { char unknown_0_[0x44]; };
struct Struct_ov003_0216c00c_3 { char unknown_0_[0x950]; int unknown_950_; };
struct Struct_ov003_0216c00c_4 { char unknown_0_[0x150]; struct Struct_ov003_0216c00c_3* unknown_150_; };
struct Struct_ov003_0215d4fc { char unknown_0_[0x44]; struct Struct_01ff91ac_32 unknown_44_[2]; };
static inline struct Struct_ov003_0216c00c_2* inline_ov003_0216c00c(struct Struct_ov003_0215d4fc* arg0, int arg1) {
    return (struct Struct_ov003_0216c00c_2*)&arg0->unknown_44_[arg1];
}
struct Struct_ov003_0216c00c_5 { unsigned int unknown_0_0_:21, unknown_2_5_:4, unknown_3_1_:1, unknown_3_2_:1; int unknown_4_0_:19, unknown_6_3_:11; };
struct Struct_ov003_0216c00c_6 { char unknown_0_[0x5400]; struct Struct_ov003_0216c00c_5 unknown_5400_; };
struct Struct_ov003_0216c00c_7 { char unknown_0_[0x29c]; struct Struct_ov003_0216c00c_6 unknown_29c_; };
static inline struct Struct_ov003_0216c00c_6* inline_ov003_0216c00c_2(void* arg0) { return &((struct Struct_ov003_0216c00c_7*)arg0)->unknown_29c_; }
struct Struct_ov003_0216c00c_8 { char unknown_0_[0xd]; unsigned char unknown_d_0_:7; };
struct Struct_ov003_0216c00c_9 { char unknown_0_[10]; };
struct Struct_ov009_0218aa28 { int unknown_0_, unknown_4_, unknown_8_; ~Struct_ov009_0218aa28() {} };
struct Struct_ov003_0216c00c_10 { char unknown_0_[0xa64]; struct TreasureMapMetadata unknown_a64_; };
#define META(o) (&((struct Struct_ov003_0216c00c_10*)(o))->unknown_a64_)
static inline int inline_ov003_0216c00c_3(char* arg0) {
    return *(unsigned char*)(arg0 + 0x1000 + 8) == 5;
}

struct Struct_ov003_0216c00c_11 { char unknown_0_[0x1b34]; int unknown_1b34_; char unknown_1b38_[0x1b60 - 0x1b38]; unsigned char unknown_1b60_; };
struct Struct_01ff91ac_33 { char unknown_0_[0x840]; struct Struct_ov003_0216c00c_11 unknown_840_; };
static inline struct Struct_ov003_0216c00c_11* inline_ov003_0216c00c_4(void* arg0) { return &((struct Struct_01ff91ac_33*)arg0)->unknown_840_; }
static inline int inline_ov003_0216c00c_5(struct Struct_ov003_0216c00c_11* arg0) { return arg0->unknown_1b34_; }
static inline void inline_ov003_0216c00c_6(struct Struct_ov003_0216c00c_11* arg0, int arg1) { arg0->unknown_1b34_ = arg1; }
static inline unsigned char inline_ov003_0216c00c_7(struct Struct_ov003_0216c00c_11* arg0) { return arg0->unknown_1b60_; }
static inline void inline_ov003_0216c00c_8(struct Struct_ov003_0216c00c_11* arg0, unsigned char arg1) { arg0->unknown_1b60_ = arg1; }
#if defined(jpn)
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
struct Container020e0310;
char* KeyTable_Get(Container020e0310*, int);
extern char data_ov003_0217e99c[];
extern char data_ov003_0217e9b4[];
extern char data_ov003_0217e9b8[];
struct Struct_ov003_0216c00c_12 { char unknown_0_[0x8b8]; int unknown_8b8_; };
struct Struct_ov003_0216c00c_13 { char unknown_0_[0x144]; struct Struct_ov003_0216c00c_12* unknown_144_; };
struct Struct_ov003_0216c00c_14 { char unknown_0_[0x5400]; struct Struct_ov003_0216c00c_5 unknown_5400_; };
struct Struct_ov003_0216c00c_15 { char unknown_0_[0x3c]; struct Struct_ov003_0216c00c_14 unknown_3c_; };
static inline struct Struct_ov003_0216c00c_14* inline_ov003_0216c00c_9(void* arg0) { return &((struct Struct_ov003_0216c00c_15*)arg0)->unknown_3c_; }
struct Struct_ov003_0216c00c_16 { char unknown_0_[0x9c8]; struct TreasureMapMetadata unknown_9c8_; };
#define METAJ(o) (&((struct Struct_ov003_0216c00c_16*)(o))->unknown_9c8_)
static inline int inline_ov003_0216c00c_10(char* arg0) {
    return *(unsigned char*)(arg0 + 0xe88) == 5;
}
static inline struct Struct_ov003_0216c00c_5* inline_ov003_0216c00c_11(void* arg0) { return &inline_ov003_0216c00c_9(arg0)->unknown_5400_; }
struct Struct_ov003_0216c00c_17 { char unknown_0_[0x860]; struct Struct_ov003_0216c00c_11 unknown_860_; };
// JPN: func_ov003_0216c00c
extern "C" ARM void func_ov003_0216c00c(char* obj) {
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    GameResources* ov17 = GetGameResources();
    char* g = (char*)MessageSystem_GetInstance();
    struct CtxJ* ctx = (struct CtxJ*)Zone3D_GetInstance();
    struct Save840* save = &ctx->save;
    void* w = LinkSession_GetInstance();
    void* dataPtr0 = GlobalFlags_GetInstance();

    short var7 = *(short*)(arg0 + 0xa);
    if (var7 == 1) {
        func_ov003_0216d8d4(arg0, 0x41);
        *(unsigned char*)(var2 + 0x1000 + 0x7e2) = 1;
        *(int*)(var2 + 0x86c) = 2;
        *(int*)(var2 + 0x868) = 1;
        *(short*)(arg0 + 6) = 3;
        *(short*)(arg0 + 0xa) = 0;
    } else if (var7 == 2) {
        struct TreasureMapMetadata var8;
        func_020119f8((char*)var0, &var8);
        if (var8.GetMapType() != 0) {
            func_ov003_0216d8d4(arg0, 0x4a);
        } else {
            func_ov003_0216d8d4(arg0, 0x43);
        }
        *(short*)(arg0 + 6) = 0x12c;
        *(unsigned char*)(var2 + 0x1000 + 0x7e2) = 1;
        *(int*)(var2 + 0x86c) = 2;
        *(int*)(var2 + 0x868) = 1;
        *(short*)(arg0 + 0xa) = 0;
    }

    short state = *(short*)(obj + 6);
    if (state == 0) {
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)((char*)((GameState*)battle)->GetLeader() + 0x134));
        if (GetB60(save) == 0) {
            func_ov003_0216d8d4(obj, 0x47);
            *(short*)(obj + 6) = 0x63;
        } else if (LinkSession_IsActive((int*)w) != 0) {
            func_ov003_0216d8d4(obj, 0x3f);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(arg0, 0x2b);
            *(short*)(arg0 + 6) = 1;
            func_02011a40((char*)var0);
        }
    } else if (var9 == 1) {
        if (*(int*)(var2 + 0x870) != 3) return;
        if ((&((struct Struct_ov003_0216c00c_15*)var0)->unknown_3c_.unknown_5400_)->unknown_3_2_ != 0) {
            func_ov003_0216d8d4(arg0, 0x2d);
            *(short*)(arg0 + 6) = 3;
        } else {
            func_ov003_0216d8d4(arg0, 0x2c);
            *(short*)(arg0 + 6) = 2;
        }
    } else if (var9 == 2) {
        if (*(int*)(var2 + 0x870) != 0) return;
        if (func_020457e0(var2) == 1) {
            *(int*)(var2 + 0x868) = 1;
            func_ov003_0216d8d4(arg0, 0x40);
            *(short*)(arg0 + 6) = 3;
            struct Struct_0203d028_3* var10 = (Struct_0203d028_3*)((GameState*)var0)->GetProtagonist();
            if (var10 != 0) {
                struct Struct_ov003_0216c00c_2* var11 = inline_ov003_0216c00c((struct Struct_ov003_0215d4fc*)func_02053c6c((unsigned char*)var10), 1);
                struct Struct_ov003_0216c00c_5* var12 = &((struct Struct_ov003_0216c00c_15*)var0)->unknown_3c_.unknown_5400_;
                var12->unknown_3_1_ = var11->unknown_414_0_;
                var12->unknown_2_5_ = var11->unknown_414_0_;
                struct Struct_ov003_0216c00c_5* var13 = inline_ov003_0216c00c_11(var0);
                var13->unknown_6_3_ = ((struct Struct_ov003_0216c00c_13*)var10)->unknown_144_->unknown_8b8_ + 700;
            }
        } else {
            MessageSystem_Reset(g);
            *(short*)(obj + 4) = 7;
            *(short*)(obj + 6) = 0;
            InitNodeAndInsertAt_021c1798_021c1798(ov17, 0);
        }
    } else if (var9 == 3) {
        if (*(int*)(var2 + 0x870) != 0) return;
        *(int*)(var2 + 0x868) = 1;
        if (func_020457e0(var2) == 1) {
            if (func_02011804((GameState*)var0) != 0) {
                func_ov003_0216d8d4(arg0, 0x4c);
                *(short*)(arg0 + 6) = 0x64;
            } else {
                func_ov003_0216d8d4(arg0, 0x5e);
                *(short*)(arg0 + 6) = 0x12c;
            }
        } else {
            func_ov003_0216d8d4(arg0, 0x2f);
            *(short*)(arg0 + 6) = 0x67;
        }
    } else if (var9 == 0x67) {
        if (*(int*)(var2 + 0x870) != 3) return;
        *(int*)(var2 + 0x868) = 1;
        if (func_02011804((GameState*)var0) != 0) {
            func_ov003_0216d8d4(arg0, 0x4d);
            *(short*)(arg0 + 6) = 0x64;
        } else {
            func_ov003_0216d8d4(arg0, 0x5e);
            *(short*)(arg0 + 6) = 0x12c;
        }
    } else if (var9 == 0x64) {
        if (*(int*)(var2 + 0x870) != 0) return;
        *(int*)(var2 + 0x868) = 1;
        if (func_020457e0(var2) == 1) {
            func_ov003_0216d8d4(arg0, 0x48);
            *(short*)(arg0 + 6) = 0x12c;
        } else {
            func_ov003_0216d8d4(arg0, 0x49);
            *(short*)(arg0 + 6) = 0x65;
        }
    } else if (var9 == 4) {
        if (*(int*)(var2 + 0x870) != 0) return;
        *(int*)(var2 + 0x868) = 1;
        if (func_020457e0(var2) == 1) {
            func_ov003_0216d8d4(arg0, 0x32);
            *(short*)(arg0 + 6) = 0x63;
        } else if (func_02011804((GameState*)var0) != 0) {
            func_ov003_0216d8d4(arg0, 0x39);
            *(short*)(arg0 + 6) = 0x65;
        } else {
            func_ov003_0216d8d4(arg0, 0x30);
            *(short*)(arg0 + 6) = 5;
        }
    } else if (state == 0x65) {
        *(unsigned char*)(g + 0x1000 + 0x7de) = 0;
        if (*(int*)(g + 0x870) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        SetByte0x6480_020119d8(battle);
        func_ov017_021a9ff0(0);
    } else if (var9 == 0x66) {
        if (*(int*)(var2 + 0x870) != 0) return;
        *(int*)(var2 + 0x868) = 1;
        if (func_020457e0(var2) == 1) {
            func_ov003_0216d8d4(arg0, 0x32);
            *(short*)(arg0 + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(arg0, 0x30);
            *(short*)(arg0 + 6) = 5;
        }
    } else if (var9 == 5) {
        *(unsigned char*)(var2 + 0x1000 + 0x7de) = 0;
        *(int*)(arg0 + 0x1000 + 0x298) += (int)((GameState*)var0)->GetTickCount();
        if (*(int*)(var2 + 0x870) != 0) {
            if (*(int*)(arg0 + 0x1000 + 0x298) < 0x12c) return;
        }
        *(int*)(obj + 0x1000 + 0x298) = 0;
        MessageSystem_Reset(g);
        func_0209c2e0(&g_bgmPlayer, 0, 0x12);
        func_ov003_02170d88(obj + 0x368 + 0x400);
        struct TreasureMapMetadata localF0;
        CopyToRegion0x6482IfDst_020119f8((char*)battle, &localF0);
        int mapType = localF0.GetMapType();
        if (mapType != 0) {
            *(unsigned char*)(obj + 0x911) = 1;
            METAJ(obj)->DiscoveryStateAndMapTypeAndUnknown = localF0.DiscoveryStateAndMapTypeAndUnknown;
            *(struct Name10*)METAJ(obj)->DiscoveredBy = *(struct Name10*)localF0.DiscoveredBy;
            *(struct Name10*)METAJ(obj)->ClearedBy = *(struct Name10*)localF0.ClearedBy;
            METAJ(obj)->Location = localF0.Location;
            METAJ(obj)->TreasureDiscoveryFlags = localF0.TreasureDiscoveryFlags;
            METAJ(obj)->QualityOrLegacyBossID = localF0.QualityOrLegacyBossID;
            METAJ(obj)->LegacyBossLevel = localF0.LegacyBossLevel;
            METAJ(obj)->SeedOrMinTurns = localF0.SeedOrMinTurns;
        } else {
            *(unsigned char*)(arg0 + 0x911) = 0;
        }
        void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x13800);
        ((SafeAllocator*)(obj + 0x164 + 0x1000))->CreateTypeA(mem, 0x13800);
        func_ov003_02173c40(obj + 0xda0);
        func_ov003_021726f8(obj + 0xda0, (SafeAllocator*)(obj + 0x164 + 0x1000));
        Base021714a0* base768 = (Base021714a0*)(obj + 0x368 + 0x400);
        if (base768 != 0) {
            *(Base021714a0**)(obj + 0xe6c) = base768;
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
            if (IsKind5J(obj) == 0) return;
        }
        if (*(int*)(arg0 + 0x1000 + 0x280) > 0) {
            *(int*)(arg0 + 0x1000 + 0x280) -= 1;
        }
        if (inline_ov003_0216c00c_10(arg0) == 0 && *(int*)(arg0 + 0x1000 + 0x280) == 0) {
            var18 = func_ov003_021714a0((Struct_ov003_0216c00c*)(arg0 + 0x368 + 0x400));
            *(unsigned char*)(arg0 + 0x1000 + 0x27b) = (unsigned char)var18;
            if ((var18 & 0xff) == 0) {
                *(int*)(arg0 + 0x1000 + 0x280) = 0xb4;
            }
        }
        if (func_ov003_021727c8(obj + 0xda0) == 0) {
        *(unsigned char*)(obj + 0x1000 + 0x27b) = 1;
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x10080);
        *(unsigned char*)(obj + 0x1000 + 0x27e) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x27e) = *(unsigned char*)(obj + 0xe70);
        int flag = *(unsigned char*)(obj + 0xd97);
        *(unsigned char*)(obj + 0x1000 + 0x27d) = *(unsigned char*)(obj + 0xe62);
        ResetState02170d38(obj + 0x368 + 0x400);
        func_ov003_02173d40(obj + 0xda0);
        void* sig = ((SafeAllocator*)(obj + 0x164 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x164 + 0x1000))->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
        }
        int battleBlock[0x2c];
        LoadBattleBlock020ac4c0(battleBlock);
        AddClamped14BitFieldMidAt0x10_020a03f8((S_a03f8*)battleBlock, *(unsigned char*)(obj + 0x1000 + 0x27e));
        CopyInBattleField0x7540_020ac494(battleBlock);
        { int cur = GetB34(save); SetB34(save, *(unsigned char*)(obj + 0x1000 + 0x27d) + cur); }
        if (flag != 0) {
            struct CombatantStruct* cc = (CombatantStruct*)((GameState*)battle)->GetLeader();
            int i;
            for (i = 0; i < 4; i++) {
                if (i == *(short*)((char*)cc + 4)) {
                    Vec3 pos = *(Vec3*)((char*)cc + 0x44);
                    Vec3 rot = *(Vec3*)((char*)cc + 0x50);
                    pos.z += 0x1800;
                    CopyVec3ToField0x44((Target02059f38*)cc, (Vec3_02059f38*)&pos);
                    GameObject_SnapFacing((Obj02033874*)cc, 0);
                } else {
                    void* var28 = ((GameState*)var0)->GetPartyMemberByIndex(var25);
                    if (var28 != 0) {
                        ((Object3D*)var28)->MakeHidden();
                    }
                }
            }
            *(short*)(arg0 + 6) = 0xd;
        } else {
            *(short*)(arg0 + 6) = 0xc;
        }
        }
    } else if (var9 == 7) {
        if (*(int*)(var2 + 0x870) != 3) return;
        func_ov003_0216d8d4(arg0, 0x35);
        *(short*)(arg0 + 6) = 0x62;
    } else if (var9 == 8) {
        if (*(int*)(var2 + 0x870) != 3) return;
        if (*(unsigned char*)(arg0 + 0x1000 + 0x27d) != 0) {
            *(unsigned char*)(arg0 + 0x1000 + 0x27d) = 0;
            func_ov003_0216d8d4(arg0, 0x42);
        } else {
            func_ov003_0216d8d4(arg0, 0x35);
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
        BlankFunction02094b34(actor, 0x1f5, 0x66, 0, 0);
        if (AlwaysTrue02094b4c(actor) == 0) return;
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        void* p8 = *(void**)((char*)ctx + 8);
        int val = ((struct B7*)p8)->v;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if (*(unsigned char*)(obj + 0x1000 + 0x279) != 0) {
            *(int*)(g + 0x868) = 1;
            func_ov003_0216d8d4(obj, 0x4b);
            *(short*)(obj + 6) = 0x62;
            return;
        }
        *(int*)(var2 + 0x868) = 1;
        func_ov003_0216d8d4(arg0, 0x33);
        unsigned char var33 = *(unsigned char*)(arg0 + 0x1000 + 0x27e);
        if (var33 == 0) {
            *(short*)(arg0 + 6) = 9;
            goto phase2;
        }
        if (var33 < 3) {
            inline_ov003_0216c00c_8(var4, 0);
            *(short*)(arg0 + 6) = 0xa;
        } else {
            inline_ov003_0216c00c_8(var4, 0);
            *(short*)(arg0 + 6) = 0xb;
        }
    }

phase2:;
    var9 = *(short*)(arg0 + 6);
    if (var9 == 0x12c) {
        if (*(int*)(var2 + 0x870) != 0) return;
        *(int*)(var2 + 0x868) = 1;
        if (func_020457e0(var2) == 1) {
            func_ov003_0216d8d4(arg0, 0x32);
            *(short*)(arg0 + 6) = 0x63;
        } else {
            ClearStruct020a9ea4((Struct020a9ea4*)(obj + 0x29c + 0x1000));
            func_ov003_0216d8d4(obj, 0xc8);
            *(short*)(obj + 6) = 0x12e;
            FlagWord_SetBits((unsigned int*)dataPtr0, 0x80);
        }
        return;
    } else if (var9 == 0x12e) {
        *(unsigned char*)(var2 + 0x1000 + 0x7de) = 0;
        *(unsigned char*)(arg0 + 0x1000 + 0x27c) |= 4;
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
    } else if (var9 == 0x130) {
        func_ov003_0216d8d4(arg0, 0x30);
        *(short*)(arg0 + 6) = 5;
        return;
    } else if (state == 0xd) {
        *(short*)(obj + 8) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x27c) |= 1;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        if (c != 0) {
            GameObject_DisableControl((Obj020397cc*)c, 1);
        }
        *(unsigned char*)(arg0 + 0x1000 + 0x279) = 1;
        *(short*)(arg0 + 6) = 0xe;
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
        CopyVec3ToField0x44((Target02059f38*)(obj + 0x1cc + 0x1000), (Vec3_02059f38*)((char*)c + 0x44));
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
        StoreInArray0x8b0_020465c0((StoreStruct*)g, 1, GetByteField29_021b1fb0(combatant2));
        short key = GetByteField28_021b1fa8(combatant2) + 0x64;
        MessageSystem_SetStringArgument((Obj02046574*)g, 5, KeyTable_Get((Container020e0310*)(obj + 0x1b4 + 0x1000), key));
        *(int*)(g + 0x868) = 1;
        func_ov003_0216d8d4(obj, 0x4f);
        *(short*)(obj + 6) = 0x10;
        return;
    } else if (var9 == 0x10) {
        if (*(int*)(var2 + 0x868) != 0) return;
        SetBrightness(var1, -16, 0x1e);
        *(short*)(arg0 + 6) = 0x11;
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
                CopyVec3ToField0x44((Target02059f38*)c, (Vec3_02059f38*)&pos);
                GameObject_SnapFacing((Obj02033874*)c, 0x323d);
            } else {
                void* var48 = ((GameState*)var0)->GetPartyMemberByIndex(var45);
                if (var48 != 0) {
                    ((Object3D*)var48)->MakeVisible();
                }
            }
        }
        SetBrightness(var1, 0, 0x1e);
        *(short*)(arg0 + 6) = 0x12;
        return;
    } else if (state == 0x12) {
        void* c2 = Zone3D_GetInstance();
        int val = (*(struct B7**)((char*)c2 + 8))->v;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if ((unsigned int)ReadBattleField0x64f4Byte_02011804((GameState*)battle) >= 0x63) {
            *(short*)(obj + 6) = 0x13;
            char* g2 = (char*)MessageSystem_GetInstance();
            *(int*)(g2 + 0x868) = 1;
            func_ov003_0216d8d4(obj, 0x72);
            *(int*)(g + 0x218) = 1;
        } else {
            void* var52 = GetGameResources();
            struct Struct_0203d028_3* var53 = *(struct Struct_0203d028_3**)((char*)var52 + 0x3000 + 0x928);
            struct {
                unsigned char unknown_0_;
                char unknown_1_;
                struct TreasureMapMetadata unknown_2_[99];
            } var54;
            func_020ac760(&var54);
            VectorizedMemset(&var54.unknown_2_[var54.unknown_0_], 0, sizeof(struct TreasureMapMetadata));
            int var55 = func_ov017_021b1fa8(var53);
            int var56 = func_ov017_021b1fb0(var53);
            var54.unknown_2_[var54.unknown_0_].InitialiseAsLegacyBossMap(var55, var56);
            void* var57 = func_ov017_021b1fb8(var53);
            VectorizedInvertedMemcpy(var57, var54.unknown_2_[var54.unknown_0_].DiscoveredBy, 8);
            var54.unknown_0_ += 1;
            func_020ac734(&var54);
            *(short*)(arg0 + 6) = 0xc;
        }
        return;
    } else if (state == 0x13) {
        char* g2 = (char*)MessageSystem_GetInstance();
        if (*(int*)(g2 + 0x868) != 0) return;
        int fr = func_020457e0(g2);
        if (fr == 0) {
            *(short*)(obj + 6) = 0xc;
            return;
        }
        if (fr != 1) return;
        void* mb = GetGameResources();
        struct CombatantStruct* c4 = *(struct CombatantStruct**)((char*)mb + 0x3000 + 0x928);
        char nameBuf[0x28];
        VectorizedMemset(nameBuf, 0, 0x28);
        nameBuf[7] = 0;
        nameBuf[0x13] = 0;
        nameBuf[6] = 0;
        *(int*)(nameBuf + 0x20) = -1;
        nameBuf[0] = 2;
        nameBuf[1] = (char)GetByteField28_021b1fa8(c4);
        nameBuf[2] = (char)GetByteField29_021b1fb0(c4);
        *(short*)(nameBuf + 4) = 0;
        nameBuf[6] = 1;
        void* p2a = GetPtrField2a_021b1fb8(c4);
        strcpy(nameBuf + 7, (char*)p2a);
        SetNameEntries02011818(battle, (Src02011818*)nameBuf);
        int level = GetByteField29_021b1fb0(c4);
        char lvlString[0x20];
        sprintf(lvlString, data_ov003_0217e9b8, level);
        ClearRegion0x649e_02011ab8((char*)battle);
        CopyStringToField0x649e_02011a74((char*)battle, 0, KeyTable_Get((Container020e0310*)(obj + 0x1b4 + 0x1000), (short)(GetByteField28_021b1fa8(c4) + 0x64)));
        CopyStringToField0x649e_02011a74((char*)battle, 1, KeyTable_Get((Container020e0310*)(obj + 0x1b4 + 0x1000), 0x64));
        CopyStringToField0x649e_02011a74((char*)battle, 3, lvlString);
        func_ov017_021a9ff0(1);
        *(short*)(arg0 + 6) = 0x14;
        return;
    } else if (var9 == 0x14) {
        void* var66 = GetGameResources();
        void* var67 = *(void**)((char*)var66 + 0x3000 + 0x92c);
        if (*((unsigned char*)var67 + 2) == 0) {
            *(short*)(arg0 + 6) = 0xc;
        }
        return;
    } else if (var9 == 0x63) {
        if (*(int*)(var2 + 0x870) != 3) return;
        *(int*)(var2 + 0x868) = 1;
        func_ov003_0216d8d4(arg0, 0x29);
        *(short*)(arg0 + 6) = 0;
        *(short*)(arg0 + 4) = 2;
        *(short*)(arg0 + 6) = 0;
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

    short var74 = *(short*)(arg0 + 0xa);
    if (var74 == 1) {
        func_ov003_0216d8d4(arg0, 0x41, -1, -1, -1);
        *(unsigned char*)(var70 + 0x1000 + 0x9b2) = 1;
        *(int*)(var70 + 0x99c) = 2;
        *(int*)(var70 + 0x998) = 1;
        *(short*)(arg0 + 6) = 3;
        *(short*)(arg0 + 0xa) = 0;
    } else if (var74 == 2) {
        struct TreasureMapMetadata var75;
        func_020119f8((char*)var68, &var75);
        if (var75.GetMapType() != 0) {
            func_ov003_0216d8d4(arg0, 0x4a, -1, -1, -1);
        } else {
            func_ov003_0216d8d4(arg0, 0x43, -1, -1, -1);
        }
        *(short*)(arg0 + 6) = 0x12c;
        *(unsigned char*)(var70 + 0x1000 + 0x9b2) = 1;
        *(int*)(var70 + 0x99c) = 2;
        *(int*)(var70 + 0x998) = 1;
        *(short*)(arg0 + 0xa) = 0;
    }

    short state = *(short*)(obj + 6);
    if (state == 0) {
        if (GetB60(GetSave(ctx)) == 0) {
            func_ov003_0216d8d4(obj, 0x47, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else if (LinkSession_IsActive((int*)w) != 0) {
            func_ov003_0216d8d4(obj, 0x3f, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(arg0, 0x2b, -1, -1, -1);
            *(short*)(arg0 + 6) = 1;
            func_02011a40((char*)var68);
        }
    } else if (var76 == 1) {
        if (*(int*)(var70 + 0x9a0) != 3) return;
        if ((&((struct Struct_ov003_0216c00c_7*)var68)->unknown_29c_.unknown_5400_)->unknown_3_2_ != 0) {
            func_ov003_0216d8d4(arg0, 0x2d, -1, -1, -1);
            *(short*)(arg0 + 6) = 3;
        } else {
            func_ov003_0216d8d4(arg0, 0x2c, -1, -1, -1);
            *(short*)(arg0 + 6) = 2;
        }
    } else if (var76 == 2) {
        if (*(int*)(var70 + 0x9a0) != 0) return;
        if (func_020457e0(var70) == 1) {
            *(int*)(var70 + 0x998) = 1;
            func_ov003_0216d8d4(arg0, 0x40, -1, -1, -1);
            *(short*)(arg0 + 6) = 3;
            struct Struct_0203d028_3* var77 = (Struct_0203d028_3*)((GameState*)var68)->GetProtagonist();
            if (var77 != 0) {
                struct Struct_ov003_0216c00c_2* var78 = inline_ov003_0216c00c((struct Struct_ov003_0215d4fc*)func_02053c6c((unsigned char*)var77), 1);
                struct Struct_ov003_0216c00c_5* var79 = &((struct Struct_ov003_0216c00c_7*)var68)->unknown_29c_.unknown_5400_;
                var79->unknown_3_1_ = var78->unknown_414_0_;
                var79->unknown_2_5_ = var78->unknown_414_0_;
                struct Struct_ov003_0216c00c_5* var80 = &inline_ov003_0216c00c_2(var68)->unknown_5400_;
                int var81 = 20700;
                if (var78->unknown_414_0_ == 1) var81 += 50;
                var80->unknown_6_3_ = var81 - 20000 + ((struct Struct_ov003_0216c00c_4*)var77)->unknown_150_->unknown_950_;
            }
        } else {
            MessageSystem_Reset(g);
            *(short*)(obj + 4) = 7;
            *(short*)(obj + 6) = 0;
            InitNodeAndInsertAt_021c1798_021c1798(ov17, 0);
        }
    } else if (var76 == 3) {
        if (*(int*)(var70 + 0x9a0) != 0) return;
        *(int*)(var70 + 0x998) = 1;
        if (func_020457e0(var70) == 1) {
            if (func_02011804((GameState*)var68) != 0) {
                func_ov003_0216d8d4(arg0, 0x4c, -1, -1, -1);
                *(short*)(arg0 + 6) = 0x64;
            } else {
                func_ov003_0216d8d4(arg0, 0x5e, -1, -1, -1);
                *(short*)(arg0 + 6) = 0x12c;
            }
        } else {
            func_ov003_0216d8d4(arg0, 0x2f, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x67;
        }
    } else if (var76 == 0x67) {
        if (*(int*)(var70 + 0x9a0) != 3) return;
        *(int*)(var70 + 0x998) = 1;
        if (func_02011804((GameState*)var68) != 0) {
            func_ov003_0216d8d4(arg0, 0x4d, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x64;
        } else {
            func_ov003_0216d8d4(arg0, 0x5e, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x12c;
        }
    } else if (var76 == 0x64) {
        if (*(int*)(var70 + 0x9a0) != 0) return;
        *(int*)(var70 + 0x998) = 1;
        if (func_020457e0(var70) == 1) {
            func_ov003_0216d8d4(arg0, 0x48, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x12c;
        } else {
            func_ov003_0216d8d4(arg0, 0x49, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x65;
        }
    } else if (var76 == 4) {
        if (*(int*)(var70 + 0x9a0) != 0) return;
        *(int*)(var70 + 0x998) = 1;
        if (func_020457e0(var70) == 1) {
            func_ov003_0216d8d4(arg0, 0x32, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x63;
        } else if (func_02011804((GameState*)var68) != 0) {
            func_ov003_0216d8d4(arg0, 0x39, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x65;
        } else {
            func_ov003_0216d8d4(arg0, 0x30, -1, -1, -1);
            *(short*)(arg0 + 6) = 5;
        }
    } else if (state == 0x65) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        if (*(int*)(g + 0x9a0) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        SetByte0x6480_020119d8(battle);
        func_ov017_021a9ff0(0);
    } else if (var76 == 0x66) {
        if (*(int*)(var70 + 0x9a0) != 0) return;
        *(int*)(var70 + 0x998) = 1;
        if (func_020457e0(var70) == 1) {
            func_ov003_0216d8d4(arg0, 0x32, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(arg0, 0x30, -1, -1, -1);
            *(short*)(arg0 + 6) = 5;
        }
    } else if (var76 == 5) {
        *(unsigned char*)(var70 + 0x1000 + 0x9ae) = 0;
        *(int*)(arg0 + 0x1000 + 0x408) += (int)((GameState*)var68)->GetTickCount();
        if (*(int*)(var70 + 0x9a0) != 0) {
            if (*(int*)(arg0 + 0x1000 + 0x408) < 0x12c) return;
        }
        *(int*)(obj + 0x1000 + 0x408) = 0;
        MessageSystem_Reset(g);
        func_0209c2e0(&g_bgmPlayer, 0, 0x12);
        func_ov003_02170d88(obj + 0x7e0);
        struct TreasureMapMetadata localF0;
        CopyToRegion0x6482IfDst_020119f8((char*)battle, &localF0);
        int mapType = localF0.GetMapType();
        if (mapType != 0) {
            *(unsigned char*)(obj + 0x9ad) = 1;
            META(obj)->DiscoveryStateAndMapTypeAndUnknown = localF0.DiscoveryStateAndMapTypeAndUnknown;
            *(struct Name10*)META(obj)->DiscoveredBy = *(struct Name10*)localF0.DiscoveredBy;
            *(struct Name10*)META(obj)->ClearedBy = *(struct Name10*)localF0.ClearedBy;
            META(obj)->Location = localF0.Location;
            META(obj)->TreasureDiscoveryFlags = localF0.TreasureDiscoveryFlags;
            META(obj)->QualityOrLegacyBossID = localF0.QualityOrLegacyBossID;
            META(obj)->LegacyBossLevel = localF0.LegacyBossLevel;
            META(obj)->SeedOrMinTurns = localF0.SeedOrMinTurns;
        } else {
            *(unsigned char*)(arg0 + 0x9ad) = 0;
        }
        void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x13800);
        ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->CreateTypeA(mem, 0x13800);
        func_ov003_02173c40(obj + 0x31c + 0xc00);
        func_ov003_021726f8(obj + 0x31c + 0xc00, (SafeAllocator*)(obj + 0x2d4 + 0x1000));
        Base021714a0* base7e0 = (Base021714a0*)(obj + 0x7e0);
        if (base7e0 != 0) {
            *(Base021714a0**)(obj + 0xfec) = base7e0;
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
            if (IsKind5(obj) == 0) return;
        }
        if (*(int*)(arg0 + 0x1000 + 0x3f0) > 0) {
            *(int*)(arg0 + 0x1000 + 0x3f0) -= 1;
        }
        if (inline_ov003_0216c00c_3(arg0) == 0 && *(int*)(arg0 + 0x1000 + 0x3f0) == 0) {
            var86 = func_ov003_021714a0((Struct_ov003_0216c00c*)(arg0 + 0x7e0));
            *(unsigned char*)(arg0 + 0x1000 + 0x3eb) = (unsigned char)var86;
            if ((var86 & 0xff) == 0) {
                *(int*)(arg0 + 0x1000 + 0x3f0) = 0xb4;
            }
        }
        if (func_ov003_021727c8(obj + 0x31c + 0xc00) == 0) {
        *(unsigned char*)(obj + 0x1000 + 0x3eb) = 1;
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x10080);
        *(unsigned char*)(obj + 0x1000 + 0x3ee) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ee) = *(unsigned char*)(obj + 0xff0);
        int flag = *(unsigned char*)(obj + 0xf13);
        *(unsigned char*)(obj + 0x1000 + 0x3ed) = *(unsigned char*)(obj + 0xfe0);
        ResetState02170d38(obj + 0x7e0);
        func_ov003_02173d40(obj + 0x31c + 0xc00);
        void* sig = ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, sig);
        }
        int battleBlock[0x2c];
        LoadBattleBlock020ac4c0(battleBlock);
        AddClamped14BitFieldMidAt0x10_020a03f8((S_a03f8*)battleBlock, *(unsigned char*)(obj + 0x1000 + 0x3ee));
        CopyInBattleField0x7540_020ac494(battleBlock);
        SetB34(GetSave(ctx), *(unsigned char*)(obj + 0x1000 + 0x3ed) + GetB34(GetSave(ctx)));
        if (flag != 0) {
            struct CombatantStruct* cc = (CombatantStruct*)((GameState*)battle)->GetLeader();
            int i;
            for (i = 0; i < 4; i++) {
                if (i == *(short*)((char*)cc + 4)) {
                    Vec3 pos = *(Vec3*)((char*)cc + 0x44);
                    Vec3 rot = *(Vec3*)((char*)cc + 0x50);
                    pos.z += 0x1800;
                    CopyVec3ToField0x44((Target02059f38*)cc, (Vec3_02059f38*)&pos);
                    GameObject_SnapFacing((Obj02033874*)cc, 0);
                } else {
                    void* var95 = ((GameState*)var68)->GetPartyMemberByIndex(var92);
                    if (var95 != 0) {
                        ((Object3D*)var95)->MakeHidden();
                    }
                }
            }
            *(short*)(arg0 + 6) = 0xd;
        } else {
            *(short*)(arg0 + 6) = 0xc;
        }
        }
    } else if (var76 == 7) {
        if (*(int*)(var70 + 0x9a0) != 3) return;
        unsigned char var96 = *(unsigned char*)(arg0 + 0x1000 + 0x3ee);
        func_ov003_0216d8d4(arg0, 0x35, -1, -1, var96);
        *(short*)(arg0 + 6) = 0x62;
    } else if (var76 == 8) {
        if (*(int*)(var70 + 0x9a0) != 3) return;
        if (*(unsigned char*)(arg0 + 0x1000 + 0x3ed) != 0) {
            *(unsigned char*)(arg0 + 0x1000 + 0x3ed) = 0;
            func_ov003_0216d8d4(arg0, 0x42, -1, -1, -1);
        } else {
            unsigned char var97 = *(unsigned char*)(arg0 + 0x1000 + 0x3ee);
            func_ov003_0216d8d4(arg0, 0x35, -1, -1, var97);
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
        BlankFunction02094b34(actor, 0x1f5, 0x66, 0, 0);
        if (AlwaysTrue02094b4c(actor) == 0) return;
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        void* p8 = *(void**)((char*)ctx + 8);
        int val = ((struct B7*)p8)->v;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if (*(unsigned char*)(obj + 0x1000 + 0x3e9) != 0) {
            *(int*)(g + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x4b, -1, -1, -1);
            *(short*)(obj + 6) = 0x62;
            return;
        }
        *(int*)(var70 + 0x998) = 1;
        func_ov003_0216d8d4(arg0, 0x33, -1, -1, -1);
        unsigned char var102 = *(unsigned char*)(arg0 + 0x1000 + 0x3ee);
        if (var102 == 0) {
            *(short*)(arg0 + 6) = 9;
            goto phase2;
        }
        if (var102 < 3) {
            inline_ov003_0216c00c_8(inline_ov003_0216c00c_4(var71), 0);
            *(short*)(arg0 + 6) = 0xa;
        } else {
            inline_ov003_0216c00c_8(inline_ov003_0216c00c_4(var71), 0);
            *(short*)(arg0 + 6) = 0xb;
        }
    }

phase2:;
    var76 = *(short*)(arg0 + 6);
    if (var76 == 0x12c) {
        if (*(int*)(var70 + 0x9a0) != 0) return;
        *(int*)(var70 + 0x998) = 1;
        if (func_020457e0(var70) == 1) {
            func_ov003_0216d8d4(arg0, 0x32, -1, -1, -1);
            *(short*)(arg0 + 6) = 0x63;
        } else {
            ClearStruct020a9ea4((Struct020a9ea4*)(obj + 0xc + 0x1400));
            func_ov003_0216d8d4(obj, 0xc8, -1, -1, -1);
            *(short*)(obj + 6) = 0x12e;
            FlagWord_SetBits((unsigned int*)dataPtr0, 0x80);
        }
        return;
    } else if (var76 == 0x12e) {
        *(unsigned char*)(var70 + 0x1000 + 0x9ae) = 0;
        *(unsigned char*)(arg0 + 0x1000 + 0x3ec) |= 4;
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
    } else if (var76 == 0x130) {
        func_ov003_0216d8d4(arg0, 0x30, -1, -1, -1);
        *(short*)(arg0 + 6) = 5;
        return;
    } else if (state == 0xd) {
        *(short*)(obj + 8) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ec) |= 1;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetLeader();
        if (c != 0) {
            GameObject_DisableControl((Obj020397cc*)c, 1);
        }
        *(unsigned char*)(arg0 + 0x1000 + 0x3e9) = 1;
        *(short*)(arg0 + 6) = 0xe;
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
        CopyVec3ToField0x44((Target02059f38*)(obj + 0x33c + 0x1000), (Vec3_02059f38*)((char*)c + 0x44));
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
        *(unsigned char*)(arg0 + 0x1000 + 0x3e8) = 0;
        void* var111 = *(void**)((char*)var69 + 0x3b48);
        *(int*)(var70 + 0x998) = 1;
        int var112 = func_ov017_021b1fa8(var111);
        int var113 = func_ov017_021b1fb0(var111);
        func_ov003_0216d8d4(arg0, 0x4f, var112 + 0x64, var113, -1);
        *(short*)(arg0 + 6) = 0x10;
        return;
    } else if (var76 == 0x10) {
        if (*(int*)(var70 + 0x998) != 0) return;
        SetBrightness(var69, -16, 0x1e);
        *(short*)(arg0 + 6) = 0x11;
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
                CopyVec3ToField0x44((Target02059f38*)c, (Vec3_02059f38*)&pos);
                GameObject_SnapFacing((Obj02033874*)c, 0x323d);
            } else {
                void* var118 = ((GameState*)var68)->GetPartyMemberByIndex(var115);
                if (var118 != 0) {
                    ((Object3D*)var118)->MakeVisible();
                }
            }
        }
        SetBrightness(var69, 0, 0x1e);
        *(short*)(arg0 + 6) = 0x12;
        return;
    } else if (state == 0x12) {
        void* c2 = Zone3D_GetInstance();
        int val = (*(struct B7**)((char*)c2 + 8))->v;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, val);
        func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
        if ((unsigned int)ReadBattleField0x64f4Byte_02011804((GameState*)battle) >= 0x63) {
            *(short*)(obj + 6) = 0x13;
            char* g2 = (char*)MessageSystem_GetInstance();
            *(int*)(g2 + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x72, -1, -1, -1);
            *(int*)(g + 0x2c8) = 1;
        } else {
            void* var122 = GetGameResources();
            struct Struct_0203d028_3* var123 = *(struct Struct_0203d028_3**)((char*)var122 + 0x3000 + 0xb48);
            struct {
                unsigned char unknown_0_;
                char unknown_1_;
                struct TreasureMapMetadata unknown_2_[99];
            } var124;
            func_020ac760(&var124);
            unsigned char var125 = var124.unknown_0_;
            struct TreasureMapMetadata* var126 = &var124.unknown_2_[var125];
            VectorizedMemset(var126, 0, sizeof(struct TreasureMapMetadata));
            int var127 = func_ov017_021b1fa8(var123);
            int var128 = func_ov017_021b1fb0(var123);
            var126->InitialiseAsLegacyBossMap(var127, var128);
            void* var129 = func_ov017_021b1fb8(var123);
            VectorizedInvertedMemcpy(var129, (char*)var126 + 1, 8);
            var124.unknown_0_ += 1;
            func_020ac734(&var124);
            *(short*)(arg0 + 6) = 0xc;
        }
        return;
    } else if (state == 0x13) {
        char* g2 = (char*)MessageSystem_GetInstance();
        if (*(int*)(g2 + 0x998) != 0) return;
        int fr = func_020457e0(g2);
        if (fr == 0) {
            *(short*)(obj + 6) = 0xc;
            return;
        }
        if (fr != 1) return;
        void* mb = GetGameResources();
        struct CombatantStruct* c4 = *(struct CombatantStruct**)((char*)mb + 0x3000 + 0xb48);
        char nameBuf[0x28];
        VectorizedMemset(nameBuf, 0, 0x28);
        nameBuf[7] = 0;
        nameBuf[0x13] = 0;
        nameBuf[6] = 0;
        *(int*)(nameBuf + 0x20) = -1;
        nameBuf[0] = 2;
        nameBuf[1] = (char)GetByteField28_021b1fa8(c4);
        nameBuf[2] = (char)GetByteField29_021b1fb0(c4);
        *(short*)(nameBuf + 4) = 0;
        nameBuf[6] = 1;
        void* p2a = GetPtrField2a_021b1fb8(c4);
        strcpy(nameBuf + 7, (char*)p2a);
        SetNameEntries02011818(battle, (Src02011818*)nameBuf);
        const char* lvPrefix = StandardStrings_Get(1011);
        int level = GetByteField29_021b1fb0(c4);
        char lvlString[0x20];
        sprintf(lvlString, data_ov003_021801fc, lvPrefix, level);
        ClearRegion0x649e_02011ab8((char*)battle);
        short itemID = (short)(GetByteField28_021b1fa8(c4) + 0x45);
        const char* itemName = StandardStrings_Get(itemID);
        char popup[0x40];
        sprintf(popup, data_ov003_02180201, itemName, lvlString);
        CopyStringToField0x649e_02011a74((char*)battle, 0, popup);
        func_ov017_021a9ff0(1);
        *(short*)(arg0 + 6) = 0x14;
        return;
    } else if (var76 == 0x14) {
        void* var142 = GetGameResources();
        void* var143 = *(void**)((char*)var142 + 0x3000 + 0xb4c);
        if (*((unsigned char*)var143 + 2) == 0) {
            *(short*)(arg0 + 6) = 0xc;
        }
        return;
    } else if (var76 == 0x63) {
        if (*(int*)(var70 + 0x9a0) != 3) return;
        *(int*)(var70 + 0x998) = 1;
        func_ov003_0216d8d4(arg0, 0x29, -1, -1, -1);
        *(short*)(arg0 + 6) = 0;
        *(short*)(arg0 + 4) = 2;
        *(short*)(arg0 + 6) = 0;
        return;
    } else if (state == 0x62) {
        if (*(int*)(g + 0x9a0) != 0 || *(int*)(g + 0x998) != 0) return;
        MessageSystem_Reset(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
    }
}
#endif
