#include <globaldefs.h>

extern "C" int func_020c7e0c(void* data, void* arg1, int flag);
extern "C" void func_ov031_02205174(int v);

struct Struct_ov031_022051a8 { unsigned char pad[0xd]; signed char unknown_d_; };

// USA: func_ov031_022051a8
extern "C" ARM int func_ov031_022051a8(void* a, struct Struct_ov031_022051a8* b) {
	int flag = (b == NULL || (b->unknown_d_ & 1) != 0) ? 1 : 0;
	int r = func_020c7e0c(a, b, flag);
	if (r == 0) {
		func_ov031_02205174((int)b);
	}
	return (r != 0) ? 0 : -42;
}
