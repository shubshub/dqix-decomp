#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov024_021db358
extern "C" ARM float func_ov024_021db358(GameObject* obj) {
	unsigned short var0 = obj->currentStats_->primaryStats.currHP;
	if ((float)var0 == 0.0f) return 0.0f;
	unsigned short maxHP = obj->currentStats_->primaryStats.maxHP;
	return (float)var0 / (float)maxHP;
}
