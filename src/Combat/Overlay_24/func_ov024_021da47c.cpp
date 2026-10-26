#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern unsigned short data_ov024_021fe6c8;

// USA: func_ov024_021da47c
extern "C" ARM int func_ov024_021da47c(int* a0, unsigned short category, int unused1, int arg3, int arg4, int arg5) {
	int inRange = (category <= 3) ? 1 : 0;
	if (!inRange) {
		return arg5;
	}

	GameState* battle = GameState::GetInstance();

	int sum = 0;
	unsigned short buf[4];
	unsigned short* s = &data_ov024_021fe6c8;
	unsigned short* d = buf;
	int n = 4;
	do {
		unsigned short* var7 = d++;
		*var7 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	for (int i = 0; i < count; i++) {
		GameObject* c = func_0200ff1c(battle, *(short*)&buf[i]);
		if (c) {
			sum += c->currentStats_->primaryStats.attack;
		}
	}

	float var11 = NextRandomFloatBetween(*(struct Random**)a0, 0.95f, 1.5f);
	return (int)(sum * var11);
}
