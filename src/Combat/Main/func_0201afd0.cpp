#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneFeatures.h"
#include "World/ZoneChest.h"
#include "World/LootableContainer.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct ChestLoot0201afd0 {
    unsigned short uniqueID;
    unsigned short itemIDOrRank;
    unsigned short lock : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
    short angleOrCupboardNode;
    Vector3i position;
};

struct Struct_0201afd0_2;

struct Struct_0201afd0_3 {
    unsigned char unknown_0_;
};

struct Struct_020e6df0 {
    char unknown_0_[11];
};

struct TimeStamp020105a8;
struct EntryList_1e690;
struct Entry_1e690;
struct ClearThreeWords02094d00Struct;
struct AllocDest02094cdc;
struct S_02011430;
struct Container02094d14;
struct Elem02094d14;
extern "C" void* LinkSession_GetInstance();
void ComputeElapsedTime020105a8(TimeStamp020105a8*, int*);
int GenerateGrottoObjectPositionOrientation(void*, int, int, int*, int*, const TileFeaturePlacementData*, bool);
Entry_1e690* FindEntryById_0201e690(EntryList_1e690*, int);
void GrottoChestList_Clear(ClearThreeWords02094d00Struct*);
void AllocateArray02094cdc(AllocDest02094cdc*, int, SafeAllocator*);
int GetBit5cd0(S_02011430*, int, int);
int LinkSession_IsActive(int*);
void CopyElemToIndex(Container02094d14*, Elem02094d14*, int);
void ItemTable_Init(void*);
extern "C" int ItemTable_LoadIds(void*, SafeAllocator*, void*, unsigned int, unsigned short*, unsigned short);
extern "C" void __clear(void*, int);

#if defined(jpn)
extern "C" int func_020e0484(void*, SafeAllocator*, const char*, unsigned short*, unsigned short, bool);
#define data_020e6df0 data_020e7694
#endif

extern const unsigned char data_020e6e44[15];
extern const NarcName0201afd0 data_020e6df0;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;

static inline GrottoTilePoint inline_0201afd0(const FloorMap* arg0, unsigned char arg1) {
    return arg0->chests[arg1];
}

static inline int inline_0201afd0_2(int arg0) {
    return (int)(((long long)arg0 * arg0 + 0x800) >> 12);
}

static inline Struct_0201afd0_3 inline_0201afd0_3(const FloorMap* arg0, int arg1, int arg2) {
    Struct_0201afd0_3 var0;
    var0.unknown_0_ = arg0->GetAdjacencyBits(arg1, arg2);
    return var0;
}

static inline int inline_0201afd0_4(const ActiveGrottoClass* arg0, int arg1) {
    unsigned short var0 = arg0->GetActiveGrottoSeed();
    return var0 + arg1;
}

// USA: func_0201afd0
extern "C" ARM int func_0201afd0(Zone3D* zone, const void* treasureArchive, unsigned int sourceSize, int unused) {
    ZoneFeatures* features = &zone->substruct_6c_;
    GameState* gs = GameState::GetInstance();
    ActiveGrottoClass* grotto = &zone->grotto_;
    int i;
    FloorMap* map = &grotto->floorMap_;
    void* search = LinkSession_GetInstance();
    ChestLootList0201afd0* lootList = (ChestLootList0201afd0*)(zone->grottoChestList_);

    arg0->numChests_ = var4->chestCount;
    if (arg0->numChests_ == 0) {
        int var7;

        func_020105a8((Struct_020105a8*)(var1), &var7);
        srand(var7 + inline_0201afd0_4(var2, arg0->currentGrottoFloor_23ba_));
        return 0;
    }

    zone->chests_ = (ZoneChestRenderRecord*)zone->pAllocator_68_->Allocate(zone->numChests_ * sizeof(ZoneChestRenderRecord));
    features->AllocateOpcode6aEntries(zone->numChests_, zone->pAllocator_68_);
    srand(GetFloorSeed0201afd0(grotto, zone->currentGrottoFloor_23ba_));

    for (var3 = 0; var3 < arg0->numChests_; var3++) {
        Struct_020134e0::Struct_02018300 var8;
        GrottoTilePoint var9;
        Struct_0201afd0_3 var10;
        int var11;
        int var12;

        VectorizedMemset(&entry, 0, sizeof(entry));
        entry.angle = 0;
        entry.unk_22 = 0;
        entry.unk_24 = 0;
        entry.unk_8.vec.x = 0;
        entry.unk_8.vec.y = 0;
        entry.unk_8.vec.z = 0;
        entry.unk_28 = 0;
        entry.pNext = NULL;

        var8.unknown_0_ = var3;
        var8.unknown_14_.unknown1_0_.z = 0x1000;
        var8.unknown_14_.unknown1_0_.y = 0x1000;
        var8.unknown_14_.unknown1_0_.x = 0x1000;
        var8.unknown_4_ = 1;

        var9 = inline_0201afd0(var4, var3);
        var11 = GenerateGrottoObjectPositionOrientation(
            arg0, (unsigned char)(var9.x), (unsigned char)(var9.y), &var8.unknown_8_.unknown1_0_.x, &var8.unknown_8_.unknown1_0_.z, NULL, false);
        var10 = inline_0201afd0_3(var4, (unsigned char)(var9.x), (unsigned char)(var9.y));
        var12 = 0;
        if (var2->GetActiveGrottoEnviron() == 2) {
            for (int var13 = 0; var13 < 15; var13++) {
                if (var10.unknown_0_ == data_020e6e44[var13]) {
                    var12 = 1;
                    break;
                }
            }
            if (!var12) {
                var8.unknown_8_.unknown1_0_.y = -0x4cc;
            }
        }

        switch (var11) {
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
            fix32_t var14 = var8.unknown_14_.unknown1_0_.x / 2;
            fix32_t var15 = var8.unknown_14_.unknown1_0_.z / 2;
            fix32_t var16 = inline_0201afd0_2(var15);
            fix32_t var17 = inline_0201afd0_2(var14);

            var8.unknown_24_ = var17 + var16;
        }
        entry.pNext = NULL;
        features->CreateOpcode6aEntry(entry);
    }

    {
        SafeAllocator var18;
        char var19[0x400];
        LootDistribution var20;
        Struct_020e6df0 var21;
        const void* var22;
        unsigned int var23;
        int var24[32];
        unsigned short var25[100];
        int var26;
        int var27;
        int var28;
        int var29;

        var18.ResetAllocatorPointer();
        var18.CreateTypeA(var19, sizeof(var19));
        var21 = data_020e6df0;
        if (GetFileInNarcPermissive(arg1, var21.unknown_0_, &var22, &var23)) {
            var20.Reset();
            var20.LoadFromScript(&var18, var22, var23);
        }

        GrottoChestList_Clear((ClearThreeWords02094d00Struct*)(lootList));
        AllocateArray02094cdc((AllocDest02094cdc*)(lootList), zone->numChests_, zone->pAllocator_68_);
        memset(ranks, 1, sizeof(ranks));
        for (chest = 0; chest < zone->numChests_; chest++) {
            ranks[chest] = grotto->RandomizeChestRank(zone->currentGrottoFloor_23ba_);
        }

        func_020105a8((Struct_020105a8*)(var1), &var26);
        srand(var26 + inline_0201afd0_4(var2, arg0->currentGrottoFloor_23ba_));

        __clear(var25, sizeof(var25));
        var27 = 0;
        for (var29 = 0; var29 < arg0->numChests_; var29++) {
            Struct_020134e0::Struct_02018300* var30 = (Struct_020134e0::Struct_02018300*)(func_0201e690((Struct_0201afd0_4*)(var0), var29));
            const LootDistribution::Outcome* var31 = var20.Sample(var24[var29]);

            if (outcome != NULL) {
                ZoneChestRenderRecord* record = &zone->chests_[index];
                ChestLoot0201afd0 loot;

                ZoneChest_Init(record);
                record->position = entry->unk_8.vec;
                record->angleY = entry->angle;
                record->counter = 0;
                record->recordIndex = index;
                record->uniqueID = index;
                record->kind = ZoneChestKind_Grotto;
                if (GetBit5cd0((S_02011430*)(gs), zone->currentGrottoFloor_23ba_, index)) {
                    record->state = ZoneChestState_Open;
                    record->lidAngle = ZoneChestLid_Open;
                } else {
                    record->state = ZoneChestState_Closed;
                    record->lidAngle = ZoneChestLid_Closed;
                }
                if (LinkSession_IsActive((int*)(search))) {
                    record->special = 1;
                }
                if (var31->lootType == 2) {
                    var25[var27++] = var31->itemID;
                }

                loot.uniqueID = 0;
                loot.itemIDOrRank = outcome->itemID;
                loot.lock = 0;
                loot.lootType = outcome->lootType;
                loot.containerType = 4;
                loot.position = entry->unk_8.vec;
                CopyElemToIndex((Container02094d14*)(lootList), (Elem02094d14*)(&loot), record->uniqueID);
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
        var18.Reset();
        var18.Destroy();
    }
    return 1;
}
