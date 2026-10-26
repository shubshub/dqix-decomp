#include <globaldefs.h>

extern "C" void func_ov001_0215b074(int type, int a, int b);

// USA: func_ov001_0215b6f4
extern "C" ARM int func_ov001_0215b6f4(int a, int b) {
	func_ov001_0215b074(0x10, a, b);
	return 1;
}
