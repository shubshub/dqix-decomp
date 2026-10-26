#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
struct Struct_ov024_021ed9dc;
extern "C" int func_ov024_021ed9dc(struct Struct_ov024_021ed9dc* holder, int id);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021f0a20 { int battle; };
struct Struct_ov024_021fee5c { short v[8]; };
extern struct Struct_ov024_021fee5c data_ov024_021fee5c;

// USA: func_ov024_021f0a20
extern "C" ARM int func_ov024_021f0a20(struct Struct_ov024_021f0a20* obj, int unused1, int arg2, int* outCount, short* arg4) {
	int found = 0;
	struct Struct_ov024_021fee5c buf = data_ov024_021fee5c;
	int count = func_ov000_0215e9fc(obj->battle, buf.v, 4, 1);
	if (count <= 0) return 0;

	for (int i = 0; i < count; i++) {
		if (func_ov024_021ed9dc((struct Struct_ov024_021ed9dc*)obj, buf.v[i])) {
			found = 1;
			break;
		}
	}
	if (!found) return 0;

	memset(&buf, -1, sizeof(buf));
	count = func_ov000_0215eb1c(obj->battle, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->battle, buf.v[i]);
		if (!c) continue;
		if (c->currentStats_->unknown_5a_2_ >= 2) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		arg4[idx] = buf.v[i];
	}

	if (*outCount <= 0) return 0;
	func_ov024_021ed890((struct Random**)obj, outCount, arg4);
	return 1;
}
