#include <globaldefs.h>

struct Struct_ov001_02157acc {
	unsigned char pad0[0xc4];
	int unknown_c4_;
	unsigned char pad1[0x464 - 0xc8];
	int unknown_464_;
};

// USA: func_ov001_02157acc
extern "C" ARM void func_ov001_02157acc(struct Struct_ov001_02157acc* s) {
	if (s->unknown_c4_ > 0) {
		s->unknown_464_ = 1;
	}
}
