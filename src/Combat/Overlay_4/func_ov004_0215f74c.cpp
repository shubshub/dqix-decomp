#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov004_0215f74c
extern "C" ARM int func_ov004_0215f74c(int unused, int combatantId) {
	return func_0200ff1c(GameState::GetInstance(), combatantId) != NULL;
}
