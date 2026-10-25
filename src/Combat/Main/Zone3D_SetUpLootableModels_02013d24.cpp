#include <globaldefs.h>

#include "World/Zone3D.h"
#include "World/LootableContainer.h"
#include "Resource/GameResources.h"

#if defined(usa)
#endif

// Main, originally func_02013d24 (USA 0x02013d24, EUR 0x02013d34, JPN 0x02013af0)
extern "C" ARM void Zone3D_SetUpLootableModels(Zone3D* zone)
{
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    for (int i = 0; i < (unsigned char)zone->numLootables_; ++i)
    {
        ZoneLootableRecord* record = &zone->lootables_[i];
        LootableContainerManager::Container* container =
            manager->GetContainerByID(record->id, NULL);
        if (container == NULL)
            continue;

        int type = container->containerType;
        if (type == LootableContainerType_Pot)
        {
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[0], &record->primary[0]);
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[1], &record->primary[1]);
            Foo02048004* fragments = record->fragments;
            for (int j = 0; j < 4; ++j)
                CopyFieldsWithFlags02048004(zone->lootableTemplates_[2], fragments + j);
        }
        else if (type == LootableContainerType_Barrel)
        {
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[3], &record->primary[0]);
            CopyFieldsWithFlags02048004(zone->lootableTemplates_[4], &record->primary[1]);
            Foo02048004* fragments = record->fragments;
            for (int j = 0; j < 4; ++j)
                CopyFieldsWithFlags02048004(zone->lootableTemplates_[5], fragments + j);
        }
    }
}
