#include <globaldefs.h>

struct Struct_ov016_0219d0c0_6 {
	char pad0[0x4];
	int flag4;      // 0x4
#if defined(jpn)
	char pad1[0xc - 0x8];
	int unknown_38_;
	char pad2[0x30 - 0x10];
	int unknown_3c_;
#else
	char pad1[0x38 - 0x8];
	int unknown_38_;     // 0x38
	int unknown_3c_;  // 0x3c
#endif
};

extern Struct_ov016_0219d0c0_6 data_ov016_0219d0c0;

// USA: func_ov016_0218c024
extern "C" ARM void func_ov016_0218c024(void) {
	data_ov016_0219d0c0.flag4 = 1;
	if (data_ov016_0219d0c0.unknown_38_ == 0) data_ov016_0219d0c0.unknown_3c_++;
}
