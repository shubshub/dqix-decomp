#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

// USA: func_ov024_021d937c
extern "C" ARM int func_ov024_021d937c(struct Random** arg0, int id, int a2, int a3, int a4, int val) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(id);
    if (!c) return val;
    unsigned short maxHp = c->currentStats_->primaryStats.maxHP;
    struct Random* rng = *arg0;
    float f = NextRandomFloatBetween(rng, 0.4f, 0.6f);
    return (int)((float)maxHp * f);
}
