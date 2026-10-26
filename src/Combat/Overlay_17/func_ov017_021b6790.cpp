#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021b65e0 {
	unsigned char byte0;
	char pad1[0x8 - 0x1];
	SafeAllocator allocator;
	char pad2[0x1c - 0x8 - sizeof(SafeAllocator)];
	unsigned char unknown1_1c_;
	unsigned char unknown_1d_;
	unsigned char unknown_1e_;
	unsigned char unknown_1f_;
	unsigned char unknown_20_;
	char pad3[0x24 - 0x21];
	int f24;
};

// USA: func_ov017_021b6790
extern "C" ARM void func_ov017_021b6790(Struct_ov017_021b65e0* self) {
	func_0204693c((ByteHeader0204693c*)self);
	self->byte0 = 0x17;
	self->f24 = 0;
	self->unknown_1f_ = 0;
	self->unknown1_1c_ = 0;
	self->allocator.ResetAllocatorPointer();
	self->unknown_1d_ = 0;
	self->unknown_1e_ = 0xff;
	self->unknown_20_ = self->unknown_1e_ - 0x100;
}
