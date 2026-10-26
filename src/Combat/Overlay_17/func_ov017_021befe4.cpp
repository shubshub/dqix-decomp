#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_020727d8 { void* entries; short capacity; short count; };
extern "C" void func_020727d8(Struct_020727d8* list);

struct Struct_ov017_021befe4 {
	unsigned char byte0;
	unsigned char pad1[7];
	int f8;
	Struct_020727d8 unknown_c_;
	SafeAllocator alloc;
};

// USA: func_ov017_021befe4
extern "C" ARM void func_ov017_021befe4(Struct_ov017_021befe4* p) {
	func_0204693c((ByteHeader0204693c*)p);
	p->byte0 = 0x35;
	p->f8 = 0;
	func_020727d8(&p->unknown_c_);
	p->alloc.ResetAllocatorPointer();
}
