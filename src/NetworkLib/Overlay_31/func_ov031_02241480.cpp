#include <globaldefs.h>

extern "C" int func_ov031_022072ac(int a, int b, int c, int d);

struct Struct_ov031_02241480 {
	int unk0;
	int field4;
};

// USA: func_ov031_02241480
extern "C" ARM int func_ov031_02241480(struct Struct_ov031_02241480 *obj, int b, int c, int d, int e) {
	int result = func_ov031_022072ac(b, c, d, e);
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
