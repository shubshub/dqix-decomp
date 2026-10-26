#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

// USA: func_ov003_02155ffc
extern "C" ARM int func_ov003_02155ffc(void* unused, int combatantId) {
	GameObject* c = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
	int result = 0;
	if (c != NULL) {
		result = (GameObject_GetPartyMemberLevel(c) != 0x63);
	}
	return result;
}
