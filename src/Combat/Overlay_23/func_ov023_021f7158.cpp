#include <globaldefs.h>

struct Struct_ov023_021f7158 { unsigned int a, b, c; };

// USA: func_ov023_021f7158
extern "C" ARM void func_ov023_021f7158(void* obj, struct Struct_ov023_021f7158* src) {
	struct Struct_ov023_021f7158* dst = (struct Struct_ov023_021f7158*)((char*)obj + 0x3c);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
