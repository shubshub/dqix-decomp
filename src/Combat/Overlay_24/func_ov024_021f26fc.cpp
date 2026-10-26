#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
struct Struct_ov024_021f26fc;
extern "C" int func_ov024_021f273c(struct Struct_ov024_021f26fc* obj);

struct Struct_ov024_021f26fc_2 { int field0; };

// USA: func_ov024_021f26fc
extern "C" ARM int func_ov024_021f26fc(struct Struct_ov024_021f26fc_2* a, int id, int arg2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(a->field0, id);
	if (!c) return 0;
	int result;
	if (func_ov024_021f273c((struct Struct_ov024_021f26fc*)c)) {
		result = 0;
	} else {
		result = 1;
		*arg4 = (short)id;
		*outFlag = result;
	}
	return result;
}
