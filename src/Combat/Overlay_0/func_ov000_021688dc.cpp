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
struct ObjectStatePrefix;

#if defined(jpn)
enum {
    Enum_ov000_021688dc_668 = 0x218,
    kWorkConfig = 0x21c,
    kWorkState = 0x220,
    Enum_ov000_021688dc_14076 = 0x34ec,
    Enum_ov000_021688dc_14132 = 0x3524,
    Enum_ov000_021688dc_6590 = 0x17ee,
    Enum_ov000_021688dc_30674 = 0x79c2,
    Enum_ov000_021688dc_336 = 0x144,
    Enum_ov000_021688dc_22800 = 0x5b00,
    kWorkHeightBase = 0x5b00,
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
    kWorkHeightOffset = 0xc,
    Enum_ov000_021688dc_27 = 0x2b,
    Enum_ov000_021688dc_17 = 0xc,
};
#else
enum {
    Enum_ov000_021688dc_668 = 0x29c,
    kWorkConfig = 0x2a0,
    kWorkState = 0x2a4,
    Enum_ov000_021688dc_14076 = 0x36fc,
    Enum_ov000_021688dc_14132 = 0x3734,
    Enum_ov000_021688dc_6590 = 0x19be,
    Enum_ov000_021688dc_30674 = 0x77d2,
    Enum_ov000_021688dc_336 = 0x150,
    Enum_ov000_021688dc_22800 = 0x5910,
    kWorkHeightBase = 0x5900,
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
    kWorkHeightOffset = 0x1c,
    Enum_ov000_021688dc_27 = 0x1b,
    Enum_ov000_021688dc_17 = 0x11,
};
#endif

struct Struct_ov000_02183218 { unsigned char b[4]; };

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

extern "C" void func_ov017_0218d274(void* controller);
extern "C" void func_ov017_021901ac(int arg0);

extern "C" int GameState_GetProtagonistIndex(GameState* state);
extern "C" void* GameState_GetZoneTransition(GameState* state);
extern "C" void func_0200fd48(GameState* state, int id);
extern "C" void GameState_SetCamera(GameState* state, int value);

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" void func_0208902c(unsigned char* obj, int val);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_020a3634(unsigned char* obj, short* arg1);

struct ArrayContainsByteStruct {
    char pad[0xf78];
    unsigned char arr[4];
    unsigned char count;
};
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);

struct Entry0207d9bc;
extern "C" void func_0207da7c(struct Entry0207d9bc* arr, unsigned short key);
extern "C" int func_ov000_02160fd4(void* work, int mask);
extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" int func_02053c6c(unsigned char* obj);

struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_FindCurrent(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* func_0207d78c(void);
extern "C" void* GlobalFlags_GetInstance(void);

extern "C" void GameObject_EnableControl(void* obj);

struct Struct_02053f7c_3;
extern "C" void func_02053f7c(Struct_02053f7c_3* obj, unsigned short a, int b);
struct Struct_02049f50;
extern "C" void func_02049f50(struct Struct_02049f50* obj, int val, int count);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" void GameObject_UnfreezeAnimation(ObjectStatePrefix* obj);
extern "C" void func_02039d48(unsigned char* obj);
extern "C" void GameObject_ClearHidden(unsigned char* obj);
extern "C" void GameObject_ResumeFollowing(unsigned char* obj);
struct Obj02033874;
extern "C" void GameObject_SnapFacing(struct Obj02033874* obj, int arg);
extern "C" int func_ov017_0218fcf8(int a, int b, int c);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
extern "C" void func_02039758(void* obj, int val);

struct SearchStruct;
struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
extern "C" int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" void func_ov017_021cc4b8(int a, int b, int c);
extern "C" void func_02053ec8(void* obj, int value);

struct Bytes02033b88;
extern "C" int GameObject_ForceMotionState(struct Bytes02033b88* p, int val);
extern "C" GameObject* func_ov017_021a278c(void* unused, int val);

struct Foo0207df50;
extern "C" void func_02072d58(int combatantId, char* arg1, char* outBuf);
struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_203dafc;
extern "C" void func_0203dafc(struct Struct_203dafc* obj);

extern "C" void SePlayer_LoadArchive(void* objRaw, int mode);

struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

extern "C" void func_0201bf38(unsigned char* obj, int set, int a, int b, unsigned short c);
extern "C" void func_0201bf70(unsigned char* obj, int set);
extern "C" void func_020e1154(void* obj);
extern "C" void func_ov017_02195530(unsigned char* obj);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" int func_ov000_0215fc60(char* base);
extern "C" void func_ov017_021907dc(int a, int b, int c, int d, int e);

extern "C" void* func_020e3580(void);
extern "C" int func_020e37e8(unsigned char* p);
extern "C" void func_020e3798(unsigned char* obj);

extern "C" void func_020bb48c(unsigned int mode, int arg1);
extern "C" void func_ov017_021c8c04(int, int, int);
extern "C" void _ZN8Object3D10SetField06Et(void* obj, int value);

struct Struct_ov000_021688dc { unsigned char lo : 2; unsigned char hi : 6; };

extern Struct_ov000_02183218 data_ov000_02183218;
extern int data_ov000_02183b0c;
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern const char data_ov000_02183b20[];
extern const char data_ov000_02183b3b[];
extern const char data_ov000_02183b55[];
extern int g_sePlayer;

extern "C" void GameState_SetPartyOrder(char* obj, int len, void* src);
struct Slot70 { char data[0x70]; };
static inline SafeAllocator* inline_ov000_02164fac(GameResources* res, int i) { return &res->allocator_array_38[i]; }
static inline Slot70* GetSlot2cc(GameResources* res, int i) { return &((Slot70*)res->vramStates_)[i]; }

static inline short GetObjectId(GameObject* c) { return c->obj3D_.actorIndex_; }

static inline int inline_ov000_021688dc_3(GameObject* c) {
    return (**(int**)((char*)c + 0x130) & 1) != 0;
}

// USA: func_ov000_021688dc
extern "C" ARM void func_ov000_021688dc(unsigned char* work) {
    if (((BackgroundLoader*)((void*)(int)BackgroundLoader::GetInstance()))->GetNumQueuedTasks() > 0) {
        return;
    }

    GPCReadPair pair;
    char var1[0xa];
    char outName[0xa];
    char name[0x28];
    ObjectArchiveLoadInfo info;
    ObjectArchiveLoadInfo info2;
    Struct_ov000_02183218 region;
    short ids[4];
    unsigned int size;

    GameState* battle = GameState::GetInstance();
    int ovBase = (int)GetGameResources();
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    unsigned short* p30 = Zone3D_GetInstance();
    OamManager_GetInstance();

    void* var13 = *(void**)(work + Enum_ov000_021688dc_668);
    struct ArrayContainsByteStruct* arrStruct = (struct ArrayContainsByteStruct*)GameState_GetParty(battle);
    GameObject* prot = battle->GetProtagonist();
    struct Entry_02028bd0* entry = ZoneRecords_FindCurrent();
    int globalBase = MessageSystem_GetInstance();
    void* var18 = func_0207d78c();
    void* var19 = *(void**)(ovBase + Enum_ov000_021688dc_14076);
    unsigned char* var20 = *(unsigned char**)(ovBase + Enum_ov000_021688dc_14132);
    GlobalFlags_GetInstance();

    if (*((unsigned char*)var13 + 0x8e97) != 0) {
        GameObject* c = battle->GetPartyMemberByIndex(GameState_GetProtagonistIndex(battle));
        if (c != NULL && func_02010088((struct S_10088*)c)) {
            func_0208902c(*(unsigned char**)((char*)c + 0x138), 1);
            Party_ReformLine(ovBase, 1, 1, 1, 1);
        }
    }

    GameObject* c397c = battle->GetLeader();

    if (LinkSession_IsActive((int*)search)) {
        int var23 = 1;
        int k;
        for (k = 0; k < 4; k++) {
            if (func_020a35e0(*(unsigned char**)(work + kWorkConfig), k)) {
                GameObject* c = func_0200ff1c(battle, k);
                if (c != NULL) {
                    if (!func_02010088((struct S_10088*)c)) {
                        var23 = 0;
                        break;
                    }
                }
            }
        }
        if (var23) {
            *(*(unsigned char**)(work + Enum_ov000_021688dc_668) + 0x8e14) = 2;
        }
    }

    func_ov017_0218d274((void*)ovBase);
    ClearFlags04((GameResources*)ovBase, 0x200000);
    func_0207da7c((struct Entry0207d9bc*)var18, *(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8));
    *(unsigned char*)(globalBase + Enum_ov000_021688dc_6590) = 0;

    if (func_ov000_02160fd4(work, 0x400000)) {
        GameObject* c1 = func_0200ff1c(battle, 1);
        if (c1 != NULL) {
            int f150 = func_02053c6c((unsigned char*)c1);
            if (f150 != 0) {
                func_02082828(f150);
            }
        }
        arrStruct->count -= 1;
        func_0200fd48(battle, 1);
        battle->SetTimeOfDay((TimeOfDay)2);

        int regionCount = 1;
        region = data_ov000_02183218;
        GameState_SetPartyOrder((char*)battle, regionCount, &region);

        SafeAllocator* var29 = inline_ov000_02164fac((GameResources*)ovBase, 3);
        Slot70* var30 = GetSlot2cc((GameResources*)ovBase, 3);
        func_020542b4(func_ov017_021a11f4((GameResources*)ovBase, 2), var29, var30);
        *(int*)((char*)LightingManager::GetInstance() + 0x98) = 2;
    }

    int count = func_020a3634(*(unsigned char**)(work + kWorkConfig), ids);

    if (c397c != NULL) {
        GameObject_EnableControl(c397c);
        *((unsigned char*)c397c + 0xc3) = 0xf;
    }

    short leadId = prot->obj3D_.actorIndex_;
    if (func_02086ef0(arrStruct, 0)) {
        for (int idx = 0; idx < arrStruct->count; idx++) {
            GameObject* c = battle->GetPartyMemberByIndex(arrStruct->arr[idx]);
            if (c != NULL && !func_02010088((struct S_10088*)c)) {
                if (!inline_ov000_021688dc_3(c)) {
                    leadId = c->obj3D_.actorIndex_;
                    break;
                }
            }
        }
    } else {
        leadId = c397c->obj3D_.actorIndex_;
    }

    for (int i = 0; i < 4; i++) {
        if (func_020a35e0(*(unsigned char**)(work + kWorkConfig), i)) {
            GameObject* c = battle->GetPartyMemberByIndex(i);
            if (c != NULL) {
                c->obj3D_.MakeVisible();
                func_02053f7c((struct Struct_02053f7c_3*)c, 0, 0);
                func_02049f50((struct Struct_02049f50*)c, 0x1f, 0);
                func_ov017_02191aac(ovBase, 0, i, 2);
                func_ov017_02191aac(ovBase, 0, i, 4);

                if (func_ov000_02160fd4(work, 1) && work[Enum_ov000_021688dc_30674] != 0) {
                    func_02048b0c(c, func_02083b00(*(unsigned char**)((char*)c + Enum_ov000_021688dc_336), 0x99) ? 1 : 0);
                    GameObject_UnfreezeAnimation((ObjectStatePrefix*)c);
                }

                if (func_02086ef0(arrStruct, GetObjectId(c))) {
                    if (leadId != c->obj3D_.actorIndex_) {
                        func_02039d48((unsigned char*)c);
                    }
                    if (func_ov000_02160fd4(work, 1)) {
                        c->obj3D_.position_ = *(Vector3i*)(work + Enum_ov000_021688dc_22800 + leadId * 16);
                        GameObject_SnapFacing((struct Obj02033874*)c, *(short*)(work + leadId * 16 + kWorkHeightBase + kWorkHeightOffset));
                    }
                } else {
                    if (func_ov000_02160fd4(work, 1)) {
                        c->obj3D_.position_ = *(Vector3i*)(work + Enum_ov000_021688dc_22800 + i * 16);
                        GameObject_SnapFacing((struct Obj02033874*)c, *(short*)(work + i * 16 + kWorkHeightBase + kWorkHeightOffset));
                    }
                    if (*(unsigned short*)((char*)c + Enum_ov000_021688dc_434) != 0) {
                        GameObject_ClearHidden((unsigned char*)c);
                    }
                }

                c->obj3D_.unknown_9c_ = 0;
                c->obj3D_.SetField9e(0);
                func_ov017_0218fcf8(ovBase, i, 0);
                GameObject_ResetTrail((unsigned char*)c);
                GameObject_ResumeFollowing((unsigned char*)c);
                func_02039758(c, 0);

                if (LinkSession_IsActive((int*)search)) {
                    int cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search);
                    if (cur == i) {
                        continue;
                    }
                    if (!LinkSession_IsSlotMember(search, i)) {
                        func_ov017_021cc4b8(i, 0, 8);
                        continue;
                    }
                    func_ov017_021cc4b8(i, i, 8);
                }
                *((unsigned char*)c + 0xe0) |= 0x20;
            }
        }
    }

    for (int j = 0; j < arrStruct->count; j++) {
        GameObject* c = func_0200ff1c(battle, arrStruct->arr[j]);
        if (c != NULL) {
            func_02053ec8(c, 0);
            func_ov017_021c9e00(arrStruct->arr[j], 1, 0, 1);
        }
    }

    if (*(int*)(work + kWorkState) != 0) {
        GameState_SetCamera(battle, *(int*)(work + kWorkState));
    }

    int var40 = 0;
    if (!LinkSession_IsActive((int*)search) ||
        LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)search) == 0) {
        GameObject* c6 = func_ov017_021a278c((void*)ovBase,
            *(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8));
        if (c6 != NULL) {
            if (func_ov000_02163c80(work, 0) != 0) {
                var40 = 1;
            } else {
                FieldMonsterState_Init(c6);
                c6->obj3D_.MakeHidden();
            }
        }
        if (entry != NULL) {
            *(int*)((char*)entry + 8) = 0;
        }
    }
    for (int k = 0; k < 8; k++) {
        func_0200fd48(battle, k + 0xc0);
    }

    ClearFlags04((GameResources*)ovBase, 0x80);
    ClearFlags04((GameResources*)ovBase, 4);
    ClearFlags04((GameResources*)ovBase, 0x10);
    ClearFlags04((GameResources*)ovBase, 0x40);
    ClearFlags04((GameResources*)ovBase, 2);
    ClearFlags00((GameResources*)ovBase, 0x20);
    ClearFlags00((GameResources*)ovBase, 0x10);
    func_ov000_021626a0(work, 0x26, 1);
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
    RenderConfig::SetDiffuseAmbientColors(p30[Enum_ov000_021688dc_27], 0, 0);
    func_ov017_021901ac(ovBase);

    for (int m = 0; m < count; m++) {
        GameObject* c = func_0200ff1c(battle, ids[m]);
        if (c != NULL) {
            ((Struct_ov000_021688dc*)((char*)c + 0xc1))->lo &= ~3;
            _ZN8Object3D10SetField06Et(c, *(int*)((char*)c + Enum_ov000_021688dc_348));
            *(int*)((char*)c + Enum_ov000_021688dc_348) = data_ov000_02183b0c;
            if (*(int**)((char*)c + 0x13c) != NULL) {
                **(int**)((char*)c + 0x13c) = 0;
            }
            func_02049c88(c, NULL);
            *((unsigned char*)c + 0xc2) &= ~0x20;
            func_ov017_021917f0(ids[m], 0);
        }
    }

    if (!LinkSession_IsActive((int*)search)) {
        if (*(signed char*)(*(unsigned char**)(work + Enum_ov000_021688dc_668) + 0x8e14) != 2) {
            for (int n = 0; n < count; n++) {
                GameObject* c = func_0200ff1c(battle, ids[n]);
                if (c != NULL && inline_ov000_021688dc_3(c)) {
                    *(int*)((char*)c + Enum_ov000_021688dc_396) |= 1;
                    GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
                }
            }
        }
    } else {
        for (int n = 0; n < count; n++) {
            GameObject* c = func_0200ff1c(battle, ids[n]);
            if (c != NULL && inline_ov000_021688dc_3(c)) {
                *(int*)((char*)c + Enum_ov000_021688dc_396) |= 1;
                GameObject_ForceMotionState((struct Bytes02033b88*)c, 0);
            }
        }
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair* var49 = &pair;
    unsigned char* buf = g_fileLoadBuffer;
    unsigned int capacity = 0x30000;
    ZeroInitGPCPointer(&var49->pGPCFile);
    var49->ZeroInitializeMachine();

    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
            data_ov000_02183b20, buf, size, capacity, false, NULL)) {
        buf += size;
        capacity -= size;

        for (int i = 0; i < 4; i++) {
            if (func_020a35e0(*(unsigned char**)(work + kWorkConfig), i)) {
                GameObject* c = func_0200ff1c(battle, i);
                if (c != NULL) {
                    c->obj3D_.MakeVisible();
                    *((unsigned char*)c + 0xc1) &= ~0xf0;
                    unsigned char* model = *(unsigned char**)((char*)c + Enum_ov000_021688dc_340);
                    if (model != NULL) {
                        SafeAllocator* alloc;

                        c->obj3D_.RemoveAllAnimationPackages();
                        ((SafeAllocator*)(model + 0x52c))->Reset();
                        ((SafeAllocator*)(model + 0x540))->Reset();
                        func_02072d58(i, var1, outName);

                        if (func_02061bd8((struct Struct_0205faf4_11*)c)) {
                            c->obj3D_.Destroy();
                            unsigned char* var56 = *(unsigned char**)((char*)c + Enum_ov000_021688dc_452);
                            if (var56 != NULL) {
                                sprintf(name, data_ov000_02183b3b, var56[Enum_ov000_021688dc_17]);
                            }
                            alloc = (SafeAllocator*)(model + 4);
                            alloc->Reset();
                            VramState_Rewind((struct Foo0207df50*)(model + 0xcc));
                            VramState_Restore((char*)(model + 0xcc));
                            LoadFileIntoMemory(name, g_fileLoadBuffer, &size);
                            buf = g_fileLoadBuffer;
                        } else {
                            sprintf(name, data_ov000_02183b55, var1);
                            alloc = (SafeAllocator*)(model + 0x52c);
                            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name);
                        }

                        if (size != 0) {
                            func_0203dafc((struct Struct_203dafc*)&info);
                            info.allocator = alloc;
                            info.unk_10 = 1;
                            info.packageID = 0;
                            info.fileSize = size;
                            info.fileData = buf;
                            c->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
                        }

                        if (func_02061bd8((struct Struct_0205faf4_11*)c)) {
                            VramState_Save((char*)(model + 0xcc));
                        } else {
                            sprintf(name, data_ov000_02183b55, outName);
                            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name)) {
                                func_0203dafc((struct Struct_203dafc*)&info2);
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

        pair.Reset();
    }

    if (LinkSession_IsActive((int*)search)) {
        func_ov017_021c8c04(*(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8), var40, *p30);
    }

    func_ov000_02168284(work);

    LightingManager* var57 = LightingManager::GetInstance();
    var57->SetZone((Zone3D*)p30);
    var57->BeginFade(0x1000, 0);

    FontBankLoader* g = FontBankLoader_GetInstance();
    func_02094b40(g);
    FontBankLoader_CancelLoads(g);

    battle->SetGameSpeed(0x1000);
    func_ov000_02160fa8(work, 0x400);
    SePlayer_LoadArchive(&g_sePlayer, 0x64);

    unsigned char done;
    *(int*)((char*)battle + Enum_ov000_021688dc_29172) = 0;
    for (done = 0; done < *(short*)(work + Enum_ov000_021688dc_21944); done++) {
        if (var20[3] != 0 || var20[2] != 0) {
            break;
        }
        func_ov017_021baedc(var20, 1);
        *(unsigned short*)(var20 + 8) = *(int*)(work + done * 4 + Enum_ov000_021688dc_21912);
        unsigned short* p = Zone3D_GetInstance();
        GameObject* var61 = battle->GetProtagonist();
        *(int*)((char*)battle + Enum_ov000_021688dc_29172) = *p;
        int v54 = var61->obj3D_.rotation_.y;
        Vector3i pos = var61->obj3D_.position_;
        *(Vector3i*)((char*)battle + Enum_ov000_021688dc_29156) = pos;
        *(int*)((char*)battle + Enum_ov000_021688dc_29168) = v54;
        func_020469b4((struct TailList020469b4*)var19, (struct TailNode020469b4*)var20);
        done = 1;
        break;
    }

    if (done == 0) {
        if (!func_ov000_02160fd4(work, 1)) {
            func_ov017_0219bd1c(0, 4, 0, 0);
        }
    } else {
        unsigned char* var64 = *(unsigned char**)(ovBase + Enum_ov000_021688dc_14092);
        if (var64[2] != 0) {
            func_02046a8c(var19, var64);
        }
    }

    ClearFlags00((GameResources*)ovBase, 4);

    if (*(int*)(work + Enum_ov000_021688dc_28196) != 0) {
        func_0201bf38((unsigned char*)p30, 1, work[Enum_ov000_021688dc_28202], work[Enum_ov000_021688dc_28203], *(unsigned short*)(work + Enum_ov000_021688dc_28204));
    }
    if (*(int*)(work + Enum_ov000_021688dc_28216) != 0) {
        func_0201bf70((unsigned char*)p30, 1);
    }
    if (*(int*)(work + Enum_ov000_021688dc_28196) != 0 || *(int*)(work + Enum_ov000_021688dc_28216) != 0) {
        func_020e1154((void*)0xfa0);
    }
    func_ov017_02195530((unsigned char*)ovBase);

    struct FlagWord020466f4* fw = (struct FlagWord020466f4*)GlobalFlags_GetInstance();
    FlagWord_ClearBits(fw, 2);
    FlagWord_ClearBits(fw, 0x200);
    FlagWord_ClearBits(fw, 0x2000);
    ClearFlags08((GameResources*)ovBase, 4);
    FlagWord_ClearBits(fw, 0x40000);

    if (func_ov000_0215fc60((char*)var13)) {
        GameObject* c0 = func_0200ff1c(battle, 0);
        if (c0 != NULL && *(unsigned short*)(*(unsigned char**)((char*)c0 + 0x130) + 4) == 0) {
            func_02048150(c0, 1, 1);
            *(int*)((char*)c0 + Enum_ov000_021688dc_396) &= ~1;
        }
        *(*(unsigned char**)(work + Enum_ov000_021688dc_668) + 0x8e14) = 1;
    }
    ClearFlags04((GameResources*)ovBase, 0x400);

    if (LinkSession_IsGuest(search)) {
        func_ov017_021907dc(ovBase, 0, 1, 1, 1);
        func_ov017_02191234(ovBase);
    }
    *(unsigned short*)((char*)GameState_GetZoneTransition(battle) + 0x1e) = *(int*)(*(unsigned char**)(work + kWorkConfig) + 0xc);

    if (LinkSession_IsActive((int*)search)) {
        unsigned char* p4 = (unsigned char*)func_020e3580();
        if (func_020e37e8(p4)) {
            func_020e3798(p4);
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
