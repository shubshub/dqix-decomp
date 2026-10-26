#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021f6230 {
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

struct Struct_ov024_021f6230_2 { char pad[8]; unsigned short field8; char pad2[0x4e]; struct Struct_ov024_021f6230 unknown_58_; };

// USA: func_ov024_021f6230
#pragma optimize_for_size off
extern "C" ARM int func_ov024_021f6230(int* a0, int a1, int a2, int* a3, short* a4) {
	GameObject* c = func_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	struct Struct_ov024_021f6230_2* s = (struct Struct_ov024_021f6230_2*)c->currentStats_;
	if (s->field8 >= 0xffff) goto fail;
	if (s->unknown_58_.unknown_0_0_ < 2) goto success;
fail:
	return 0;
success:
	*a3 = 1;
	*a4 = (short)a1;
	return 1;
}
