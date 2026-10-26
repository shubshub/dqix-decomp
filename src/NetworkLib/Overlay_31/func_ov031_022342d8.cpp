#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
extern "C" void func_ov031_0223cbbc(int channel, int mask);
extern "C" void func_ov031_022274d0(int a, int b);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02233a00(void);

// USA: func_ov031_022342d8
extern "C" ARM void func_ov031_022342d8(void) {
	if (func_ov031_0223c054(0) != 0) {
		return;
	}
	func_ov031_0223cbbc(0, 0x14);
	func_ov031_022274d0(0, 1);
	func_ov031_022274c0((int)func_ov031_02233a00);
}
