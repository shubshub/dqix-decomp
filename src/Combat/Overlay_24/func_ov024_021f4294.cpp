#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);
extern "C" int func_020882f8(unsigned char* obj);

struct Struct_ov024_021f4294 { char unk[0x47]; unsigned char unknown_47_; };

extern unsigned short data_ov024_021fec44;

// USA: func_ov024_021f4294
extern "C" ARM int func_ov024_021f4294(int* a0, int a1, int a2, int* outCount, short* arg4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fec44;
	int n = 4;
	do {
		short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (func_020882f8((unsigned char*)c->currentStats_)) continue;
		int value = ((struct Struct_ov024_021f4294*)c->currentStats_)->unknown_47_;
		if (value <= 0) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		arg4[idx] = buf[i];
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(arg4, buf, 8);
	return 1;
}
