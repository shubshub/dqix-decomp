#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(int size, int align);
extern void* data_ov031_02250bf0;

// USA: func_ov031_022236e8
extern "C" ARM void func_ov031_022236e8(void) {
	data_ov031_02250bf0 = func_ov031_0223cf4c(0x10, 4);
}
