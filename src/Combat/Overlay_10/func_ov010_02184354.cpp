#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_ov010_02184a80 data_ov010_02185b40
#define data_ov010_02184aa6 data_ov010_02185b54
#endif

extern AllocatorUnion g_mainAllocator;
extern int g_sePlayer;
extern const char data_ov010_02184a80[];
extern const char data_ov010_02184a95[];
extern const char data_ov010_02184aa6[];

struct Struct_ov010_021842d8;
extern "C" void func_ov010_021842d8(struct Struct_ov010_021842d8* obj);

struct Obj020397cc;
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

struct Struct_020727d8 {
    void* entries;
    short capacity;
    short count;
};
extern "C" void func_020727d8(struct Struct_020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a4, int a5, int a6);

struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void SePlayer_LoadExtraArchiveB(void* obj, int a, int b);
extern "C" void SePlayer_PlayExtra(void* obj, int a, int b);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);

struct ColorHolder0204bd7c;
extern "C" unsigned short func_0204bd7c(struct ColorHolder0204bd7c* obj);

struct SearchEntry {
    unsigned short key;
    unsigned char pad2[0xc];
    unsigned char unknown_e_0_ : 2;
    unsigned char kind : 4;
    unsigned char unknown_e_6_ : 2;
    unsigned char unknown_f_;
};
struct SearchTable;
extern "C" struct SearchEntry* ZoneTable_FindEntry(struct SearchTable* table, int key);

extern "C" void* GameObject_GetFloorAttribute(void* obj);
extern "C" void* GameState_GetZoneTable(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* b);
extern "C" void* GameState_GetPlayerLocation(char* base, unsigned int index);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);

struct Struct_020340b4;
extern "C" void func_020340b4(struct Struct_020340b4* p);

extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
extern "C" void func_02046380(void* global);
extern "C" int func_020457e0(void* global);

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);

struct Struct_02057de0_2;
extern "C" void* func_02057924(void);
extern "C" int func_02057de0(struct Struct_02057de0_2* list, int a1, SafeAllocator* alloc, int a2, int a3);
extern "C" int func_02057fb4(void* list, int id, void* params);

struct Vector3i;

extern "C" void* func_02079e2c(char* p, int key);

struct Struct_02048350_2;
extern "C" int func_02048350(struct Struct_02048350_2* obj, int amount);

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);

struct Struct_ov010_02184354 { short x; short y; short z; };
extern "C" void func_ov017_021d360c(int a, unsigned char b, int c, struct Struct_ov010_02184354 d);

struct MoveRecord02184354 {
    unsigned short id;
    unsigned char pad2[6];
    struct Struct_ov010_02184354_3* info;
};
struct Struct_ov010_02184354_3 {
    unsigned char pad0[0xc];
    unsigned char category : 4;
    unsigned char unknown_c_4_ : 4;
    unsigned char pad0d;
    unsigned char unknown_e_0_ : 6;
    unsigned char unknown_e_6_ : 1;
    unsigned char unknown_e_7_ : 1;
};

struct Struct_ov010_02184354_4 {
    unsigned char pad0[0xc];
    unsigned char combatantId;
};
extern "C" MessageSystem* MessageSystem_GetInstance(void);

struct Struct_ov010_02184354_5 {
    unsigned char pad0[8];
    unsigned int amount : 8;
    unsigned int unknown_9_0_ : 24;
};

struct Struct_ov010_02184354_6 { int x; int y; int z; };

struct Struct_ov010_02184354_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20; int f24; int f28;
    int unknown_2c_; int unknown_30_; int f34;
    int unknown_38_; int f3c; int f40;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

struct Struct_ov010_02184354_8 {
    unsigned char state;
    unsigned char visible;
    unsigned short unknown_2_;
    int taskId;
    int nodeId;
    struct Struct_020727d8 list;
    SafeAllocator alloc;
};

// USA: func_ov010_02184354
extern "C" ARM int func_ov010_02184354(struct Struct_ov010_02184354_8* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    MessageSystem* presenter = MessageSystem_GetInstance();
    GameState* bs = GameState::GetInstance();
    GameObject* caster;
    struct MoveRecord02184354* move;
#if defined(jpn)
    struct Struct_ov010_02184354_4* actorInfo = *(Struct_ov010_02184354_4**)((char*)GetGameResources() + 0x3988);
#else
    struct Struct_ov010_02184354_4* actorInfo = *(Struct_ov010_02184354_4**)((char*)GetGameResources() + 0x3ba8);
#endif
    caster = bs->GetPartyMemberByIndex(actorInfo->combatantId);
    GameObject* active = bs->GetPartyMemberByIndex(GameState_GetLeaderIndex(bs));
    void* scene = LinkSession_GetInstance();
    void* ov17 = GetGameResources();
    move = (struct MoveRecord02184354*)Zone3D_GetInstance();
#if defined(jpn)
    char message[200];
#endif

    if (caster == NULL || active == NULL) {
        func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
        return 1;
    }

    unsigned char state = obj->state;
    if (state == 0) {
        GameObject_DisableControl((struct Obj020397cc*)active, 1);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x7800);
        if (buffer == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            return 1;
        }
        obj->alloc.CreateTypeA(buffer, 0x7800);
#if defined(jpn)
        obj->taskId = loader->QueueLoadFile(data_ov010_02184a80, NULL);
#else
        obj->taskId = loader->QueueLoadFileInGP2(data_ov010_02184a80, data_ov010_02184a95, NULL);
#endif
        obj->state = 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(obj->taskId) == 0) return 0;
        if (loader->GetDetailedTaskStatus(obj->taskId) != 2) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            return 1;
        }
        void* filePtr;
        unsigned int fileLen;
        loader->GetLoadedFileByID(obj->taskId, &filePtr, &fileLen);
        func_020727d8(&obj->list);
        func_020728ac(&obj->list, &obj->alloc, filePtr, fileLen, 0, 0, 0);
        loader->RemoveTask(obj->taskId);

        unsigned short* slot = (unsigned short*)GameState_GetPlayerLocation((char*)bs, GameState_GetProtagonistIndex(bs));
        if (slot == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            return 1;
        }
        struct Struct_ov010_02184354_3* info = move->info;
        if (info == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            return 1;
        }

        unsigned char visible = 1;
        obj->visible = visible;
        if (info->category == 0) {
            void* colour = GameObject_GetFloorAttribute(caster);
            if (colour != NULL) {
                struct SearchTable* table = (struct SearchTable*)GameState_GetZoneTable(bs);
                struct SearchEntry* entry = ZoneTable_FindEntry(table,
                    func_0204bd7c((struct ColorHolder0204bd7c*)colour));
                if (entry != NULL) {
                    if (entry->kind != 0) obj->visible = 0;
                }
            }
        } else {
            struct Struct_ov010_02184354_3* self = move->info;
            if (self != NULL) {
                if (self->unknown_e_6_ == 0) visible = 0;
                obj->visible = visible;
            }
        }

        int key;
        if (obj->visible == 0) {
            obj->state = 3;
            key = 2;
        } else if (*slot != 0) {
            obj->state = 2;
            key = 1;
        } else {
            key = 0;
            obj->state = 4;
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, key);
        }

        void* entry = func_02072a68((struct TableA68*)&obj->list, (short)key);
#if defined(jpn)
        sprintf(message, (const char*)entry, *(char**)((char*)caster + 0x134));
        func_0204500c(presenter, message, 0);
        presenter->active = 1;
#else
        struct Struct_ov010_02184354_6 casterObj;
        NameText_InitFromPartyMember(&casterObj, actorInfo->combatantId);
        func_02046380(presenter);
        *(void**)presenter = &casterObj;
        func_0204500c(presenter, (const char*)entry, 0, 0xe3);
        presenter->active = 1;
#endif
    } else if (state == 2) {
#if defined(jpn)
        if (presenter->active != 0) return 0;
#else
        if (presenter->active != 0) return 0;
#endif
        if (func_020457e0(presenter) == 0) {
            void* entry = func_02072a68((struct TableA68*)&obj->list, 0);
#if defined(jpn)
            sprintf(message, (const char*)entry, *(char**)((char*)caster + 0x134));
            func_0204500c(presenter, message, 0);
            presenter->active = 1;
#else
            struct Struct_ov010_02184354_6 casterObj;
            NameText_InitFromPartyMember(&casterObj, actorInfo->combatantId);
            func_02046380(presenter);
            *(void**)presenter = &casterObj;
            func_0204500c(presenter, (const char*)entry, 0, 0xe3);
            presenter->active = 1;
#endif
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            unsigned short* slot = (unsigned short*)GameState_GetPlayerLocation((char*)bs, GameState_GetProtagonistIndex(bs));
            if (slot != NULL) *slot = 0;
            obj->state = 4;
        } else {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            return 1;
        }
    } else if (state == 4) {
        obj->taskId = loader->QueueLoadFile(data_ov010_02184aa6, NULL);
        obj->state = 5;
        obj->unknown_2_ = 0;
    } else if (state == 5) {
        if (loader->GetTaskStatus(obj->taskId) == 0) return 0;
        if (loader->GetDetailedTaskStatus(obj->taskId) != 2) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            return 1;
        }
        if (obj->unknown_2_ < 0xf) {
            obj->unknown_2_ = obj->unknown_2_ + 1;
            return 0;
        }
        SePlayer_LoadExtraArchiveB(&g_sePlayer, 0x74, 0x74);
        SePlayer_PlayExtra(&g_sePlayer, 0, 0);

        void* filePtr;
        unsigned int fileLen;
        loader->GetLoadedFileByID(obj->taskId, &filePtr, &fileLen);

#if defined(jpn)
        char* stage = (char*)ov17 + 0x27c;
#else
        char* stage = (char*)ov17 + 0x2cc;
#endif
        struct Struct_ov010_02184354_6 pos = *(struct Struct_ov010_02184354_6*)((char*)caster + 0x44);
        VramState_Rewind((struct Foo0207df50*)(stage + 0xc40));
        VramState_Restore(stage + 0xc40);
        void* nodes = func_02057924();
        func_02057de0((struct Struct_02057de0_2*)nodes, 0x11, &obj->alloc,
                                      (int)filePtr, (int)fileLen);
        VramState_Save(stage + 0xc40);

        struct Struct_ov010_02184354_6 scale;
        scale.x = 0x10a;
        scale.y = 0x10a;
        scale.z = 0x10a;

        struct Struct_ov010_02184354_7 params;
        params.unknown_0_ = 0;
        params.f10 = 1;
        params.f12 = 0;
        params.f14 = -1;
        params.unknown_16_ = -1;
        params.f18 = -1;
        params.unknown_1a_ = -1;
        params.f1c = -0x1000;
        params.f20 = 0;
        params.f24 = 0;
        params.f28 = 0;
        params.unknown_2c_ = 0;
        params.unknown_30_ = 0;
        params.f34 = 0;
        params.unknown_38_ = 0;
        params.f3c = 0;
        params.f40 = 0;
        params.unknown_44_ = 0x1000;
        params.unknown_48_ = 0x1000;
        params.unknown_4c_ = 0x1000;
        params.b0 = 0;
        params.b1 = 0;
        params.b2 = 1;
        params.b3 = 0;
        params.unknown_11_4_ = 0;
        params.unknown_11_5_ = 0;
        params.unknown_11_6_ = 0;
        params.unknown_11_7_ = 0;

        *(Vector3i*)&params.unknown_2c_ = *(Vector3i const*)&pos.x;
        *(Vector3i*)&params.unknown_44_ = *(Vector3i const*)&scale.x;
        obj->nodeId = func_02057fb4(nodes, 0x11, &params);

        struct Struct_ov010_02184354 anchor;
        anchor.x = (short)(pos.x >> 4);
        anchor.y = (short)(pos.y >> 4);
        anchor.z = (short)(pos.z >> 4);

        if (LinkSession_IsHostOrSolo(scene) != 0) {
            unsigned short* slot = (unsigned short*)GameState_GetPlayerLocation((char*)bs, GameState_GetProtagonistIndex(bs));
            if (slot != NULL) {
                slot[0] = move->id;
                slot[1] = anchor.x;
                slot[2] = anchor.y;
                slot[3] = anchor.z;
            }
        }

        struct Struct_ov010_02184354_5* row =
            (struct Struct_ov010_02184354_5*)func_02079e2c((char*)func_020797dc(), 0xd2);
        if (row != NULL) {
            func_02048350((struct Struct_02048350_2*)caster, row->amount);
        }
        GameObject* target = bs->GetLeader();
        if (target != NULL) {
            func_020340b4((struct Struct_020340b4*)target);
        }
        func_ov017_021d360c(0, GameState_GetProtagonistIndex(bs), move->id, anchor);
        obj->state = 3;
    } else if (state == 3) {
        GameState* now = GameState::GetInstance();
        int var39 = 0;
        if (obj->visible != 0) {
#if defined(jpn)
            if (now->GetGameObjectByIndex(obj->nodeId) == NULL && presenter->active == 0) {
#else
            if (now->GetGameObjectByIndex(obj->nodeId) == NULL && presenter->active == 0) {
#endif
                var39 = 1;
            }
        } else {
#if defined(jpn)
            if (presenter->active == 0) var39 = 1;
#else
            if (presenter->active == 0) var39 = 1;
#endif
        }
        if (var39 != 0) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)obj);
            SePlayer_UnloadExtraArchiveB(&g_sePlayer);
            return 1;
        }
    }
    return 0;
}
