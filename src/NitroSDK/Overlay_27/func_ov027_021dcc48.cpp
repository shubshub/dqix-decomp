#include <globaldefs.h>

extern "C" int func_020d5004(int arg);
extern "C" void func_ov027_021dd0cc(int a, int b);

struct Struct_ov027_021e33e0_11 {
	unsigned char pad0[8];
	unsigned char* ptr;
};

extern Struct_ov027_021e33e0_11 data_ov027_021e33e0;

// USA: func_ov027_021dcc48
extern "C" ARM int func_ov027_021dcc48(void) {
	int result = func_020d5004(*(int*)(data_ov027_021e33e0.ptr + 0x508));
	func_ov027_021dd0cc(1, result);
	if (result == 2) result = 0;
	return result;
}
