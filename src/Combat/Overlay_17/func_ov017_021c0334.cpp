#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021c0334 {
	unsigned char byte0;
	unsigned char pad1[7];
	SafeAllocator alloc;
	int f1c;
	int f20;
	unsigned char unknown_24_;
};

// USA: func_ov017_021c0334
extern "C" ARM void func_ov017_021c0334(Struct_ov017_021c0334* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x28;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	p->f20 = 0;
	p->unknown_24_ = 0;
}
