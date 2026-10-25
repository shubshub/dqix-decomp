#include <globaldefs.h>
#include <World/LootableContainer.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <World/ZoneChest.h>


// One loot point of func_0208e0a8's list (the layout func_ov017_021986fc picks them up with).
struct LootPoint0201647c {
    unsigned int itemId : 16;       // what it gives (func_ov017_021986fc hands it to the pickup task)
    unsigned int pointId : 7;       // func_ov017_021986fc: EnqueueEventTag183_021d38f8's pointId, progress flag + 0xc12
    unsigned int unknown2_7 : 9;
    unsigned int kind : 4;
    unsigned int flags : 28;
    void* state;                    // its LootPointState
    Vector3fix positions[8];        // where it can be picked up (func_ov017_021986fc)
    LootPoint0201647c* next;
};
// func_0208e0a8's list (LootPointList_AppliesToMap).
struct LootPointList0201647c {
    char pad0[4];
    LootPoint0201647c* nodes;
    char pad8[4];
    short* itemIds;                 // read instead of the nodes when the first node's kind is 9 (16 of them)
};
extern "C" void* Scenario_GetInstance();
extern "C" int* func_0202ae18();
extern "C" void* func_0208e0a8();
int LootPointList_AppliesToMap(void*, char*);
int Scenario_TestFlag(int, unsigned char*, int);
int CheckField0NonZero_0202b7d8(int*);
void ItemTable_Init(void*);
extern "C" int ItemTable_LoadIds(void*, SafeAllocator*, void*, unsigned int, short*, unsigned short);
extern "C" void Zone3D_SetUpLootables(Zone3D*, SafeAllocator*);
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, short*, unsigned short, bool);
#endif

// Main, originally func_0201647c (USA 0x0201647c, EUR 0x0201648c, JPN 0x02016248)
extern "C" ARM void Zone3D_SetUpContainers(Zone3D* zone) {
    SafeAllocator* allocator = zone->pAllocator_68_;
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    unsigned char* progress = (unsigned char*)Scenario_GetInstance();
    int* flags = func_0202ae18();
    LootPointList0201647c* lootPoints = (LootPointList0201647c*)func_0208e0a8();
    LootableContainerManager::Container* container = containers->pContainerList_;
    bool lootPointsApply = false;
    if (LootPointList_AppliesToMap(lootPoints, zone->pUnknownStruct_8_->mapShortName_)) lootPointsApply = true;
    int containerCount = 0;
    for (; container; container = container->pNext) {
        if (container->containerType == LootableContainerType_RedChest || container->containerType == LootableContainerType_BlueChest) containerCount++;
    }
    zone->chests_ = (ZoneChestRenderRecord*)allocator->Allocate(containerCount * sizeof(ZoneChestRenderRecord));
    if (!zone->chests_) return;
    container = containers->pContainerList_;
    zone->numChests_ = 0;
    for (; container; container = container->pNext) {
        if (container->containerType == LootableContainerType_RedChest || container->containerType == LootableContainerType_BlueChest) {
            ZoneChestRenderRecord* chest = &zone->chests_[zone->numChests_];
            ZoneChest_Init(chest);
            chest->position = container->position;
            chest->angleY = container->angleOrCupboardNode;
            chest->counter = 0;
            chest->recordIndex = zone->numChests_;
            chest->uniqueID = container->uniqueID;
            chest->kind = ZoneChestKind_Red;
            if (container->containerType == LootableContainerType_BlueChest) chest->kind = ZoneChestKind_Blue;
            if ((container->containerType == LootableContainerType_RedChest &&
                 Scenario_TestFlag((int)progress, progress + 0x8c, container->uniqueID + 0x212)) ||
                (container->containerType == LootableContainerType_BlueChest &&
                 Scenario_TestFlag((int)progress, progress + 0x8c, container->uniqueID + 0x79e))) {
                chest->state = ZoneChestState_Open;
                chest->lidAngle = ZoneChestLid_Open;
                container->lootType = LootType_Nothing;
            } else {
                chest->state = ZoneChestState_Closed;
                chest->lidAngle = ZoneChestLid_Closed;
            }
            if (CheckField0NonZero_0202b7d8(flags) && container->containerType == LootableContainerType_BlueChest)
                chest->special = 1;
            zone->numChests_++;
        } else if (container->containerType == LootableContainerType_Cupboard) {
            ZoneFeatures::Opcode6aEntry* node = ZoneFeatures_FindEntry(&zone->substruct_6c_, 5, (unsigned short)container->angleOrCupboardNode);
            if (node) node->unk_2c.type5.cupboardContainerId = container->uniqueID;
        }
    }
    short itemIds[100];
    int itemCount = 0;
    for (container = containers->pContainerList_; container; container = container->pNext) {
        if (container->lootType == LootType_Item) {
            unsigned int itemId = container->itemIDOrRank;
            bool unique = true;
            for (int i = 0; i < itemCount; i++) {
                if (itemId == itemIds[i]) {
                    unique = false;
                    break;
                }
            }
            if (unique) itemIds[itemCount++] = itemId;
        }
    }
    if (lootPointsApply && lootPoints->nodes) {
        LootPoint0201647c* node = lootPoints->nodes;
        if (node->kind == 9) {
            short* source = lootPoints->itemIds;
            if (source) {
                for (int i = 0; i < 16; itemCount++, source++, i++) itemIds[itemCount] = *source;
            }
        } else {
            while (node) {
                itemIds[itemCount++] = node->itemId;
                node = node->next;
            }
        }
    }
    ItemTable_Init(zone->containerItems_);
    if (itemCount > 0) {
#if defined(jpn)
        func_020e0484(zone->containerItems_, allocator, g_itemDataArchive, itemIds,
            (unsigned short)itemCount, true);
#else
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        void* file = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);
        if (file) ItemTable_LoadIds(zone->containerItems_, allocator, file, size, itemIds, (unsigned short)itemCount);
        BackgroundLoader::RemoveLockGlobal();
#endif
    }
    Zone3D_SetUpLootables(zone, zone->pAllocator_68_);
    if (zone->pendingLootableMask_) {
        Zone3D_SetSearchedLootables(zone, zone->pendingLootableMask_);
        zone->pendingLootableMask_ = 0;
    }
    if (zone->pendingType2Mask_) {
        Zone3D_OpenDoorsByMask(zone, zone->pendingType2Mask_);
        zone->pendingType2Mask_ = 0;
    }
}
