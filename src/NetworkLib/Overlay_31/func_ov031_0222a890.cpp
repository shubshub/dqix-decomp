#include <globaldefs.h>

extern "C" void func_ov031_0222a900(void);
extern "C" void func_ov031_0222a904(void);
extern "C" signed char func_ov031_02237e9c(void);
extern unsigned char data_ov031_02290c78;
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_0222785c(int);
extern "C" void func_ov031_02237e58(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222a908(void);

// USA: func_ov031_0222a890
extern "C" ARM void func_ov031_0222a890(void) {
	func_ov031_0222a900();
	func_ov031_0222a904();
	signed char v = func_ov031_02237e9c();
	switch (v) {
	case 0:
		(&data_ov031_02290c78)[1] = 0;
		func_ov031_02236878(7);
		break;
	case 1:
		(&data_ov031_02290c78)[1] = 1;
		func_ov031_02236878(0xe);
		break;
	default:
		return;
	}
	func_ov031_0222785c(0);
	func_ov031_02237e58();
	func_ov031_022274c0((int)func_ov031_0222a908);
}
