#include <globaldefs.h>

extern int data_ov031_02290ce8;
extern "C" void func_ov031_02235034(int a);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);

// USA: func_ov031_02234ff8
extern "C" ARM void func_ov031_02234ff8(int a, int b, int c) {
	*(int*)((char*)&data_ov031_02290ce8 + 0x4) = a + (b << 5);
	*(int*)((char*)&data_ov031_02290ce8 + 0x8) = (c << 5) + 0x5000000;
	func_ov031_0223e218((void*)1, (void*)func_ov031_02235034, NULL, 0x78);
}
