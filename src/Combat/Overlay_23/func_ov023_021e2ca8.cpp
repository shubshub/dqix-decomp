#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void*, void*, int, int);

struct Struct_ov023_021e2ca8 { char pad[0x4]; short field4; short field6; };

// USA: func_ov023_021e2ca8
extern "C" ARM void* func_ov023_021e2ca8(void* a, void* b, int c, int d) {
	struct Struct_ov023_021e2ca8* r = (struct Struct_ov023_021e2ca8*)func_ov023_021e2418(a, b, c, d);
	if (r != 0) {
		r->field4 = (short)c;
		r->field6 = (short)d;
	}
	return r;
}
