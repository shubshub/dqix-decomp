#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
int MessageSystem_GetInstance();

// USA: func_ov017_021acce4
extern "C" ARM void func_ov017_021acce4(void*, void*) {
	GameState::GetInstance();
	LinkSession_GetInstance();
	GetGameResources();
	MessageSystem_GetInstance();
}
