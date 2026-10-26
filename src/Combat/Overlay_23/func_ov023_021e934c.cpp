#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_0201081c(char* obj);
extern "C" void func_ov017_021d6134(void* obj, int v);

// USA: func_ov023_021e934c
extern "C" ARM int func_ov023_021e934c(void* obj) {
	GameState* bs = GameState::GetInstance();
	int v = func_0201081c((char*)bs);
	func_ov017_021d6134(obj, v);
	return 1;
}
