#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

static inline unsigned short inline_ov024_021dc540_2(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.maxMP; }
static inline unsigned short inline_ov000_0215cd44_2(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.currMP; }

// USA: func_ov024_021f3248
extern "C" ARM int func_ov024_021f3248(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = func_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	float ratio = (float)inline_ov000_0215cd44_2(c) / (float)inline_ov024_021dc540_2(c);
	if (ratio > 0.1f) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
