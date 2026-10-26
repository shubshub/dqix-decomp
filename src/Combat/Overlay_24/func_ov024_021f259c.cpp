#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int arg2, int* count, short* ids);

struct Struct_ov024_021da9c8 { char unk[0x14]; int flags; };
struct Struct_ov024_021da670_8 { char unk[0x138]; struct Struct_ov024_021da9c8* inner; };
extern "C" int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj);

extern unsigned short data_ov024_021febd4;

// USA: func_ov024_021f259c
extern "C" ARM int func_ov024_021f259c(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021febd4;
	int n = 4;
	do {
		short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov024_021edf00(a0, a1, buf);
	if (count <= 0) {
		count = func_ov000_0215e9fc(*a0, buf, 4, 1);
		if (count <= 0) return 0;
	}

	*a3 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(*a0, buf[i]);
		if (c && !func_ov024_021da9c8((struct Struct_ov024_021da670_8*)c)) {
			int idx = *a3;
			*a3 = idx + 1;
			a4[idx] = buf[i];
		}
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return 1;
}
