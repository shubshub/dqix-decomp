#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

extern "C" void func_ov017_0218f5a4(void* ov, int id, int b, int c, int d);

// USA: func_ov017_021b0b4c
extern "C" ARM int func_ov017_021b0b4c(void*) {
	GameState* bs = GameState::GetInstance();
	GameResources* ov = GetGameResources();

	int i;
	for (i = 0; i < 4; i++) {
		GameObject* combatant = bs->GetGameObjectByIndex(i);
		if (combatant) {
			func_ov017_0218f5a4(ov, i, 0, 0, 0);
		}
	}

	return TestFlags00((GameResources*)ov, 0x10) == 0 ? 1 : 0;
}
