#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" void func_ov017_021d6134(void*, int);
unsigned char GameState_GetLeaderIndex(GameState* battleStruct);

// USA: func_ov001_02161930
ARM int ForwardCombatantOrFallback_02161930(void* self) {
#if defined(jpn)
    enum { queueOffset = 0x524, idOffset = 0x12 };
#else
    enum { queueOffset = 0x734, idOffset = 0x16 };
#endif
	GameState* battle = GameState::GetInstance();
	char* p = (char*)GetGameResources() + 0x3000;
	char* table = *(char**)(p + queueOffset) + 0x100;
	int cid = *(signed char*)(table + idOffset);
	GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, cid);
	int n = cid;
	if (c == NULL) {
		n = GameState_GetLeaderIndex(battle);
	}
	func_ov017_021d6134(self, n);
	return 1;
}
