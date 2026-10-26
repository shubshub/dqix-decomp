#if defined(jpn)
enum { spriteSlotsOffset = 0x620, vramStatesOffset = 0x27c };
#else
enum { spriteSlotsOffset = 0x600, vramStatesOffset = 0x2cc };   // Zone3D's sprite slots, GameResources' VRAM states
#endif

#include <globaldefs.h>
#include "World/FieldTask.h"
#include "World/ZoneLootableRecord.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

struct Struct0218d618;
extern "C" int GameResources_IsSpecialItemEffectLoaded(struct Struct0218d618* p);

extern "C" void* Zone3D_GetInstance(void);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

struct Foo02048004;
extern "C" void SprSprite_Unload(struct Foo02048004* obj);

struct State0207dfc8;
extern "C" void VramState_CopyCurrentTo(struct State0207dfc8* src, struct State0207dfc8* dst);
extern "C" void VramState_Restore(char* obj);
extern "C" void VramState_Save(char* obj);
extern "C" void SprSprite_LoadFile(void* a, int b, int c, int d);

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5dc4 : FieldTask {
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

// Overlay 17, originally func_ov017_021b5dc4 (USA/EUR 0x021b5dc4, JPN 0x021b6378)
extern "C" ARM int SearchPotTask_WaitSprite(SearchPotTask021b5dc4* self) {
    if (self->special != 0) {
        if (!GameResources_IsSpecialItemEffectLoaded((struct Struct0218d618*)((char*)GetGameResources())))
            return SearchPotStep_WaitSprite;
    } else {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->loadTask) != 0) {
            if (loader->GetDetailedTaskStatus(self->loadTask) == BackgroundLoader::TaskStatus_Complete) {
                void* file;
                unsigned int fileSize;
                loader->GetLoadedFileByID(self->loadTask, &file, &fileSize);
                void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x100);
                if (fileSize != 0 && buffer != 0) {
                    self->spriteAllocator.CreateTypeA(buffer, 0x100);
                    GameState* gs = GameState::GetInstance();
                    char* zone = (char*)Zone3D_GetInstance();
                    int protagonist = GameState_GetProtagonistIndex(gs);
                    char* slot = zone + spriteSlotsOffset + protagonist * sizeof(Foo02048004);
                    self->sprite = slot;
                    SprSprite_Unload((struct Foo02048004*)self->sprite);
                    SprSprite_Init((struct Foo02048004*)self->sprite);
                    unsigned char vramState[0x70];
                    short* vramStates = (short*)(((char*)GetGameResources()) + vramStatesOffset);
                    VramState_CopyCurrentTo((struct State0207dfc8*)((char*)vramStates + 0x230), (struct State0207dfc8*)vramState);
                    VramState_Restore((char*)vramState);
                    SprSprite_LoadFile(self->sprite, (int)file, (int)fileSize, (int)&self->spriteAllocator);
                    VramState_Save((char*)vramState);
                }
            }
            loader->RemoveTask(self->loadTask);
            self->loadTask = -1;
        }
    }
    return (self->loadTask < 0) ? SearchPotStep_ShowMessage : SearchPotStep_WaitSprite;
}
