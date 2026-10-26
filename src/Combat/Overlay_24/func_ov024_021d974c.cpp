#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

// USA: func_ov024_021d974c
extern "C" ARM int func_ov024_021d974c(struct Random** arg0, int id, int a2, int a3, int a4, int val) {
	GameObject* c = GetCombatantByID((int)*arg0, (short)id);
	if (!c) return val;
	unsigned short maxMP = c->currentStats_->primaryStats.maxMP;
	struct Random* rng = *arg0;
	float f = NextRandomFloatBetween(rng, 0.2f, 0.5f);
	return (int)((float)maxMP * f);
}
