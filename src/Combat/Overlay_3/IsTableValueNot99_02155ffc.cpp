#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned short GameObject_GetPartyMemberLevel(void* obj);

// USA: func_ov003_02155ffc
ARM int IsTableValueNot99_02155ffc(void* unused, int combatantId) {
	GameObject* c = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
	int result = 0;
	if (c != NULL) {
		result = (GameObject_GetPartyMemberLevel(c) != 0x63);
	}
	return result;
}
