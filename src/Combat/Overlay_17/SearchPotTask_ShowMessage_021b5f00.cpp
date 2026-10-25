#include <globaldefs.h>
#include "World/FieldTask.h"
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern int g_sePlayer;
extern "C" void GameResources_PlaySpecialItemEffect(GameResources* resources, void* position, int b);
void* TextQueue_GetInstance(void);
extern "C" void SearchPotTask_DrawSprite(void* self);
void GameObject_EnableControl(void* obj);
extern "C" void SearchPotTask_Release(void* self);

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5f00 : FieldTask {
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
    short* message;                // what the step messages show
    SafeAllocator spriteAllocator;
    unsigned char special;         // the pot holds item 0x5617
};

// Overlay 17, originally func_ov017_021b5f00 (USA/EUR 0x021b5f00, JPN 0x021b64b4)
extern "C" ARM int SearchPotTask_ShowMessage(SearchPotTask021b5f00* self) {
    GameResources* resources = GetGameResources();
    if (self->special != 0) {
        GameResources_PlaySpecialItemEffect(resources, &self->position, 0);
        void* textQueue = TextQueue_GetInstance();
#if defined(jpn)
        TextQueue_Push(textQueue, self->message, 0, 0, 1);
#else
        TextQueue_Push(textQueue, self->message, 0, 0, 1, 0);
#endif
        return SearchPotStep_ShowItem;
    }
    SearchPotTask_DrawSprite(self);
    GameObject_EnableControl(self->leader);
    if (*self->message != 0) {
        void* textQueue = TextQueue_GetInstance();
#if defined(jpn)
        TextQueue_Push(textQueue, self->message, 0, 0, 1);
#else
        TextQueue_Push(textQueue, self->message, 0, 0, 1, 0);
#endif
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0xe, 0);
        return SearchPotStep_ShowItem;
    }
    SearchPotTask_Release(self);
    self->done = 1;
    return SearchPotStep_Done;
}
