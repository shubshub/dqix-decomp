#include <globaldefs.h>

extern "C" void func_ov023_021f809c(void* obj, int a1, int a2, int a3);

struct Struct_ov004_0215f6f4 { char pad[0xe2]; unsigned short unknown_e2_; };

// USA: func_ov023_021f8944
extern "C" ARM void func_ov023_021f8944(struct Struct_ov004_0215f6f4* obj, int a1, int a2, int a3) {
	a2 &= 0xf;
	obj->unknown_e2_ = a2;
	if (a3 != 0) func_ov023_021f809c(obj, a1, a2, a3);
}
