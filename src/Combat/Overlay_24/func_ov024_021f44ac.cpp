#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);

struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);

struct Struct_ov024_021f44ac { char pad[0x4d]; unsigned char unknown_4d_; };

extern unsigned short data_ov024_021fea94;

// USA: func_ov024_021f44ac
extern "C" ARM int func_ov024_021f44ac(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fea94;
	int n = 4;
	do {
		short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, (unsigned short*)buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*a3 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (!c) continue;
		if (func_020885b4((struct Struct_020885b4*)c->currentStats_)) continue;
		short level = ((struct Struct_ov024_021f44ac*)c->currentStats_)->unknown_4d_;
		if (level <= 0) continue;
		int idx = *a3;
		*a3 = idx + 1;
		a4[idx] = buf[i];
	}
	if (*a3 <= 0) return 0;
	if (*a3 * 3 < count * 2) return 0;

	*a3 = count;
	memcpy(a4, buf, 8);
	return 1;
}
