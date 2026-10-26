#include <globaldefs.h>
#include "Resource/ItemTable.h"
#include "World/FieldTask.h"
#include "World/LootableContainer.h"

// One record of the item table, as CharacterModel_Load's copy names it (the struct tag is kept:
// ItemRecord_GetFileNumber's C++ symbol is mangled with it).
struct StructDE234_020de234 {
    int model_, unk_4, unk_8, unk_c;
    unsigned int maleFileNumber_ : 10;
    unsigned int femaleFileNumber_ : 10;
    unsigned int letter_ : 8;       // the icon file's letter (/data/ani/d_%c%03d.spr)
    unsigned int unk_10_28 : 4;
    short unk_14, unk_16, itemId_, unk_1a, unk_1c;
};

// An item table (the struct tag is kept: ItemTable_Find's C++ symbol is mangled with it).
// Zone3D's layout up to containerItems_.
struct Zone3D021b5c88 {
#if defined(jpn)
    unsigned char pad0[0x2794];
#else
    unsigned char pad0[0x2754];
#endif
    ItemTable containerItems_;  // every item the zone's containers can give
};

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5c88 : FieldTask {
    int step;                      // SearchPotStep
    unsigned char unknownC;        // zeroed by FieldTask_InitSearchPot
    char padD;
    short unknownE;                // likewise
    unsigned short lootableIndex;  // the pot (Zone3D_GetLootable)
    short itemId;                  // the item found, or the gold amount
    unsigned short spriteNumber;   // the icon file's number
    unsigned char spriteTimer;     // frames the icon stays (61)
    signed char spriteLetter;      // the icon file's letter
    short holdTimer;               // ms the player is held still (500)
    char pad1a[2];
    void* leader;
    void* sprite;                  // the icon's sprite slot (Zone3D +0x600 + 0x88 * GameState+0x3ac)
    LootableContainerManager::Container* container;   // the pot's
};

extern "C" Zone3D021b5c88* Zone3D_GetInstance(void);
extern "C" StructDE234_020de234* ItemTable_Find(ItemTable* table, int key);
extern "C" unsigned short ItemRecord_GetFileNumber(StructDE234_020de234* record, int preferMid);

// Overlay 17, originally func_ov017_021b5c88 (USA/EUR 0x021b5c88, JPN 0x021b623c)
extern "C" ARM int SearchPotTask_PickSprite(SearchPotTask021b5c88* self) {
    ItemTable* itemTable = &Zone3D_GetInstance()->containerItems_;
    if (self->container->lootType == LootType_Gold) {   // gold: d_i127
        self->spriteLetter = 0x69;
        self->spriteNumber = 0x7f;
    } else {
        StructDE234_020de234* item = ItemTable_Find(itemTable, self->itemId);
        if (item != NULL) {
            self->spriteLetter = item->letter_;
            self->spriteNumber = ItemRecord_GetFileNumber(item, 0);
        }
    }
    return SearchPotStep_LoadSprite;
}
