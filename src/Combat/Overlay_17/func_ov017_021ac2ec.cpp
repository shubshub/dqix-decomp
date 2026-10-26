#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_0219931c {
	unsigned char byte0;
	unsigned char pad1[7];
	int f8;
	int fc;
	SafeAllocator alloc;
	int f24;
	unsigned char unknown_28_;
	unsigned char unknown_29_;
};

// USA: func_ov017_021ac2ec
extern "C" ARM void func_ov017_021ac2ec(Struct_ov017_0219931c* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x1e;
	p->f8 = 0;
	p->fc = 0;
	p->alloc.ResetAllocatorPointer();
	p->f24 = -1;
	p->unknown_28_ = 0;
	p->unknown_29_ = 0;
}
