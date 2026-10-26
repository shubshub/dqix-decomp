#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);
extern "C" int func_020546bc(void* obj);

#pragma optimize_for_size off
// USA: func_ov017_02191764
extern "C" ARM int func_ov017_02191764(int a, int b) {
	GameState* battleStruct = GameState::GetInstance();
	int var1 = 0;
	for (int i = 0; i < 4; i++) {
		GameObject* combatant = func_0200ff58(battleStruct, i);
		if (!combatant || i == a) continue;
		if (b != func_020546a8(combatant)) continue;
		var1 |= 1 << func_020546bc(combatant);
	}
	int result = 0;
	for (int j = 0; j < 4; ++j) {
		if ((var1 & (1 << j)) == 0) {
			result = j;
			break;
		}
	}
	return result;
}
