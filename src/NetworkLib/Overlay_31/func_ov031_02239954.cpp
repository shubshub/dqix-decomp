#include <globaldefs.h>

extern "C" int func_ov031_02239368(int);
extern "C" void func_ov031_02239984(void);
extern "C" int func_020d5aec(int a);
extern "C" void func_ov031_022393e4(int v);

// USA: func_ov031_02239954
extern "C" ARM int func_ov031_02239954(void) {
	func_ov031_02239368(3);
	int r = func_020d5aec((int)func_ov031_02239984);
	if (r == 2) {
		return 1;
	}
	func_ov031_022393e4(r);
	return 0;
}
