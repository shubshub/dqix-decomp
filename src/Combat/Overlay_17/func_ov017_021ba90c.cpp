#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_0219bfb4 {
	unsigned char byte0;
	unsigned char pad1[7];
	SafeAllocator alloc;
	int f1c;
	unsigned char unknown_20_;
	unsigned char unknown_21_;
	unsigned char unknown_22_;
	unsigned char unknown_23_;
};

// USA: func_ov017_021ba90c
extern "C" ARM void func_ov017_021ba90c(Struct_ov017_0219bfb4* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x10;
	p->unknown_22_ = 0;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	p->unknown_20_ = 0;
	p->unknown_21_ = 0;
	p->unknown_23_ = 0xff;
}
