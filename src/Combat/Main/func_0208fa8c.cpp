#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Grotto/Main/DetailedTreasureMapData.h"
#include "Resource/GameResources.h"

struct Struct_0208fa8c { unsigned short unknown_0_; };
struct Struct_0208fa8c_2 {
#if defined(jpn)
    char unknown_0_[0x280];
#else
    char unknown1_0_[0x260];
#endif
    unsigned char unknown_260_;
};
void* GameState_GetZoneTransition(GameState*);
int ZoneId_IsGrotto(int);
void ClearOrFillBattleRegion02027ad8(int, int);
int LinkSession_IsActive(int*);
extern "C" {
int* LinkSession_GetInstance();
ZoneState* Zone3D_GetInstance();
void func_020a0cc4(int);
void func_020a3720();
void func_020a395c();
void ROMFilesystem_InitFileTables();
int LinkSession_IsGuest(int*);
}
void ExportDetailedTreasureMapData(const TreasureMapMetadata*, DetailedTreasureMapData*, bool, const unsigned char*);

// USA: func_0208fa8c
extern "C" ARM void func_0208fa8c(DetailedTreasureMapData* map) {
    ZoneState* current;
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    int* session = LinkSession_GetInstance();
    current = (ZoneState*)GameState_GetZoneTransition(game);
    GrottoStruct* grotto = game->GetGrottoStruct();
    int currentZone;
    void* region = resources->unknown_ptr_36d0;
    ZoneState* destination = Zone3D_GetInstance();
    currentZone = current->zoneId;
    int nextZone = destination->zoneId;
    if (ZoneId_IsGrotto(currentZone) && !ZoneId_IsGrotto(nextZone) &&
        (nextZone < 30000 || nextZone > 39999)) {
        map->Clear();
        func_020a0cc4(0x2000);
        func_020a3720();
        ExportDetailedTreasureMapData(&var4->activeMapData, arg0, true, 0);
        func_020a395c();
        ROMFilesystem_InitFileTables();
        if (!grotto->unknown_0[0]) ((DetailedMapFlags*)map)->field260 = 1;
        grotto->unknown_0[1] = 0;
        if (LinkSession_IsGuest(session)) grotto->activeMapLevel = map->GetLevel();
        if (region && nextZone) ClearOrFillBattleRegion02027ad8((int)region, map->discoveryState_ == 3);
    } else if (!ZoneId_IsGrotto(currentZone) && ZoneId_IsGrotto(nextZone) &&
               (currentZone < 30000 || currentZone > 39999)) {
        if (LinkSession_IsActive(session) && LinkSession_IsGuest(session) && !grotto->unknown_0[1])
            grotto->unknown_0[1] = 0;
        else grotto->unknown_0[1] = 1;
        if (region) ClearOrFillBattleRegion02027ad8((int)region, 0);
    }
}
