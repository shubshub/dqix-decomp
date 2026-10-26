#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Zone02012fe4 {
#if defined(jpn)
    char pad[0x240c];
#else
    char pad[0x23ec];
#endif
    ActiveGrottoClass activeGrotto;
};

struct Struct_020e3f1c_6 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct Struct_020e3f1c_7 {
#if defined(jpn)
    const char* name;
    char pad4[0x10 - 0x4];
#else
    char pad[0x10];
#endif
    unsigned short id;
};

struct Actor020e3f1c {
    char pad0[0x44];
    struct Vec3 position;
    char unknown_50_[0xb2 - 0x50];
    short unknown_b2_;
    char unknown_b4_[0xc1 - 0xb4];
    struct Struct_020e3f1c_6 unknown_c1_;
    char unknown_c2_[0x134 - 0xc2];
    char* name;
    char unknown_138_[0x17d - 0x138];
    unsigned char unknown_17d_;
    char unknown_17e_[0x180 - 0x17e];
    struct Struct_020e3f1c_7* info;
};

struct PartyOrder020e3f1c {
    char pad[0xf78];
    unsigned char order[4];
    unsigned char count;
};

struct Camera020e3f1c {
    char pad[0x10];
    struct Vec3 target;
};

struct Display020e3f1c {
#if defined(jpn)
    char pad0[0x868];
    int busy;
    int active;
    char unknown_870_[0x17e2 - 0x870];
#else
    char pad0[0x998];
    int busy;
    int active;
    char unknown_9a0_[0x19b2 - 0x9a0];
#endif
    unsigned char visible;
};

struct Struct_020e3f1c_4 {
    char pad0[0x8];
    unsigned short monsterIndex;
    unsigned char state;
    char unknown_b_;
    short taskId;
    unsigned char unknown_e_;
};

struct Struct_02076a8c_2;
struct Bytes02033b88;
struct Obj020397cc;
struct Struct_020338d4;
struct GlobalObj0202e6a8;
struct Camera;
struct Struct_0202ea4c;
struct Obj020d7aa0;
struct Obj02046574;
struct Container020e0310;

extern "C" struct Display020e3f1c* MessageSystem_GetInstance();
extern "C" struct Zone02012fe4* Zone3D_GetInstance();
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" int func_ov017_021959b4();
extern "C" void func_020e4524(char* obj);
extern "C" void FieldTask_EndGrottoBossIntro(void* obj);
extern "C" void func_02076b58(struct Struct_02076a8c_2* actor);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* word, unsigned int mask);
extern "C" void GameObject_ForceMotionState(struct Bytes02033b88* obj, int value);
extern "C" void GameObject_UpdatePartyMember(GameObject* obj);
extern "C" void GameObject_DisableControl(struct Obj020397cc* obj, int arg);
extern "C" void func_020531f0(GameObject* obj);
extern "C" void func_020a27b8(unsigned char* obj);
extern "C" int GameObject_GetLinePosition(void* obj);
extern "C" void func_020338d4(struct Struct_020338d4* self, struct Vec3* target);
extern "C" void GameObject_ResetTrail(unsigned char* obj);
extern "C" void func_020338b0(unsigned char* obj, int target);
extern "C" void Camera_SetOrbitYaw(struct GlobalObj0202e6a8* obj, int value);
extern "C" int Camera_GetOrbitDistance(void* obj);
extern "C" void Camera_SetPosition(struct Camera* obj, int x, int y, int z);
extern "C" void func_0202ea4c(struct Struct_0202ea4c* obj);
extern "C" void Camera_Update(struct Camera020e3f1c* camera);
extern "C" struct Obj020d7aa0* TextQueue_GetInstance();
extern "C" void TextQueue_Reset(struct Obj020d7aa0* obj);
extern "C" void func_ov017_021c3e18(int arg);
extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void* KeyTable_Construct(void* p);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void KeyTable_Load(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* ptr);
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* name);
#if defined(jpn)
extern "C" void func_0204500c(void* global, void* entry, int a);
#else
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
#endif
extern "C" void MessageSystem_Stop(void* global);

extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
struct Struct_020727d8 {
    void* unk_0;
    void* unk_4;
};
struct TableA68;
#include "Filesystem/FileIO.h"
extern "C" int STD_CompareString(const char* a, const char* b);
extern "C" void func_020727d8(struct Struct_020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a4, int a5, int a6);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern const char data_020f2e30[];
extern const char data_020f2e3b[];
extern const char data_020f2e4d[];
#else
extern const char data_020f2cd4[];
extern const char data_020f2ce4[];
#endif

static inline int FxMul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_020e3f1c
extern "C" ARM void func_020e3f1c(struct Struct_020e3f1c_4* intro) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameState* gs = GameState::GetInstance();
    struct Display020e3f1c* display = MessageSystem_GetInstance();
    FontBankLoader* mgr = FontBankLoader_GetInstance();
    ActiveGrottoClass* grotto = &Zone3D_GetInstance()->activeGrotto;
    struct Camera020e3f1c* camera = (struct Camera020e3f1c*)GameState_GetFollowCamera((char*)gs);
    struct Actor020e3f1c* leader = (struct Actor020e3f1c*)gs->GetLeader();
    GameResources* res = GetGameResources();

    if (func_ov017_021959b4()) {
        func_020e4524((char*)intro);
        return;
    }

    short bossId = -1;
    if (grotto != NULL) {
        DetailedTreasureMapData* map = grotto->GetDetailedData();
        if (map != NULL) {
            if (map->mapType_ == 1) {
                bossId = map->regular_.bossMonsterID_;
            } else if (map->mapType_ == 2) {
                bossId = map->legacy_.bossMonsterID_;
            }
        }
    }

    struct Actor020e3f1c* monster = (struct Actor020e3f1c*)gs->GetFieldMonsterByIndex(intro->monsterIndex);
    if (monster == NULL) {
        FieldTask_EndGrottoBossIntro(intro);
        return;
    }
    func_02076b58((struct Struct_02076a8c_2*)monster);
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 2);

    int i;
    for (i = 0; i < 4; i++) {
        GameObject* member = gs->GetPartyMemberByIndex(i);
        if (member != NULL) {
            member->obj3D_.EnableFlag(0x1000000);
            member->obj3D_.DisableFlag(0x1020);
            ((struct Actor020e3f1c*)member)->unknown_c1_.mode |= 2;
            if (((struct Actor020e3f1c*)member)->unknown_b2_ > 0) {
                GameObject_ForceMotionState((struct Bytes02033b88*)member, 1);
            } else {
                GameObject_ForceMotionState((struct Bytes02033b88*)member, 0);
            }
            GameObject_UpdatePartyMember(member);
        }
    }

    if (intro->state == 0) {
        if (leader != NULL) {
            GameObject_DisableControl((struct Obj020397cc*)leader, 1);
            leader->unknown_b2_ = 0;
        }
        for (int j = 0; j < 4; j++) {
            GameObject* member = gs->GetPartyMemberByIndex(j);
            if (member != NULL) {
                func_020531f0(member);
            }
        }
        func_020a27b8((unsigned char*)camera);
        SetMainBrightness(res, -16, 0x1e);
#if defined(jpn)
        if (STD_CompareString(monster->info->name, data_020f2e30) == 0) {
#else
        if (monster->info->id == 0x133) {
#endif
            intro->unknown_e_ = 2;
        } else if (monster->unknown_17d_ & 4) {
            intro->unknown_e_ = 1;
        }
        intro->state = 1;
    } else if (intro->state == 1) {
        if (IsMainBrightnessTransitionActive(res)) {
            return;
        }
        struct Vec3 pos = monster->position;
        struct PartyOrder020e3f1c* party = (struct PartyOrder020e3f1c*)GameState_GetParty(gs);
        for (int k = 0; k < party->count; k++) {
            struct Actor020e3f1c* member = (struct Actor020e3f1c*)gs->GetPartyMemberByIndex(party->order[k]);
            if (member != NULL) {
                if (GameObject_GetLinePosition(member) > 0) {
                    ((GameObject*)member)->obj3D_.SetInheritedAlpha(0);
                }
                member->position.x = pos.x;
                member->position.y = pos.y;
                member->position.z = pos.z + 0x3000;
                func_020338d4((struct Struct_020338d4*)member, &monster->position);
                GameObject_ResetTrail((unsigned char*)member);
            }
        }
        func_020338b0((unsigned char*)monster, (int)&leader->position);
        Camera_SetOrbitYaw((struct GlobalObj0202e6a8*)camera, 0);
        int dist = Camera_GetOrbitDistance(camera);
        struct Vec3 target = camera->target;
        if (intro->unknown_e_ == 1) {
            int dz = FxMul(dist, 0xddb);
            int dy = FxMul(dist, 0x599);
            Camera_SetPosition((struct Camera*)camera, target.x, target.y + dy, target.z + dz);
            func_0202ea4c((struct Struct_0202ea4c*)camera);
        } else if (intro->unknown_e_ == 2) {
            Camera_SetPosition((struct Camera*)camera, target.x, target.y + 0x2000, target.z + 0xd800);
            func_0202ea4c((struct Struct_0202ea4c*)camera);
        }
        Camera_Update(camera);
        TextQueue_Reset(TextQueue_GetInstance());
        func_02094b34(mgr, 0x74, 0x20e, 0, 0);
        func_ov017_021c3e18(0);
        intro->state = 2;
    } else if (intro->state == 2) {
        SetMainBrightness(res, 0, 0x3c);
        intro->state = 3;
    } else if (intro->state == 3) {
        if (IsMainBrightnessTransitionActive(res)) {
            return;
        }
        if (!func_02094b4c(mgr)) {
            return;
        }
#if defined(jpn)
        intro->taskId = loader->QueueLoadFile(data_020f2e3b, NULL);
#else
        char fileName[16];
        sprintf(fileName, data_020f2cd4, bossId);
        intro->taskId = loader->QueueLoadFileInGP2(data_020f2ce4, fileName, NULL);
#endif
        intro->state = 4;
    } else if (intro->state == 4) {
        if (!loader->GetTaskStatus(intro->taskId)) {
            return;
        }
        if (loader->GetDetailedTaskStatus(intro->taskId) != 2) {
            FieldTask_EndGrottoBossIntro(intro);
            return;
        }
        void* fileData;
        unsigned int size;
        loader->GetLoadedFileByID(intro->taskId, &fileData, &size);
        if (fileData == NULL) {
            FieldTask_EndGrottoBossIntro(intro);
            return;
        }
#if defined(jpn)
        char name[16];
        sprintf(name, data_020f2e4d, bossId);
        const void* ptr = NULL;
        unsigned int len = 0;
        if (!GetFileInNarc(fileData, name, &ptr, &len, 0)) {
            return;
        }
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x400);
        if (buf == NULL) {
            FieldTask_EndGrottoBossIntro(intro);
            return;
        }
        SafeAllocator alloc;
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0x400);
        struct Struct_020727d8 list;
        func_020727d8(&list);
        func_020728ac(&list, &alloc, (void*)ptr, len, 0, 0, 0);
        loader->RemoveTask(intro->taskId);
        intro->taskId = -1;
        void* entry = func_02072a68((struct TableA68*)&list, bossId);
#else
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x500);
        if (buf == NULL) {
            FieldTask_EndGrottoBossIntro(intro);
            return;
        }
        SafeAllocator alloc;
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0x500);
        struct Struct020dfc40 table;
        KeyTable_Construct(&table);
        KeyTable_Reset(&table);
        KeyTable_Load(&table, &alloc, fileData, size);
        loader->RemoveTask(intro->taskId);
        intro->taskId = -1;
        void* entry = (void*)KeyTable_Get((struct Container020e0310*)&table, bossId);
#endif
        if (entry == NULL) {
            alloc.Destroy();
            AllocatorUnion_Free(&g_mainAllocator, buf);
            FieldTask_EndGrottoBossIntro(intro);
            return;
        }
        display->visible = 1;
        display->active = 1;
        MessageSystem_SetStringArgument((struct Obj02046574*)display, 0, leader->name);
#if defined(jpn)
        func_0204500c(display, entry, 0);
#else
        func_0204500c(display, entry, 0, 0xe3);
#endif
        display->busy = 1;
        alloc.Destroy();
        AllocatorUnion_Free(&g_mainAllocator, buf);
        intro->state = 5;
    } else if (intro->state == 5) {
        display->active = 1;
        if (display->busy == 0) {
            display->active = 0;
            MessageSystem_Stop(display);
            FieldTask_EndGrottoBossIntro(intro);
        }
    }
}
