#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void*, void*, int, int);

struct Struct_ov023_021e2cc8 { char pad[0x8]; short field8; short fielda; };

// USA: func_ov023_021e2cc8
extern "C" ARM void* func_ov023_021e2cc8(void* a, void* b, int c, int d) {
	struct Struct_ov023_021e2cc8* r = (struct Struct_ov023_021e2cc8*)func_ov023_021e2418(a, b, c, d);
	if (r != 0) {
		r->field8 = (short)c;
		r->fielda = (short)d;
	}
	return r;
}
