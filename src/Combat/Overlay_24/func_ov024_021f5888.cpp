#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

static inline unsigned short inline_ov024_021dc700(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.maxHP; }
static inline unsigned short inline_ov000_0215cd44(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.currHP; }

// USA: func_ov024_021f5888
extern "C" ARM int func_ov024_021f5888(int* p0, int id, int arg2, int* outFlag, void* arg4) {
	GameObject* c = func_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (inline_ov000_0215cd44(c) >= inline_ov024_021dc700(c)) return 0;
	*outFlag = 0;
	memset(arg4, -1, 8);
	return 1;
}
