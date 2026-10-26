#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Main/TreasureMapMetadata.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" int ZoneId_IsGrottoBossFloor(int x);

struct Struct_ov017_021b6e70 {
    unsigned char pad0[0xc];
    unsigned char unknown_c_;
    unsigned char unknown_d_;
};

// USA: func_ov017_021b6e70
extern "C" ARM bool func_ov017_021b6e70(struct Struct_ov017_021b6e70* obj, int combatantId) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetFieldMonsterByIndex(combatantId);
    if (combatant) {
        unsigned char flags = *((unsigned char*)combatant + 0x17d);
        if (flags & 0x2) {
            obj->unknown_c_ = 1;
        } else if (flags & 0x4) {
            obj->unknown_d_ = 1;
        }
    }

    void* misc = Zone3D_GetInstance();
    struct GrottoStruct* grotto = battleStruct->GetGrottoStruct();
#if defined(jpn)
    int mapType = grotto->activeMapData.GetMapType();
#else
    int mapType = grotto->activeMapData.GetMapType();
#endif
    int val = *(unsigned short*)misc;

    if (ZoneId_IsGrottoBossFloor(val)) {
        if (mapType == 1) {
            obj->unknown_c_ = 1;
        } else if (mapType == 2) {
            obj->unknown_d_ = 1;
        }
    }

    return obj->unknown_c_ != 0 || obj->unknown_d_ != 0;
}
