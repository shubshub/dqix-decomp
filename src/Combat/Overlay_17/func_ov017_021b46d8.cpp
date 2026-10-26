#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_0219dc90_3 {
	unsigned char byte0;
	unsigned char pad1[7];
	int unknown_8_;
	int unknown_c_;
	unsigned char unknown_10_;
	unsigned char unknown_11_;
	unsigned short unknown_12_;
	int unknown_14_;
};

// USA: func_ov017_021b46d8
extern "C" ARM void func_ov017_021b46d8(struct Struct_ov017_0219dc90_3* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x14;
	p->unknown_8_ = 0;
	p->unknown_10_ = 0;
	p->unknown_c_ = -1;
	p->unknown_12_ = 0;
#if !defined(jpn)
	p->unknown_14_ = 0;
#endif
	p->unknown_11_ = 0;
}
