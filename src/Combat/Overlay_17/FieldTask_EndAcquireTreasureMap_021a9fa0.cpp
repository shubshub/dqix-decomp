#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" ARM unsigned short* Zone3D_GetInstance(void);
ARM int GetFieldIfFlag4_020100f8(char* obj);
ARM void SetField0x23cTrue_020a27ac(void* obj);
ARM int IsValueInRange0201b5d8(int x);
ARM void InitContext020e1154(void* obj);

// Overlay 17, originally func_ov017_021a9fa0 (USA/EUR 0x021a9fa0, JPN 0x021aa810)
extern "C" ARM void FieldTask_EndAcquireTreasureMap(void* obj) {
	GameState* battle = GameState::GetInstance();
	((int)GetGameResources());
	unsigned short* w = Zone3D_GetInstance();
	SetField0x23cTrue_020a27ac((void*)GetFieldIfFlag4_020100f8((char*)battle));
	if (IsValueInRange0201b5d8(*w))
		InitContext020e1154((void*)0x3e8);
	((unsigned char*)obj)[1] = 1;
}
