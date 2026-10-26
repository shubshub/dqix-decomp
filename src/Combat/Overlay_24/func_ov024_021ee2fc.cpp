#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021ee2fc { void* field0; };

static inline int inline_ov024_021dc700(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.maxHP; }
static inline int inline_ov000_0215cd44(GameObject* c) { ModifiableCombatStats* stats = c->currentStats_; return stats->primaryStats.currHP; }

// USA: func_ov024_021ee2fc
extern "C" ARM int func_ov024_021ee2fc(struct Struct_ov024_021ee2fc* holder, int id, int unused, int* outPtr) {
	GameObject* combatant = GetCombatantByID((int)holder->field0, id);
	if (!combatant) return 0;
	if (inline_ov000_0215cd44(combatant) * 3 <= inline_ov024_021dc700(combatant)) {
		*outPtr = 0;
		return 1;
	}
	return 0;
}
