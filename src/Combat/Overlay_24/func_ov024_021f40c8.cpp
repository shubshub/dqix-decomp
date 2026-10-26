#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021f40c8 {
    signed int unknown_0_0_:3;
    signed int w1:3;
    signed int w2:3;
    signed int unknown_1_1_:3;
    signed int w4:3;
    signed int unknown_1_7_:3;
    signed int unknown_2_2_:3;
    signed int unknown_2_5_:3;
    signed int w8:3;
    signed int unknown_3_3_:3;
    signed int pad:2;
};

// USA: func_ov024_021f40c8
extern "C" ARM int func_ov024_021f40c8(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = func_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	struct Struct_ov024_021f40c8* w = (struct Struct_ov024_021f40c8*)((char*)c->currentStats_ + 0x58);
	if (w->w4 >= 2 || w->unknown_1_7_ >= 2) return 0;
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
