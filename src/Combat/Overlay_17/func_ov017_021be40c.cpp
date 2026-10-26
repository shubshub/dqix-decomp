#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory.h"

struct ByteHeader0204693c { signed char byte0, unknown_1_, unknown_2_, unknown_3_; };
extern "C" void func_0204693c(ByteHeader0204693c* p);

struct Struct_ov017_021be40c {
	ByteHeader0204693c header;  // 0x0
	unsigned char pad4[4];      // 0x4
	int f8;                     // 0x8
	int fc;                     // 0xc
	int f10;                    // 0x10
	int f14;                    // 0x14
	int f18;                    // 0x18
	int f1c;                    // 0x1c
	int f20;                    // 0x20
	SafeAllocator allocator;    // 0x24
	unsigned char unknown_38_;          // 0x38
	unsigned char unknown_39_;          // 0x39
	unsigned char buf[0x10];    // 0x3a
};

// USA: func_ov017_021be40c
extern "C" ARM void func_ov017_021be40c(Struct_ov017_021be40c* obj) {
	func_0204693c(&obj->header);
	obj->header.byte0 = 0x4e;
	obj->f8 = 0;
	obj->fc = 0;
	obj->f20 = -1;
	obj->f1c = 0;
	obj->unknown_38_ = 0;
	obj->allocator.ResetAllocatorPointer();
	obj->f10 = 0;
	obj->f14 = 0;
	obj->f18 = 0;
	obj->unknown_39_ = 0;
	VectorizedMemset(obj->buf, 0, 0x10);
}
