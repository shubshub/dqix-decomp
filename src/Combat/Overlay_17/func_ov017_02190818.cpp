#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov017_02190818
extern "C" ARM int func_ov017_02190818(int id) {
	GameState* bs = GameState::GetInstance();
	if (bs->GetPartyMemberByIndex(id) == NULL)
		goto zero;
	{
	GameObject* c = bs->GetGameObjectByIndex(id * 0xc + 0x14);
	if (c == NULL)
		goto zero;
	{
	short v = c->obj3D_.unknown_2_;
	if (v != 0x2347) {
		if (v != 0x2348) {
			if (v != 0x2349) {
				goto zero;
			}
		}
	}
	return 1;
	}
	}
zero:
	return 0;
}
