#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_0204359c(void* obj, int count);
extern "C" void func_020439b0(int a, int b);

// USA: func_ov017_021a9638
extern "C" ARM void func_ov017_021a9638(void*) {
	GameState* b = GameState::GetInstance();
	int x = MessageSystem_GetInstance();
	unsigned int y = b->GetTickCount();
	func_0204359c((void*)x, y);
	func_020439b0(x, 0);
}
