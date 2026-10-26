#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
// USA: func_ov024_021e57c0
extern "C" ARM void func_ov024_021e57c0(int* arg0, int id) {
	GameObject* combatant = GetCombatantByID(arg0[4], id);
	if (combatant != NULL) {
		*((char*)combatant->currentStats_ + 0x21) = 1;
	}
}
