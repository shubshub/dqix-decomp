#include <globaldefs.h>

extern "C" int func_020d5214(int arg);
extern "C" void func_ov031_022393e4(int v);
extern "C" int func_ov031_02239a00(short* p);

// USA: func_ov031_022399d8
extern "C" ARM int func_ov031_022399d8(void) {
	int r = func_020d5214((int)func_ov031_02239a00);
	if (r == 2) return 1;
	func_ov031_022393e4(r);
	return 0;
}
