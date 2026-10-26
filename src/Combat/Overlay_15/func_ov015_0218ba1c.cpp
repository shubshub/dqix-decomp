#include <globaldefs.h>

struct Struct_ov015_0218b6e4 { int a; int b; };
struct Struct_ov015_0218ba1c { void* f0; Struct_ov015_0218b6e4* arr; void* f8; int count; };

// USA: func_ov015_0218ba1c
extern "C" ARM void func_ov015_0218ba1c(struct Struct_ov015_0218ba1c* obj, struct Struct_ov015_0218b6e4* src) {
	int idx = obj->count;
	obj->count = idx + 1;
	struct Struct_ov015_0218b6e4* dst = &obj->arr[idx];
	dst->a = src->a;
	dst->b = src->b;
}
