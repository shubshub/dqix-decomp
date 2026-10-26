#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021f0920 { void* field0; };

// USA: func_ov024_021f0920
extern "C" ARM int func_ov024_021f0920(struct Struct_ov024_021f0920* holder, int id) {
	GameObject* combatant = GetCombatantByID((int)holder->field0, id);
	if (!combatant) return 0;
	int flag = func_ov024_021eda60(combatant);
	int result = !flag;
	return result;
}
