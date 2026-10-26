#include <globaldefs.h>

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov003_02164400 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char b8;
	unsigned char pad2[6];
	signed char unknown_f_;
	signed char b10;
	unsigned char pad3;
	unsigned short unknown_12_;
};

// USA: func_ov017_021aeedc
extern "C" ARM void func_ov017_021aeedc(Struct_ov003_02164400* p) {
	signed char var0 = 0 - 1;
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x25;
	p->b8 = 0;
	p->unknown_f_ = var0;
	p->unknown_12_ = 0;
	p->b10 = var0;
}
