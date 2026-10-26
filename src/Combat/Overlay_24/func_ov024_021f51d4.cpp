#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021f51d4 {
	signed int unknown_0_0_ : 3;
	signed int unknown_0_3_ : 3;
	signed int unknown_0_6_ : 3;
	signed int unknown_1_1_ : 3;
	signed int unknown_1_4_ : 3;
	signed int unknown_1_7_ : 3;
	signed int unknown_2_2_ : 3;
	signed int unknown_2_5_ : 3;
	signed int unknown_3_0_ : 3;
	signed int unknown_3_3_ : 3;
};

// USA: func_ov024_021f51d4
extern "C" ARM int func_ov024_021f51d4(int* p0, short id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(*p0, id);
	if (!c) return 0;
	struct Struct_ov024_021f51d4* var1 = (struct Struct_ov024_021f51d4*)((char*)c->currentStats_ + 0x58);
	if (var1->unknown_3_3_ >= 2) {
		return 0;
	} else {
		*outFlag = 1;
		*arg4 = id;
		return 1;
	}
}
