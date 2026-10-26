#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_02153e78(int battle, short* out, int max, int group, int flag);
extern "C" int func_02010088(struct S_10088* obj);

struct Struct_ov024_021eecc8 {
	unsigned char pad0;
	unsigned char flags : 4;
	unsigned char groupCount : 2;
	unsigned char pad1 : 2;
	char pad2[4];
	unsigned char ids[8];
	unsigned char memberCount : 4;
	unsigned char weight : 4;
	char unknown_f_[0x18 - 0xf];
};
struct Struct_ov024_021eecc8_2 { char pad0[0x18]; unsigned int unknown_18_; };
struct Struct_ov024_021eecc8_3 { int field0; };
struct Struct_ov024_021fecec { short v[8]; };
extern struct Struct_ov024_021fecec data_ov024_021fecec;

// USA: func_ov024_021eecc8
extern "C" ARM int func_ov024_021eecc8(struct Struct_ov024_021eecc8_3* obj, int unused1, int arg2, int* outCount, short* arg4) {
	struct Struct_ov024_021eecc8* groups = (struct Struct_ov024_021eecc8*)((char*)obj->field0 + 0x81b0);
	if (!groups) return 0;
	int weight = 0;
	int var2 = 0;
	for (int i = 0; i < groups->groupCount; i++) {
		weight += groups[i].weight;
		struct Struct_ov024_021fecec buf = data_ov024_021fecec;
		var2 += func_ov000_02153e78(obj->field0, buf.v, 8, i, 0);
	}
	if (weight >= 5) return 0;
	if (var2 > 5) var2 = 5;
	if (var2 < weight * 2) return 0;
	*outCount = 0;
	int var5 = var2 - weight;
	for (int i = 0; i < groups->groupCount; i++) {
		struct Struct_ov024_021eecc8* g = &groups[i];
		for (int j = 0; j < g->memberCount; j++) {
			int id = g->ids[j] + 0xc0;
			GameObject* c = GetCombatantByID(obj->field0, (short)id);
			if (!c) continue;
			if (((struct Struct_ov024_021eecc8_2*)c->currentStats_)->unknown_18_ & 0x2000) continue;
			if (func_02010088((struct S_10088*)c)) {
				if (var5 > 0) {
					var5--;
					arg4[(*outCount)++] = id;
				}
			} else {
				arg4[(*outCount)++] = id;
			}
			if (*outCount >= 5) break;
		}
	}
	return 1;
}
