#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_02155f9c(struct Random* arg0, int combatantId, int zero);
extern "C" float func_ov000_02156270(struct Random* arg0, int combatantId);
extern "C" int func_ov000_02156404(GameObject* combatant);

struct Struct_ov000_02156f98 {
    char pad[0x10];
    unsigned int field10;
};

// USA: func_ov000_02156f98
extern "C" ARM int func_ov000_02156f98(struct Random* arg0, int combatantId, struct Struct_ov000_02156f98* arg2) {
    GameState::GetInstance();
    if (!(arg2->field10 & 0x20)) {
        return 0;
    }
    if (func_ov000_02155f9c(arg0, combatantId, 0) != 0) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetCombatantByIndex(combatantId);
    if (combatant == 0) {
        return 0;
    }
    if (func_ov000_02156404(combatant)) {
        short val = *(short*)((char*)arg0 + 0x8e00 + 0x6e);
        return val < 0x32;
    }
    float var3 = func_ov000_02156270(arg0, combatantId);
    int roll = NextRandomMax(arg0, 100);
    return roll < (int)var3;
}
