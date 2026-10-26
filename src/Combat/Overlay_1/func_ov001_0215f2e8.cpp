#include <globaldefs.h>

extern int data_ov001_021658b8;
extern "C" void func_ov001_0215a850(int v);

// USA: func_ov001_0215f2e8
extern "C" ARM int func_ov001_0215f2e8(void) {
	func_ov001_0215a850(*(int*)&data_ov001_021658b8);
	return 1;
}
