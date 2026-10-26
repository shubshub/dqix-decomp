#include <globaldefs.h>

struct Struct_ov015_0218f344 {
	char pad[0xc];
	int val;
};

struct Struct_ov015_0218f344_2 {
	char unknown_0_[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	struct Struct_ov015_0218f344* sub;
};

// USA: func_ov015_0218f344
extern "C" ARM int func_ov015_0218f344(struct Struct_ov015_0218f344_2* obj) {
	unsigned char state = obj->state;
	switch (state) {
	case 0:
	case 1:
		return obj->sub->val;
	default:
		return obj->sub->val;
	}
}
