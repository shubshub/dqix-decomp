#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_0215f1b0
extern "C" ARM int func_ov001_0215f1b0(void* self) {
	GameState::GetInstance();
	GameResources* p = GetGameResources();
	int a = func_ov017_021d60f4(self);
	int b = func_ov017_021d60f4((char*)self + 0x8);
	if (b != 0) {
		SetFlags04(p, a);
	} else {
		ClearFlags04(p, a);
	}
	return 1;
}
