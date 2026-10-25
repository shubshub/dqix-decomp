#pragma once

#include "../Memory/SafeAllocator.h"
#include "../Graphics/Vector.h"

// LootableContainerManager::Container::containerType
enum LootableContainerType {
    LootableContainerType_RedChest = 0,
    LootableContainerType_Pot = 1,      // Zone3D_SetUpLootableModels' pot templates (0-2); breaking plays sound 0x10
    LootableContainerType_Barrel = 2,   // the barrel templates (3-5); breaking plays sound 0x11
    LootableContainerType_Cupboard = 3, // no position: tied to a type 5 zone feature (Zone3D_SetUpContainers)
    LootableContainerType_BlueChest = 4,// its chest record gets kind ZoneChestKind_Blue
};

// LootableContainerManager::Container::lootType, LootDistribution::Outcome::lootType
enum LootType {
    LootType_Nothing = 0,   // an opened chest's (Zone3D_SetUpContainers)
    LootType_Gold = 1,      // itemIDOrRank is the amount; the icon is the gold bag d_i127
    LootType_Item = 2,      // itemIDOrRank is the item; the icon is the item's d_%c%03d
    LootType_Ambush = 3,
};

// sizeof == 0xc == 12.
// Reads configurations of red/blue chests, pots, barrels etc from script files
// within data/scenario/treasure.nsarc.
class LootableContainerManager
{
public:
    struct Container
    {
        unsigned short uniqueID;
        unsigned short itemIDOrRank;
        // 0 none; 1 opens with item 0x561a or 0x561b; 2 only with 0x561b; item 0x561c opens either
        // (FieldTask_OpenChest, which clears it when the chest opens)
        unsigned short lock : 2;
        unsigned short lootType : 2;        // LootType
        unsigned short containerType : 3;   // LootableContainerType
        short angleOrCupboardNode;  // a chest's angle (copied to its ZoneChestRenderRecord); for a cupboard (type 3,
                                    // no position) the id of the zone feature node it opens (Zone3D_SetUpContainers)
        Vector3fix position;
        Container* pNext;
    };

    char unk_0[4];
    Container* pContainerList_;
    unsigned short numEntries_;
    short unk_10;

    // there is one main instance used by the game, but you can also create
    // a local copy just to get information - this is how Treasure Eye Land /
    // Nose for Treasure work
    static LootableContainerManager* GetMainInstance();

    LootableContainerManager() { Reset(); }
    ~LootableContainerManager() { Reset(); }

    void Reset();
    void ResetAllocator(SafeAllocator* alloc);
    void LoadZoneContainers(const void* treasureArchive, unsigned int archiveLength, const char* zoneName, SafeAllocator* alloc);
    void RegisterContainer(Container* container);
    Container* GetContainerByID(int id, unsigned short* outListPos);
};

class LootDistribution
{
public:
    struct Outcome
    {
        union {
            unsigned char rankAndLootType;
            struct {
                unsigned char rank : 5;
                // 1 = gold, 2 = regular item, 3 = ambush
                unsigned char lootType : 3;
            };
        };
        unsigned char percentage;
        unsigned short itemID; // or amount of gold, or ambush type
    };

    Outcome* pOutcomes_;
    unsigned short outcomeArrayCapacity_;
    unsigned short outcomeArraySize_;
    SafeAllocator* pAllocator_;

    void Reset();

    void LoadFromScript(SafeAllocator* alloc, const void* script, unsigned int length);
    void InsertOutcome(Outcome* atom);
    void AllocateOutcomes(unsigned short count);

    // Sample from the specified distribution
    const Outcome* Sample(int rank);
    // Returns the number put in the list
    int GetOutcomesByRank(int rank, const Outcome** outList, int outCapacity);
};