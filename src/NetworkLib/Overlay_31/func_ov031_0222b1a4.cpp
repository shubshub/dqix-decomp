#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void func_ov031_0223e2c0(int, int);
extern "C" void func_ov031_02222e98(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222b420(void);

struct Struct_ov031_02290c80_2 { unsigned char pad[4]; int field4; };
extern Struct_ov031_02290c80_2 data_ov031_02290c80;

// USA: func_ov031_0222b1a4
extern "C" ARM void func_ov031_0222b1a4(void) {
	if (func_ov031_02222e0c() != 0) return;
	int v = data_ov031_02290c80.field4;
	if (v == 0) return;
	func_ov031_0223e2c0(1, v);
	data_ov031_02290c80.field4 = 0;
	func_ov031_02222e98();
	func_ov031_022274c0((int)func_ov031_0222b420);
}
