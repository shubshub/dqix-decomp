#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/LootableContainer.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"


struct Struct_02015ef4_4 {
    int unknown_0_, unknown_4_, unknown_8_, unknown_c_;
    unsigned int unknown_10_0_ : 10;
    unsigned int unknown_11_2_ : 10;
    unsigned int unknown_12_4_ : 8;
    unsigned int unknown_13_4_ : 4;
    short unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_;
};

struct Base02019508;
struct ItemTable;
struct Foo02048004;

extern "C" void* Zone3D_GetInstance(void);
void ClearAndFlagEntry0201ba1c(struct Base02019508* base, int key1, int key2);
void EnqueueEventTag166_021cfe40(unsigned short a, unsigned short b, unsigned short c);
extern "C" unsigned char* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
int GameState_GetProtagonistIndex(GameState* battleStruct);
void SprSprite_Unload(struct Foo02048004* obj);
StructDE234_020de234* ItemTable_Find(struct ItemTable* c, int key);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void GameResources_LoadSpecialItemEffect(int a, void* b);
unsigned short ItemRecord_GetFileNumber(struct StructDE234_020de234* p, int preferMid);

struct Struct_ov017_021d6ca4 {
    char unknown_0_[0x20];
};

extern AllocatorUnion g_mainAllocator;
extern const FileName_021bf7ac data_ov017_021d6ca4;
extern const char data_ov017_021d7ee8[];

struct Struct_ov017_021bf7ac {
    char unknown_0_[0x2c];
    unsigned short unknown_2c_;
    unsigned short unknown_2e_;
    unsigned short unknown_30_;
};

struct Struct_ov017_021bf7ac_2 {
    char unknown_0_[8];
    short unknown_8_;
    char unknown_a_[2];
    struct Struct_ov017_021bf7ac* unknown_c_;
    struct Struct_02012fa4* unknown_10_;
    short unknown_14_;
    char unknown_16_[0x48 - 0x16];
    unsigned char unknown_48_;
    char unknown_49_[3];
    SafeAllocator unknown_4c_;
};

// USA: func_ov017_021bf7ac
extern "C" ARM int func_ov017_021bf7ac(struct Struct_ov017_021bf7ac_2* arg0) {
#if defined(jpn)
 enum {Enum_ov017_021bf7ac_852=0x394, Enum_ov017_021bf7ac_1536=0x620};
#else
 enum {Enum_ov017_021bf7ac_852=0x354, Enum_ov017_021bf7ac_1536=0x600};
#endif
    GameState* gs = GameState::GetInstance();
    gs->GetLeader();
    unsigned short* events = (unsigned short*)Zone3D_GetInstance();
    struct Info_021bf7ac* info = obj->info;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short key1 = info->key1;
    unsigned short key2 = info->key2;
    ClearAndFlagEntry0201ba1c((struct Base02019508*)events, key1, key2);
    EnqueueEventTag166_021cfe40(*events, key1, key2);

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
            FileName_021bf7ac name = data_ov017_021d6ca4;
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
    arg0->unknown_8_ = 0x12c;
    return 3;
}
