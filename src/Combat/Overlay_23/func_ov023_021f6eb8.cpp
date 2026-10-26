#include <globaldefs.h>

extern "C" void func_ov023_021f6788(void* p);

// USA: func_ov023_021f6eb8
extern "C" ARM void func_ov023_021f6eb8(void* obj, int idx) {
	if (idx >= 3) return;
	func_ov023_021f6788((char*)obj + 0x30 + idx * 0x16);
}
