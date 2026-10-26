#include <globaldefs.h>


extern int data_ov031_0224b3c0[];
extern "C" int func_ov031_02223478(int);
extern "C" int func_ov031_0223b61c(int, int, int);
extern "C" void func_020ca4b4(int, void*, unsigned int);
extern "C" void func_ov031_0223b710(int);
extern "C" void* func_ov031_0223e218(void*, void*, void*, int);
extern void* data_ov031_02250bf4;
extern "C" void func_ov031_02223a24(int arg0);

// USA: func_ov031_02223998
extern "C" ARM void func_ov031_02223998(int idx) {
	int elem = data_ov031_0224b3c0[idx];
	int a = func_ov031_02223478(elem);
	int v = func_ov031_0223b61c(a, 0, 4);
	func_020ca4b4(v, data_ov031_02250bf4, 0xc0);
	func_ov031_0223b710(v);
	func_ov031_0223e218((void*)1, (void*)func_ov031_02223a24, NULL, 0x78);
}
