#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021eda78_6;
extern "C" int func_ov024_021edc20(struct Struct_ov024_021eda78_6* obj);

struct Struct_ov024_021eda78_7;
extern "C" int func_ov024_021edc38(struct Struct_ov024_021eda78_7* obj);

// USA: func_ov024_021f2548
extern "C" ARM int func_ov024_021f2548(int* p0, short id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (func_ov024_021edc20((struct Struct_ov024_021eda78_6*)c)) return 0;
	if (func_ov024_021edc38((struct Struct_ov024_021eda78_7*)c)) return 0;
	*arg4 = id;
	*outFlag = 1;
	return 1;
}
