#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_0218fcf8(int a, int b, int c);

// USA: func_ov017_021bdb78
extern "C" ARM void func_ov017_021bdb78(int id) {
	GameState* bs = GameState::GetInstance();
	int helper = ((int)GetGameResources());
	GameObject* combatant = bs->GetGameObjectByIndex(id);
	if (!combatant) {
		return;
	}
	combatant->obj3D_.unknown_9c_ = 0x40c8;
	func_ov017_0218fcf8(helper, 0, 0x40c8);
}
