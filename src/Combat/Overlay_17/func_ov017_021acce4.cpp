#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* func_0202ae18(void);
int MessageSystem_GetInstance();

// USA: func_ov017_021acce4
extern "C" ARM void func_ov017_021acce4(void*, void*) {
	GameState::GetInstance();
	func_0202ae18();
	GetGameResources();
	MessageSystem_GetInstance();
}
