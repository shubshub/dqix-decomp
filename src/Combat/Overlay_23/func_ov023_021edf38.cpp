#include <globaldefs.h>

struct Struct_ov023_021edc08_5 { unsigned int a, b, c; };

// USA: func_ov023_021edf38
extern "C" ARM void func_ov023_021edf38(void* obj, struct Struct_ov023_021edc08_5* src) {
	struct Struct_ov023_021edc08_5* dst = (struct Struct_ov023_021edc08_5*)((char*)obj + 0x0);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
