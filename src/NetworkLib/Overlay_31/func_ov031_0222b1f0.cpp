#include <globaldefs.h>

extern "C" void func_ov031_02222e98(void);
extern "C" ARM int func_ov031_0223e2e0(int, void*);
extern "C" void func_ov031_0223c278(int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222b22c(void);

struct Struct_ov031_02290c80_3 { unsigned char pad[4]; int field4; };
extern Struct_ov031_02290c80_3 data_ov031_02290c80;

// USA: func_ov031_0222b1f0
extern "C" ARM void func_ov031_0222b1f0(void) {
	func_ov031_02222e98();
	if (data_ov031_02290c80.field4 != 0) {
		func_ov031_0223e2e0(1, (void*)data_ov031_02290c80.field4);
	}
	func_ov031_0223c278(8);
	func_ov031_022274c0((int)func_ov031_0222b22c);
}
