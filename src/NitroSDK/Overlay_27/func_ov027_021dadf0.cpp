#include <globaldefs.h>

extern "C" void func_ov027_021dae1c(void);

struct Struct_ov027_021dd940_2 {
	char pad0[0x14];
	int f14;
	int f18;
	int f1c;
	char pad1[0x24 - 0x20];
	unsigned char f24;
};

extern Struct_ov027_021dd940_2 data_ov027_021dd940;

// USA: func_ov027_021dadf0
extern "C" ARM void func_ov027_021dadf0(void) {
	data_ov027_021dd940.f18 = 0;
	data_ov027_021dd940.f1c = 0;
	data_ov027_021dd940.f24 = 1;
	data_ov027_021dd940.f14 = 0;
	func_ov027_021dae1c();
}
