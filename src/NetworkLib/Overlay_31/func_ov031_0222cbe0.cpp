#include <globaldefs.h>

extern unsigned char data_ov031_02248eb4[2];
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);

extern void* data_ov031_02290c94;

extern "C" void func_ov031_02227520(int*, int*);
extern "C" void func_ov031_02235f0c(void*);
extern "C" int func_ov031_0223dd34(unsigned char*, int);
extern "C" void func_ov031_0222cd14(void);
extern "C" void func_ov031_02223998(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02223518(int);
extern "C" int func_ov031_0223c560(int, int);
extern "C" int func_ov031_0223be44(int, int);
extern "C" void func_ov031_0222d3b0(void);
extern "C" void func_ov031_0222d2bc(void);
extern "C" void func_ov031_022274c0(int);
extern "C" void func_ov031_0222cdd0(void);

struct Struct_ov031_0222cbe0 { unsigned char pad[4]; unsigned short pad2 : 10; unsigned short unknown_5_2_ : 2; };

// USA: func_ov031_0222cbe0
extern "C" ARM void func_ov031_0222cbe0(void) {
	unsigned char localbuf[2];
	localbuf[0] = data_ov031_02248eb4[0];
	localbuf[1] = data_ov031_02248eb4[1];
	data_ov031_02290c94 = func_ov031_0223cf4c(0x2c, 4);

	int var1, var2;
	func_ov031_02227520(&var1, &var2);

	if (var1 == 0) {
		func_ov031_02235f0c((char*)data_ov031_02290c94 + 8);
		unsigned char idx = func_ov031_0223dd34((unsigned char*)((char*)data_ov031_02290c94 + 8), 0x20);
		*((unsigned char*)data_ov031_02290c94 + 0x29) = idx;
	}
	func_ov031_0222cd14();
	func_ov031_02223998(var1 + 9);
	if (var2 == 1) {
		func_ov031_0222336c(0x35, -1, 0);
	} else {
		func_ov031_0222336c(localbuf[var1], -1, 0);
	}
	func_ov031_02223518(2);
	int r = func_ov031_0223c560(0, 0);
	*(int*)data_ov031_02290c94 = r;
	int r2 = func_ov031_0223be44(0, 0x3e);
	*(int*)((char*)data_ov031_02290c94 + 4) = r2;
	Struct_ov031_0222cbe0* p = *(Struct_ov031_0222cbe0**)((char*)data_ov031_02290c94 + 4);
	p->unknown_5_2_ = 3;
	func_ov031_0222d3b0();
	func_ov031_0222d2bc();
	func_ov031_022274c0((int)func_ov031_0222cdd0);
}
