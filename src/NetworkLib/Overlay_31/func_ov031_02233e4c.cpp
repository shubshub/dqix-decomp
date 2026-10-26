#include <globaldefs.h>

extern "C" void func_ov031_02233e7c(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02233ee8(void);
extern unsigned char data_ov031_02290cd8;
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_02233e4c
extern "C" ARM void func_ov031_02233e4c(void) {
	(&data_ov031_02290cd8)[0] = 0;
	func_ov031_02233e7c();
	func_ov031_022235a0(0x2d);
	func_ov031_022274c0((int)func_ov031_02233ee8);
}
