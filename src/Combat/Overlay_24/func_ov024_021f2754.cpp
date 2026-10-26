#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021f2754 { int field0; };
struct Struct_ov024_021feccc { short v[8]; };
extern struct Struct_ov024_021feccc data_ov024_021feccc;

// USA: func_ov024_021f2754
extern "C" ARM int func_ov024_021f2754(struct Struct_ov024_021f2754* obj, int arg1, int unused, int* outCount, short* arg4) {
	GameObject* self = func_ov000_021536f8(obj->field0, arg1);
	if (!self) return 0;
	if (func_ov024_021db358(self) < 0.5f) return 0;
	struct Struct_ov024_021feccc buf = data_ov024_021feccc;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;
	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (arg1 == buf.v[i]) continue;
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		if (*(short*)((char*)c->currentStats_ + 0x2c) >= 0) continue;
		int n = *outCount;
		*outCount = n + 1;
		arg4[n] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	func_ov024_021ed890((struct Random**)obj, outCount, arg4);
	return 1;
}
