#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_ov003_0216d7ec(char* obj);

// USA: func_ov003_0217f194
extern "C" ARM void func_ov003_0217f194(char* obj) {
	GameState::GetInstance();
	GetGameResources();
	char* p = *(char**)(obj + 0xc);
	if (p != 0) func_ov003_0216d7ec(p);
}
