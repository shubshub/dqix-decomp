#include <globaldefs.h>

extern "C" void func_ov031_02239368(int);
extern "C" int func_020d5aec(int);
extern "C" void func_ov031_02239aa4(void);
extern "C" void func_ov031_022393e4(int);

// USA: func_ov031_02239a74
extern "C" ARM int func_ov031_02239a74(void) {
	func_ov031_02239368(3);
	int r = func_020d5aec((int)func_ov031_02239aa4);
	if (r == 2) return 1;
	func_ov031_022393e4(r);
	return 0;
}
