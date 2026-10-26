#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov017_021c07d0(void* p);

struct Struct_ov017_021c0580 {
	unsigned char pad0[8];
	SafeAllocator alloc;
	int f1c;
	int f20;
	unsigned char unknown_24_;
	unsigned char pad2[0xbc - 0x25];
	unsigned char unknown_bc_;
};

// USA: func_ov017_021c0820
extern "C" ARM void func_ov017_021c0820(Struct_ov017_021c0580* p) {
	func_ov017_021c07d0(p);
	p->f20 = 0;
	p->unknown_24_ = 0;
	p->f1c = 0;
	p->alloc.ResetAllocatorPointer();
	p->unknown_bc_ = 0;
}
