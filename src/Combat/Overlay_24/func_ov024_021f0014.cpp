#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021f0014 { int field0; };
extern unsigned short data_ov024_021fea64;

// USA: func_ov024_021f0014
extern "C" ARM int func_ov024_021f0014(struct Struct_ov024_021f0014* obj, int unused1, int arg2, int* outCount, void* arg4) {
	short buf[4];
	unsigned short* d = (unsigned short*)buf;
	unsigned short* s = &data_ov024_021fea64;
	int n = 4;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215e9fc(obj->field0, buf, 4, 1);
	if (count <= 0) return 0;

	int found = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = GetCombatantByID(obj->field0, buf[i]);
		if (c && c->currentStats_->primaryStats.agility != 0 && c->currentStats_->agilityBuff > -2 && !func_ov024_021eda60(c)) {
			int var9 = *((unsigned char*)c->currentStats_ + 0x51);
			if (var9 > 0) found++;
		}
	}
	if (found * 3 < count * 2) return 0;

	*outCount = count;
	memcpy(arg4, buf, 8);
	return 1;
}
