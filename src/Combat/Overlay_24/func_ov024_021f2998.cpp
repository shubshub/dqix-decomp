#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov024_021edf00(int* a0, int a1, short* a2);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" void func_ov024_021ed8c0(void* context, int id, int arg2, int* count, short* ids);

struct Struct_ov024_021e05e4 { char unk[0x18]; int flags; };
struct Struct_ov024_021e04e0 { char unk[0x138]; struct Struct_ov024_021e05e4* inner; };
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj);

struct Struct_ov024_021f2998 { char unk[0x2e]; short unknown_2e_; };

extern unsigned short data_ov024_021fea4c;

// USA: func_ov024_021f2998
extern "C" ARM int func_ov024_021f2998(int* a0, int a1, int a2, int* a3, short* a4) {
	short buf[4];
	short* d = buf;
	unsigned short* s = &data_ov024_021fea4c;
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
		if (c && func_ov024_021e05e4((struct Struct_ov024_021e04e0*)c)
			&& a1 != ((struct Struct_ov024_021f2998*)c->currentStats_)->unknown_2e_) {
			int idx = *a3;
			*a3 = idx + 1;
			a4[idx] = buf[i];
		}
	}
	if (*a3 <= 0) return 0;

	func_ov024_021ed8c0(a0, a1, a2, a3, a4);
	return 1;
}
