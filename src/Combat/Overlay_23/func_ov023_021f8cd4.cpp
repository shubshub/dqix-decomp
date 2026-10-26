#include <globaldefs.h>

struct Struct_ov023_021f8cd4 { unsigned int a, b, c; };

// USA: func_ov023_021f8cd4
extern "C" ARM void func_ov023_021f8cd4(void* obj, struct Struct_ov023_021f8cd4* src) {
	struct Struct_ov023_021f8cd4* dst = (struct Struct_ov023_021f8cd4*)((char*)obj + 0x24);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
