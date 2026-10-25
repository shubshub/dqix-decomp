#include <globaldefs.h>
#include "World/FieldTask.h"

#if defined(jpn)
enum { kResourceNodeOffset = 0x4fc };
#else
enum { kResourceNodeOffset = 0x70c };
#endif

#include "Resource/GameResources.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
int GetFieldIfFlag4_020100f8(char* obj);
void FollowCamera_DisableFollow(void* obj);
void FollowCamera_EnableFollow(void* obj);
void GameObject_EnableControl(void* obj);
void GameResources_UpdateSpecialItemEffect(void* obj);
struct ListHead02046b38;
struct ListNode02046b38;
int ListContainsNode(ListHead02046b38* list, ListNode02046b38* target);
extern "C" void SearchPotTask_Release(void* self);

typedef int (*SearchPotTaskStepFn)(void*);
struct SearchPotTaskSteps { SearchPotTaskStepFn steps[7]; };   // SearchPotStep -> step function
extern SearchPotTaskSteps SearchPotTask_steps;

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b58b8 : FieldTask {
    int step;                      // SearchPotStep
    unsigned char unknownC;        // zeroed by FieldTask_InitSearchPot
    char padD;
    short unknownE;                // likewise
    unsigned short lootableIndex;  // the pot (Zone3D_GetLootable)
    unsigned short itemId;         // the item found, or the gold amount
    short spriteNumber;            // the icon file's number (/data/ani/d_%c%03d.spr)
    unsigned char spriteTimer;     // frames the icon stays (61)
    signed char spriteLetter;      // the icon file's letter
    unsigned short holdTimer;      // ms the player is held still (500)
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
};

// Overlay 17, originally func_ov017_021b58b8 (USA/EUR 0x021b58b8, JPN 0x021b5e6c)
extern "C" ARM void FieldTask_SearchPot(SearchPotTask021b58b8* self, ListNode02046b38* queue) {
    if (self->holdTimer != 0) {
        GameState* gs = GameState::GetInstance();
        GameObject* leader = gs->GetUnknownGameObject();
        if (leader != 0) {
            unsigned int elapsed = (unsigned int)gs->GetEffectiveDeltaTime();
            if (elapsed < self->holdTimer) {
                GameObject_DisableControl((Obj020397cc*)leader, 1);
                *(unsigned short*)((char*)leader + 0xb2) = 0;
                self->holdTimer = self->holdTimer - elapsed;
                int camera = GetFieldIfFlag4_020100f8((char*)gs);
                if (camera != 0) {
                    FollowCamera_DisableFollow((void*)camera);
                }
                GameResources* resources = GetGameResources();
                if (resources != 0) {
                    SetFlags04(resources, 0x80);
                }
            } else if (self->special == 0) {
                GameObject_EnableControl((void*)leader);
                self->holdTimer = 0;
                int camera = GetFieldIfFlag4_020100f8((char*)gs);
                if (camera != 0) {
                    FollowCamera_EnableFollow((void*)camera);
                }
                GameResources* resources = GetGameResources();
                if (resources != 0) {
                    ClearFlags04(resources, 0x80);
                }
            }
        }
    }

    GameResources* resources = GetGameResources();
    if (resources != 0) {
        GameResources_UpdateSpecialItemEffect((void*)resources);
    }

    SearchPotTaskSteps steps = SearchPotTask_steps;
    SearchPotTaskStepFn stepFn = steps.steps[self->step];
    if (stepFn != 0) {
        self->step = stepFn(self);
    }

    if (ListContainsNode((ListHead02046b38*)queue, *(ListNode02046b38**)((char*)resources + 0x3000 + kResourceNodeOffset)) != 0) {
        self->done = 1;
        SearchPotTask_Release(self);
    }
    if (self->done != 0) {
        ClearFlags04(resources, 0x40);
    }
}
