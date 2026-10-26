#include <globaldefs.h>
#include "World/FieldTask.h"
#include "Memory/SafeAllocator.h"
#include "World/LootableContainer.h"
#include "Resource/Brightness.h"


// The zone's lootable record (ZoneLootableRecord's layout, up to the position).
struct ZoneLootableRecord021b5aec {
    unsigned short id;
    short state;                // ZoneLootableState
    short field4;
    unsigned char reserved6[2];
    char primary8[0x1c];        // ZoneLootableRecord::primary[0], up to:
    Vector3fix position;        // the pot's
};

// Zone3D's first field (this file's copy)
struct Zone3D021b5aec {
    unsigned short id;
};

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5aec : FieldTask {
    int step;                      // SearchPotStep
    unsigned char unknownC;        // zeroed by FieldTask_InitSearchPot
    char padD;
    short unknownE;                // likewise
    unsigned short lootableIndex;  // the pot (Zone3D_GetLootable)
    unsigned short itemId;         // the item found, or the gold amount
    short spriteNumber;            // the icon file's number (/data/ani/d_%c%03d.spr)
    unsigned char spriteTimer;     // frames the icon stays (61)
    signed char spriteLetter;      // the icon file's letter
    short holdTimer;               // ms the player is held still (500)
    char pad1a[2];
    void* leader;
    void* sprite;                  // the icon's sprite slot (Zone3D +0x600 + 0x88 * GameState+0x3ac)
    LootableContainerManager::Container* container;
    int loadTask;                  // BackgroundLoader task, -1 for none
    Vector3fix position;           // the pot's; the icon is drawn above it
    int bobAngle;                  // the icon rises along a sine of this, up to 90 degrees
    int message;                   // where the item text goes
};

class Zone3D;
extern "C" Zone3D021b5aec* Zone3D_GetInstance(void);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" ZoneLootableRecord021b5aec* Zone3D_GetLootable(Zone3D* zone, int index);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void SearchPotTask_Release(SearchPotTask021b5aec* self);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void func_0207cbe8(char* obj);
extern "C" void func_0207d538(LootTextContext* context, int lootType, int itemID, int arg, int flag);
extern "C" void Zone3D_MarkLootableSearched(int id, int index, int bit);
extern "C" void LinkMessageQueue_SendLootableSearched(unsigned short a, unsigned short b, unsigned short c);

// Overlay 17, originally func_ov017_021b5aec (USA/EUR 0x021b5aec, JPN 0x021b60a0)
extern "C" ARM int SearchPotTask_Check(SearchPotTask021b5aec* self) {
#if defined(jpn)
 enum { containerItemsOffset = 0x2794 };   // Zone3D::containerItems_
#else
 enum { containerItemsOffset = 0x2754 };
#endif
    Zone3D021b5aec* zone = Zone3D_GetInstance();
    unsigned char* progress = Scenario_GetInstance();
    LootableContainerManager* containers = LootableContainerManager::GetMainInstance();
    ZoneLootableRecord021b5aec* lootable = Zone3D_GetLootable((Zone3D*)zone, self->lootableIndex);
    if (containers == 0 || progress == 0 || lootable == 0) {
        GameObject_EnableControl(self->leader);
        SearchPotTask_Release(self);
        self->done = 1;
        return SearchPotStep_Done;
    }

    self->position.x = lootable->position.x;
    self->position.y = lootable->position.y;
    self->position.z = lootable->position.z;
    int alreadyOpened = 1;
    int var5 = 0;
    unsigned short listPos = 0;
    unsigned short containerID = 0;
    LootableContainerManager::Container* container = containers->GetContainerByID(lootable->id, &listPos);
    if (container != 0) {
        containerID = container->uniqueID;
        alreadyOpened = Scenario_TestFlag((int)progress, progress + 0x8c, containerID + 0x79e);
        if (!alreadyOpened) {
            self->container = container;
            if (container->lootType) {
                var5 = 1;
                LootTextContext context;
                context.allocator.ResetAllocatorPointer();
                ItemTable_Construct(context.itemTable);
                func_0207cbe8((char*)&context);
                func_0207cbe8((char*)&context);
                context.containerItems = (char*)zone + containerItemsOffset;
                func_0207d538(&context, container->lootType, container->itemIDOrRank, self->message, 1);
                self->itemId = container->itemIDOrRank;
            }
        }
    }
    Zone3D_MarkLootableSearched(zone->id, self->lootableIndex, containerID);
    LinkMessageQueue_SendLootableSearched(zone->id, self->lootableIndex, containerID);
    if (!alreadyOpened && var5) {
        SetFlags04(GetGameResources(), 0x40);
        return SearchPotStep_PickSprite;
    }
    GameObject_EnableControl(self->leader);
    SearchPotTask_Release(self);
    self->done = 1;
    return SearchPotStep_Done;
}
