#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_ov003_0217ef24 {
	unsigned char byte0;              // 0x0
	char pad1[0xc - 1];
	int unknown_c_;                     // 0xc
	int unknown_10_;                    // 0x10
	char pad2[0x28 - 0x14];
	unsigned char unknown_28_;          // 0x28
	char pad3[0x3a - 0x29];
	unsigned char unknown_3a_;          // 0x3a
	unsigned char unknown_3b_;          // 0x3b
};

// USA: func_ov003_0217ef24
extern "C" ARM void func_ov003_0217ef24(struct Struct_ov003_0217ef24* p) {
	func_0204693c((struct ByteHeader0204693c*)p);
	p->byte0 = 0x2a;
	p->unknown_c_ = 0;
	p->unknown_10_ = 0;
	p->unknown_3a_ = 0;
	p->unknown_3b_ = 0;
	p->unknown_28_ = 0xff;
}
