#include <globaldefs.h>
#include "World/FieldTask.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void SearchPotTask_Release(unsigned char* obj);
extern "C" void SearchPotTask_DrawSprite(unsigned char* obj);
extern "C" void FontBankLoader_CancelLoads(int a);
extern "C" int FontBankLoader_GetInstance(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" int GameResources_IsSpecialItemEffectPlaying(void* obj);
extern "C" void GameObject_EnableControl(void* obj);

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b5fc0 : FieldTask {
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

// Overlay 17, originally func_ov017_021b5fc0 (USA/EUR 0x021b5fc0, JPN 0x021b6574)
extern "C" ARM int SearchPotTask_ShowItem(SearchPotTask021b5fc0* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x228};
#else
 enum {regionalOffset0=0x2d8};
#endif
    GameState* gameState = GameState::GetInstance();
    int ticks = gameState->GetTickCount();
    GetGameResources();

    if (obj->special != 0) {
        void* resources = GetGameResources();
        if (GameResources_IsSpecialItemEffectPlaying(resources) != 0) {
            return SearchPotStep_ShowItem;
        }
        obj->spriteTimer = 0;
        FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
        SearchPotTask_Release((unsigned char*)obj);
        obj->done = 1;
        char* messageSystem = (char*)MessageSystem_GetInstance();
        *(int*)(messageSystem + regionalOffset0) = 0;
        return SearchPotStep_Done;
    }

    SearchPotTask_DrawSprite((unsigned char*)obj);
    char* messageSystem = (char*)MessageSystem_GetInstance();
    unsigned char timer = obj->spriteTimer;
    if (ticks < timer) {
        obj->spriteTimer = timer - ticks;
        goto stillShowing;
    }
    obj->spriteTimer = 0;
    FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
    GameObject_EnableControl(obj->leader);
    SearchPotTask_Release((unsigned char*)obj);
    obj->done = 1;
    *(int*)(messageSystem + regionalOffset0) = 0;
    return SearchPotStep_Done;
stillShowing:
    return SearchPotStep_ShowItem;
}
