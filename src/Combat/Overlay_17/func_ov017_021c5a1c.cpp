#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" GameObject* func_ov017_021a278c(void* unused, int val);

// USA: func_ov017_021c5a1c
extern "C" ARM int func_ov017_021c5a1c(int val) {
	if (val < 0x8000)
		goto skip;
	if (val <= 0x8004)
		return 1;
skip:
	if (val < 1)
		return 0;
	if (val > 0x7fff)
		return 0;
	GameState::GetInstance();
	void* p = GetGameResources();
	if (p == NULL)
		return 0;
	return func_ov017_021a278c(p, val) != NULL;
}
