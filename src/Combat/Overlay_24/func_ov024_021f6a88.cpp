#include <globaldefs.h>
#include "Combat/Main/CombatCalculations.h"

struct Struct_ov024_021f6a88_2 {
	char pad[0xa];
	unsigned short pad0:7;
	unsigned short field4:4;
	unsigned short pad1:5;
};

struct Struct_ov024_021f6a88 {
	char pad0[8];
	struct Struct_ov024_021f6a88_2* inner;
	char pad1[0x14-0xc];
	float x;
	float y;
	float outX;
	float outY;
};

// USA: func_ov024_021f6a88
extern "C" ARM int func_ov024_021f6a88(struct Struct_ov024_021f6a88* obj) {
	struct Struct_ov024_021f6a88_2* inner = obj->inner;
	if (inner != NULL) {
		if (inner->field4 == 2) {
			obj->outX = (float)RoundUp(obj->x * 1.5f);
			obj->outY = (float)RoundUp(obj->y * 1.5f);
		}
	}
	return 1;
}
