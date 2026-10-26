#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/BattleSkillEligibility.h"
#include "Grotto/Main/ActiveGrottoClass.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gameState, int combatantId);
void* FindEntryForCombatant02153758(void* obj, int idx);
extern "C" char* Zone3D_GetInstance(void);

struct Struct_ov000_02159dbc {
    char unknown_0_[0xa];
    unsigned short unknown_a_0_ : 7;
};

struct Struct_ov000_02159dbc_2 {
    char unknown_0_[0x25];
    unsigned char unknown_25_;
};

// USA: func_ov000_02159dbc
extern "C" ARM int func_ov000_02159dbc(char* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = func_0200fea4(GameState::GetInstance(), arg1);
    if (var1 == 0) {
        return 1;
    }
    struct Struct_ov000_02159dbc* var2 =
        (struct Struct_ov000_02159dbc*)func_ov000_02153758(arg0, arg1);
    if (var2 == 0) {
        return 1;
    }
    char* zone = Zone3D_GetInstance();
    if (GameState_IsInGrotto(gs) && (*(struct PartyWork_02159dbc**)(battle + 0x8e18))->field_0x25 != 0) {
#if defined(jpn)
        enum { Enum_ov000_02159dbc_9196 = 0x240c };
#else
        enum { Enum_ov000_02159dbc_9196 = 0x23ec };
#endif
        DetailedTreasureMapData* var4 = ((ActiveGrottoClass*)(var3 + Enum_ov000_02159dbc_9196))->GetDetailedData();
        short var5 = var1->obj3D_.unknown_2_;
        unsigned short var6 = var4->legacy_.MaybeGetCurrentAlternateID();
        if (var6 == var5) {
            return var4->legacy_.level_;
        }
    }
    return var2->unknown_a_0_;
}
