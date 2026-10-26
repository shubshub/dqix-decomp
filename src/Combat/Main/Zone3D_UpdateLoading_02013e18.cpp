#include <globaldefs.h>

#include "World/Zone3D.h"
#include "World/ZoneChest.h"
#include "Graphics/LightingManager.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" {
    int Zone3D_UnpackMapList(void*);
    int _ZN6Zone3D13UnpackMapAMDJEv(void*);
    int Zone3D_UnpackAtmosphericEffects(void*);
    int func_0201a600(void*);
    void Zone3D_RestoreElementsFromScenario(Zone3D*);
    int ZoneId_IsMainGrottoFloor(int);
    int ZoneId_IsGrottoBossFloor(int);
    void Set3DClearColor(int, int, int, int, int);
    void Zone3D_ApplyChestDiffuseColor(unsigned char*);
    void Zone3D_CollectTerrainElements(void*);
    int GameState_GetFollowCamera(char const*);
}

// GameResources flags04 bit: while set, the field skips LightingManager::DrawBackgroundGradient (func_ov017_021960b8)
enum { kResourcesFlag_NoBackgroundGradient = 0x800 };

// Set3DClearColor's alpha (of 31) and depth (the farthest) for the zone's clear colour
enum { kClearAlpha = 0x10, kClearDepthFarthest = 0x7fff };

// Main, originally func_02013e18 (USA 0x02013e18, EUR 0x02013e28, JPN 0x02013be4)
extern "C" ARM int Zone3D_UpdateLoading(Zone3D* zone)
{
    if (zone->unknown_424_ == 0)
        return 1;

    if (!Zone3D_UnpackMapList(zone))
        return 0;

    if (!zone->UnpackMapAMBL())
        return 0;

    if (!zone->UnpackATS_AMBL())
        return 0;

    if (!_ZN6Zone3D13UnpackMapAMDJEv(zone))
        return 0;

    if (!Zone3D_UnpackAtmosphericEffects(zone))
        return 0;

    int zoneId = zone->pUnknownStruct_8_->unknown_0_;

    if (ZoneId_IsMainGrottoFloor(zoneId))
    {
        func_02019728(zone, zoneId % 20, 0, 0, 0);
        func_0201a600(zone);
    }
    else if (ZoneId_IsGrottoBossFloor(zoneId))
    {
        func_0201a600(zone);
    }

    LightingManager* lighting = LightingManager::GetInstance();
    lighting->ProcessZoneChange(zone);

    int lightingOverride = lighting->lightingIndexOverride_;
    int lightingIndex = lighting->timeOfDayIndex_;
    if (lightingOverride)
        lightingIndex = lightingOverride;

    int clearColor;
    if (zone->lighting_.maybeMode_ == 1)
        clearColor = zone->lighting_.basic_.backgroundColor[lightingIndex];
    else
        clearColor = zone->lighting_.advanced_.backgroundColor[lightingIndex];

    Set3DClearColor(clearColor, kClearAlpha, kClearDepthFarthest, 0, 0);

    GameResources* resources = GetGameResources();
    // bit 7 of the zone table entry's byte 0xe
    int hasBackgroundGradient = (unsigned int)((unsigned char*)zone->pUnknownStruct_8_)[0xe] << 24 >> 31;
    if (!hasBackgroundGradient)
        SetFlags04(resources, kResourcesFlag_NoBackgroundGradient);
    else
        ClearFlags04(resources, kResourcesFlag_NoBackgroundGradient);

    Zone3D_ApplyChestDiffuseColor((unsigned char*)zone);
    Zone3D_CollectTerrainElements(zone);
    (void)GameState_GetFollowCamera((char const*)GameState::GetInstance());

    zone->unk_830[1] = (char)lighting->timeOfDayIndex_;
    zone->unk_830[2] = 0;
    zone->unknown_424_ = 0;

    zone->unk_23bc[0] = 1;
    Zone3D_MarkDoorElements(zone);
    Zone3D_RestoreElementsFromScenario(zone);
    return 1;
}
