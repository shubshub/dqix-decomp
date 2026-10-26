#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern int data_ov031_02290cc0;
extern "C" void func_ov031_02232568(void);
extern "C" void func_ov031_02223998(int idx);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02223518(int);
extern "C" void func_ov031_02232678(void);
extern "C" void func_ov031_02232ce8(void);
extern "C" ARM void func_ov031_022274c0(int v);
extern "C" void func_ov031_02232780(void);

// USA: func_ov031_02232508
extern "C" ARM void func_ov031_02232508(void) {
	void* p = func_ov031_0223cf4c(0x20, 4);
	*(int*)((char*)&data_ov031_02290cc0 + 0x4) = (int)p;
	((unsigned char*)p)[0x1d] = 0;
	func_ov031_02232568();
	func_ov031_02223998(1);
	func_ov031_0222336c(0x2f, -1, 0);
	func_ov031_02223518(0);
	func_ov031_02232678();
	func_ov031_02232ce8();
	func_ov031_022274c0((int)func_ov031_02232780);
}
