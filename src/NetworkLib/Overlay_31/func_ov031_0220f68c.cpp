#include <globaldefs.h>

extern void* data_ov031_0224e580;
extern "C" int func_020c7fe0(void* obj, unsigned int* out, int arg2);

// USA: func_ov031_0220f68c
extern "C" ARM void func_ov031_0220f68c(void) {
	func_020c7fe0(data_ov031_0224e580, (unsigned int*)((char*)data_ov031_0224e580 + 0x24), 1);
	if (*(void**)((char*)data_ov031_0224e580 + 0x24) == NULL) return;
	*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x1c) = 0;
	*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x20) = 0;
	*(int*)((char*)(*(void**)((char*)data_ov031_0224e580 + 0x24)) + 0x24) = 0;
}
