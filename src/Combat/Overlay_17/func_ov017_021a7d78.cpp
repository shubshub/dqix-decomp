#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021a7c94 {
	unsigned char byte0;
	unsigned char pad0[7];
	SafeAllocator alloc;
	int f1c;
	int f20;
	int f24;
	int f28;
	int unknown_2c_;
	short unknown_30_;
	short unknown_32_;
	int f34;
	short unknown_38_;
	short unknown_3a_;
	int f3c;
	int f40;
	int unknown_44_;
	int unknown_48_;
	int unknown_4c_;
};

// USA: func_ov017_021a7d78
extern "C" ARM void func_ov017_021a7d78(Struct_ov017_021a7c94* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x41;
	p->alloc.ResetAllocatorPointer();
	p->f1c = 0;
	p->f20 = 0;
	p->f24 = 0;
	p->f28 = -1;
	p->unknown_2c_ = 0;
	p->unknown_30_ = -1;
	p->f34 = -1;
	p->unknown_38_ = 0;
	p->unknown_3a_ = 0;
#if !defined(jpn)
	p->f3c = 0;
	p->f40 = 0;
	p->unknown_44_ = 0;
	p->unknown_48_ = 0;
	p->unknown_4c_ = 0;
#endif
}
