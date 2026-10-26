#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
extern "C" int func_020882f8(unsigned char* obj);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);
struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021fedec { short v[8]; };
extern struct Struct_ov024_021fedec data_ov024_021fedec;

// USA: func_ov024_021f36cc
extern "C" ARM int func_ov024_021f36cc(int* a0, int arg1, int a2, int* outCount, short* arg4) {
	struct Struct_ov024_021fedec buf = data_ov024_021fedec;

	int count = func_ov000_0215eb1c(*a0, buf.v, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		if (arg1 == buf.v[i]) continue;
		GameObject* member = GetCombatantByID(*a0, buf.v[i]);
		if (!member) continue;
		if (func_020882f8((unsigned char*)member->currentStats_)) continue;
		if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)member)) continue;
		if (func_ov024_021de25c((struct Struct_ov024_021de124*)member)) continue;
		if (func_ov024_021da9c8((struct Struct_ov024_021da670_8*)member)) continue;
		if (func_ov024_021dd260((struct Struct_ov024_021dd028_5*)member)) continue;
		int idx = *outCount;
		*outCount = idx + 1;
		arg4[idx] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	func_ov024_021ed890((struct Random**)a0, outCount, arg4);
	return 1;
}
