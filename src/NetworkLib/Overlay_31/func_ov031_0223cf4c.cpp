#include <globaldefs.h>


extern "C" ARM void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" int func_020ca4b4(void*, void*, int);
extern "C" ARM void* func_ov031_0223e218(void *a, void *b, void *c, int d);
extern "C" void func_ov031_02234fa4(void);

extern unsigned char* data_ov031_02290ce8;

// USA: func_ov031_02234ea8
extern "C" ARM void func_ov031_02234ea8(void* arg) {
	unsigned char* p = (unsigned char*)func_ov031_0223cf4c(0x608, 4);
	data_ov031_02290ce8 = p;
	func_020ca4b4(arg, p + 4, 0x600);
	void* r = func_ov031_0223e218((void*)1, (void*)func_ov031_02234fa4, 0, 0x78);
	*(void**)data_ov031_02290ce8 = r;
}
