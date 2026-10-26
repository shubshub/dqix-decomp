#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021f5c80 {
	int field0;
};

// USA: func_ov024_021f5c80
extern "C" ARM int func_ov024_021f5c80(struct Struct_ov024_021f5c80* a, int id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (c->currentStats_->attackBuff >= 2 && c->currentStats_->defenseBuff >= 2 && c->currentStats_->agilityBuff >= 2) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*arg4 = (short)id;
	}
	return result;
}
