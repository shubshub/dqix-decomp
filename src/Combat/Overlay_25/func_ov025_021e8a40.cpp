#include <globaldefs.h>

// USA: func_ov025_021e8a40
extern "C" ARM void func_ov025_021e8a40(char* obj, int a, int b) {
	*(int*)(obj + 0x10) = a;
	*(int*)(obj + 0x20) = b;
}
