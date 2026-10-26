#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);
struct Struct_020a3578;
extern "C" void func_020a3578(struct Struct_020a3578* s);

// USA: func_ov017_021b6f18
extern "C" ARM void func_ov017_021b6f18(char* self) {
	func_0204693c((struct ByteHeader0204693c*)self);
	self[0] = 0xa;
	((SafeAllocator*)(self + 8))->ResetAllocatorPointer();
	func_020a3578((struct Struct_020a3578*)(self + 0x1c));

	*(int*)(self + 0x6ac) = 0;
	*(int*)(self + 0x6b0) = 0;
	*(unsigned short*)(self + 0x600 + 0xb4) = 1;
	*(unsigned short*)(self + 0x600 + 0xb6) = 0;
	*(int*)(self + 0x6b8) = 0;
	*(unsigned char*)(self + 0x6bd) = 0xff;
	*(unsigned char*)(self + 0x6bc) = 0xff;
	*(signed char*)(self + 0x6be) = -1;

	memset(self + 0x6c0, 0, 3);

	self[0x6c3] = 0;
	*(unsigned short*)(self + 0x600 + 0xc4) = 0;
	self[0x6c7] = 0;
	*(unsigned short*)(self + 0x600 + 0xc8) = 0;
	self[0x6c6] = 0;
}
