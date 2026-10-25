#include <globaldefs.h>
#include "Resource/TextQueue.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/LootableContainer.h"
#include "Resource/GameResources.h"
#include "World/FieldTask.h"



struct State0207dfc8 { unsigned int words[28]; };
struct StoreStruct;
struct Struct0218d618;
struct SePlayer;
struct ItemTable;
struct LootEventInfo { char pad0[0x30]; unsigned short containerId; };
struct LootEvent {
    char pad0[8]; unsigned short timer; short fieldA;
    LootEventInfo* info; Foo02048004* display; short taskId;
    char pad16[0x28 - 0x16]; Vector3fix position; SafeAllocator allocator;
    unsigned char special;
};
#if defined(jpn)
struct Struct_ov017_021bf9a0_3 { char unknown_0_[0x2794]; char unknown_2754_[4]; };
#else
struct Struct_ov017_021bf9a0_3 { char unknown_0_[0x2754]; char unknown_2754_[4]; };
#endif
StoreStruct* MessageSystem_GetInstance();
extern "C" PersistentLootState* Zone3D_GetInstance();
extern "C" unsigned char* Scenario_GetInstance();
int GameResources_IsSpecialItemEffectLoaded(Struct0218d618*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void SprSprite_Unload(Foo02048004*);
void VramState_CopyCurrentTo(State0207dfc8*, State0207dfc8*);
void VramState_Restore(char*);
void VramState_Save(char*);
void SprSprite_LoadFile(void*, int, int, int);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_ov017_021cdb00(int, int, int, int);
extern "C" void __clear(void*, int);
void* ItemTable_Construct(void*);
void InitStruct0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
void* TextQueue_GetInstance();
extern "C" void GameResources_PlaySpecialItemEffect(GameResources*, Vector3fix*, int);
void SePlayer_Play(SePlayer*, int, int);
extern AllocatorUnion g_mainAllocator;
extern SePlayer g_sePlayer;

static inline char& GetResourceStateBuffer(GameResources* resources, int offset) {
    return resources->vramStates_[offset];
}

// USA: func_ov017_021bf9a0
extern "C" ARM int func_ov017_021bf9a0(LootEvent* self) {
    unsigned int delta = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (delta < self->timer) { self->timer -= delta; return 3; }
    self->timer = 0;
    MessageSystem_GetInstance();
    LootEventInfo* info = self->info;
    Zone3D_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    unsigned char* flags = Scenario_GetInstance();
    if (!manager || !flags) return 3;
    if (self->special) {
        if (!GameResources_IsSpecialItemEffectLoaded((Struct0218d618*)GetGameResources())) return 5;
    } else if (self->taskId >= 0) {
        if (loader->GetTaskStatus(self->taskId)) {
            void* file = 0;
            unsigned int length = 0;
            loader->GetLoadedFileByID(self->taskId, &file, &length);
            void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 256);
            if (file && buffer) {
                self->allocator.CreateTypeA(buffer, 256);
                SprSprite_Unload(self->display);
                SprSprite_Init(self->display);
                State0207dfc8 saved;
                VramState_CopyCurrentTo((State0207dfc8*)&GetResourceStateBuffer(GetGameResources(), 0x230), &saved);
                VramState_Restore((char*)&saved);
                SprSprite_LoadFile(self->display, (int)file, length, (int)&self->allocator);
                VramState_Save((char*)&saved);
            }
            var2->RemoveTask(arg0->unknown_14_);
            arg0->unknown_14_ = -1;
        } else return 3;
    }
    self->timer = 300;
    unsigned short listPosition = 0;
    LootableContainerManager::Container* container = manager->GetContainerByID(info->containerId, &listPosition);
    if (container) {
        int id = container->uniqueID;
        int flagIndex = id + 0x79e;
        if (!Scenario_TestFlag((int)flags, flags + 0x8c, flagIndex)) {
            Scenario_SetFlag(flags, flags + 0x8c, flagIndex, 1);
            func_ov017_021cdb00(8, id, 1, -1);
            char text[128] = {};
            PersistentLootState* state = Zone3D_GetInstance();
            LootTextContext context;
            context.allocator.ResetAllocatorPointer();
            ItemTable_Construct(context.itemTable);
            InitStruct0207cbe8((char*)&context);
            InitStruct0207cbe8((char*)&context);
            context.containerItems = (ItemTable*)state->containerData;
            if (func_0207d538(&context, container->lootType, container->itemIDOrRank, text, 1)) {
#if defined(jpn)
                TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1);
#else
                TextQueue_Push(TextQueue_GetInstance(), text, 0, 0, 1, 0);
#endif
                GameResources* resources = GetGameResources();
                if (self->special) GameResources_PlaySpecialItemEffect(resources, &self->position, 0);
                else SePlayer_Play(&g_sePlayer, 14, 0);
                return 4;
            }
        }
    }
    return 5;
}
