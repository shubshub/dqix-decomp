#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021aa4cc {
	unsigned char byte0;
	unsigned char pad0[7];
	int f8;
	int fc;
	int f10;
	int f14;
	int f18;
	int f1c;
	int f20;
	SafeAllocator alloc;
	int unknown_38_;
	int f3c;
	int f40;
	int unknown_44_;
	short unknown_48_;
	short unknown_4a_;
	short unknown_4c_;
	short unknown_4e_;
	int unknown_50_;
	int unknown_54_;
	int unknown_58_;
	unsigned char unknown_5c_;
	unsigned char unknown_5d_[3];
	int f60;
	int f64;
};

// USA: func_ov017_021aa50c
extern "C" ARM void func_ov017_021aa50c(Struct_ov017_021aa4cc* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x1a;
	p->fc = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
	p->f8 = 0;
	p->f18 = 0;
	p->f20 = 0;
	p->f1c = 0;
	p->alloc.ResetAllocatorPointer();
	p->unknown_38_ = 0;
	p->f3c = 0;
	p->f40 = 0;
	p->unknown_44_ = 0;
	p->unknown_48_ = -1;
	p->unknown_4a_ = -1;
	p->unknown_4c_ = -0xb;
	p->unknown_50_ = -1;
	p->f10 = 0;
	p->f14 = 0;
	p->unknown_54_ = 0;
	p->unknown_58_ = 0;
	p->unknown_5c_ = 0;
	p->f60 = 0;
	p->f64 = 0;
}
