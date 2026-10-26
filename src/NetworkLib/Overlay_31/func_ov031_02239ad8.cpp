#include <globaldefs.h>

extern "C" void func_ov031_02239368(int);
extern "C" int func_020d559c(int, unsigned int);
extern "C" void func_ov031_02239b10(void);
extern "C" void func_ov031_022393e4(int);
extern "C" int func_ov031_0223a358(void);

// USA: func_ov031_02239ad8
extern "C" ARM int func_ov031_02239ad8(void) {
	func_ov031_02239368(3);
	int r = func_020d559c((int)func_ov031_02239b10, 0);
	if (r == 2) return 1;
	func_ov031_022393e4(r);
	func_ov031_0223a358();
	return 0;
}
