#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021d9654 { struct Random* rng; };

// USA: func_ov024_021d9654
extern "C" ARM int func_ov024_021d9654(struct Struct_ov024_021d9654* holder, int id, int a2, int a3, int a4, int arg5) {
	GameState* bs = GameState::GetInstance();
	GameObject* combatant = bs->GetCombatantByIndex(id);
	if (!combatant) return arg5;
	struct Random* rng = holder->rng;
	if (NextRandomMax(rng, 2) > 0) return 0;
	unsigned short var3 = combatant->baseStats_->primaryStats.attack;
	float f = NextRandomFloatBetween(rng, 0.95f, 1.05f);
	return (int)((float)var3 * f);
}
