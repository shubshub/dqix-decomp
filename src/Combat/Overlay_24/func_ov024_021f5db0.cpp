#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov000_0215ec80(int battle, unsigned short* table, int count, int flag);
extern "C" int func_020882f8(unsigned char* obj);

struct Struct_ov024_021fee1c { unsigned short v[8]; };
extern struct Struct_ov024_021fee1c data_ov024_021fee1c;

struct Struct_ov024_021f5db0 {
	int counter;
	struct Struct_ov024_021fee1c table;
};

// USA: func_ov024_021f5db0
extern "C" ARM int func_ov024_021f5db0(int* a0, int id, int a2, int* outFlag, short* arg4) {
	GameObject* c = func_ov000_021536f8(*a0, id);
	if (!c) return 0;
	int var1 = *((unsigned char*)c + 0x17c);
	if (var1 >= 3) return 0;

	struct Struct_ov024_021f5db0 buf;
	buf.table = data_ov024_021fee1c;
	buf.counter = 1;

	int count = func_ov000_0215ec80(*a0, buf.table.v, 8, var1 & 0xff);
	int var4 = 0;
	for (int i = 0; i < count; i++) {
		GameObject* member = GetCombatantByID(*a0, *(short*)&buf.table.v[i]);
		if (member && !func_020882f8((unsigned char*)member->currentStats_)) {
			var4++;
		}
	}
	if (var4 != 3) return 0;
	*outFlag = 1;
	*arg4 = (short)id;
	return 1;
}
