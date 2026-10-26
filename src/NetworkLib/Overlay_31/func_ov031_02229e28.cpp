#include <globaldefs.h>

extern unsigned char data_ov031_02290c6c;
extern "C" void func_ov031_02229e70(void);
extern "C" void func_ov031_02223998(int);
extern "C" int func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02229ef0(void);

// USA: func_ov031_02229e28
extern "C" ARM void func_ov031_02229e28(void) {
	data_ov031_02290c6c = 0;
	func_ov031_02229e70();
	func_ov031_02223998(0x13);
	func_ov031_0222336c(0x3c, 0x3c - 0x3d, 0);
	func_ov031_022235a0(0x1b);
	func_ov031_022274c0((int)func_ov031_02229ef0);
}
