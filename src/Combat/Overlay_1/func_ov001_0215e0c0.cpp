#include <globaldefs.h>

extern int data_ov001_02165880;
extern "C" void func_ov001_02159290(int v);

// USA: func_ov001_0215e0c0
extern "C" ARM int func_ov001_0215e0c0(void) {
	func_ov001_02159290(*(int*)((char*)&data_ov001_02165880 + 0x24));
	return 1;
}
