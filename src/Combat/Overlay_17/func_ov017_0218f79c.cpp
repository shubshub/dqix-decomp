#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_02191fec(void* obj, int idx);
extern "C" void func_ov017_0218f80c(void* obj, int idx);

// USA: func_ov017_0218f79c
extern "C" ARM void func_ov017_0218f79c(void* obj) {
	GameState* battle = GameState::GetInstance();
	int i;
	for (i = 0; i < 4; i++) {
		if (battle->GetGameObjectByIndex(i) != NULL) {
			int flag = func_ov017_02191fec(obj, i) ? 1 : 0;
			if (flag) {
				func_ov017_0218f80c(obj, i);
			}
		}
	}
}
