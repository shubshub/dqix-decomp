#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

extern int data_ov017_021d83ec;

struct Struct_ov017_021b146c {
	unsigned char byte0;
	unsigned char pad0[7];
	SafeAllocator alloc;
	int f1c;
	unsigned char pad20[0x10];
	unsigned char unknown_30_;
	unsigned char unknown_31_;
	unsigned char unknown_32_[0x16];
	unsigned char unknown_48_;
	unsigned char unknown_49_;
	unsigned char unknown_4a_;
};

// USA: func_ov017_021b14a0
extern "C" ARM void func_ov017_021b14a0(Struct_ov017_021b146c* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x2b;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	data_ov017_021d83ec = 0;
	p->unknown_30_ = 0;
	p->unknown_31_ = 0;
	p->unknown_48_ = 0;
	p->unknown_49_ = 1;
	p->unknown_4a_ = 0;
}
