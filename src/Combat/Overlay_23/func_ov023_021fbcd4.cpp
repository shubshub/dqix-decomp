#include <globaldefs.h>

struct Struct_ov023_021fbcd4 { unsigned int a, b, c; };

// USA: func_ov023_021fbcd4
extern "C" ARM void func_ov023_021fbcd4(void* obj, struct Struct_ov023_021fbcd4* src) {
	struct Struct_ov023_021fbcd4* dst = (struct Struct_ov023_021fbcd4*)((char*)obj + 0x20);
	dst->a = src->a;
	dst->b = src->b;
	dst->c = src->c;
}
