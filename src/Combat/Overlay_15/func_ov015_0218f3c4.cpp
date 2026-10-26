#include <globaldefs.h>

struct Struct_ov015_0218f3c4 {
	char unknown_0_[0x1c];
	int val;
};

struct Struct_ov015_0218f3c4_2 {
	char unknown_0_[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	struct Struct_ov015_0218f3c4* sub;
};

// USA: func_ov015_0218f3c4
extern "C" ARM float func_ov015_0218f3c4(struct Struct_ov015_0218f3c4_2* obj) {
	switch (obj->state) {
	case 0:
	case 1:
		return (float)obj->sub->val / 4096.0f;
	default:
		return (float)obj->sub->val / 4096.0f;
	}
}
