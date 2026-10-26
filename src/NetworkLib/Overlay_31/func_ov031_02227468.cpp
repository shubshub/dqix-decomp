#include <globaldefs.h>

extern "C" void GX_DispOff(void);
extern "C" int func_ov031_0223dffc(void);
extern "C" int SetLcdPower(int a);
extern "C" void func_ov031_0223d06c(void);
extern "C" void func_ov031_0223d7f4(void);
extern "C" void func_ov031_0223684c(void);
extern "C" void func_ov031_0223b870(void);
extern "C" void func_ov031_0223da0c(void);
extern "C" void func_ov031_0223c40c(void);
extern "C" int func_ov031_0223c040(void);
extern "C" void func_ov031_0223b4d4(void);
extern "C" void func_ov031_0223e120(void);
extern "C" void func_ov031_0223cedc(void);
extern "C" void func_ov031_0223de5c(void);

// USA: func_ov031_02227468
extern "C" ARM void func_ov031_02227468(void) {
	GX_DispOff();
	volatile unsigned int* var0 = (volatile unsigned int*)0x4001000;
	*var0 &= ~0x10000;
	func_ov031_0223dffc();
	SetLcdPower(1);
	func_ov031_0223d06c();
	func_ov031_0223d7f4();
	func_ov031_0223684c();
	func_ov031_0223b870();
	func_ov031_0223da0c();
	func_ov031_0223c40c();
	func_ov031_0223c040();
	func_ov031_0223b4d4();
	func_ov031_0223e120();
	func_ov031_0223cedc();
	func_ov031_0223de5c();
}
