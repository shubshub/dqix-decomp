#include <globaldefs.h>

extern void* data_ov031_0224e580;
extern "C" void func_ov031_02210314(int v);

// USA: func_ov031_0220fed8
extern "C" ARM void func_ov031_0220fed8(void) {
	if (data_ov031_0224e580 == NULL) return;
	func_ov031_02210314(0);
	*(int*)((char*)data_ov031_0224e580 + 0x28) = 0;
	*(int*)((char*)data_ov031_0224e580 + 0x2c) = 1;
}
