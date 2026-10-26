#include <globaldefs.h>

extern "C" int func_ov027_021d9de8();
extern "C" void func_ov027_021d8c6c(int a, int b, int c);

struct Struct_ov027_021e33ec {
	void *field0;
};

extern struct Struct_ov027_021e33ec data_ov027_021e33ec;

// USA: func_ov027_021d8c20
extern "C" ARM void func_ov027_021d8c20(int index, int value, int c) {
	if (func_ov027_021d9de8() != 0) {
		((int *)((char *)data_ov027_021e33ec.field0 + 0x14e8))[index - 1] = value;
	}
	func_ov027_021d8c6c(index, value, c);
}
