#include <globaldefs.h>
#include "World/FieldTask.h"
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Vec3copy0202ec84 { unsigned int v[3]; };
extern "C" int Camera_WorldToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
extern "C" void func_020473c8(struct StructAt020473c8* obj, int param1);

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b6090 : FieldTask {
    int step;                           // SearchPotStep
    unsigned char unknownC;             // zeroed by FieldTask_InitSearchPot
    char padD;
    short unknownE;                     // likewise
    unsigned short lootableIndex;       // the pot (Zone3D_GetLootable)
    unsigned short itemId;              // the item found, or the gold amount
    short spriteNumber;                 // the icon file's number (/data/ani/d_%c%03d.spr)
    unsigned char spriteTimer;          // frames left; also the icon's alpha (up to 31)
    signed char spriteLetter;           // the icon file's letter
    short holdTimer;                    // ms the player is held still (500)
    char pad1a[2];
    void* leader;
    void* sprite;                       // the icon's sprite slot (Zone3D +0x600 + 0x88 * GameState+0x3ac)
    void* container;                    // the pot's LootableContainerManager::Container
    int loadTask;                       // BackgroundLoader task, -1 for none
    struct Vec3copy0202ec84 position;   // the pot's
    int bobAngle;                       // the icon rises along its sine, up to 90 degrees
};

// Overlay 17, originally func_ov017_021b6090 (USA/EUR 0x021b6090, JPN 0x021b6644)
extern "C" ARM void SearchPotTask_DrawSprite(struct SearchPotTask021b6090* self) {
    GameState* gameState = GameState::GetInstance();
    void* camera = gameState->GetCamera();
    struct Vec3copy0202ec84 iconPosition = self->position;

    if (self->bobAngle < 0x191e) {
        self->bobAngle += gameState->GetTickCount() * 0x199;
    }

    iconPosition.v[1] += fix32sin(self->bobAngle);

    int screenX, screenY;
    if (camera != NULL) {
        Camera_WorldToScreen(camera, &iconPosition, &screenX, &screenY);
    }

    unsigned char* sprite = (unsigned char*)self->sprite;
    if (sprite == NULL) return;

    int spriteX = (screenX - 0xc) << 0xc;
    int spriteY = (screenY - 0x28) << 0xc;
    *(int*)(sprite + 0x1c) = spriteX;
    *(int*)(sprite + 0x20) = spriteY;
    *(int*)(sprite + 0x24) = 0;
    func_020473c8((struct StructAt020473c8*)sprite, 1);

    unsigned char timer = self->spriteTimer;
    unsigned short alpha = (timer > 0x1f) ? 0x1f : timer;
    *(unsigned short*)(sprite + 0x82) = alpha;
}
