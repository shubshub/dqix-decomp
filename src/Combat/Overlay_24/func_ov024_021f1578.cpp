#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
struct Struct_ov024_021f1330;
extern "C" int func_ov024_021f1440(struct Struct_ov024_021f1330* obj);
extern "C" int func_ov000_0215eb1c(int a, short* buf, int max, int start);

struct Struct_ov024_021f1578 { int field0; };
struct Struct_ov024_021fef5c { short v[8]; };
extern struct Struct_ov024_021fef5c data_ov024_021fef5c;

struct Struct_ov024_021f1578_2 {
    signed int unknown_0_0_ : 3;
    signed int unknown_0_3_ : 3;
    signed int unknown_0_6_ : 3;
    signed int unknown_1_1_ : 3;
    signed int unknown_1_4_ : 3;
    signed int unknown_1_7_ : 3;
    signed int unknown_2_2_ : 3;
    signed int unknown_2_5_ : 3;
};

// USA: func_ov024_021f1578
extern "C" ARM int func_ov024_021f1578(struct Struct_ov024_021f1578* obj, short id, int arg2, int* outCount, void* arg4) {
	GameObject* c0 = func_ov000_021536f8(obj->field0, id);
	if (!c0) return 0;
	if (!func_ov024_021f1440((struct Struct_ov024_021f1330*)c0)) return 0;

	struct Struct_ov024_021fef5c buf = data_ov024_021fef5c;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;

	int found = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		struct Struct_ov024_021f1578_2* var6 = (struct Struct_ov024_021f1578_2*)((char*)c->currentStats_ + 0x58);
		if (var6->unknown_2_5_ < 2) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;

	*outCount = count;
	memcpy(arg4, buf.v, 0x10);
	return 1;
}
