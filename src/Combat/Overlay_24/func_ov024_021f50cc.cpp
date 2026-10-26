#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);

struct Struct_ov024_021f50cc { int field0; };
extern unsigned short data_ov024_021feabc;

// USA: func_ov024_021f50cc
extern "C" ARM int func_ov024_021f50cc(struct Struct_ov024_021f50cc* obj, int unused1, int arg2, int* outCount, void* arg4) {
	short buf[4];
	unsigned short* d = (unsigned short*)buf;
	unsigned short* s = &data_ov024_021feabc;
	int n = 4;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(obj->field0, buf, 4, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf[i]);
		if (c && c->currentStats_->primaryStats.agility != 0 && c->currentStats_->agilityBuff > -2) {
			((short*)arg4)[(*outCount)++] = buf[i];
		}
	}
	if (*outCount <= 0) return 0;
	if (*outCount * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(arg4, buf, 8);
	return 1;
}
