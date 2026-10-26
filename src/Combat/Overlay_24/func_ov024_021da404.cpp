#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov024_021da404 { unsigned int unknown_0_; unsigned int val : 10; };

// USA: func_ov024_021da404
extern "C" ARM int func_ov024_021da404(int a, int id, int b, int c, int d, int arg5) {
	int var0 = (unsigned int)id <= 3;
	if (!var0) {
		return arg5;
	}
	GameState* battleStruct = GameState::GetInstance();
	GameObject* combatant = func_0200ff1c(battleStruct, id);
	if (!combatant) {
		return arg5;
	}
	struct Struct_ov024_021da404* fieldPtr = (struct Struct_ov024_021da404*)func_02053c6c((unsigned char*)combatant);
	if (fieldPtr) {
		unsigned int v = fieldPtr->val;
		int var5 = (int)((float)v * 0.25f);
		arg5 = var5 + arg5 / 2;
	}
	return arg5;
}
