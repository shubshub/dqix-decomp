#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021ab250 {
	unsigned char byte0;
	unsigned char pad1[7];
	int w8;
	int unknown_c_;
	unsigned char pad2[4];
	int unknown_14_;
	int unknown_18_;
	int unknown_1c_;
};

// USA: func_ov017_021ab250
extern "C" ARM void func_ov017_021ab250(Struct_ov017_021ab250* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 6;
	p->w8 = 0;
	p->unknown_c_ = 0;
	p->unknown_14_ = 0;
	p->unknown_18_ = 0;
	p->unknown_1c_ = 0;
}
