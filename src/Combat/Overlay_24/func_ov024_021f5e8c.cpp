#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

extern unsigned short data_ov024_021fea74;

// USA: func_ov024_021f5e8c
extern "C" ARM int func_ov024_021f5e8c(int* a0, int a1, int a2, int* outCount, short* arg4) {
	unsigned short buf[4];
	unsigned short* s = &data_ov024_021fea74;
	unsigned short* d = buf;
	int n = 4;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
		if (!member) continue;
		if (func_ov024_021de25c((struct Struct_ov024_021de124*)member)) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		arg4[idx] = *((short*)buf + i);
	}
	if (*outCount > 0) {
		func_ov024_021ed890((struct Random**)a0, outCount, arg4);
		return 1;
	}
	return 0;
}
