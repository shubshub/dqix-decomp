#include <globaldefs.h>

struct Struct_ov024_021e6a90_7 {
	unsigned int pad0;
	unsigned int val:12;
	unsigned int rest:20;
	unsigned int unknown_8_0_:29;
	unsigned int flag8:1;
	unsigned int unknown_b_6_:2;
};

// USA: func_ov024_021ea7fc
extern "C" ARM int func_ov024_021ea7fc(void* unused0, struct Struct_ov024_021e6a90_7* p, int c) {
	if (c == 0) return 0;
	if (p->flag8) {
		if (p->val != 0x1f9) return 0;
	}
	if (p->val == 0x70) return 0;
	if (p->val == 0x48) return 0;
	return 1;
}
