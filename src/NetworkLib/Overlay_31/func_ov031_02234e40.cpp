#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
extern "C" ARM void func_ov031_022274c0(int);
extern "C" void func_ov031_02234b2c(void);
extern "C" void func_ov031_02234cac(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02222e80(void);
extern "C" void func_ov031_022376e4(int val);
extern "C" void func_ov031_02234a90(void);

extern unsigned char data_ov031_02290ce4;

// USA: func_ov031_02234e40
extern "C" ARM void func_ov031_02234e40(void) {
	if (func_ov031_02237eb0() != 0) {
		return;
	}
	if (data_ov031_02290ce4 == 1) {
		func_ov031_022274c0((int)func_ov031_02234b2c);
		return;
	}
	func_ov031_02236878(0xb);
	func_ov031_02222e80();
	data_ov031_02290ce4 = 0;
	func_ov031_022376e4((int)func_ov031_02234cac);
	func_ov031_022274c0((int)func_ov031_02234a90);
}
