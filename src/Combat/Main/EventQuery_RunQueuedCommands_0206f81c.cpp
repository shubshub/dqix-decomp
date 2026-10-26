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

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_020703c8(int index, int arg1, int arg2, int second);
extern "C" void* func_ov017_021baedc(void* self, int flag);

struct TailNode020469b4;
struct TailList020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct SetFlagStruct;
extern "C" void MapDisplay_SetHoldSubScreenDark(struct SetFlagStruct* p, int value);
extern "C" void func_020e1154(void* obj);

extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void func_02070378(char* obj);

extern "C" void* func_0203cf4c(void);
extern "C" void* func_0203df78(void* base, int key);
extern "C" int func_02040528(int* obj);

extern "C" void func_ov017_021b8d80(void*);
extern "C" void func_ov017_021b8d1c(void* obj);

extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27b8(unsigned char* obj);

struct Vector3i;

extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_021b6e70(void* evt, unsigned short tag);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" void func_ov017_021b7104(void* node, void* out);

struct GameState;
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void ItemTable_Init(void* obj);
extern char* g_itemDataArchive;
extern char* g_itemDataFile;
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020de980(void* a, void* b, void* c, int d, int e);
extern "C" void func_0207cbe8(char* obj);
extern "C" void func_0207d300(void* obj, short id, int a, int b);

extern "C" int func_02086d88(unsigned char* self, int key);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
struct CombatantStruct;
extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_0206f81c;
extern "C" void* func_02083554(struct Struct_0206f81c* c, int id);
extern "C" void func_02083738(void* obj, int bits);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021c3fb4(int combatantId, int flag);
extern "C" void func_ov017_021c4418(int combatantId, signed char arg1);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

struct FieldTaskQueue;
extern "C" void FieldTaskQueue_Update(struct FieldTaskQueue* self);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

extern "C" void* Zone3D_GetInstance(void);
extern "C" void Scenario_LoadZoneTriggers(void* a, int b);
extern "C" int GameState_GetProtagonistIndex(GameState*);

extern "C" void func_ov017_021c16a8(unsigned char* self);

extern "C" void func_ov017_021b65e0(void* obj, int arg1);

struct Struct_0206f81c_2;
extern "C" void func_ov017_021b2174(unsigned char* obj);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* obj, char* src);
extern "C" void func_ov017_021b2bd0(void* obj, int a, int b);
struct Struct_0206f81c_3;
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* obj, unsigned int v);
struct Struct_0206f81c_4;
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* obj, unsigned int v);
struct Struct_0206f81c_5;
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* obj, unsigned int v);
struct HeadList020469f8;
struct HeadNode020469f8;
extern "C" void func_020469f8(struct HeadList020469f8* list, struct HeadNode020469f8* node);

extern "C" void func_ov004_0215e25c(void*, void*);
extern "C" void func_ov004_02168684();
extern "C" void func_ov004_021689d8(SafeAllocator*, void*);
extern char data_020f0b40[];
extern char data_020f0b4c[];
extern char data_020f0b56[];

struct Struct_0206f81c_6 {
    char pad[0x164 - sizeof(SafeAllocator)];
    SafeAllocator allocs[2];
    SafeAllocator* inline_0206f81c(int i) { return &allocs[i]; }
};

struct Struct_0206f81c_7 {
    SafeAllocator alloc;
    char pad[0x14 - sizeof(SafeAllocator)];
    char sub14[0x18];
    void* unknown_2c_;
    char pad2[8];
};

struct Struct_0206f81c_8 {
    int unk0;
    int unk4;
    unsigned int kind : 4;
};

struct Struct_0206f81c_9 {
    unsigned short low : 13;
    unsigned short high : 3;
};

struct Struct_0206f81c_10 {
    char pad[0x5d0c];
    struct Struct_0206f81c_9 flags;
};

struct Struct_0206f81c_11 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned short f4;
    unsigned char pad6[2];
    int f8;
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char unknown_13_;
    int f14;
};

// Main, originally func_0206f81c (USA 0x0206f81c, EUR 0x0206f82c, JPN 0x020708dc)
extern "C" ARM void EventQuery_RunQueuedCommands(void* a0) {
    void* searchPtr;
    void* miscCtx;
    int var2;
    int var3;
    int var4;
    int var5;
    short var6;
    struct BattleStruct* battle2;
    BackgroundLoader* inst;
    struct TailList020469b4* var9;
    int vec[3];
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    void* g = GetGameResources();
    void* var13 = (char*)g + 0x3000;
    var9 = *(struct TailList020469b4**)((char*)var13 + REGION_VALUE(0x4ec, 0x6fc));
    searchPtr = LinkSession_GetInstance();
    miscCtx = Scenario_GetInstance();
    unsigned char* node = *(unsigned char**)((char*)a0 + 0x30);
    unsigned char slFlag;
    var2 = 0;
    var3 = 0;
    slFlag = 0;
    var4 = 0;
    var5 = 0;

    if (node != NULL) {
        while (node != NULL) {
            unsigned short type = *(unsigned short*)(node + 0);
            switch (type) {
            case 0x84: {
                func_020703c8(((unsigned char*)miscCtx)[0x332], *(unsigned short*)(node + 4), *(unsigned short*)(node + 6), *(unsigned short*)(node + 8));
                var2 = 1;
                break;
            }

            case 0x94: {
                for (int i = 0; i < 5; i++) {
                    func_020703c8(i, *(unsigned short*)(node + 4), *(unsigned short*)(node + 6), *(unsigned short*)(node + 8));
                }
                var2 = 1;
                break;
            }

            case 0xd6: {
                func_020703c8(*(unsigned short*)(node + 2), *(unsigned short*)(node + 4), *(unsigned short*)(node + 6), *(unsigned short*)(node + 8));
                var2 = 1;
                break;
            }

            case 0x77: case 0x80: case 0x9b: {
                struct TailNode020469b4* var18 = *(struct TailNode020469b4**)((char*)g + 0x3000 + REGION_VALUE(0x524, 0x734));
                func_ov017_021baedc(var18, 1);
                *(unsigned short*)((char*)var18 + 8) = *(unsigned short*)(node + 2);
                func_020469b4(var9, var18);
                MapDisplay_SetHoldSubScreenDark(*(struct SetFlagStruct**)((char*)g + 0x3000 + REGION_VALUE(0x4c0, 0x6d0)), 1);
                func_020e1154((void*)0x1f4);
                break;
            }

            case 0x85: case 0x8a: case 0xe2: {
                unsigned char* f3f8 = (unsigned char*)GameState_GetZoneTransition((GameState*)battle);
                func_02070378((char*)f3f8);
                f3f8[2] = 1;
                *(unsigned short*)(f3f8 + 0) = *(unsigned short*)(node + 2);
                *(unsigned int*)(f3f8 + 0x20) = *(unsigned short*)(node + 4);
                if (*(unsigned short*)(node + 0) == 0x8a) f3f8[6] = 1;
                if (*(unsigned short*)(node + 0) == 0xe2) f3f8[0xc] = 1;
                if (*((unsigned char*)battle + 0x5000 + REGION_VALUE(0xa4c, 0xcac)) != 0) f3f8[0x60] = 1;
                slFlag = 1;
                MapDisplay_SetHoldSubScreenDark(*(struct SetFlagStruct**)((char*)g + 0x3000 + REGION_VALUE(0x4c0, 0x6d0)), slFlag);
                break;
            }

            case 0x76: {
                void* entry = func_0203df78(func_0203cf4c(), *(unsigned short*)(node + 2));
                int sb = 0;
                if (entry != NULL) {
                    sb = func_02040528((int*)entry);
                }
                if (sb != 0) {
                    unsigned char var22;
                    unsigned char* r8 = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x500, 0x710));
                    var22 = *(unsigned char*)(r8 + 3);
                    if (var22 != 0) {
                        func_ov017_021b8d80(r8);
                    }
                    unsigned char* var24 = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x50c, 0x71c));
                    var22 |= (*(unsigned char*)(var24 + 3) != 0 && *(unsigned char*)(var24 + 0x20) != 0);
                    func_ov017_021b8d1c(r8);
                    *(int*)(r8 + 0x114) = sb;
                    *(int*)(r8 + 0x124) = *(unsigned short*)(node + 4);
                    *(unsigned char*)(r8 + 0x139) = (var22 != 0) ? 1 : 0;
                    func_020469b4(var9, (struct TailNode020469b4*)r8);
                    int flag4 = GameState_GetFollowCamera((char*)battle);
                    if (flag4 != 0) {
                        func_020a27b8((unsigned char*)flag4);
                    }
                }
                break;
            }

            case 0x79: case 0x89: case 0xe1: {
                unsigned char* f3f8 = (unsigned char*)GameState_GetZoneTransition((GameState*)battle);
                func_02070378((char*)f3f8);
                f3f8[2] = 1;
                *(unsigned short*)(f3f8 + 0) = *(unsigned short*)(node + 2);
                f3f8[0xc] = 1;
                if (*(unsigned short*)(node + 0) == 0x89) f3f8[6] = 1;
                if (*(unsigned short*)(node + 0) == 0xe1) f3f8[0xc] = 0;
                slFlag = 1;
                break;
            }

            case 0x7a: {
                *(Vector3i*)vec = *(Vector3i const*)(node + 4);
                var4 = 1;
                break;
            }

            case 0x7b: {
                var6 = *(short*)(node + 4);
                var5 = 1;
                break;
            }

            case 0x78: {
                struct TailList020469b4* var27;
                unsigned char* r8 = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x508, 0x718));
                var27 = *(struct TailList020469b4**)((char*)g + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
                void* sb = LightingManager::GetInstance();
                func_ov017_021b6f18(r8);

                struct Struct_0206f81c_11 desc;
                desc.f0 = 1;
                desc.f1 = 0;
                desc.f2 = 0;
                desc.f4 = 0;
                desc.fc = 0;
                desc.unknown_d_ = 0;
                desc.fe = 0;
                desc.ff = 0;
                desc.f14 = 0;
                desc.f10 = -1;
                desc.f12 = 2;
                desc.f8 = -1;

                desc.f1 = GameState_GetProtagonistIndex((GameState*)battle);
                desc.f4 = *(unsigned short*)(node + 2) + 5 + 0x8000;
                desc.f2 = 0xffff;
                desc.f8 = *(unsigned short*)(node + 2);
                func_ov017_021b6e70(&desc, desc.f2);
                desc.f12 = *(int*)((char*)sb + 0x98);

                if (LinkSession_IsGuest(searchPtr) != 0) {
                    if (desc.fc == 0 && desc.unknown_d_ == 0) {
                        desc.f14 = 1;
                    }
                }
                func_ov017_021b7104(r8, &desc);
                func_020469b4(var27, (struct TailNode020469b4*)r8);
                break;
            }

            case 0x7c: {
                void* e = func_0203df78(func_0203cf4c(), *(unsigned short*)(node + 2));
                if (e != NULL) {
                    *(int*)e |= 0x8000;
                }
                break;
            }

            case 0x72: case 0x74: {
                if (GameState_GetParty((GameState*)battle) != NULL) {
                    unsigned char eventBuf[0x18];
#if defined(jpn)
                    SafeAllocator* r7base = ((Struct_0206f81c_6*)g)->inline_0206f81c(1);
#else
                    void* r7base = ((Struct_0206f81c_6*)g)->inline_0206f81c(1);
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
                        func_020de980(eventBuf, r7base, loaded, outSize, (int)(*(short*)(node + 2)));
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    Struct_0206f81c_7 selfBuf;
                    selfBuf.alloc.ResetAllocatorPointer();
                    ItemTable_Construct(selfBuf.sub14);
                    func_0207cbe8((char*)&selfBuf);
                    func_0207cbe8((char*)&selfBuf);
                    selfBuf.unknown_2c_ = eventBuf;
                    func_0207d300(&selfBuf, *(short*)(node + 2), (signed char)*(unsigned short*)(node + 4), 0);
                }
                break;
            }

            case 0x73: case 0x75: {
                void* p2a04 = GameState_GetParty((GameState*)battle);
                if (p2a04 != NULL) {
                    int matchCount = 0;
                    for (int total = 0; total < *(unsigned short*)(node + 4); total++) {
                        if (func_02086d88((unsigned char*)p2a04, *(short*)(node + 2)) != 0) matchCount++;
                    }
                    if (matchCount < *(unsigned short*)(node + 4)) {
                        battle2 = (BattleStruct*)GameState::GetInstance();
                        unsigned char buf40[4];
                        int idArr[4];
                        int var43 = 0;
                        unsigned char count = GameState_GetOwnPartyOrder((char*)battle2, buf40);
                        for (int i = 0; i < count; i++) {
                            struct CombatantStruct* combatant = (CombatantStruct*)func_0200ff1c((GameState*)battle2, buf40[i]);
                            if (combatant != NULL) {
                                int field150 = func_02053c6c((unsigned char*)combatant);
                                if (field150 != 0) {
                                    struct Struct_0206f81c_8* entry = (struct Struct_0206f81c_8*)func_02083554((struct Struct_0206f81c*)field150, *(unsigned short*)(node + 2));
                                    if (entry != NULL) {
                                        func_02083738((void*)field150, entry->kind);
                                        idArr[var43] = buf40[i];
                                        var43++;
                                        matchCount++;
                                        if (matchCount == *(unsigned short*)(node + 4)) break;
                                    }
                                }
                            }
                        }
                        int var49 = -1;
                        for (int j = 0; j < var43; j++) {
                            if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
                                int cid = idArr[j];
                                func_ov017_021c3fb4(cid, 1);
                                func_ov017_021c4418(cid, var49);
                            }
                            void* g2 = GetGameResources();
                            void* field700 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f0, 0x700));
                            void* field704 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f4, 0x704));
                            inst = BackgroundLoader::GetInstance();
                            func_ov017_0218f5a4(g2, idArr[j], 1, 0, 0);
                            while (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field700) == 0x13) {
                                inst->RemoveAllLocks();
                                FieldTaskQueue_Update((struct FieldTaskQueue*)field700);
                                if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field704) == 0x14) {
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
                    if (func_02086d88((unsigned char*)p2a04, *(short*)(node + 4)) != 0) found = 1;
                    if (found == 0) {
                        unsigned char buf3c[4];
                        unsigned char count = GameState_GetOwnPartyOrder((char*)battle, buf3c);
                        for (int i = 0; i < count; i++) {
                            int cid = buf3c[i];
                            struct CombatantStruct* c = (CombatantStruct*)func_0200ff1c((GameState*)battle, cid);
                            if (c != NULL) {
                                int field150 = func_02053c6c((unsigned char*)c);
                                if (field150 != 0) {
                                    struct Struct_0206f81c_8* entry = (struct Struct_0206f81c_8*)func_02083554((struct Struct_0206f81c*)field150, *(short*)(node + 4));
                                    if (entry != NULL) {
                                        func_02083738((void*)field150, entry->kind);
                                        if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
                                            func_ov017_021c3fb4(cid, 1);
                                            func_ov017_021c4418(cid, -1);
                                        }
                                        void* g2 = GetGameResources();
                                        void* field700 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f0, 0x700));
                                        void* field704 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f4, 0x704));
                                        BackgroundLoader* inst = BackgroundLoader::GetInstance();
                                        func_ov017_0218f5a4(g2, cid, 1, 0, 0);
                                        while (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field700) == 0x13) {
                                            inst->RemoveAllLocks();
                                            FieldTaskQueue_Update((struct FieldTaskQueue*)field700);
                                            if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field704) == 0x14) {
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
                    SafeAllocator* r7base2 = ((Struct_0206f81c_6*)g)->inline_0206f81c(1);
#else
                    void* r7base2 = ((Struct_0206f81c_6*)g)->inline_0206f81c(1);
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
                        func_020de980(eventBuf2, r7base2, loaded2, outSize2, (int)(*(short*)(node + 6)));
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    Struct_0206f81c_7 selfBuf2;
                    selfBuf2.alloc.ResetAllocatorPointer();
                    ItemTable_Construct(selfBuf2.sub14);
                    func_0207cbe8((char*)&selfBuf2);
                    func_0207cbe8((char*)&selfBuf2);
                    selfBuf2.unknown_2c_ = eventBuf2;
                    func_0207d300(&selfBuf2, *(short*)(node + 6), 1, 0);
                }
                break;
            }

            case 0x8d: {
                var3 = *(unsigned short*)(node + 2);
                break;
            }

            case 0x91: {
                void* g2 = GetGameResources();
                unsigned short sub = *(unsigned short*)(node + 2);
                struct HeadList020469f8* var76 = *(struct HeadList020469f8**)((char*)g2 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
                switch (sub) {
                case 2:
                    func_ov017_021b65e0(g2, 1);
                    break;
                case 6:
                    ((struct Struct_0206f81c_10*)((char*)battle + REGION_VALUE(0xc, 0x26c)))->flags.low |= 0x20;
                case 5: {
                    unsigned char* var77 = *(unsigned char**)((char*)g2 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    func_ov017_021b2174(var77);
                    func_ov017_021b2ba0((Struct_0206f81c_2*)var77, data_020f0b40);
                    func_ov017_021b2bd0(var77, (int)func_ov004_0215e25c, OVERLAY_ID(4));
                    func_020469f8(var76, (struct HeadNode020469f8*)var77);
                    break;
                }
                case 7: {
                    unsigned char* var78 = *(unsigned char**)((char*)g2 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    func_ov017_021b2174(var78);
                    func_ov017_021b2bf4((Struct_0206f81c_3*)var78, 1);
                    func_ov017_021b2c0c((Struct_0206f81c_4*)var78, 1);
                    func_ov017_021b2ba0((Struct_0206f81c_2*)var78, data_020f0b4c);
                    func_ov017_021b2bd0(var78, (int)func_ov004_02168684, OVERLAY_ID(4));
                    func_020469f8(var76, (struct HeadNode020469f8*)var78);
                    break;
                }
                case 8: {
                    unsigned char* var79 = *(unsigned char**)((char*)g2 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    func_ov017_021b2174(var79);
                    func_ov017_021b2bf4((Struct_0206f81c_3*)var79, 1);
                    func_ov017_021b2c0c((Struct_0206f81c_4*)var79, 1);
                    func_ov017_021b2bdc((Struct_0206f81c_5*)var79, 0);
                    func_ov017_021b2ba0((Struct_0206f81c_2*)var79, data_020f0b56);
                    func_ov017_021b2bd0(var79, (int)func_ov004_021689d8, OVERLAY_ID(4));
                    func_020469f8(var76, (struct HeadNode020469f8*)var79);
                    break;
                }
                }
                break;
            }
            }

            node = *(unsigned char**)(node + 0x18);
        }

        if (var4 != 0 && slFlag != 0) {
            unsigned char* f3f8 = (unsigned char*)GameState_GetZoneTransition((GameState*)battle);
            f3f8[7] = 1;
            *(Vector3i*)(f3f8 + 0x10) = *(Vector3i const*)vec;
        }
        if (var5 != 0 && slFlag != 0) {
            unsigned char* f3f8 = (unsigned char*)GameState_GetZoneTransition((GameState*)battle);
            f3f8[7] = 1;
            *(short*)(f3f8 + 0x1c) = var6;
        }
        BackgroundLoader* var82 = BackgroundLoader::GetInstance();
        if (var2 != 0 && var82->GetNumQueuedTasks() <= 0) {
            void* r4b = Scenario_GetInstance();
            void* misc2 = Zone3D_GetInstance();
            Scenario_LoadZoneTriggers(r4b, *(int*)((char*)misc2 + 8));
        }
        if (var3 != 0) {
            unsigned char* var85 = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x938, 0xb58));
            if (var85[2] == 0) {
                func_ov017_021c16a8(var85);
                func_020469b4(var9, (struct TailNode020469b4*)var85);
            }
        }
    }
}
