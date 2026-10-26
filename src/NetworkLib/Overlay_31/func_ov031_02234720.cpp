#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void func_ov031_02236878(int);
extern unsigned char data_ov031_02290ce0;
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_02234770(void);

// USA: func_ov031_02234720
extern "C" ARM void func_ov031_02234720(void) {
	int v = func_ov031_02222e0c();
	if (v == 0) goto isZero;
	if (v == 1) goto isOne;
	return;
isZero:
	func_ov031_02236878(7);
	goto shared;
isOne:
	func_ov031_02236878(6);
	data_ov031_02290ce0 = 1;
shared:
	func_ov031_022274c0((int)func_ov031_02234770);
}
