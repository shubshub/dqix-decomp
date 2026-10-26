#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

// USA: func_ov024_021f331c
extern "C" ARM int func_ov024_021f331c(int* p0, short id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (c->currentStats_->magicalMightBuff >= 2) {
		return 0;
	} else {
		*outFlag = 1;
		*arg4 = id;
		return 1;
	}
}
