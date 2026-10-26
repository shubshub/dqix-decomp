#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" float func_ov024_021db358(GameObject* obj);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021fecfc { short v[8]; };
extern struct Struct_ov024_021fecfc data_ov024_021fecfc;

struct Struct_ov024_021f286c { char pad[0x2c]; short unknown_2c_; };
struct Struct_ov024_021f286c_2 { int field0; };

// USA: func_ov024_021f286c
extern "C" ARM int func_ov024_021f286c(Struct_ov024_021f286c_2* obj, int id, int unused, int* outCount, short* arg4) {
	GameObject* self = func_ov000_021536f8(obj->field0, id);
	if (!self) return 0;
	if (func_ov024_021db358(self) < 0.5f) return 0;

	struct Struct_ov024_021fecfc buf = data_ov024_021fecfc;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (id == buf.v[i]) continue;
		GameObject* member = GetCombatantByID(obj->field0, buf.v[i]);
		if (!member) continue;
		if (((Struct_ov024_021f286c*)member->currentStats_)->unknown_2c_ >= 0) continue;
		if (func_ov024_021db358(member) >= 0.5f) continue;
		int n = *outCount;
		*outCount = n + 1;
		arg4[n] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	func_ov024_021ed890((struct Random**)obj, outCount, arg4);
	return 1;
}
