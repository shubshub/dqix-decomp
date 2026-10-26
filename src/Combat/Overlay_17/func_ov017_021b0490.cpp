#include <globaldefs.h>

struct Struct_ov017_021b0490 {
	unsigned char pad0[9];
	unsigned char unknown_9_;
	unsigned char unknown_a_;
	unsigned char pad1[0x23 - 0xb];
	unsigned char unknown_23_;
	unsigned char unknown_24_;
	unsigned char pad2[0x30 - 0x25];
	int unknown_30_;
};

// USA: func_ov017_021b0490
extern "C" ARM int func_ov017_021b0490(Struct_ov017_021b0490* p) {
	if (p->unknown_9_ == 0) {
		if (p->unknown_30_ != 0) {
			p->unknown_23_ = 0;
			p->unknown_24_ = 0;
			return 9;
		}
	}
	return p->unknown_a_;
}
