#include <globaldefs.h>


extern "C" void func_ov031_02239108(unsigned short v);
extern "C" int func_ov027_021dcc24(int a);
extern "C" int func_ov031_0223883c(int a);
extern "C" void HaltSystem(void);

// USA: func_ov031_022387f4
extern "C" ARM void func_ov031_022387f4(int a0, int a1) {
	func_ov031_02239108(2);
	if (func_ov027_021dcc24(a1) != 0) {
		func_ov031_02239108(7);
		return;
	}
	if (func_ov031_0223883c(a0) == 0) {
		HaltSystem();
	}
}
