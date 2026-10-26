#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/LightingInfo.h"
#include "World/ZoneFeatures.h"
#include "Graphics/AtmosphericEffect.h"
#include "GameState/GameState.h"
#include "World/Zone3D.h"

#if defined(jpn)
enum { MiddleFieldDelta = 0x20, TailFieldDelta = 0x40 };
#else
enum { MiddleFieldDelta = 0, TailFieldDelta = 0 };
#endif

struct ClearThreeWords02094d00Struct;
extern "C" void GrottoChestList_Clear(ClearThreeWords02094d00Struct*);
extern "C" void Zone3D_ResetLootIcons(char* obj);
extern "C" void func_020982b4(void* obj);
extern "C" unsigned char func_0200fb9c(char* gs);
extern "C" int func_0201201c(void* gs);
struct FieldBlock63d6_115a8;
extern "C" unsigned char func_020115a8(FieldBlock63d6_115a8*);

// Zone3D::savedActor_ as set up when func_0201201c is 5 or GameState byte 4 is 4 or 2: zone 1900 (0x76c),
// position (25.0, 0.1, 56.8) in 20.12 fixed point
enum {
    kDefaultSavedZoneId = 0x76c,
    kDefaultSavedPositionX = 0x19000,
    kDefaultSavedPositionY = 0x199,
    kDefaultSavedPositionZ = 0x38ccc,
};

// Main, originally func_020134e0 (USA 0x020134e0, EUR 0x020134f0, JPN 0x020132a8)
extern "C" ARM void Zone3D_Reset(Zone3D* zone) {
    void* gameState = GameState::GetInstance();
    char* raw = (char*)zone;

    zone->currentZoneID_ = 0;
    zone->previousZoneID_ = 0;
    zone->unknown_4_ = 0;
    zone->unknown_424_ = 0;
    zone->pUnknownStruct_8_ = 0;
    zone->pAllocator_4c_ = 0;
    zone->pAllocator_68_ = 0;
    zone->vramState_ = 0;
    zone->numLootables_ = 0;
    zone->numChests_ = 0;
    zone->terrainElementCount_ = 0;
    zone->unk_830[0] = 0;
    *(int*)(raw + 0x428 + MiddleFieldDelta) = 1;
    zone->textureImageMemory_ = 0;
    zone->texturePaletteMemory_ = 0;
    zone->unknown_42c_ = 0;
    zone->firstBMDJStruct_41c_ = 0;
    zone->firstModel_418_ = 0;
    zone->lootables_ = 0;
    zone->chests_ = 0;
    zone->unknown_834_ = 0;
    zone->isInMainGrottoFloor_23b8_ = 0;
    zone->unknown_23b9_ = 0;
    zone->grottoTileMapData_420_ = 0;
    zone->unk_23bc[0] = 0;
    *(int*)(raw + 0x276c + TailFieldDelta) = -1;
    *(int*)(raw + 0x2770 + TailFieldDelta) = 0;
    zone->unk_830[1] = 0;
    zone->unk_830[2] = 0;
    zone->unk_830[3] = 0;
    zone->unknown_281f_ = 0;
    zone->unknown_2820_ = 0;
    *(short*)(raw + 0x27d6 + TailFieldDelta) = 0;
    zone->copyOfCurrentGrottoFloor_23bb_ = -1;

    zone->substruct_6c_.Reset();
    zone->atmosphericEffects_.Reset();
    zone->lighting_.Initialize();
    zone->internalAllocator_.ResetAllocatorPointer();
    ((SafeAllocator*)(raw + 0x2730 + TailFieldDelta))->ResetAllocatorPointer();
    zone->models_498_[0].Clear();
    zone->models_498_[1].Clear();
    GrottoChestList_Clear((ClearThreeWords02094d00Struct*)zone->grottoChestList_);

    *(int*)(raw + 0x27c4 + TailFieldDelta) = 0;
    *(int*)(raw + 0x27b8 + TailFieldDelta) = 0;
    *(int*)(raw + 0x27bc + TailFieldDelta) = 0xa000;
    *(int*)(raw + 0x27c0 + TailFieldDelta) = 0;
    zone->lootIconAlpha_ = 0;
    Zone3D_ResetLootIcons((char*)zone->lootIcons_);
    memset(zone->unknown_27dc_, 0, 0x40);

    *(char*)(raw + 0x281c + TailFieldDelta) = 0;
    *(char*)(raw + 0x2744 + TailFieldDelta) = 0;
    *(char*)(raw + 0x2745 + TailFieldDelta) = 1;
    *(char*)(raw + 0x2746 + TailFieldDelta) = 0;
    *(short*)(raw + 0x2748 + TailFieldDelta) = 0;
    zone->chestRenderingEnabled_274c_ = 1;
    *(int*)(raw + 0x2750 + TailFieldDelta) = 1;

    if (func_0200fb9c((char*)gameState) != 5) {
        zone->pendingType2Mask_ = 0;
        zone->pendingLootableMask_ = 0;
    }
    *(char*)(raw + 0x281d + TailFieldDelta) = 0;
    zone->unknown_281e_ = 0;
    if (func_020115a8((FieldBlock63d6_115a8*)gameState) != 0) {
        return;
    }

    if (func_0201201c(gameState) == 5 || func_0200fb9c((char*)gameState) == 4 ||
        func_0200fb9c((char*)gameState) == 2) {
        func_020982b4(zone->unk_840);
        *(short*)(raw + 0x27b4 + TailFieldDelta) = 2;
        *(short*)(raw + 0x27b6 + TailFieldDelta) = 0;
        zone->savedActor_.nodeId = 0;
        zone->savedActor_.zoneId = kDefaultSavedZoneId;
        zone->savedActor_.active = 0;
        zone->savedActor_.rotationY = 0;
        *(int*)(raw + 0x2794 + TailFieldDelta) = 0x50;
        *(char*)(raw + 0x27d0 + TailFieldDelta) = 0;
        zone->savedActor_.position.x = kDefaultSavedPositionX;
        zone->savedActor_.position.y = kDefaultSavedPositionY;
        zone->savedActor_.position.z = kDefaultSavedPositionZ;
    }
}
