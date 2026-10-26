#include <globaldefs.h>

#include "World/Zone3D.h"
#include "World/ZoneChest.h"
#include "Graphics/LightingManager.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" {
    int _Z20Zone3D_UnpackMapListP6Zone3D(void*);
    int _ZN6Zone3D13UnpackMapAMDJEv(void*);
    int _Z31Zone3D_UnpackAtmosphericEffectsPv(void*);
    int func_0201a600(void*);
    void Zone3D_RestoreElementsFromScenario(Zone3D*);
    int _Z24ZoneId_IsMainGrottoFloori(int);
    int _Z24ZoneId_IsGrottoBossFloori(int);
    void _Z15Set3DClearColoriiiii(int, int, int, int, int);
    void _Z29Zone3D_ApplyChestDiffuseColorPh(unsigned char*);
    void _Z29Zone3D_CollectTerrainElementsPv(void*);
    int _Z25GameState_GetFollowCameraPc(char const*);
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

    if (!_Z20Zone3D_UnpackMapListP6Zone3D(zone))
        return 0;

    if (!zone->UnpackMapAMBL())
        return 0;

    if (!zone->UnpackATS_AMBL())
        return 0;

    if (!_ZN6Zone3D13UnpackMapAMDJEv(zone))
        return 0;

    if (!_Z31Zone3D_UnpackAtmosphericEffectsPv(zone))
        return 0;

    int zoneId = zone->pUnknownStruct_8_->unknown_0_;

    if (_Z24ZoneId_IsMainGrottoFloori(zoneId))
    {
        func_02019728(zone, zoneId % 20, 0, 0, 0);
        func_0201a600(zone);
    }
    else if (_Z24ZoneId_IsGrottoBossFloori(zoneId))
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

    _Z15Set3DClearColoriiiii(clearColor, kClearAlpha, kClearDepthFarthest, 0, 0);

    GameResources* resources = GetGameResources();
    // bit 7 of the zone table entry's byte 0xe
    int hasBackgroundGradient = (unsigned int)((unsigned char*)zone->pUnknownStruct_8_)[0xe] << 24 >> 31;
    if (!hasBackgroundGradient)
        SetFlags04(resources, kResourcesFlag_NoBackgroundGradient);
    else
        ClearFlags04(resources, kResourcesFlag_NoBackgroundGradient);

    _Z29Zone3D_ApplyChestDiffuseColorPh((unsigned char*)zone);
    _Z29Zone3D_CollectTerrainElementsPv(zone);
    (void)_Z25GameState_GetFollowCameraPc((char const*)GameState::GetInstance());

    zone->unk_830[1] = (char)lighting->timeOfDayIndex_;
    zone->unk_830[2] = 0;
    zone->unknown_424_ = 0;

    zone->unk_23bc[0] = 1;
    Zone3D_MarkDoorElements(zone);
    Zone3D_RestoreElementsFromScenario(zone);
    return 1;
}
