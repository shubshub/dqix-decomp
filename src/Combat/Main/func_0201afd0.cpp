#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneFeatures.h"
#include "World/ZoneChest.h"
#include "World/LootableContainer.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_0201afd0 {
    unsigned short uniqueID;
    unsigned short itemIDOrRank;
    unsigned short lock : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
    short angleOrCupboardNode;
    Vector3i position;
};

struct ChestLootList0201afd0;

struct Struct_0201afd0_3 {
    unsigned char bits;
};

struct Struct_020e6df0 {
    char name[11];
};

struct Struct_020105a8;
struct Struct_0201afd0_4;
struct Struct_0201e690;
struct ClearThreeWords02094d00Struct;
struct Struct_0201afd0_5;
struct Struct_02011430;
struct Struct_0201afd0_6;
struct Struct_0201afd0_7;
extern "C" void* LinkSession_GetInstance();
extern "C" void func_020105a8(Struct_020105a8*, int*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
extern "C" Struct_0201e690* func_0201e690(Struct_0201afd0_4*, int);
extern "C" void GrottoChestList_Clear(ClearThreeWords02094d00Struct*);
extern "C" void func_02094cdc(Struct_0201afd0_5*, int, SafeAllocator*);
extern "C" int func_02011430(Struct_02011430*, int, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" void func_02094d14(Struct_0201afd0_6*, Struct_0201afd0_7*, int);
extern "C" void ItemTable_Init(void*);
extern "C" int ItemTable_LoadIds(void*, SafeAllocator*, void*, unsigned int, unsigned short*, unsigned short);
extern "C" void __clear(void*, int);

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, unsigned short*, unsigned short, bool);
#define data_020e6df0 data_020e7694
#endif

extern const unsigned char data_020e6e44[15];
extern const Struct_020e6df0 data_020e6df0;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

static inline GrottoTilePoint inline_0201afd0(const FloorMap* map, unsigned char index) {
    return map->chests[index];
}

static inline int inline_0201afd0_2(int a) {
    return (int)(((long long)a * a + 0x800) >> 12);
}

static inline Struct_0201afd0_3 inline_0201afd0_3(const FloorMap* map, int x, int y) {
    Struct_0201afd0_3 result;
    result.bits = map->GetAdjacencyBits(x, y);
    return result;
}

static inline int inline_0201afd0_4(const ActiveGrottoClass* grotto, int floor) {
    unsigned short seed = grotto->GetActiveGrottoSeed();
    return seed + floor;
}

// USA: func_0201afd0
extern "C" ARM int func_0201afd0(Zone3D* zone, const void* arg1, unsigned int arg2, int unused) {
    ZoneFeatures* features = &zone->substruct_6c_;
    GameState* gs = GameState::GetInstance();
    ActiveGrottoClass* grotto = &zone->grotto_;
    int i;
    FloorMap* map = &grotto->floorMap_;
    void* search = LinkSession_GetInstance();
    ChestLootList0201afd0* lootList = (ChestLootList0201afd0*)(zone->grottoChestList_);

    zone->numChests_ = map->chestCount;
    if (zone->numChests_ == 0) {
        int elapsed;

        func_020105a8((Struct_020105a8*)(gs), &elapsed);
        srand(elapsed + inline_0201afd0_4(grotto, zone->currentGrottoFloor_23ba_));
        return 0;
    }

    zone->chests_ = (ZoneChestRenderRecord*)zone->pAllocator_68_->Allocate(zone->numChests_ * sizeof(ZoneChestRenderRecord));
    features->AllocateOpcode6aEntries(zone->numChests_, zone->pAllocator_68_);
    srand(inline_0201afd0_4(grotto, zone->currentGrottoFloor_23ba_));

    for (i = 0; i < zone->numChests_; i++) {
        ZoneFeatures::Opcode6aEntry entry;
        GrottoTilePoint tile;
        Struct_0201afd0_3 var10;
        int dir;
        int found;

        VectorizedMemset(&entry, 0, sizeof(entry));
        entry.angle = 0;
        entry.unk_22 = 0;
        entry.unk_24 = 0;
        entry.unk_8.vec.x = 0;
        entry.unk_8.vec.y = 0;
        entry.unk_8.vec.z = 0;
        entry.unk_28 = 0;
        entry.pNext = NULL;

        entry.unk_0 = i;
        entry.unk_14.vec.z = 0x1000;
        entry.unk_14.vec.y = 0x1000;
        entry.unk_14.vec.x = 0x1000;
        entry.maybeType = 1;

        tile = inline_0201afd0(map, i);
        dir = GenerateGrottoObjectPositionOrientation(
            zone, (unsigned char)(tile.x), (unsigned char)(tile.y), &entry.unk_8.vec.x, &entry.unk_8.vec.z, NULL, false);
        var10 = inline_0201afd0_3(map, (unsigned char)(tile.x), (unsigned char)(tile.y));
        found = 0;
        if (grotto->GetActiveGrottoEnviron() == 2) {
            for (int j = 0; j < 15; j++) {
                if (var10.bits == data_020e6e44[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                entry.unk_8.vec.y = -0x4cc;
            }
        }

        switch (dir) {
        case 0:
            entry.angle = entry.unk_22 = 0x3244;
            break;
        case 1:
            entry.angle = entry.unk_22 = 0x1922;
            break;
        case 2:
            entry.angle = entry.unk_22 = 0;
            break;
        case 3:
            entry.angle = entry.unk_22 = 0x4b66;
            break;
        }

        {
            fix32_t halfX = entry.unk_14.vec.x / 2;
            fix32_t halfZ = entry.unk_14.vec.z / 2;
            fix32_t var16 = inline_0201afd0_2(halfZ);
            fix32_t var17 = inline_0201afd0_2(halfX);

            entry.unk_24 = var17 + var16;
        }
        entry.pNext = NULL;
        features->CreateOpcode6aEntry(entry);
    }

    {
        SafeAllocator alloc;
        char buffer[0x400];
        LootDistribution distribution;
        Struct_020e6df0 name;
        const void* script;
        unsigned int var23;
        int var24[32];
        unsigned short itemIDs[100];
        int elapsed;
        int itemCount;
        int chest;
        int index;

        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buffer, sizeof(buffer));
        name = data_020e6df0;
        if (GetFileInNarcPermissive(arg1, name.name, &script, &var23)) {
            distribution.Reset();
            distribution.LoadFromScript(&alloc, script, var23);
        }

        GrottoChestList_Clear((ClearThreeWords02094d00Struct*)(lootList));
        func_02094cdc((Struct_0201afd0_5*)(lootList), zone->numChests_, zone->pAllocator_68_);
        memset(var24, 1, sizeof(var24));
        for (chest = 0; chest < zone->numChests_; chest++) {
            var24[chest] = grotto->RandomizeChestRank(zone->currentGrottoFloor_23ba_);
        }

        func_020105a8((Struct_020105a8*)(gs), &elapsed);
        srand(elapsed + inline_0201afd0_4(grotto, zone->currentGrottoFloor_23ba_));

        __clear(itemIDs, sizeof(itemIDs));
        itemCount = 0;
        for (index = 0; index < zone->numChests_; index++) {
            ZoneFeatures::Opcode6aEntry* entry = (ZoneFeatures::Opcode6aEntry*)(func_0201e690((Struct_0201afd0_4*)(features), index));
            const LootDistribution::Outcome* outcome = distribution.Sample(var24[index]);

            if (outcome != NULL) {
                ZoneChestRenderRecord* record = &zone->chests_[index];
                Struct_0201afd0 loot;

                ZoneChest_Init(record);
                record->position = entry->unk_8.vec;
                record->angleY = entry->angle;
                record->counter = 0;
                record->recordIndex = index;
                record->uniqueID = index;
                record->kind = ZoneChestKind_Grotto;
                if (func_02011430((Struct_02011430*)(gs), zone->currentGrottoFloor_23ba_, index)) {
                    record->state = ZoneChestState_Open;
                    record->lidAngle = ZoneChestLid_Open;
                } else {
                    record->state = ZoneChestState_Closed;
                    record->lidAngle = ZoneChestLid_Closed;
                }
                if (LinkSession_IsActive((int*)(search))) {
                    record->special = 1;
                }
                if (outcome->lootType == 2) {
                    itemIDs[itemCount++] = outcome->itemID;
                }

                loot.uniqueID = 0;
                loot.itemIDOrRank = outcome->itemID;
                loot.lock = 0;
                loot.lootType = outcome->lootType;
                loot.containerType = 4;
                loot.position = entry->unk_8.vec;
                func_02094d14((Struct_0201afd0_6*)(lootList), (Struct_0201afd0_7*)(&loot), record->uniqueID);
            }
        }

        ItemTable_Init(zone->containerItems_);
        if (itemCount > 0) {
#if defined(jpn)
            func_020e0484(zone->containerItems_, zone->pAllocator_68_, g_itemDataArchive, itemIDs, itemCount, true);
#else
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            void* data = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &size);

            if (data != NULL) {
                ItemTable_LoadIds(zone->containerItems_, zone->pAllocator_68_, data, size, itemIDs, itemCount);
            }
            BackgroundLoader::RemoveLockGlobal();
#endif
        }
        alloc.Reset();
        alloc.Destroy();
    }
    return 1;
}
