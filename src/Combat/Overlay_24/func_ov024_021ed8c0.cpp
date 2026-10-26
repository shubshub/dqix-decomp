#include <globaldefs.h>
#include "std_library_functions.h"
#include "Util/Random.h"

extern "C" int func_ov000_02154f30(struct Random* arg0, int id, int count, short* ids);

struct Struct_ov024_021ed8c0 {
	char unk[0x1c];
	unsigned int unknown_1c_0_ : 14;
	unsigned int unknown_1d_6_ : 5;
	unsigned int unknown_1e_3_ : 13;
};

struct Struct_ov024_021fec5c { short v[8]; };
extern struct Struct_ov024_021fec5c data_ov024_021fec5c;

// USA: func_ov024_021ed8c0
extern "C" ARM void func_ov024_021ed8c0(struct Random** context, int id, struct Struct_ov024_021ed8c0* record, int* count, short* ids) {
	struct Random* rng = *context;
	int var1 = 1;
	switch (record->unknown_1d_6_) {
	case 0:
	case 10:
		break;
	case 3:
		var1 = NextRandomBetween(rng, 3, 4);
		break;
	case 4:
		var1 = 2;
		break;
	case 5:
		var1 = 4;
		break;
	case 7:
		var1 = 7;
		break;
	case 8:
		var1 = 3;
		break;
	}

	short n = 0;
	struct Struct_ov024_021fec5c buf = data_ov024_021fec5c;
	for (int i = 0; i < var1; i++) {
		int r = func_ov000_02154f30(*context, id, *count, ids);
		if (r < 0) break;
		buf.v[n] = r;
		n++;
	}
	*count = n;
	memcpy(ids, buf.v, sizeof(buf));
}
