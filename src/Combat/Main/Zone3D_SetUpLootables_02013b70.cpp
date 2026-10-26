#include <globaldefs.h>

#include "World/Zone3D.h"
#include "World/LootableContainer.h"
#include "Graphics/LightingManager.h"

extern "C" void ZoneLootable_Init(ZoneLootableRecord* base);
extern "C" void Zone3D_SetUpLootableModels(Zone3D* zone);

// The scale on each axis a pot's or barrel's first sprite gets (1.0 is 0x1000)
enum { kLootableScale = 0x80 };

// Main, originally func_02013b70 (USA 0x02013b70, EUR 0x02013b80, JPN 0x0201393c)
extern "C" ARM void Zone3D_SetUpLootables(Zone3D* zone, SafeAllocator* allocator)
{
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    const unsigned short diffuseColor = LightingManager::GetInstance()->maybePotBarrelDiffuseColor_;
    LootableContainerManager::Container* container = manager->pContainerList_;
    unsigned int count = 0;

    for (; container != NULL; container = container->pNext)
    {
        if (container->containerType == LootableContainerType_Pot || container->containerType == LootableContainerType_Barrel)
            count++;
    }

    zone->lootables_ = static_cast<ZoneLootableRecord*>(
        allocator->Allocate(count * sizeof(ZoneLootableRecord)));
    if (zone->lootables_ == NULL)
        return;

    for (container = manager->pContainerList_; container != NULL; container = container->pNext)
    {
        if (container->containerType != LootableContainerType_Pot && container->containerType != LootableContainerType_Barrel)
            continue;

        ZoneLootableRecord* record = &zone->lootables_[(unsigned char)zone->numLootables_];

        ZoneLootable_Init(record);
        SprSprite_Init(&record->primary[0]);
        record->primary[0].color = diffuseColor;
        SprSprite_Init(&record->primary[1]);
        record->primary[1].color = diffuseColor;

        for (int i = 0; i < 4; ++i)
        {
            SprSprite_Init(&record->fragments[i]);
            record->fragments[i].color = diffuseColor;
        }

        Vector3fix* position = &record->primary[0].position;
        *position = container->position;

        record->primary[0].scale.x = kLootableScale;
        record->primary[0].scale.y = kLootableScale;
        record->primary[0].scale.z = kLootableScale;
        record->id = container->uniqueID;
        record->state = ZoneLootableState_Searchable;
        zone->numLootables_ = (char)((unsigned char)zone->numLootables_ + 1);
    }

    Zone3D_SetUpLootableModels(zone);
}
