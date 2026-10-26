#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
struct Struct_ov024_021df454_2;
extern "C" int func_ov024_021df6ec(struct Struct_ov024_021df454_2* obj);
struct Struct_ov024_021dced0_2;
extern "C" int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj);

struct Struct_ov024_021f3564 {
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

struct Struct_ov024_021f3564_2 { int field0; };

// USA: func_ov024_021f3564
extern "C" ARM int func_ov024_021f3564(struct Struct_ov024_021f3564_2* a, int id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int n = 0;
	if (func_020885b4((struct Struct_020885b4*)c->currentStats_)) n++;
	if (func_02088514((struct Struct_02088514*)c->currentStats_)) n++;
	if (func_ov024_021df6ec((struct Struct_ov024_021df454_2*)c)) n++;
	if (func_ov024_021dd010((struct Struct_ov024_021dced0_2*)c)) n++;
	struct Struct_ov024_021f3564* var2 = (struct Struct_ov024_021f3564*)((char*)c->currentStats_ + 0x58);
	if (var2->unknown_0_0_ < 0) n++;
	if (var2->unknown_0_3_ < 0) n++;
	if (var2->unknown_0_6_ < 0) n++;
	if (var2->unknown_1_1_ < 0) n++;
	if (var2->unknown_1_4_ < 0) n++;
	if (var2->unknown_1_7_ < 0) n++;
	if (var2->unknown_2_2_ < 0) n++;
	if (var2->unknown_2_5_ < 0) n++;
	if (var2->unknown_3_3_ < 0) n++;
	if (var2->unknown_3_0_ < 0) n++;
	int result;
	if (n <= 0) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*arg4 = (short)id;
	}
	return result;
}
