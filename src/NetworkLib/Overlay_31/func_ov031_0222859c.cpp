#include <globaldefs.h>

extern unsigned char data_ov031_02290c58;
extern "C" void func_ov031_022285e4(void);
extern "C" void func_ov031_02223998(int);
extern "C" int func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02228664(void);

// USA: func_ov031_0222859c
extern "C" ARM void func_ov031_0222859c(void) {
	data_ov031_02290c58 = 0;
	func_ov031_022285e4();
	func_ov031_02223998(0x12);
	func_ov031_0222336c(0x3b, 0x3b - 0x3c, 0);
	func_ov031_022235a0(0x17);
	func_ov031_022274c0((int)func_ov031_02228664);
}
