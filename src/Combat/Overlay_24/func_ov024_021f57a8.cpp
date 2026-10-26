#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int battle, short* buf, int max, int start);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021feb1c { short v[4]; };
extern struct Struct_ov024_021feb1c data_ov024_021feb1c;

// USA: func_ov024_021f57a8
extern "C" ARM int func_ov024_021f57a8(int* a0, int a1, int a2, int* outCount, short* arg4) {
	struct Struct_ov024_021feb1c buf = data_ov024_021feb1c;
	int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
	if (count <= 0) {
		return 0;
	}

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf.v[i]);
		if (!c) continue;
		if (*((unsigned char*)c->currentStats_ + 0x24) == 0) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		arg4[idx] = buf.v[i];
	}
	if (*outCount <= 0) {
		return 0;
	}
	func_ov024_021ed890((struct Random**)a0, outCount, arg4);
	return 1;
}
