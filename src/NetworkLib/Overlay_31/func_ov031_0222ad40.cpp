#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern unsigned char data_ov031_02290c7c;
extern "C" int func_ov031_02222e54(void);
extern "C" int func_ov031_02227840(void);
extern "C" void func_ov031_02222bdc(void);
extern "C" void* func_ov031_0223c7c4(int);
extern "C" int func_ov031_02223440(void);
extern "C" void func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_022274d0(int, int);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222905c(void);
extern "C" void func_ov031_0222a35c(void);
extern "C" void func_ov031_0222a6c4(void);

// USA: func_ov031_0222ad40
extern "C" ARM void func_ov031_0222ad40(void) {
	if (func_ov031_0223c054(0) != 0) return;
	if (data_ov031_02290c7c == 0) {
		if (func_ov031_0223c054(1) != 0) return;
	}
	if (func_ov031_02222e54() == 0) return;
	if (data_ov031_02290c7c == 0) {
		if (func_ov031_02227840() == 0) return;
	}

	func_ov031_02222bdc();
	func_ov031_0223c7c4(0);

	if (data_ov031_02290c7c == 0) {
		func_ov031_02223440();
		func_ov031_0223cbbc(1, 1);
	}
	func_ov031_0223cbbc(0, 0x15);

	unsigned char b = data_ov031_02290c7c;
	if (b == 0) {
		func_ov031_022274d0(0, 1);
		func_ov031_022274c0((int)func_ov031_0222905c);
		return;
	}
	if (b == 2) {
		func_ov031_022274d0(0, 1);
		func_ov031_022274c0((int)func_ov031_0222a35c);
		return;
	}
	func_ov031_022274d0(0, 1);
	func_ov031_022274c0((int)func_ov031_0222a6c4);
}
