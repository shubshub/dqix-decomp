#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" ARM unsigned short* Zone3D_GetInstance(void);
extern "C" ARM int GameState_GetFollowCamera(char* obj);
extern "C" ARM void func_020a27ac(void* obj);
extern "C" ARM int ZoneId_IsGrottoBossFloor(int x);
extern "C" ARM void func_020e1154(void* obj);

// Overlay 17, originally func_ov017_021a9fa0 (USA/EUR 0x021a9fa0, JPN 0x021aa810)
extern "C" ARM void FieldTask_EndAcquireTreasureMap(void* obj) {
	GameState* battle = GameState::GetInstance();
	((int)GetGameResources());
	unsigned short* w = Zone3D_GetInstance();
	func_020a27ac((void*)GameState_GetFollowCamera((char*)battle));
	if (ZoneId_IsGrottoBossFloor(*w))
		func_020e1154((void*)0x3e8);
	((unsigned char*)obj)[1] = 1;
}
