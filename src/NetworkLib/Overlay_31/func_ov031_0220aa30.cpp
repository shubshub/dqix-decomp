#include <globaldefs.h>

extern void (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_0220aa30
extern "C" ARM void func_ov031_0220aa30(void* self) {
	char* ctx = *(char**)((char*)self + 0xc);
	*(unsigned char*)(ctx + 0x455) = 0;
	void* handle = *(void**)(ctx + 0x824);
	if (handle != 0) {
		data_ov031_0224c9c0(handle);
	}
	*(void**)(ctx + 0x824) = 0;
}
