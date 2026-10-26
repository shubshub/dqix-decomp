#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);
extern "C" void func_ov017_0219bcac(unsigned char flag);
extern "C" int* func_020936f8(void);
extern "C" void func_02094030(int*, short, short, signed char);

// USA: func_ov017_0219bf04
extern "C" ARM void func_ov017_0219bf04(unsigned char flag, int mode) {
#if defined(jpn)
 enum {regionalOffset0=0x4200, regionalOffset1=0x2};
#else
 enum {regionalOffset0=0x4400, regionalOffset1=0xb2};
#endif
	GameState* battleStruct = GameState::GetInstance();
	GameResources* ov = GetGameResources();
	func_ov017_0219bcac(flag);
	char* obj = (char*)GameState_GetZoneTransition(battleStruct);
	obj[0x6e] = 1;
	obj[0xa] = 0;
	obj[0x67] = 1;
	if (mode == 0) {
		*(short*)((char*)ov + regionalOffset0 + regionalOffset1) = 0x4e23;
		return;
	}
	int* g = func_020936f8();
	func_02094030(g, 0x4e23, -1, 0);
}
