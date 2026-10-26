#include <globaldefs.h>

struct Struct_ov014_02186bc8_2 {
	unsigned char pad0[0xd0];
	short* unknown_d0_;
	unsigned char pad1[0x17a - 0xd4];
	unsigned char unknown_17a_;
	unsigned char unknown_17b_;
	unsigned char pad2[0x17f - 0x17c];
	unsigned char unknown_17f_;
};

// USA: func_ov014_02186df0
extern "C" ARM void func_ov014_02186df0(struct Struct_ov014_02186bc8_2* o) {
	if (o->unknown_17f_ != 0) return;
	o->unknown_17f_ = 1;
	short* p = o->unknown_d0_;
	if (p != NULL) *p = -1;
	o->unknown_d0_ = NULL;
	o->unknown_17a_ = 5;
	o->unknown_17b_ = 0;
}
