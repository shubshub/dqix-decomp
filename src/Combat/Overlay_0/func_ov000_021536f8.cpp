#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_021536f8
extern "C" ARM GameObject* func_ov000_021536f8(int unused, int id) {
	return func_0200fea4(GameState::GetInstance(), id);
}
