#include <globaldefs.h>
#include "Util/Random.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021f3c3c { int field0; };
struct Struct_ov024_021feeac { short v[8]; };
extern struct Struct_ov024_021feeac data_ov024_021feeac;

static inline unsigned short inline_ov024_021f3c3c(GameObject* c) { return c->currentStats_->primaryStats.maxMP; }

// USA: func_ov024_021f3c3c
extern "C" ARM int func_ov024_021f3c3c(struct Struct_ov024_021f3c3c* obj, int id, int unused, int* outCount, short* arg4) {
	GameObject* self = func_ov000_021536f8(obj->field0, id);
	if (!self) return 0;
	if (self->currentStats_->primaryStats.currMP == 0) return 0;
	struct Struct_ov024_021feeac buf = data_ov024_021feeac;
	int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
	if (count <= 0) return 0;
	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (id == buf.v[i]) continue;
		GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
		if (!c) continue;
		unsigned short maxMP = inline_ov024_021f3c3c(c);
		if ((float)c->currentStats_->primaryStats.currMP / (float)maxMP >= 1.0f) continue;
		arg4[(*outCount)++] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	func_ov024_021ed890((struct Random**)obj, outCount, arg4);
	return 1;
}
