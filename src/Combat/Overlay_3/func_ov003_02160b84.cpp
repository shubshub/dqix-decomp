#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff94(GameState* battleStruct, int combatantId);

// USA: func_ov003_02160b84
extern "C" ARM int func_ov003_02160b84(void*) {
	GameState* bs = GameState::GetInstance();
	int count = 0;
	int i;
	for (i = 0; i < 4; i++) {
		if (func_0200ff94(bs, i) != 0) count++;
	}
	return count - *((unsigned char*)GameState_GetParty(GameState::GetInstance()) + 0xf7c);
}
