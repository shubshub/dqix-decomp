#include <globaldefs.h>

extern "C" void func_ov001_02157908(void*);

// USA: func_ov001_02159408
extern "C" ARM int func_ov001_02159408(void* unused, char* p) {
	func_ov001_02157908(p + 0x11c);
	return 0;
}
