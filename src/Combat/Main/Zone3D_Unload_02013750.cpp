#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Graphics/AtmosphericEffect.h"
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"
#include "World/Zone3D.h"

void ItemTable_Init(void* obj);
void Zone3D_ResetLootIcons(char* base);

// The SafeAllocator at Zone3D +0x2730 (jpn +0x2770), inside the header's unk_2730; Zone3D_Reset resets its pointer
struct AllocAt0x2730_02013750 {
    char pad[(IS_JPN ? 0x770 : 0x730) + 0x2000];
    SafeAllocator alloc;
};

#pragma optimize_for_size off

// Main, originally ResetBigStruct02013750 (USA 0x02013750, EUR 0x02013760, JPN 0x02013518)
ARM void Zone3D_Unload(void* obj, int destroyAllocators) {
    Zone3D* zone = (Zone3D*)obj;
    zone->textureImageMemory_ = 0;
    zone->texturePaletteMemory_ = 0;
    zone->unknown_424_ = 0;
    zone->firstBMDJStruct_41c_ = 0;
    zone->firstModel_418_ = 0;
    zone->numLootables_ = 0;
    zone->numChests_ = 0;
    zone->terrainElementCount_ = 0;
    zone->unknown_474_ = 0;
    zone->terrainElementCount_ = 0;
    zone->unknown_42c_ = 0;
    zone->mapListLoadHandle_ = -1;
    zone->unknown_434_ = -1;
    zone->mapAMBLLoadHandle_ = -1;
    zone->mapAMDJLoadHandle_ = -1;
    zone->atsAMBLLoadHandle_ = -1;
    zone->lootables_ = 0;
    zone->chests_ = 0;
    zone->unk_23bc[0] = 0;
    zone->unk_23bc[1] = 0;
    zone->unknown_834_ = 0;
    zone->substruct_6c_.Reset();
    ItemTable_Init(zone->containerItems_);
    zone->atmosphericEffects_.Reset();
    Zone3D_ResetLootIcons((char*)zone->lootIcons_);
    if (!destroyAllocators) {
        return;
    }
    AllocAt0x2730_02013750* b = (AllocAt0x2730_02013750*)obj;
    if (b->alloc.GetSignedAllocator() != NULL) {
        b->alloc.Destroy();
        b->alloc.ResetAllocatorPointer();
    }
    if (zone->internalAllocator_.GetSignedAllocator() == NULL) {
        return;
    }
    zone->internalAllocator_.Destroy();
    zone->internalAllocator_.ResetAllocatorPointer();
}
