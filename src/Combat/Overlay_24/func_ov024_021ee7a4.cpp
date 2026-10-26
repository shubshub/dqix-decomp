#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_ov024_021eda60(GameObject* combatant);
extern "C" float func_ov024_021db358(GameObject* obj);

struct Struct_ov024_021ee7a4 { int field0; };
struct Struct_ov024_021fecac { short v[8]; };
extern struct Struct_ov024_021fecac data_ov024_021fecac;

// USA: func_ov024_021ee7a4
extern "C" ARM int func_ov024_021ee7a4(struct Struct_ov024_021ee7a4* obj, int unused1, int arg2, int* outCount, short* arg4) {
	struct Struct_ov024_021fecac buf = data_ov024_021fecac;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;
	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		if (func_ov024_021eda60(c)) continue;
		if (func_ov024_021db358(c) >= 0.5f) continue;
		arg4[*outCount] = buf.v[i];
		*outCount = *outCount + 1;
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;
	*outCount = count;
	memcpy(arg4, buf.v, 0x10);
	return 1;
}
