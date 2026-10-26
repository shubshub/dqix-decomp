#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int func_020882f8(unsigned char* obj);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021fee0c { short v[8]; };
extern struct Struct_ov024_021fee0c data_ov024_021fee0c;

// USA: func_ov024_021f37fc
extern "C" ARM int func_ov024_021f37fc(int* a0, int a1, int a2, int* outCount, short* arg4) {
	struct Struct_ov024_021fee0c buf = data_ov024_021fee0c;

	int count = func_ov000_0215eb1c(*a0, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf.v[i]);
		if (!c) continue;
		if (func_020882f8((unsigned char*)c->currentStats_) || func_ov024_021de25c((struct Struct_ov024_021de124*)c)) {
			int idx = *outCount;
			*outCount = idx + 1;
			arg4[idx] = buf.v[i];
		}
	}
	if (*outCount > 0) {
		func_ov024_021ed890((struct Random**)a0, outCount, arg4);
		return 1;
	}
	return 0;
}
