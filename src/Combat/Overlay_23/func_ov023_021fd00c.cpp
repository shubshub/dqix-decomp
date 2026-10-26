#include <globaldefs.h>

struct Struct_ov023_021fd00c { unsigned int a, b, c; };

// USA: func_ov023_021fd00c
extern "C" ARM void func_ov023_021fd00c(void* obj, struct Struct_ov023_021fd00c* src) {
	struct Struct_ov023_021fd00c* dst = (struct Struct_ov023_021fd00c*)((char*)obj + 0x64);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
