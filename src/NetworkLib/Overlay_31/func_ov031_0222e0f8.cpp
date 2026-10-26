#include <globaldefs.h>

typedef void (*Type_ov031_02226fe4)(void*);
struct Struct_ov031_02248f0c { Type_ov031_02226fe4 h[5]; };
extern Struct_ov031_02248f0c data_ov031_02248f0c;

extern "C" bool func_ov031_02237eb0(void);

struct Struct_ov031_0222e0f8 {
	unsigned char pad[4];
	int* field4;
	unsigned char pad2[0x15 - 8];
	unsigned char unknown_15_;
};
extern Struct_ov031_0222e0f8* data_ov031_02290c98;

extern "C" void func_ov031_02227520(int* a, int* b);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222d9a4(void);
extern "C" void func_ov031_0222dee0(void);

// USA: func_ov031_0222e0f8
extern "C" ARM void func_ov031_0222e0f8(void) {
	Struct_ov031_02248f0c table = data_ov031_02248f0c;

	if (func_ov031_02237eb0()) return;

	Struct_ov031_0222e0f8* ptr = data_ov031_02290c98;
	if (ptr->unknown_15_ == 0) {
		*ptr->field4 &= 0xc1fffcff;
		func_ov031_022274c0((int)func_ov031_0222d9a4);
		return;
	}

	int idx;
	func_ov031_02227520(&idx, NULL);
	ptr = data_ov031_02290c98;
	table.h[idx]((char*)ptr + 8);
	func_ov031_022274c0((int)func_ov031_0222dee0);
}
