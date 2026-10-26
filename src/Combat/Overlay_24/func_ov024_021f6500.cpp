#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

extern unsigned short data_ov024_021fedbc;

struct Struct_ov024_021f6500 { int field0; };

// USA: func_ov024_021f6500
extern "C" ARM int func_ov024_021f6500(struct Struct_ov024_021f6500* obj, int a1, int a2, int* outCount, short* arg4) {
	short buf[8];
	unsigned short* d = (unsigned short*)buf;
	unsigned short* s = &data_ov024_021fedbc;
	int n = 8;
	do {
		unsigned short* var4 = d++;
		*var4 = *s++;
	} while (--n);

	int count = func_ov000_0215eb1c(obj->field0, buf, 8, 1);
	if (count <= 0) return 0;

	*outCount = 0;
	for (int i = 0; i < count; i++) {
		GameObject* c = func_ov000_021536f8(obj->field0, buf[i]);
		if (!c) continue;
		if (c->obj3D_.unknown_2_ != 0x13a) continue;
		if (*(short*)((char*)c->currentStats_ + 0x2c) > 0) continue;
		arg4[*outCount] = buf[i];
		*outCount = *outCount + 1;
	}

	if (*outCount <= 0) return 0;
	func_ov024_021ed890((struct Random**)obj, outCount, arg4);
	return 1;
}
