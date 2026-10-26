#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

// USA: func_ov024_021d8b68
extern "C" ARM int func_ov024_021d8b68(struct Random** arg0, int id, int a2, int a3, int a4, int val) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(id);
    if (!c) return val;
    unsigned short var2 = c->baseStats_->primaryStats.attack;
    struct Random* rng = *arg0;
    float f = NextRandomFloatBetween(rng, 0.85f, 0.95f);
    return (int)((float)var2 * f);
}
