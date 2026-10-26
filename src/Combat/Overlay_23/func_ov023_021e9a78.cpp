#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021e9a78
extern "C" ARM int func_ov023_021e9a78(void* obj) {
	GameState* bs = GameState::GetInstance();
	void* p = GameState_GetParty(bs);
	int v = *(int*)((char*)p + 0xf68);
	func_ov017_021d6134(obj, v);
	return 1;
}
