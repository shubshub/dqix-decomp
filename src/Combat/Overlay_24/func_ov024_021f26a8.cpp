#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);

struct Struct_ov024_021eda78_2;
extern "C" int func_ov024_021edca4(struct Struct_ov024_021eda78_2* obj);

struct Struct_ov024_021eda78;
extern "C" int func_ov024_021edc80(struct Struct_ov024_021eda78* obj);

// USA: func_ov024_021f26a8
extern "C" ARM int func_ov024_021f26a8(int* p0, short id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(*p0, id);
	if (!c) return 0;
	if (func_ov024_021edca4((struct Struct_ov024_021eda78_2*)c)) return 0;
	if (func_ov024_021edc80((struct Struct_ov024_021eda78*)c)) return 0;
	*arg4 = id;
	*outFlag = 1;
	return 1;
}
