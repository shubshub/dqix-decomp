#include <globaldefs.h>

extern "C" int func_ov031_02207380(int a, int b, int c, int d);

struct Struct_ov031_022414cc {
	int unk0;
	int field4;
};

// USA: func_ov031_022414cc
extern "C" ARM int func_ov031_022414cc(struct Struct_ov031_022414cc *obj, int b, int c, int d, int e) {
	int result = func_ov031_02207380(b, c, d, e);
	if (result >= 0) {
		return result;
	}
	if (obj->field4 != 0) {
		return 0xfffffc16;
	}
	if (result == ~0x37) {
		return 0;
	}
	return ~0x3e8;
}
