#include <globaldefs.h>

extern "C" bool func_ov031_02237eb0();
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02227520(int* a, int* b);
extern "C" void func_ov031_0222ce24();
extern "C" void func_ov031_0222d1b8();

struct Struct_ov031_02248eb4_2 {
	char pad[0x10];
	void (*unknown_10_)(void*);
	void (*unknown_14_)(void*);
};
extern Struct_ov031_02248eb4_2 data_ov031_02248eb4;

struct Struct_ov031_0222d474 {
	char pad0[4];
	unsigned int* field4;
	char pad1[0x2a - 8];
	unsigned char field2a;
};
extern Struct_ov031_0222d474* data_ov031_02290c94;

// USA: func_ov031_0222d474
extern "C" ARM void func_ov031_0222d474() {
	void (*var0[2])(void*);
	var0[0] = data_ov031_02248eb4.unknown_10_;
	var0[1] = data_ov031_02248eb4.unknown_14_;
	if (func_ov031_02237eb0()) {
		return;
	}
	Struct_ov031_0222d474* p = data_ov031_02290c94;
	if (p->field2a == 0) {
		*p->field4 &= 0xc1fffcff;
		func_ov031_022274c0((int)func_ov031_0222ce24);
		return;
	}
	int idx;
	func_ov031_02227520(&idx, (int*)0);
	p = data_ov031_02290c94;
	void (*fn)(void*) = var0[idx];
	fn((char*)p + 8);
	func_ov031_022274c0((int)func_ov031_0222d1b8);
}
