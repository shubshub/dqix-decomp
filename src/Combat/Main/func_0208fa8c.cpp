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
extern "C" void* func_0200fd0c(GameState*);
extern "C" int func_0201b588(int);
extern "C" void func_02027ad8(int, int);
extern "C" int func_0202b7d8(int*);
extern "C" {
int* func_0202ae18();
ZoneState* Zone3D_GetInstance();
void func_020a0cc4(int);
void func_020a3720();
void func_020a395c();
void func_020a0c0c();
int func_0202c540(int*);
}
void ExportDetailedTreasureMapData(const TreasureMapMetadata*, DetailedTreasureMapData*, bool, const unsigned char*);

// USA: func_0208fa8c
extern "C" ARM void func_0208fa8c(DetailedTreasureMapData* map) {
    ZoneState* current;
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetGameResources();
    int* session = func_0202ae18();
    current = (ZoneState*)GetField0x3f8Address_0200fd0c(game);
    GrottoStruct* grotto = game->GetGrottoStruct();
    int currentZone;
    void* region = resources->unknown_ptr_36d0;
    ZoneState* destination = Zone3D_GetInstance();
    currentZone = current->zoneId;
    int nextZone = destination->zoneId;
    if (IsInRange0201b588(currentZone) && !IsInRange0201b588(nextZone) &&
        (nextZone < 30000 || nextZone > 39999)) {
        map->Clear();
        func_020a0cc4(0x2000);
        func_020a3720();
        ExportDetailedTreasureMapData(&var4->activeMapData, arg0, true, 0);
        func_020a395c();
        func_020a0c0c();
        if (!var4->unknown_0[0]) ((Struct_0208fa8c_2*)arg0)->unknown_260_ = 1;
        var4->unknown_0[1] = 0;
        if (func_0202c540(var3)) var4->activeMapLevel = arg0->GetLevel();
        if (var6 && var8) func_02027ad8((int)var6, arg0->discoveryState_ == 3);
    } else if (!func_0201b588(var5) && func_0201b588(var8) &&
               (var5 < 30000 || var5 > 39999)) {
        if (func_0202b7d8(var3) && func_0202c540(var3) && !var4->unknown_0[1])
            var4->unknown_0[1] = 0;
        else var4->unknown_0[1] = 1;
        if (var6) func_02027ad8((int)var6, 0);
    }
}
