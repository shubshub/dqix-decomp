#include <globaldefs.h>

struct Struct_ov016_0219d1c0_2 {
	int f0;
	int f4;
	char pad0[0xc - 0x8];
	int fc;
	int f10;
	char pad1[0x20 - 0x14];
	int f20;
};

extern Struct_ov016_0219d1c0_2 data_ov016_0219d1c0;

// USA: func_ov016_0218fcac
extern "C" ARM void func_ov016_0218fcac(void* h, int mask) {
	data_ov016_0219d1c0.f10 = (int)h;
	data_ov016_0219d1c0.fc = mask & ~3;
	data_ov016_0219d1c0.f4 = 0;
	data_ov016_0219d1c0.f0 = 0;
	data_ov016_0219d1c0.f20 = 0;
}
