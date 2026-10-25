#include <globaldefs.h>
#include "World/FieldTask.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "NitroSDK/HWRegisters.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
int MessageSystem_GetInstance();

// A FieldTaskKind_SearchPot task (its own copy of the layout, as in the other step files).
struct SearchPotTask021b57fc : FieldTask {
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

// Overlay 17, originally func_ov017_021b57fc (USA/EUR 0x021b57fc, JPN 0x021b5db0)
extern "C" ARM void FieldTask_InitSearchPot(SearchPotTask021b57fc* self) {
    ResetByteHeader((struct ByteHeader0204693c*)self);

    self->kind = FieldTaskKind_SearchPot;
    self->step = SearchPotStep_Check;
    self->unknownC = 0;
    self->lootableIndex = 0xffff;
    self->leader = 0;
    self->unknownE = 0;
    self->sprite = 0;
    self->container = 0;
    self->loadTask = -1;
    self->itemId = 0xffff;
    self->spriteTimer = 0x3d;
    self->bobAngle = 0;
    self->spriteLetter = 0;
    self->spriteNumber = -1;
    self->holdTimer = 500;

    self->spriteAllocator.ResetAllocatorPointer();
    self->specialAllocator.ResetAllocatorPointer();

    int messages = MessageSystem_GetInstance();
#if defined(jpn)
    void* messageBuffer = *(void**)((char*)messages + 0x28);
    memset(self->message = messageBuffer, 0, 0x800);
#else
    void* messageBuffer = *(void**)((char*)messages + 0x5c);
    memset(self->message = messageBuffer, 0, 0x960);
#endif

    unsigned int layers = (DISPCNT & 0x1f00) >> 8;   // the displayed layers: BG0-BG3, OBJ (0x10)
    layers |= 0x10;
    unsigned int cleared = DISPCNT & ~0x1f00;
    DISPCNT = cleared | (layers << 8);

    self->special = 0;
}
