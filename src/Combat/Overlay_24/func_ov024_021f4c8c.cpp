#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021ede2c(int* a0);
struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

extern unsigned short data_ov024_021febb4;

// USA: func_ov024_021f4c8c
extern "C" ARM int func_ov024_021f4c8c(int* a0, int a1, int a2, int* outCount, void* arg4) {
	unsigned short buf[4];
	unsigned short* d = buf;
	unsigned short* s = &data_ov024_021febb4;
	int n = 4;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
	if (count <= 0) return 0;
	if (!func_ov024_021ede2c(a0)) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
		if (member && !func_ov024_021da9b0((struct Struct_ov024_021da670_7*)member)) {
			*outCount = *outCount + 1;
		}
	}
	if (*outCount <= 0) return 0;

	*outCount = count;
	memcpy(arg4, buf, 8);
	return 1;
}
