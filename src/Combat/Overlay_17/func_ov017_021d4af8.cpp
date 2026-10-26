#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov017_021d4af8_3 { int f0; int f4; int f8; };
struct Struct_ov017_021d4af8 { int f0; char pad4[4]; int f8; int fc; };

struct Struct_ov017_021d4af8_2 {
	char pad0[0x14];
	int f14;
	char pad1[0x28 - 0x14 - 4];
	struct Struct_ov017_021d4af8_3* f28;
	struct Struct_ov017_021d4af8_3* unknown_2c_;
	int unknown_30_;
	struct Struct_ov017_021d4af8* f34;
	char pad2[0x48 - 0x34 - 4];
	int unknown_48_;
};

extern "C" void func_0200159c(int code);

// USA: func_ov017_021d4af8
extern "C" ARM int func_ov017_021d4af8(struct Struct_ov017_021d4af8_2* self, struct Struct_ov017_021d4af8* arg, int value) {
	struct Struct_ov017_021d4af8_3* dst = self->f28;
	if (dst >= self->unknown_2c_) {
		func_0200159c(-2);
	}
	dst->f0 = value;
	self->f28->f8 = (int)self->f34;
	self->f28->f4 = self->unknown_30_;

	self->unknown_30_ = self->f14 - (arg->fc << 3);
	self->f14 = self->unknown_30_ + (arg->f8 << 3);
	self->f34 = arg;
	self->f28 = (struct Struct_ov017_021d4af8_3*)((char*)self->f28 + 0xc);

	memset((void*)(self->unknown_30_ + (self->f34->fc << 3)), 0, (self->f34->f8 - self->f34->fc) << 3);

	return self->unknown_48_ + arg->f0;
}
