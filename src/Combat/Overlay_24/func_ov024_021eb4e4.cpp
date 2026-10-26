#include <globaldefs.h>

struct Struct_ov024_021da9e0_4 {
	char pad[0x48];
	int slots[8];
};

// USA: func_ov024_021eb4e4
extern "C" ARM void func_ov024_021eb4e4(struct Struct_ov024_021da9e0_4* obj, int val) {
	for (int i = 0; i < 8; i++) {
		if (obj->slots[i] == 0) {
			obj->slots[i] = val;
			return;
		}
	}
}
