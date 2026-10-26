#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
struct Struct_ov024_021e04e0;
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj);
struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(struct Struct_ov024_021da670_6* obj);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);
extern "C" void func_ov024_021ed8c0(void* context, int id, int arg2, int* count, short* ids);

struct Struct_ov024_021f2ab4 { char pad0[0x2e]; short targetId; };

extern unsigned short data_ov024_021feb5c;

// USA: func_ov024_021f2ab4
extern "C" ARM int func_ov024_021f2ab4(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = func_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	if (func_ov024_021e05e4((struct Struct_ov024_021e04e0*)c)) {
		GameObject* target = GetCombatantByID(*a0, ((struct Struct_ov024_021f2ab4*)c->currentStats_)->targetId);
		if (target && !func_02010088((struct S_10088*)target)) {
			*a3 = 1;
			a4[0] = ((struct Struct_ov024_021f2ab4*)c->currentStats_)->targetId;
			return 1;
		}
	}

	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021feb5c;
	int n = 4;
	do {
		short* var6 = d++;
		*var6 = *s++;
	} while (--n);

	int count = func_ov024_021edf00(a0, a1, buf);
	if (count <= 0) {
		count = func_ov000_0215e9fc(*a0, buf, 4, 1);
		if (count <= 0) return 0;
	}

	*a3 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* m = GetCombatantByID(*a0, buf[i]);
		if (m && (func_ov024_021da998((struct Struct_ov024_021da670_6*)m) || func_ov024_021dd260((struct Struct_ov024_021dd028_5*)m))) {
			int idx = *a3;
			*a3 = idx + 1;
			a4[idx] = buf[i];
		}
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return 1;
}
