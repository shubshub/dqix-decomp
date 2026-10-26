#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);

struct Struct_ov024_021f3524 { int field0; };

// USA: func_ov024_021f3524
extern "C" ARM int func_ov024_021f3524(struct Struct_ov024_021f3524* a, int id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (func_ov024_021dd260((struct Struct_ov024_021dd028_5*)c)) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*arg4 = (short)id;
	}
	return result;
}
