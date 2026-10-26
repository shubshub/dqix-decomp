#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Obj021abb68 {
	unsigned char byte0;
	unsigned char pad1[7];
	unsigned char b8;
	unsigned char pad2;
	unsigned short ha;
	unsigned char unknown_c_;
	unsigned char unknown_d_;
	unsigned char pad3[2];
	SafeAllocator alloc;
	int f24;
};

// USA: func_ov017_021abb68
extern "C" ARM void func_ov017_021abb68(Obj021abb68* p, unsigned char b) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x1c;
	p->b8 = 0;
	p->ha = 0;
	p->unknown_c_ = b;
	p->f24 = -1;
	p->unknown_d_ = 0;
	p->alloc.ResetAllocatorPointer();
}
