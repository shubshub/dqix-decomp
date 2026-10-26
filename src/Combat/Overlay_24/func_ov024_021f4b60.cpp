#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);
struct Struct_020885b4;
struct Struct_02088514;
extern "C" int func_020885b4(struct Struct_020885b4* c);
extern "C" int func_02088514(struct Struct_02088514* s);

struct Struct_ov024_021feb4c { short v[4]; };
extern struct Struct_ov024_021feb4c data_ov024_021feb4c;

struct Struct_ov024_021f4b60 { char pad[0x4d]; unsigned char unknown_4d_; };

// USA: func_ov024_021f4b60
extern "C" ARM int func_ov024_021f4b60(int* a0, int a1, int a2, int* outCount, short* arg4) {
	struct Struct_ov024_021feb4c buf = data_ov024_021feb4c;
	int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, buf.v[i]);
		if (!member) continue;
		if (func_020885b4((struct Struct_020885b4*)member->currentStats_)) continue;
		if (func_02088514((struct Struct_02088514*)member->currentStats_)) continue;
		int value = ((Struct_ov024_021f4b60*)member->currentStats_)->unknown_4d_;
		if (value <= 0) continue;
		int n = *outCount;
		*outCount = n + 1;
		arg4[n] = buf.v[i];
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(arg4, &buf, 8);
	return 1;
}
