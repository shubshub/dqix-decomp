#include <globaldefs.h>

extern "C" void func_ov031_022364c0(void);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222785c(int);
extern "C" void *func_ov031_022277e4(void);
extern "C" void func_ov031_022274c0(int v);
extern "C" ARM void func_ov031_022298a8(void);
extern unsigned char data_ov031_02290c68;

// USA: func_ov031_02229964
extern "C" ARM void func_ov031_02229964(int mode) {
	if (mode == 2) {
		func_ov031_022364c0();
		data_ov031_02290c68 = 1;
		func_ov031_022368e0();
		func_ov031_02236878(0x10);
	} else if (mode == 3) {
		data_ov031_02290c68 = 2;
		func_ov031_022368e0();
		func_ov031_02236878(0x12);
	} else {
		data_ov031_02290c68 = 0;
		func_ov031_022368e0();
		func_ov031_02236878(0x12);
	}
	func_ov031_0222785c(0);
	func_ov031_022277e4();
	func_ov031_022274c0((int)func_ov031_022298a8);
}
