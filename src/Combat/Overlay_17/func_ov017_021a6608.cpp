#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021a65c4 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char b8;
	unsigned char unknown_9_;
	unsigned char unknown_a_;
	unsigned char unknown_b_;
	unsigned char unknown_c_;
	unsigned char pad2;
	unsigned short he;
	SafeAllocator alloc;
};

// USA: func_ov017_021a6608
extern "C" ARM void func_ov017_021a6608(Struct_ov017_021a65c4* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x3d;
	p->b8 = 0;
	p->he = (unsigned short)(p->b8 - 1);
	p->unknown_9_ = 0;
	p->unknown_a_ = 0;
	p->unknown_b_ = 0;
	p->unknown_c_ = 0;
	p->alloc.ResetAllocatorPointer();
}
