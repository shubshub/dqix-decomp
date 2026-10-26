#include <globaldefs.h>

extern "C" void func_ov027_021dca40(int a);

struct Struct_ov027_021e33e0_10 {
	unsigned char pad0[0xc];
	char* ptr;
};

extern Struct_ov027_021e33e0_10 data_ov027_021e33e0;

// USA: func_ov027_021dcc24
extern "C" ARM void func_ov027_021dcc24(int a) {
	*(int*)(data_ov027_021e33e0.ptr + 0x1000 + 0x320) = 1;
	func_ov027_021dca40(a);
}
