#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern char* g_itemDataArchive;
extern "C" int func_020e04f8(void*, void*, const char*, short, bool);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};

extern "C" void* func_0202ae18(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_020703c8(int index, int hour, int minute, int second);
extern "C" void* func_ov017_021baedc(void* self, int flag);

struct Struct_0201bdac;
struct Struct_0201bdac_2;
extern "C" void func_020469b4(struct Struct_0201bdac_2* arg0, struct Struct_0201bdac* arg1);

struct Struct_020213fc;
extern "C" void func_020213fc(struct Struct_020213fc* arg0, int arg1);
extern "C" void func_020e1154(void* arg0);

extern "C" void* func_0200fd0c(GameState*);
extern "C" void func_02070378(char* arg0);

extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* arg0, int arg1);
extern "C" int func_02040528(int* arg0);

extern "C" void func_ov017_021b8d80(void*);
extern "C" void func_ov017_021b8d1c(void* arg0);

extern "C" int func_020100f8(char* arg0);
extern "C" void func_020a27b8(unsigned char* arg0);

struct Vector3i;

extern "C" void func_ov017_021b6f18(void* arg0);
extern "C" void func_ov017_021b6e70(void* arg0, unsigned short arg1);
extern "C" int func_0202c540(void* arg0);
extern "C" void func_ov017_021b7104(void* arg0, void* arg1);

struct GameState;
void* ItemTable_Construct(void* obj);
void ItemTable_Init(void* obj);
extern char* g_itemDataArchive;
extern char* g_itemDataFile;
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
int BuildDescriptorFlag1_020de980(void* a, void* b, void* c, int d, int e);
void InitStruct0207cbe8(char* obj);
extern "C" void func_0207d300(void* obj, short id, int a, int b);

extern "C" int func_02086d88(unsigned char* arg0, int arg1);
extern "C" unsigned char func_02011494(char* arg0, void* arg1);
struct Struct_0203d028_3;
extern "C" int func_02053c6c(unsigned char* arg0);
struct Struct_0206f81c;
extern "C" void* func_02083554(struct Struct_0206f81c* arg0, int arg1);
extern "C" void func_02083738(void* arg0, int arg1);
extern "C" int func_0202b7d8(int* arg0);
extern "C" void func_ov017_021c3fb4(int arg0, int arg1);
extern "C" void func_ov017_021c4418(int arg0, signed char arg1);
extern "C" void func_ov017_0218f5a4(void* arg0, int arg1, int arg2, int arg3, int arg4);

struct FieldTaskQueue;
void FieldTaskQueue_Update(struct FieldTaskQueue* self);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

extern "C" void* Zone3D_GetInstance(void);
extern "C" void Scenario_LoadZoneTriggers(void* a, int b);
int GameState_GetProtagonistIndex(GameState*);

extern "C" void func_ov017_021c16a8(unsigned char* arg0);

extern "C" void func_ov017_021b65e0(void* arg0, int arg1);

struct Struct_0206f81c_2;
extern "C" void func_ov017_021b2174(unsigned char* arg0);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* arg0, char* arg1);
extern "C" void func_ov017_021b2bd0(void* arg0, int arg1, int arg2);
struct Struct_0206f81c_3;
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* arg0, unsigned int arg1);
struct Struct_0206f81c_4;
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* arg0, unsigned int arg1);
struct Struct_0206f81c_5;
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* arg0, unsigned int arg1);
struct Struct_020469f8;
struct Struct_020469f8_2;
extern "C" void func_020469f8(struct Struct_020469f8* arg0, struct Struct_020469f8_2* arg1);

extern "C" void func_ov004_0215e25c(void*, void*);
extern "C" void func_ov004_02168684();
extern "C" void func_ov004_021689d8(SafeAllocator*, void*);
extern char data_020f0b40[];
extern char data_020f0b4c[];
extern char data_020f0b56[];

struct Struct_0206f81c_6 {
    char unknown_0_[0x164 - sizeof(SafeAllocator)];
    SafeAllocator unknown_150_[2];
    SafeAllocator* inline_0206f81c(int arg0) { return &unknown_150_[arg0]; }
};

struct Struct_0206f81c_7 {
    SafeAllocator unknown_0_;
    char unknown_14_[0x14 - sizeof(SafeAllocator)];
    char unknown1_14_[0x18];
    void* unknown_2c_;
    char unknown_30_[8];
};

struct Struct_0206f81c_8 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
};

struct Struct_0206f81c_9 {
    unsigned short unknown_0_0_ : 13;
    unsigned short unknown_1_5_ : 3;
};

struct Struct_0206f81c_10 {
    char unknown_0_[0x5d0c];
    struct Struct_0206f81c_9 unknown_5d0c_;
};

struct Struct_0206f81c_11 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_[2];
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    int unknown_14_;
};

// Main, originally func_0206f81c (USA 0x0206f81c, EUR 0x0206f82c, JPN 0x020708dc)
extern "C" ARM void EventQuery_RunQueuedCommands(void* a0) {
    void* searchPtr;
    void* miscCtx;
    int flag20;
    int val1c;
    int flag18;
    int flag14;
    short val10;
    struct BattleStruct* battle2;
    BackgroundLoader* inst;
    struct TailList020469b4* tailList;
    int vec[3];
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    void* g = GetGameResources();
    void* gBase = (char*)g + 0x3000;
    tailList = *(struct TailList020469b4**)((char*)gBase + REGION_VALUE(0x4ec, 0x6fc));
    searchPtr = func_0202ae18();
    miscCtx = Scenario_GetInstance();
    unsigned char* node = *(unsigned char**)((char*)a0 + 0x30);
    unsigned char slFlag;
    flag20 = 0;
    val1c = 0;
    slFlag = 0;
    flag18 = 0;
    flag14 = 0;

    if (var14 != NULL) {
        while (var14 != NULL) {
            unsigned short var16 = *(unsigned short*)(var14 + 0);
            switch (var16) {
            case 0x84: {
                func_020703c8(((unsigned char*)var1)[0x332], *(unsigned short*)(var14 + 4), *(unsigned short*)(var14 + 6), *(unsigned short*)(var14 + 8));
                var2 = 1;
                break;
            }

            case 0x94: {
                for (int var17 = 0; var17 < 5; var17++) {
                    func_020703c8(var17, *(unsigned short*)(var14 + 4), *(unsigned short*)(var14 + 6), *(unsigned short*)(var14 + 8));
                }
                var2 = 1;
                break;
            }

            case 0xd6: {
                func_020703c8(*(unsigned short*)(var14 + 2), *(unsigned short*)(var14 + 4), *(unsigned short*)(var14 + 6), *(unsigned short*)(var14 + 8));
                var2 = 1;
                break;
            }

            case 0x77: case 0x80: case 0x9b: {
                struct Struct_0201bdac* var18 = *(struct Struct_0201bdac**)((char*)var12 + 0x3000 + REGION_VALUE(0x524, 0x734));
                func_ov017_021baedc(var18, 1);
                *(unsigned short*)((char*)var18 + 8) = *(unsigned short*)(var14 + 2);
                func_020469b4(var9, var18);
                func_020213fc(*(struct Struct_020213fc**)((char*)var12 + 0x3000 + REGION_VALUE(0x4c0, 0x6d0)), 1);
                func_020e1154((void*)0x1f4);
                break;
            }

            case 0x85: case 0x8a: case 0xe2: {
                unsigned char* var19 = (unsigned char*)func_0200fd0c((GameState*)var11);
                func_02070378((char*)var19);
                var19[2] = 1;
                *(unsigned short*)(var19 + 0) = *(unsigned short*)(var14 + 2);
                *(unsigned int*)(var19 + 0x20) = *(unsigned short*)(var14 + 4);
                if (*(unsigned short*)(var14 + 0) == 0x8a) var19[6] = 1;
                if (*(unsigned short*)(var14 + 0) == 0xe2) var19[0xc] = 1;
                if (*((unsigned char*)var11 + 0x5000 + REGION_VALUE(0xa4c, 0xcac)) != 0) var19[0x60] = 1;
                var15 = 1;
                func_020213fc(*(struct Struct_020213fc**)((char*)var12 + 0x3000 + REGION_VALUE(0x4c0, 0x6d0)), var15);
                break;
            }

            case 0x76: {
                void* var20 = func_0203df78(func_0203cf4c(), *(unsigned short*)(var14 + 2));
                int var21 = 0;
                if (var20 != NULL) {
                    var21 = func_02040528((int*)var20);
                }
                if (var21 != 0) {
                    unsigned char var22;
                    unsigned char* var23 = *(unsigned char**)((char*)var12 + 0x3000 + REGION_VALUE(0x500, 0x710));
                    var22 = *(unsigned char*)(var23 + 3);
                    if (var22 != 0) {
                        func_ov017_021b8d80(var23);
                    }
                    unsigned char* var24 = *(unsigned char**)((char*)var12 + 0x3000 + REGION_VALUE(0x50c, 0x71c));
                    var22 |= (*(unsigned char*)(var24 + 3) != 0 && *(unsigned char*)(var24 + 0x20) != 0);
                    func_ov017_021b8d1c(var23);
                    *(int*)(var23 + 0x114) = var21;
                    *(int*)(var23 + 0x124) = *(unsigned short*)(var14 + 4);
                    *(unsigned char*)(var23 + 0x139) = (var22 != 0) ? 1 : 0;
                    func_020469b4(var9, (struct Struct_0201bdac*)var23);
                    int var25 = func_020100f8((char*)var11);
                    if (var25 != 0) {
                        func_020a27b8((unsigned char*)var25);
                    }
                }
                break;
            }

            case 0x79: case 0x89: case 0xe1: {
                unsigned char* var26 = (unsigned char*)func_0200fd0c((GameState*)var11);
                func_02070378((char*)var26);
                var26[2] = 1;
                *(unsigned short*)(var26 + 0) = *(unsigned short*)(var14 + 2);
                var26[0xc] = 1;
                if (*(unsigned short*)(var14 + 0) == 0x89) var26[6] = 1;
                if (*(unsigned short*)(var14 + 0) == 0xe1) var26[0xc] = 0;
                var15 = 1;
                break;
            }

            case 0x7a: {
                *(Vector3i*)var10 = *(Vector3i const*)(var14 + 4);
                var4 = 1;
                break;
            }

            case 0x7b: {
                var6 = *(short*)(var14 + 4);
                var5 = 1;
                break;
            }

            case 0x78: {
                struct Struct_0201bdac_2* var27;
                unsigned char* var28 = *(unsigned char**)((char*)var12 + 0x3000 + REGION_VALUE(0x508, 0x718));
                var27 = *(struct Struct_0201bdac_2**)((char*)var12 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
                void* var29 = LightingManager::GetInstance();
                func_ov017_021b6f18(var28);

                struct Struct_0206f81c_11 var30;
                var30.unknown_0_ = 1;
                var30.unknown_1_ = 0;
                var30.unknown_2_ = 0;
                var30.unknown_4_ = 0;
                var30.unknown_c_ = 0;
                var30.unknown_d_ = 0;
                var30.unknown_e_ = 0;
                var30.unknown_f_ = 0;
                var30.unknown_14_ = 0;
                var30.unknown_10_ = -1;
                var30.unknown_12_ = 2;
                var30.unknown_8_ = -1;

                desc.f1 = GameState_GetProtagonistIndex((GameState*)battle);
                desc.f4 = *(unsigned short*)(node + 2) + 5 + 0x8000;
                desc.f2 = 0xffff;
                desc.f8 = *(unsigned short*)(node + 2);
                func_ov017_021b6e70(&desc, desc.f2);
                desc.f12 = *(int*)((char*)sb + 0x98);

                if (func_0202c540(var0) != 0) {
                    if (var30.unknown_c_ == 0 && var30.unknown_d_ == 0) {
                        var30.unknown_14_ = 1;
                    }
                }
                func_ov017_021b7104(var28, &var30);
                func_020469b4(var27, (struct Struct_0201bdac*)var28);
                break;
            }

            case 0x7c: {
                void* var31 = func_0203df78(func_0203cf4c(), *(unsigned short*)(var14 + 2));
                if (var31 != NULL) {
                    *(int*)var31 |= 0x8000;
                }
                break;
            }

            case 0x72: case 0x74: {
                if (GameState_GetParty((GameState*)battle) != NULL) {
                    unsigned char eventBuf[0x18];
#if defined(jpn)
                    SafeAllocator* var33 = ((Struct_0206f81c_6*)var12)->inline_0206f81c(1);
#else
                    void* var34 = ((Struct_0206f81c_6*)var12)->inline_0206f81c(1);
#endif
                    ItemTable_Construct(eventBuf);
                    ItemTable_Init(eventBuf);
#if defined(jpn)
                    func_020e04f8(eventBuf, (void*)r7base, g_itemDataArchive, *(short*)(node + 2), true);
#else
                    BackgroundLoader::AddLockGlobal();
                    unsigned int outSize = 0;
                    void* loaded = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &outSize);
                    if (loaded != NULL) {
                        BuildDescriptorFlag1_020de980(eventBuf, r7base, loaded, outSize, (int)(*(short*)(node + 2)));
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    SelfBuf0206f81c selfBuf;
                    selfBuf.alloc.ResetAllocatorPointer();
                    ItemTable_Construct(selfBuf.sub14);
                    InitStruct0207cbe8((char*)&selfBuf);
                    InitStruct0207cbe8((char*)&selfBuf);
                    selfBuf.eventPtr = eventBuf;
                    func_0207d300(&selfBuf, *(short*)(node + 2), (signed char)*(unsigned short*)(node + 4), 0);
                }
                break;
            }

            case 0x73: case 0x75: {
                void* p2a04 = GameState_GetParty((GameState*)battle);
                if (p2a04 != NULL) {
                    int matchCount = 0;
                    for (int total = 0; total < *(unsigned short*)(node + 4); total++) {
                        if (DecrementKeyEverywhere02086d88((unsigned char*)p2a04, *(short*)(node + 2)) != 0) matchCount++;
                    }
                    if (var39 < *(unsigned short*)(var14 + 4)) {
                        var7 = (Struct_0203d028_2*)GameState::GetInstance();
                        unsigned char var41[4];
                        int var42[4];
                        int var43 = 0;
                        unsigned char var44 = func_02011494((char*)var7, var41);
                        for (int var45 = 0; var45 < var44; var45++) {
                            struct Struct_0203d028_3* var46 = (Struct_0203d028_3*)func_0200ff1c((GameState*)var7, var41[var45]);
                            if (var46 != NULL) {
                                int var47 = func_02053c6c((unsigned char*)var46);
                                if (var47 != 0) {
                                    struct Struct_0206f81c_8* var48 = (struct Struct_0206f81c_8*)func_02083554((struct Struct_0206f81c*)var47, *(unsigned short*)(var14 + 2));
                                    if (var48 != NULL) {
                                        func_02083738((void*)var47, var48->unknown_8_0_);
                                        var42[var43] = var41[var45];
                                        var43++;
                                        var39++;
                                        if (var39 == *(unsigned short*)(var14 + 4)) break;
                                    }
                                }
                            }
                        }
                        int var49 = -1;
                        for (int var50 = 0; var50 < var43; var50++) {
                            if (func_0202b7d8((int*)func_0202ae18())) {
                                int var51 = var42[var50];
                                func_ov017_021c3fb4(var51, 1);
                                func_ov017_021c4418(var51, var49);
                            }
                            void* g2 = GetGameResources();
                            void* field700 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f0, 0x700));
                            void* field704 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f4, 0x704));
                            inst = BackgroundLoader::GetInstance();
                            func_ov017_0218f5a4(g2, idArr[j], 1, 0, 0);
                            while (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field700) == 0x13) {
                                inst->RemoveAllLocks();
                                FieldTaskQueue_Update((struct FieldTaskQueue*)field700);
                                if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field704) == 0x14) {
                                    FieldTaskQueue_Update((struct FieldTaskQueue*)field704);
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 0x9c: case 0x9d: {
                if (type == 0x9c) {
                    void* p2a04 = GameState_GetParty((GameState*)battle);
                    if (p2a04 == NULL) break;
                    int found = 0;
                    if (DecrementKeyEverywhere02086d88((unsigned char*)p2a04, *(short*)(node + 4)) != 0) found = 1;
                    if (found == 0) {
                        unsigned char buf3c[4];
                        unsigned char count = CopyOutRegion0x5718_02011494((char*)battle, buf3c);
                        for (int i = 0; i < count; i++) {
                            int cid = buf3c[i];
                            struct CombatantStruct* c = (CombatantStruct*)GetCombatantWithFlag0x100_0200ff1c((GameState*)battle, cid);
                            if (c != NULL) {
                                int field150 = GetFieldAt0x150_02053c6c((unsigned char*)c);
                                if (field150 != 0) {
                                    struct Entry02083554* entry = (struct Entry02083554*)FindEntryByShortField02083554((struct Container02083554*)field150, *(short*)(node + 4));
                                    if (entry != NULL) {
                                        func_02083738((void*)field150, entry->kind);
                                        if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
                                            func_ov017_021c3fb4(cid, 1);
                                            func_ov017_021c4418(cid, -1);
                                        }
                                        void* g2 = GetGameResources();
                                        void* field700 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f0, 0x700));
                                        void* field704 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f4, 0x704));
                                        BackgroundLoader* inst = BackgroundLoader::GetInstance();
                                        func_ov017_0218f5a4(g2, cid, 1, 0, 0);
                                        while (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field700) == 0x13) {
                                            inst->RemoveAllLocks();
                                            FieldTaskQueue_Update((struct FieldTaskQueue*)field700);
                                            if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field704) == 0x14) {
                                                FieldTaskQueue_Update((struct FieldTaskQueue*)field704);
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                if (GameState_GetParty((GameState*)battle) != NULL) {
                    unsigned char eventBuf2[0x18];
#if defined(jpn)
                    SafeAllocator* var69 = ((Struct_0206f81c_6*)var12)->inline_0206f81c(1);
#else
                    void* var70 = ((Struct_0206f81c_6*)var12)->inline_0206f81c(1);
#endif
                    ItemTable_Construct(eventBuf2);
                    ItemTable_Init(eventBuf2);
#if defined(jpn)
                    func_020e04f8(eventBuf2, (void*)r7base2, g_itemDataArchive, *(short*)(node + 6), true);
#else
                    BackgroundLoader::AddLockGlobal();
                    unsigned int outSize2 = 0;
                    void* loaded2 = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &outSize2);
                    if (loaded2 != NULL) {
                        BuildDescriptorFlag1_020de980(eventBuf2, r7base2, loaded2, outSize2, (int)(*(short*)(node + 6)));
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    SelfBuf0206f81c selfBuf2;
                    selfBuf2.alloc.ResetAllocatorPointer();
                    ItemTable_Construct(selfBuf2.sub14);
                    InitStruct0207cbe8((char*)&selfBuf2);
                    InitStruct0207cbe8((char*)&selfBuf2);
                    selfBuf2.eventPtr = eventBuf2;
                    func_0207d300(&selfBuf2, *(short*)(node + 6), 1, 0);
                }
                break;
            }

            case 0x8d: {
                var3 = *(unsigned short*)(var14 + 2);
                break;
            }

            case 0x91: {
                void* var74 = GetGameResources();
                unsigned short var75 = *(unsigned short*)(var14 + 2);
                struct Struct_020469f8* var76 = *(struct Struct_020469f8**)((char*)var74 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
                switch (var75) {
                case 2:
                    func_ov017_021b65e0(var74, 1);
                    break;
                case 6:
                    ((struct Struct_0206f81c_10*)((char*)var11 + REGION_VALUE(0xc, 0x26c)))->unknown_5d0c_.unknown_0_0_ |= 0x20;
                case 5: {
                    unsigned char* var77 = *(unsigned char**)((char*)var74 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    func_ov017_021b2174(var77);
                    func_ov017_021b2ba0((Struct_0206f81c_2*)var77, data_020f0b40);
                    func_ov017_021b2bd0(var77, (int)func_ov004_0215e25c, OVERLAY_ID(4));
                    func_020469f8(var76, (struct Struct_020469f8_2*)var77);
                    break;
                }
                case 7: {
                    unsigned char* var78 = *(unsigned char**)((char*)var74 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    func_ov017_021b2174(var78);
                    func_ov017_021b2bf4((Struct_0206f81c_3*)var78, 1);
                    func_ov017_021b2c0c((Struct_0206f81c_4*)var78, 1);
                    func_ov017_021b2ba0((Struct_0206f81c_2*)var78, data_020f0b4c);
                    func_ov017_021b2bd0(var78, (int)func_ov004_02168684, OVERLAY_ID(4));
                    func_020469f8(var76, (struct Struct_020469f8_2*)var78);
                    break;
                }
                case 8: {
                    unsigned char* var79 = *(unsigned char**)((char*)var74 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    func_ov017_021b2174(var79);
                    func_ov017_021b2bf4((Struct_0206f81c_3*)var79, 1);
                    func_ov017_021b2c0c((Struct_0206f81c_4*)var79, 1);
                    func_ov017_021b2bdc((Struct_0206f81c_5*)var79, 0);
                    func_ov017_021b2ba0((Struct_0206f81c_2*)var79, data_020f0b56);
                    func_ov017_021b2bd0(var79, (int)func_ov004_021689d8, OVERLAY_ID(4));
                    func_020469f8(var76, (struct Struct_020469f8_2*)var79);
                    break;
                }
                }
                break;
            }
            }

            var14 = *(unsigned char**)(var14 + 0x18);
        }

        if (var4 != 0 && var15 != 0) {
            unsigned char* var80 = (unsigned char*)func_0200fd0c((GameState*)var11);
            var80[7] = 1;
            *(Vector3i*)(var80 + 0x10) = *(Vector3i const*)var10;
        }
        if (var5 != 0 && var15 != 0) {
            unsigned char* var81 = (unsigned char*)func_0200fd0c((GameState*)var11);
            var81[7] = 1;
            *(short*)(var81 + 0x1c) = var6;
        }
        BackgroundLoader* inst2 = BackgroundLoader::GetInstance();
        if (flag20 != 0 && inst2->GetNumQueuedTasks() <= 0) {
            void* r4b = Scenario_GetInstance();
            void* misc2 = Zone3D_GetInstance();
            Scenario_LoadZoneTriggers(r4b, *(int*)((char*)misc2 + 8));
        }
        if (var3 != 0) {
            unsigned char* var85 = *(unsigned char**)((char*)var12 + 0x3000 + REGION_VALUE(0x938, 0xb58));
            if (var85[2] == 0) {
                func_ov017_021c16a8(var85);
                func_020469b4(var9, (struct Struct_0201bdac*)var85);
            }
        }
    }
}
