#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_ov003_02155f88
extern "C" ARM int func_ov003_02155f88(void* unused, int combatantId) {
	GameObject* c = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
	int result = 1;
	if (c != NULL) {
		int* p = *(int**)((char*)c + 0x130);
		result = (*p & 4) != 0;
	}
	return result;
}
