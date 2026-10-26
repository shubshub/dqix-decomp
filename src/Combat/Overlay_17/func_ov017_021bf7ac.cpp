#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/LootableContainer.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"


struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int field10High : 8;
    unsigned int unknown_13_4_ : 4;
    short e, f, g, h, i;
};

struct Base02019508;
struct ItemTable;
struct Foo02048004;

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_0201ba1c(struct Base02019508* base, int key1, int key2);
extern "C" void func_ov017_021cfe40(unsigned short a, unsigned short b, unsigned short c);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void SprSprite_Unload(struct Foo02048004* obj);
extern "C" StructDE234_020de234* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void GameResources_LoadSpecialItemEffect(int a, void* b);
extern "C" unsigned short ItemRecord_GetFileNumber(struct StructDE234_020de234* p, int preferMid);

struct Struct_ov017_021d6ca4 {
    char path[0x20];
};

extern AllocatorUnion g_mainAllocator;
extern const Struct_ov017_021d6ca4 data_ov017_021d6ca4;
extern const char data_ov017_021d7ee8[];

struct Struct_ov017_021bf7ac {
    char pad0[0x2c];
    unsigned short key1;
    unsigned short key2;
    unsigned short containerId;
};

struct Struct_ov017_021bf7ac_2 {
    char pad0[8];
    short timer;
    char padA[2];
    struct Struct_ov017_021bf7ac* info;
    struct Foo02048004* entry;
    short taskId;
    char pad16[0x48 - 0x16];
    unsigned char field48;
    char unknown_49_[3];
    SafeAllocator allocator;
};

// USA: func_ov017_021bf7ac
extern "C" ARM int func_ov017_021bf7ac(struct Struct_ov017_021bf7ac_2* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x394, regionalOffset1=0x620};
#else
 enum {regionalOffset0=0x354, regionalOffset1=0x600};
#endif
    GameState* gs = GameState::GetInstance();
    gs->GetLeader();
    unsigned short* events = (unsigned short*)Zone3D_GetInstance();
    struct Struct_ov017_021bf7ac* info = obj->info;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short key1 = info->key1;
    unsigned short key2 = info->key2;
    func_0201ba1c((struct Base02019508*)events, key1, key2);
    func_ov017_021cfe40(*events, key1, key2);

    LootableContainerManager* mgr = LootableContainerManager::GetMainInstance();
    unsigned char* flags = Scenario_GetInstance();
    if (mgr == 0 || flags == 0) {
        return 3;
    }

    unsigned short listPos = 0;
    LootableContainerManager::Container* container = mgr->GetContainerByID(info->containerId, &listPos);
    if (container != 0 && !Scenario_TestFlag((int)flags, flags + 0x8c, container->uniqueID + 0x79e)) {
        char* base = (char*)Zone3D_GetInstance();
        char* sub = base + regionalOffset0;
        obj->entry = (struct Foo02048004*)(base + regionalOffset1 + GameState_GetProtagonistIndex(gs) * 0x88);
        SprSprite_Unload(obj->entry);
        if (container->lootType == 1) {
            Struct_ov017_021d6ca4 name = data_ov017_021d6ca4;
            obj->taskId = loader->QueueLoadFile(name.path, 0);
        } else {
            StructDE234_020de234* elem = ItemTable_Find((struct ItemTable*)(sub + 0x2400), (short)container->itemIDOrRank);
            if (elem != 0) {
                if (elem->g == 0x5617) {
                    obj->field48 = 1;
                    obj->allocator.ResetAllocatorPointer();
                    obj->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x4000), 0x4000);
                    obj->allocator.Reset();
                    GameResources_LoadSpecialItemEffect((int)GetGameResources(), &obj->allocator);
                } else {
                    char path[0x80];
                    sprintf(path, data_ov017_021d7ee8, (signed char)elem->field10High, ItemRecord_GetFileNumber(elem, 0));
                    obj->taskId = loader->QueueLoadFile(path, 0);
                }
            }
        }
    }
    obj->timer = 0x12c;
    return 3;
}
