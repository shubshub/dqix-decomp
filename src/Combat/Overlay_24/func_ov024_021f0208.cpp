#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021feddc { short v[8]; };
extern struct Struct_ov024_021feddc data_ov024_021feddc;

// USA: func_ov024_021f0208
extern "C" ARM int func_ov024_021f0208(int* a0, int a1, int a2, int* outCount, short* arg4) {
	struct Struct_ov024_021feddc buf = data_ov024_021feddc;

	int count = func_ov000_0215eb1c(*a0, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, buf.v[i]);
		if (!member) continue;
		if (member->currentStats_->primaryStats.attack >= 0xffff) continue;
		if (member->currentStats_->attackBuff >= 2) continue;
		if (func_ov024_021eda60(member)) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		arg4[idx] = buf.v[i];
	}
	if (*outCount > 0) {
		func_ov024_021ed890((struct Random**)a0, outCount, arg4);
		return 1;
	}
	return 0;
}
