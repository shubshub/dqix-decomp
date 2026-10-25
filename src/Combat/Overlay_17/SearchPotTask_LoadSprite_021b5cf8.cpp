#include <globaldefs.h>
#include "World/FieldTask.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void GameResources_LoadSpecialItemEffect(int a, void* b);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;
int GameState_GetProtagonistIndex(GameState* gs);
struct Holder020159c0;
void Zone3D_ClearChestIconsByOpener(struct Holder020159c0* zone, int opener);
#if defined(jpn)
extern char SearchPotTask_spritePathFormat[];  // jpn's copy of the path format below (0x021d8314, originally data_ov017_021d7bf8); not checked against a jpn ROM
#endif

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5cf8 : FieldTask {
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
    void* container;               // the pot's LootableContainerManager::Container
    int loadTask;                  // BackgroundLoader task, -1 for none
    Vector3fix position;           // the pot's; the icon is drawn above it
    int bobAngle;                  // the icon rises along a sine of this, up to 90 degrees
    void* message;                 // what the step messages show
    SafeAllocator spriteAllocator;
    unsigned char special;         // the pot holds item 0x5617
    char pad55[3];
    SafeAllocator specialAllocator;
};

// Overlay 17, originally func_ov017_021b5cf8 (USA/EUR 0x021b5cf8, JPN 0x021b62ac)
extern "C" ARM int SearchPotTask_LoadSprite(SearchPotTask021b5cf8* self) {
    if (self->itemId == 0x5617) {
        self->special = 1;
        self->specialAllocator.ResetAllocatorPointer();
        self->specialAllocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x4000), 0x4000);
        self->specialAllocator.Reset();
        GameResources_LoadSpecialItemEffect(((int)GetGameResources()), (char*)&self->specialAllocator);
    } else {
        GameState* gs = GameState::GetInstance();
        void* zone = Zone3D_GetInstance();
        Zone3D_ClearChestIconsByOpener((struct Holder020159c0*)zone, (signed char)GameState_GetProtagonistIndex(gs));
        char path[0x80];
#if defined(jpn)
        sprintf(path, SearchPotTask_spritePathFormat, self->spriteLetter, self->spriteNumber);
#else
        // Originally data_ov017_021d7bf8 (USA/EUR 0x021d7bf8): the item icon's file (gold is d_i127.spr).
        sprintf(path, "/data/ani/d_%c%03d.spr", self->spriteLetter, self->spriteNumber);
#endif
        self->loadTask = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)path), (SafeAllocator*)(0));
    }
    return SearchPotStep_WaitSprite;
}
