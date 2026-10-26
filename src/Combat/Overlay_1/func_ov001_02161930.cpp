#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void*, int);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);

// USA: func_ov001_02161930
extern "C" ARM int func_ov001_02161930(void* self) {
#if defined(jpn)
    enum { Enum_ov001_02161930_1844 = 0x524, Enum_ov001_02161930_22 = 0x12 };
#else
    enum { Enum_ov001_02161930_1844 = 0x734, Enum_ov001_02161930_22 = 0x16 };
#endif
	GameState* battle = GameState::GetInstance();
	char* p = (char*)GetGameResources() + 0x3000;
	char* table = *(char**)(p + Enum_ov001_02161930_1844) + 0x100;
	int cid = *(signed char*)(table + Enum_ov001_02161930_22);
	GameObject* c = func_0200ff1c(battle, cid);
	int n = cid;
	if (c == NULL) {
		n = GameState_GetLeaderIndex(battle);
	}
	func_ov017_021d6134(self, n);
	return 1;
}
