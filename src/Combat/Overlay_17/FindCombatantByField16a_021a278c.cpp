#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_ov017_021a278c
ARM GameObject* FindCombatantByField16a_021a278c(void* unused, int val) {
	if (val <= 0) return NULL;
	GameState* battle = GameState::GetInstance();
	for (int i = 0; i < 0x30; i++) {
		GameObject* c = battle->GetFieldMonsterByIndex(i + 0x70);
		if (c) {
			unsigned short field16a = *(unsigned short*)((char*)c + 0x100 + 0x6a);
			if (val == field16a) return c;
		}
	}
	return NULL;
}
