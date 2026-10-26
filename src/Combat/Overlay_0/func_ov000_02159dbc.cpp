#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/BattleSkillEligibility.h"
#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" GameObject* func_0200fea4(GameState* gameState, int combatantId);
extern "C" void* func_ov000_02153758(void* obj, int idx);
extern "C" char* Zone3D_GetInstance(void);

struct Struct_ov000_02159dbc {
    char pad0[0xa];
    unsigned short level : 7;
};

struct PartyWork_02159dbc {
    char pad[0x25];
    unsigned char field_0x25;
};

// USA: func_ov000_02159dbc
extern "C" ARM int func_ov000_02159dbc(char* battle, int combatantId) {
    GameState* gs = GameState::GetInstance();
    GameObject* combatant = func_0200fea4(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 1;
    }
    struct Struct_ov000_02159dbc* entry =
        (struct Struct_ov000_02159dbc*)func_ov000_02153758(battle, combatantId);
    if (entry == 0) {
        return 1;
    }
    char* zone = Zone3D_GetInstance();
    if (GameState_IsInGrotto(gs) && (*(struct PartyWork_02159dbc**)(battle + 0x8e18))->field_0x25 != 0) {
#if defined(jpn)
        enum { Enum_ov000_02159dbc_9196 = 0x240c };
#else
        enum { Enum_ov000_02159dbc_9196 = 0x23ec };
#endif
        DetailedTreasureMapData* detail = ((ActiveGrottoClass*)(zone + Enum_ov000_02159dbc_9196))->GetDetailedData();
        short monsterId = combatant->obj3D_.unknown_2_;
        unsigned short var6 = detail->legacy_.MaybeGetCurrentAlternateID();
        if (var6 == monsterId) {
            return detail->legacy_.level_;
        }
    }
    return entry->level;
}
