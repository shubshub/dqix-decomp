#include <globaldefs.h>

extern void* data_ov031_02290d14;
extern "C" void func_ov031_0223932c(void* obj);

// USA: func_ov031_02238694
extern "C" ARM void func_ov031_02238694(void* obj) {
	data_ov031_02290d14 = obj;
	func_ov031_0223932c((char*)obj + 0x1b160);
	*(int*)((char*)data_ov031_02290d14 + 0x1b140) = 0;
	*(int*)((char*)data_ov031_02290d14 + 0x1b144) = 0;
}
