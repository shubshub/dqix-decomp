#include <globaldefs.h>
#include <Resource/IndexedResourceEntry.h>
#include "Resource/FontBankLoader.h"
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/VRAMStaging.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/VRAM.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"
struct Struct_02032e58;

#if defined(jpn)
enum {
    Enum_ov000_021688dc_668 = 0x218,
    Enum_ov000_021688dc_672 = 0x21c,
    Enum_ov000_021688dc_676 = 0x220,
    Enum_ov000_021688dc_14076 = 0x34ec,
    Enum_ov000_021688dc_14132 = 0x3524,
    Enum_ov000_021688dc_6590 = 0x17ee,
    Enum_ov000_021688dc_30674 = 0x79c2,
    Enum_ov000_021688dc_336 = 0x144,
    Enum_ov000_021688dc_22800 = 0x5b00,
    Enum_ov000_021688dc_22784 = 0x5b00,
    Enum_ov000_021688dc_434 = 0x1a6,
    Enum_ov000_021688dc_348 = 0x150,
    Enum_ov000_021688dc_396 = 0x180,
    Enum_ov000_021688dc_340 = 0x148,
    Enum_ov000_021688dc_452 = 0x1b8,
    Enum_ov000_021688dc_29172 = 0x6fb4,
    Enum_ov000_021688dc_29156 = 0x6fa4,
    Enum_ov000_021688dc_29168 = 0x6fb0,
    Enum_ov000_021688dc_21912 = 0x5788,
    Enum_ov000_021688dc_21944 = 0x57a8,
    Enum_ov000_021688dc_14092 = 0x34fc,
    Enum_ov000_021688dc_28196 = 0x7014,
    Enum_ov000_021688dc_28202 = 0x701a,
    Enum_ov000_021688dc_28203 = 0x701b,
    Enum_ov000_021688dc_28204 = 0x701c,
    Enum_ov000_021688dc_28216 = 0x7028,
    Enum_ov000_021688dc_28 = 0xc,
    Enum_ov000_021688dc_27 = 0x2b,
    Enum_ov000_021688dc_17 = 0xc,
};
#else
enum {
    Enum_ov000_021688dc_668 = 0x29c,
    Enum_ov000_021688dc_672 = 0x2a0,
    Enum_ov000_021688dc_676 = 0x2a4,
    Enum_ov000_021688dc_14076 = 0x36fc,
    Enum_ov000_021688dc_14132 = 0x3734,
    Enum_ov000_021688dc_6590 = 0x19be,
    Enum_ov000_021688dc_30674 = 0x77d2,
    Enum_ov000_021688dc_336 = 0x150,
    Enum_ov000_021688dc_22800 = 0x5910,
    Enum_ov000_021688dc_22784 = 0x5900,
    Enum_ov000_021688dc_434 = 0x1b2,
    Enum_ov000_021688dc_348 = 0x15c,
    Enum_ov000_021688dc_396 = 0x18c,
    Enum_ov000_021688dc_340 = 0x154,
    Enum_ov000_021688dc_452 = 0x1c4,
    Enum_ov000_021688dc_29172 = 0x71f4,
    Enum_ov000_021688dc_29156 = 0x71e4,
    Enum_ov000_021688dc_29168 = 0x71f0,
    Enum_ov000_021688dc_21912 = 0x5598,
    Enum_ov000_021688dc_21944 = 0x55b8,
    Enum_ov000_021688dc_14092 = 0x370c,
    Enum_ov000_021688dc_28196 = 0x6e24,
    Enum_ov000_021688dc_28202 = 0x6e2a,
    Enum_ov000_021688dc_28203 = 0x6e2b,
    Enum_ov000_021688dc_28204 = 0x6e2c,
    Enum_ov000_021688dc_28216 = 0x6e38,
    Enum_ov000_021688dc_28 = 0x1c,
    Enum_ov000_021688dc_27 = 0x1b,
    Enum_ov000_021688dc_17 = 0x11,
};
#endif

struct Struct_ov000_02183218 { unsigned char unknown_0_[4]; };

extern "C" void* LinkSession_GetInstance(void);
extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* OamManager_GetInstance(void);
extern "C" void func_02082828(int field150);
extern "C" void func_020542b4(void* a, void* b, void* c);
extern "C" void func_02048b0c(void* obj, int flag);
extern "C" void func_02049c88(void* obj, void* state);
extern "C" void func_02046a8c(void* list, void* node);
extern "C" void FieldMonsterState_Init(void* obj);
extern "C" int func_ov000_02163c80(void* work, int flag);
extern "C" void func_ov000_02168284(void* work);
extern "C" void func_02048150(void* combatant, int a, int b);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void func_ov017_02191234(int a);
extern "C" void func_ov017_021baedc(void* node, int flag);
extern "C" void Party_ReformLine(int ovBase, int c, int d, int e, int flag);
extern "C" void func_ov017_02191aac(int ovBase, int mode, int idx, int mask);
extern "C" void func_ov017_021c9e00(int a, int b, int c, int d);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" void func_ov000_021626a0(void* work, int a, int b);

extern "C" void func_ov017_0218d274(void* arg0);
extern "C" void func_ov017_021901ac(int arg0);

int GameState_GetProtagonistIndex(GameState* state);
void* GameState_GetZoneTransition(GameState* state);
void ClearCombatantSlot_0200fd48(GameState* state, int id);
void GameState_SetCamera(GameState* state, int value);

struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);
void ResetFields14And18KeepFlag0x4_0208902c(unsigned char* obj, int val);
int LinkSession_IsActive(int* obj);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
int CollectSetBitIndicesAt0x34_020a3634(unsigned char* obj, short* outArray);

struct Struct_02048150 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};
extern "C" int func_02086ef0(struct Struct_02048150* arg0, int arg1);

struct Struct_0207d7f4;
extern "C" void func_0207da7c(struct Struct_0207d7f4* arg0, unsigned short arg1);
extern "C" int func_ov000_02160fd4(void* arg0, int arg1);
extern "C" void func_ov000_02160fa8(void* arg0, int arg1);
extern "C" int func_02053c6c(unsigned char* arg0);

struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_FindCurrent(void);
int MessageSystem_GetInstance(void);
void* GetData02108ea8_0207d78c(void);
void* GlobalFlags_GetInstance(void);

void GameObject_EnableControl(void* obj);

struct Obj02053f7c;
void SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c* obj, unsigned short a, int b);
struct Obj02049f50;
void SetField41AndScaleSub02049f50(struct Obj02049f50* obj, int val, int count);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);
void GameObject_UnfreezeAnimation(ObjectStatePrefix* obj);
void SetFlag0x1ceBit0x4_02039d48(unsigned char* obj);
void GameObject_ClearHidden(unsigned char* obj);
void GameObject_ResumeFollowing(unsigned char* obj);
struct Obj02033874;
void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
int CallHelperIfCheckPasses_0218fcf8(int a, int b, int c);
void GameObject_ResetTrail(unsigned char* obj);
void SetIntField0x264_02039758(void* obj, int val);

struct SearchStruct;
struct SearchStruct0202c1a4;
int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" void _Z25EnqueueEventTag8_021cc4b8hhi(int a, int b, int c);
void SetField0x158_02053ec8(void* obj, int value);

struct Bytes02033b88;
int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
GameObject* FindCombatantByField16a_021a278c(void* unused, int val);

struct Foo0207df50;
void FormatAndAppendCombatMessage02072d58(int combatantId, char* statsBuf, char* outBuf);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
void VramState_Rewind(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Struct_0203d028_11;
extern "C" void func_0203dafc(struct Struct_0203d028_11* arg0);

void SePlayer_LoadArchive(void* objRaw, int mode);

struct Struct_0201bdac_2;
struct Struct_0201bdac;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

void StoreBattleParams0201bf38(unsigned char* obj, int set, int a, int b, unsigned short c);
void SetOrClearBit1_0201bf70(unsigned char* obj, int set);
void InitContext020e1154(void* obj);
void SetFlag320_02195530(unsigned char* obj);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
int ClassifyField0x81fe_ov000_0215fc60(char* base);
void CallHelperWithBuf_021907dc(int a, int b, int c, int d, int e);

extern "C" void* func_020e3580(void);
extern "C" int func_020e37e8(unsigned char* arg0);
extern "C" void func_020e3798(unsigned char* arg0);

extern "C" void func_020bb48c(unsigned int arg0, int arg1);
extern "C" void func_ov017_021c8c04(int, int, int);
extern "C" void _ZN8Object3D10SetField06Et(void* arg0, int arg1);

struct Struct_ov000_021688dc { unsigned char unknown_0_0_ : 2; unsigned char unknown_0_2_ : 6; };

extern Struct_ov000_02183218 data_ov000_02183218;
extern int data_ov000_02183b0c;
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern const char data_ov000_02183b20[];
extern const char data_ov000_02183b3b[];
extern const char data_ov000_02183b55[];
extern int g_sePlayer;

void GameState_SetPartyOrder(char* obj, int len, void* src);
struct Slot70 { char data[0x70]; };
static inline SafeAllocator* GetAllocator38(GameResources* res, int i) { return &res->allocator_array_38[i]; }
static inline Slot70* GetSlot2cc(GameResources* res, int i) { return &((Slot70*)res->vramStates_)[i]; }

static inline short GetObjectId(GameObject* c) { return c->obj3D_.actorIndex_; }

static inline int inline_ov000_021688dc_3(GameObject* arg0) {
    return (**(int**)((char*)arg0 + 0x130) & 1) != 0;
}

// USA: func_ov000_021688dc
extern "C" ARM void func_ov000_021688dc(unsigned char* arg0) {
    if (((BackgroundLoader*)((void*)(int)BackgroundLoader::GetInstance()))->GetNumQueuedTasks() > 0) {
        return;
    }

    GPCReadPair var0;
    char var1[0xa];
    char var2[0xa];
    char var3[0x28];
    ObjectArchiveLoadInfo var4;
    ObjectArchiveLoadInfo var5;
    Struct_ov000_02183218 var6;
    short var7[4];
    unsigned int var8;

    GameState* battle = GameState::GetInstance();
    int ovBase = (int)GetGameResources();
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    unsigned short* p30 = Zone3D_GetInstance();
    OamManager_GetInstance();

    void* p29c = *(void**)(work + kWorkData);
    struct ArrayContainsByteStruct* arrStruct = (struct ArrayContainsByteStruct*)GameState_GetParty(battle);
    GameObject* prot = battle->GetProtagonist();
    struct Entry_02028bd0* entry = ZoneRecords_FindCurrent();
    int globalBase = MessageSystem_GetInstance();
    void* dataPtr20 = GetData02108ea8_0207d78c();
    void* p1c = *(void**)(ovBase + kResourceNode);
    unsigned char* p18 = *(unsigned char**)(ovBase + kResourceParams);
    GlobalFlags_GetInstance();

    if (*((unsigned char*)p29c + 0x8e97) != 0) {
        GameObject* c = battle->GetPartyMemberByIndex(GameState_GetProtagonistIndex(battle));
        if (c != NULL && IsFlag10088Set_02010088((struct S_10088*)c)) {
            ResetFields14And18KeepFlag0x4_0208902c(*(unsigned char**)((char*)c + 0x138), 1);
            Party_ReformLine(ovBase, 1, 1, 1, 1);
        }
    }

    GameObject* c397c = battle->GetLeader();

    if (LinkSession_IsActive((int*)search)) {
        int allFlagged = 1;
        int k;
        for (k = 0; k < 4; k++) {
            if (TestBitAt0x34_020a35e0(*(unsigned char**)(work + kWorkConfig), k)) {
                GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, k);
                if (c != NULL) {
                    if (!IsFlag10088Set_02010088((struct S_10088*)c)) {
                        allFlagged = 0;
                        break;
                    }
                }
            }
        }
        if (var23) {
            *(*(unsigned char**)(arg0 + Enum_ov000_021688dc_668) + 0x8e14) = 2;
        }
    }

    func_ov017_0218d274((void*)var10);
    ClearFlags04((GameResources*)var10, 0x200000);
    func_0207da7c((struct Struct_0207d7f4*)var18, *(unsigned short*)(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672) + 8));
    *(unsigned char*)(var17 + Enum_ov000_021688dc_6590) = 0;

    if (func_ov000_02160fd4(arg0, 0x400000)) {
        GameObject* var26 = func_0200ff1c(var9, 1);
        if (var26 != NULL) {
            int var27 = func_02053c6c((unsigned char*)var26);
            if (var27 != 0) {
                func_02082828(var27);
            }
        }
        var14->unknown_f7c_ -= 1;
        func_0200fd48(var9, 1);
        var9->SetTimeOfDay((TimeOfDay)2);

        int regionCount = 1;
        region = data_ov000_02183218;
        GameState_SetPartyOrder((char*)battle, regionCount, &region);

        SafeAllocator* var29 = inline_ov000_02164fac((GameResources*)var10, 3);
        Struct_ov000_02164fac_2* var30 = inline_ov000_021688dc((GameResources*)var10, 3);
        func_020542b4(func_ov017_021a11f4((GameResources*)var10, 2), var29, var30);
        *(int*)((char*)LightingManager::GetInstance() + 0x98) = 2;
    }

    int var31 = func_020a3634(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var7);

    if (c397c != NULL) {
        GameObject_EnableControl(c397c);
        *((unsigned char*)c397c + 0xc3) = 0xf;
    }

    short leadId = prot->obj3D_.actorIndex_;
    if (ArrayContainsByte_02086ef0(arrStruct, 0)) {
        for (int idx = 0; idx < arrStruct->count; idx++) {
            GameObject* c = battle->GetPartyMemberByIndex(arrStruct->arr[idx]);
            if (c != NULL && !IsFlag10088Set_02010088((struct S_10088*)c)) {
                if (!IsFlag130Bit0(c)) {
                    leadId = c->obj3D_.actorIndex_;
                    break;
                }
            }
        }
    } else {
        leadId = c397c->obj3D_.actorIndex_;
    }

    for (int var35 = 0; var35 < 4; var35++) {
        if (func_020a35e0(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var35)) {
            GameObject* var36 = var9->GetPartyMemberByIndex(var35);
            if (var36 != NULL) {
                var36->obj3D_.MakeVisible();
                func_02053f7c((struct Struct_02053f7c_3*)var36, 0, 0);
                func_02049f50((struct Struct_02049f50*)var36, 0x1f, 0);
                func_ov017_02191aac(var10, 0, var35, 2);
                func_ov017_02191aac(var10, 0, var35, 4);

                if (GetCombatWorkFlags0x55f4_ov000_02160fd4(work, 1) && work[kWorkPlacementFlag] != 0) {
                    func_02048b0c(c, TestBitInArray0x8ec_02083b00(*(unsigned char**)((char*)c + kCombatantRecord), 0x99) ? 1 : 0);
                    GameObject_UnfreezeAnimation((ObjectStatePrefix*)c);
                }

                if (ArrayContainsByte_02086ef0(arrStruct, GetObjectId(c))) {
                    if (leadId != c->obj3D_.actorIndex_) {
                        SetFlag0x1ceBit0x4_02039d48((unsigned char*)c);
                    }
                    if (GetCombatWorkFlags0x55f4_ov000_02160fd4(work, 1)) {
                        c->obj3D_.position_ = *(Vector3i*)(work + kWorkPositions + leadId * 16);
                        GameObject_SnapFacing((struct Obj02033874*)c, *(short*)(work + leadId * 16 + kWorkHeightBase + kWorkHeightOffset));
                    }
                } else {
                    if (GetCombatWorkFlags0x55f4_ov000_02160fd4(work, 1)) {
                        c->obj3D_.position_ = *(Vector3i*)(work + kWorkPositions + i * 16);
                        GameObject_SnapFacing((struct Obj02033874*)c, *(short*)(work + i * 16 + kWorkHeightBase + kWorkHeightOffset));
                    }
                    if (*(unsigned short*)((char*)c + kCombatantHeightFlag) != 0) {
                        GameObject_ClearHidden((unsigned char*)c);
                    }
                }

                c->obj3D_.unknown_9c_ = 0;
                c->obj3D_.SetField9e(0);
                CallHelperIfCheckPasses_0218fcf8(ovBase, i, 0);
                GameObject_ResetTrail((unsigned char*)c);
                GameObject_ResumeFollowing((unsigned char*)c);
                SetIntField0x264_02039758(c, 0);

                if (LinkSession_IsActive((int*)search)) {
                    int cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search);
                    if (cur == i) {
                        continue;
                    }
                    if (!LinkSession_IsSlotMember(search, i)) {
                        _Z25EnqueueEventTag8_021cc4b8hhi(i, 0, 8);
                        continue;
                    }
                    func_ov017_021cc4b8(var35, var35, 8);
                }
                *((unsigned char*)var36 + 0xe0) |= 0x20;
            }
        }
    }

    for (int var38 = 0; var38 < var14->unknown_f7c_; var38++) {
        GameObject* var39 = func_0200ff1c(var9, var14->unknown_f78_[var38]);
        if (var39 != NULL) {
            func_02053ec8(var39, 0);
            func_ov017_021c9e00(var14->unknown_f78_[var38], 1, 0, 1);
        }
    }

    if (*(int*)(work + kWorkState) != 0) {
        GameState_SetCamera(battle, *(int*)(work + kWorkState));
    }

    int sp14 = 0;
    if (!LinkSession_IsActive((int*)search) ||
        LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search) == 0) {
        GameObject* c6 = FindCombatantByField16a_021a278c((void*)ovBase,
            *(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8));
        if (c6 != NULL) {
            if (func_ov000_02163c80(work, 0) != 0) {
                sp14 = 1;
            } else {
                FieldMonsterState_Init(c6);
                c6->obj3D_.MakeHidden();
            }
        }
        if (var16 != NULL) {
            *(int*)((char*)var16 + 8) = 0;
        }
    }
    for (int var42 = 0; var42 < 8; var42++) {
        func_0200fd48(var9, var42 + 0xc0);
    }

    ClearFlags04((GameResources*)var10, 0x80);
    ClearFlags04((GameResources*)var10, 4);
    ClearFlags04((GameResources*)var10, 0x10);
    ClearFlags04((GameResources*)var10, 0x40);
    ClearFlags04((GameResources*)var10, 2);
    ClearFlags00((GameResources*)var10, 0x20);
    ClearFlags00((GameResources*)var10, 0x10);
    func_ov000_021626a0(arg0, 0x26, 1);
    *(volatile unsigned short*)0x04000304 &= ~0x8000;
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(0xf);
    func_020bb48c(4, 1);
    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(0x80);
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    RenderConfig::SetDiffuseAmbientColors(var12[Enum_ov000_021688dc_27], 0, 0);
    func_ov017_021901ac(var10);

    for (int var43 = 0; var43 < var31; var43++) {
        GameObject* var44 = func_0200ff1c(var9, var7[var43]);
        if (var44 != NULL) {
            ((Struct_ov000_021688dc*)((char*)var44 + 0xc1))->unknown_0_0_ &= ~3;
            _ZN8Object3D10SetField06Et(var44, *(int*)((char*)var44 + Enum_ov000_021688dc_348));
            *(int*)((char*)var44 + Enum_ov000_021688dc_348) = data_ov000_02183b0c;
            if (*(int**)((char*)var44 + 0x13c) != NULL) {
                **(int**)((char*)var44 + 0x13c) = 0;
            }
            func_02049c88(var44, NULL);
            *((unsigned char*)var44 + 0xc2) &= ~0x20;
            func_ov017_021917f0(var7[var43], 0);
        }
    }

    if (!LinkSession_IsActive((int*)search)) {
        if (*(signed char*)(*(unsigned char**)(work + kWorkData) + 0x8e14) != 2) {
            for (int n = 0; n < count; n++) {
                GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, ids[n]);
                if (c != NULL && IsFlag130Bit0(c)) {
                    *(int*)((char*)c + kCombatantFlags) |= 1;
                    GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
                }
            }
        }
    } else {
        for (int n = 0; n < count; n++) {
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, ids[n]);
            if (c != NULL && IsFlag130Bit0(c)) {
                *(int*)((char*)c + kCombatantFlags) |= 1;
                GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
            }
        }
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair* pp = &pair;
    unsigned char* buf = g_fileLoadBuffer;
    unsigned int capacity = 0x30000;
    ZeroInitGPCPointer(&pp->pGPCFile);
    pp->ZeroInitializeMachine();

    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&var0.pGPCFile, var0.machine,
            data_ov000_02183b20, var50, var8, var51, false, NULL)) {
        var50 += var8;
        var51 -= var8;

        for (int var52 = 0; var52 < 4; var52++) {
            if (func_020a35e0(*(unsigned char**)(arg0 + Enum_ov000_021688dc_672), var52)) {
                GameObject* var53 = func_0200ff1c(var9, var52);
                if (var53 != NULL) {
                    var53->obj3D_.MakeVisible();
                    *((unsigned char*)var53 + 0xc1) &= ~0xf0;
                    unsigned char* var54 = *(unsigned char**)((char*)var53 + Enum_ov000_021688dc_340);
                    if (var54 != NULL) {
                        SafeAllocator* var55;

                        var53->obj3D_.RemoveAllAnimationPackages();
                        ((SafeAllocator*)(var54 + 0x52c))->Reset();
                        ((SafeAllocator*)(var54 + 0x540))->Reset();
                        func_02072d58(var52, var1, var2);

                        if (func_02061bd8((struct Struct_0205faf4_11*)var53)) {
                            var53->obj3D_.Destroy();
                            unsigned char* var56 = *(unsigned char**)((char*)var53 + Enum_ov000_021688dc_452);
                            if (var56 != NULL) {
                                sprintf(var3, data_ov000_02183b3b, var56[Enum_ov000_021688dc_17]);
                            }
                            alloc = (SafeAllocator*)(model + 4);
                            alloc->Reset();
                            VramState_Rewind((struct Foo0207df50*)(model + 0xcc));
                            VramState_Restore((char*)(model + 0xcc));
                            LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                            buf = g_fileLoadBuffer;
                        } else {
                            sprintf(var3, data_ov000_02183b55, var1);
                            var55 = (SafeAllocator*)(var54 + 0x52c);
                            DecompressFileFromGPCByName(var0.pGPCFile, var0.machine, var50, var8, var51, var3);
                        }

                        if (size != 0) {
                            ClearEightWords_0203dafc((struct Struct_203dafc*)&info);
                            info.allocator = alloc;
                            info.unk_10 = 1;
                            info.packageID = 0;
                            info.fileSize = size;
                            info.fileData = buf;
                            c->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
                        }

                        if (CheckField0x56bLowNibble((struct Obj02061bd8*)c)) {
                            VramState_Save((char*)(model + 0xcc));
                        } else {
                            sprintf(name, data_ov000_02183b55, outName);
                            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name)) {
                                ClearEightWords_0203dafc((struct Struct_203dafc*)&info2);
                                info2.allocator = (SafeAllocator*)(model + 0x540);
                                info2.fileSize = size;
                                info2.unk_10 = 1;
                                info2.packageID = 1;
                                info2.fileData = buf;
                                c->obj3D_.LoadFromCCHROrCMOTArchive(&info2, NULL);
                            }
                        }

                        GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
                    }
                }
            }
        }

        var0.Reset();
    }

    if (LinkSession_IsActive((int*)search)) {
        EnqueueEventTag83_021c8c04(*(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8), sp14, *p30);
    }

    func_ov000_02168284(arg0);

    LightingManager* var57 = LightingManager::GetInstance();
    var57->SetZone((Zone3D*)var12);
    var57->BeginFade(0x1000, 0);

    FontBankLoader* g = FontBankLoader_GetInstance();
    BlankFunction02094b40(g);
    FontBankLoader_CancelLoads(g);

    battle->SetGameSpeed(0x1000);
    SetCombatWorkFlags0x55f4_ov000_02160fa8(work, 0x400);
    SePlayer_LoadArchive(&g_sePlayer, 0x64);

    unsigned char var59;
    *(int*)((char*)var9 + Enum_ov000_021688dc_29172) = 0;
    for (var59 = 0; var59 < *(short*)(arg0 + Enum_ov000_021688dc_21944); var59++) {
        if (var20[3] != 0 || var20[2] != 0) {
            break;
        }
        func_ov017_021baedc(p18, 1);
        *(unsigned short*)(p18 + 8) = *(int*)(work + done * 4 + kWorkPartyIds);
        unsigned short* p = Zone3D_GetInstance();
        GameObject* pr = battle->GetProtagonist();
        *(int*)((char*)battle + kBattleSelection) = *p;
        int v54 = pr->obj3D_.rotation_.y;
        Vector3i pos = pr->obj3D_.position_;
        *(Vector3i*)((char*)battle + kBattlePosition) = pos;
        *(int*)((char*)battle + kBattleRotation) = v54;
        AppendNodeToTail((struct TailList020469b4*)p1c, (struct TailNode020469b4*)p18);
        done = 1;
        break;
    }

    if (var59 == 0) {
        if (!func_ov000_02160fd4(arg0, 1)) {
            func_ov017_0219bd1c(0, 4, 0, 0);
        }
    } else {
        unsigned char* var64 = *(unsigned char**)(var10 + Enum_ov000_021688dc_14092);
        if (var64[2] != 0) {
            func_02046a8c(var19, var64);
        }
    }

    ClearFlags00((GameResources*)var10, 4);

    if (*(int*)(arg0 + Enum_ov000_021688dc_28196) != 0) {
        func_0201bf38((unsigned char*)var12, 1, arg0[Enum_ov000_021688dc_28202], arg0[Enum_ov000_021688dc_28203], *(unsigned short*)(arg0 + Enum_ov000_021688dc_28204));
    }
    if (*(int*)(arg0 + Enum_ov000_021688dc_28216) != 0) {
        func_0201bf70((unsigned char*)var12, 1);
    }
    if (*(int*)(arg0 + Enum_ov000_021688dc_28196) != 0 || *(int*)(arg0 + Enum_ov000_021688dc_28216) != 0) {
        func_020e1154((void*)0xfa0);
    }
    func_ov017_02195530((unsigned char*)var10);

    struct FlagWord020466f4* fw = (struct FlagWord020466f4*)GlobalFlags_GetInstance();
    FlagWord_ClearBits(fw, 2);
    FlagWord_ClearBits(fw, 0x200);
    FlagWord_ClearBits(fw, 0x2000);
    ClearFlags08((GameResources*)ovBase, 4);
    FlagWord_ClearBits(fw, 0x40000);

    if (func_ov000_0215fc60((char*)var13)) {
        GameObject* var66 = func_0200ff1c(var9, 0);
        if (var66 != NULL && *(unsigned short*)(*(unsigned char**)((char*)var66 + 0x130) + 4) == 0) {
            func_02048150(var66, 1, 1);
            *(int*)((char*)var66 + Enum_ov000_021688dc_396) &= ~1;
        }
        *(*(unsigned char**)(arg0 + Enum_ov000_021688dc_668) + 0x8e14) = 1;
    }
    ClearFlags04((GameResources*)var10, 0x400);

    if (LinkSession_IsGuest(search)) {
        CallHelperWithBuf_021907dc(ovBase, 0, 1, 1, 1);
        func_ov017_02191234(ovBase);
    }
    *(unsigned short*)((char*)GameState_GetZoneTransition(battle) + 0x1e) = *(int*)(*(unsigned char**)(work + kWorkConfig) + 0xc);

    if (LinkSession_IsActive((int*)search)) {
        unsigned char* p4 = (unsigned char*)GetData02153634_020e3580();
        if (GetByte2IfGlobalFlagSet_020e37e8(p4)) {
            ClearBitOrNotifyOverlay020e3798(p4);
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    var0.Reset();
    ZeroDestroyGPCPointer(&var0.pGPCFile);
}
