#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(void* obj);
struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);

extern unsigned short data_ov024_021fec3c;

struct Struct_ov024_021f43b0 { int field0; };

// USA: func_ov024_021f43b0
extern "C" ARM int func_ov024_021f43b0(struct Struct_ov024_021f43b0* obj, int a1, int a2, int* outCount, short* arg4) {
	short buf[4];
	unsigned short* d = (unsigned short*)buf;
	unsigned short* s = &data_ov024_021fec3c;
	int n = 4;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(obj->field0, (unsigned short*)buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(obj)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf[i]);
		if (!c) continue;
		if (func_020885b4((struct Struct_020885b4*)c->currentStats_)) continue;
		int n2 = *outCount;
		*outCount = n2 + 1;
		arg4[n2] = buf[i];
	}
	if (*outCount <= 0) return 0;
	*outCount = count;
	memcpy(arg4, buf, 8);
	return 1;
}
