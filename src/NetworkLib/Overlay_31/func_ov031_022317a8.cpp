#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
extern "C" void func_ov031_02222bdc(void);
extern "C" int func_ov031_02223440(void);
extern "C" int func_ov031_0223cbbc(int, int);
extern "C" void func_ov031_02233248(void);
extern "C" void func_ov031_02231988(void);

extern "C" ARM int func_ov031_02222e54(void);
extern "C" ARM void* func_ov031_0223c7c4(int idx);
extern "C" ARM int func_ov031_02227ba4(void);
extern "C" ARM void func_ov031_022274d0(int a, int b);
extern "C" ARM void func_ov031_022274c0(int v);

extern unsigned char data_ov031_02290cb0;

// USA: func_ov031_022317a8
extern "C" ARM void func_ov031_022317a8(void) {
	if (func_ov031_0223c054(0) != 0) {
		return;
	}
	if (data_ov031_02290cb0 == 0) {
		if (func_ov031_0223c054(1) != 0) {
			return;
		}
	}
	if (func_ov031_02222e54() == 0) {
		return;
	}
	func_ov031_02222bdc();
	func_ov031_0223c7c4(0);
	if (data_ov031_02290cb0 == 0) {
		func_ov031_02223440();
		func_ov031_0223cbbc(1, 1);
	}
	func_ov031_02227ba4();
	if (data_ov031_02290cb0 == 0) {
		func_ov031_022274d0(2, 1);
		func_ov031_022274c0((int)func_ov031_02233248);
		return;
	}
	func_ov031_022274d0(0, 0);
	func_ov031_022274c0((int)func_ov031_02231988);
}
