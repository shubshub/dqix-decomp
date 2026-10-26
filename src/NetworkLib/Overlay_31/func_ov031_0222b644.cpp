#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(int size, int align);
extern "C" void func_ov031_02227520(int* a, int* b);
extern "C" int func_ov031_02235984(void* ptr);
extern "C" void func_ov031_0222b71c(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_0222336c(int a, int b, int c);
extern "C" void func_ov031_02223518(int a);
extern "C" void func_ov031_0222b870(void);
extern "C" void func_ov031_0222b918(void);
extern "C" void* func_ov031_0223c560(int a, int b);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0222c870(void);
extern "C" void func_ov031_0222c3b4(void);
extern "C" void func_ov031_0222c8cc(void);
extern "C" void func_ov031_0222ba8c(void);
extern "C" void func_ov031_022274c0(int v);

struct Struct_ov031_0222b644 {
	unsigned char pad[0xc];
	void* unknown_c_;
	unsigned char pad2[0x3c - 0x10];
	int unknown_3c_;
	unsigned char pad3[0x51 - 0x40];
	unsigned char unknown_51_;
};
struct Struct_ov031_02290c8c {
	unsigned char field0;
	unsigned char pad1;
	unsigned short field2;
	Struct_ov031_0222b644* field4;
};
extern Struct_ov031_02290c8c data_ov031_02290c8c;

// USA: func_ov031_0222b644
extern "C" ARM void func_ov031_0222b644(void) {
	int local;
	data_ov031_02290c8c.field4 = (Struct_ov031_0222b644*)func_ov031_0223cf4c(0x5c, 4);
	func_ov031_02227520(&local, NULL);
	if (local == 0) {
		data_ov031_02290c8c.field0 = 0;
		data_ov031_02290c8c.field2 = 0;
	}

	data_ov031_02290c8c.field4->unknown_51_ = (unsigned char)func_ov031_02235984(data_ov031_02290c8c.field4);

	func_ov031_0222b71c();
	func_ov031_022239f4();
	func_ov031_0222336c(0x34, -1, 0);
	func_ov031_02223518(2);
	func_ov031_0222b870();
	func_ov031_0222b918();

	data_ov031_02290c8c.field4->unknown_c_ = func_ov031_0223c560(0, 0);
	data_ov031_02290c8c.field4->unknown_3c_ = (int)func_ov031_0223e218((void*)1, (void*)func_ov031_0222c870, NULL, 0x6e);

	func_ov031_0222c3b4();
	func_ov031_0222c8cc();
	func_ov031_022274c0((int)func_ov031_0222ba8c);
}
