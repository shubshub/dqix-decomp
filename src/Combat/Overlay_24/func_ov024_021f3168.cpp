#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
struct Struct_ov024_021ed9dc;
extern "C" int func_ov024_021ed9dc(struct Struct_ov024_021ed9dc* holder, int id);

extern unsigned short data_ov024_021fed8c;

struct Struct_ov024_021f3168 {
	signed int unknown_0_0_ : 3;
	signed int unknown_0_3_ : 3;
	signed int unknown_0_6_ : 3;
	signed int unknown_1_1_ : 3;
	signed int unknown_1_4_ : 3;
	signed int unknown_1_7_ : 3;
	signed int unknown_2_2_ : 3;
	signed int unknown_2_5_ : 3;
};

// USA: func_ov024_021f3168
extern "C" ARM int func_ov024_021f3168(int* a0, int id, int a2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(*a0, id);
	if (!c) return 0;
	if (((struct Struct_ov024_021f3168*)((char*)c->currentStats_ + 0x58))->unknown_2_2_ >= 2) return 0;

	unsigned short buf[8];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021fed8c;
	int n = 8;
	do {
		unsigned short* var5 = d++;
		*var5 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;

	int found = 0;
	for (int i = 0; i < count; i++) {
		if (func_ov024_021ed9dc((struct Struct_ov024_021ed9dc*)a0, *(short*)&buf[i])) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;
	*outFlag = 1;
	*arg4 = (short)id;
	return 1;
}
