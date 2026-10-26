#include <globaldefs.h>

typedef void (*Type_ov017_021d4bc8)(void*, int);

struct Struct_ov017_021d4bc8_2 { unsigned char pad[4]; int count; Type_ov017_021d4bc8* unknown_8_; };
struct Struct_ov017_021d4bc8 { unsigned char pad[4]; int idx; unsigned char data[1]; };

// USA: func_ov017_021d4bc8
extern "C" ARM void func_ov017_021d4bc8(Struct_ov017_021d4bc8_2* a, Struct_ov017_021d4bc8* b, int c) {
	int idx = b->idx;
	if (idx < 0) return;
	if (idx >= a->count) return;
	Type_ov017_021d4bc8 fn = a->unknown_8_[idx];
	if (!fn) return;
	fn(&b->data, c - 1);
}
