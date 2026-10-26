#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// USA: func_ov017_021c0760
extern "C" ARM void func_ov017_021c0760(unsigned char* obj, unsigned char flag) {
	func_0204693c((struct ByteHeader0204693c*)obj);
	obj[0] = 0x29;
	obj[0xbc] = flag;
	*(int*)(obj + 0x20) = 0;
	obj[0x24] = 0;
	*(int*)(obj + 0x1c) = 0;
	((SafeAllocator*)(obj + 0x8))->ResetAllocatorPointer();
	if (obj[0xbc] == 0) {
		return;
	}
	obj[0x25] = 0;
	obj[0x26] = 0;
	*(short*)(obj + 0x28) = -1;
	*(short*)(obj + 0x2a) = -1;
	*(short*)(obj + 0xa8) = 0;
	*(int*)(obj + 0xac) = 0;
	*(int*)(obj + 0xb0) = 0;
	*(int*)(obj + 0xb4) = 0;
	*(int*)(obj + 0xb8) = 0;
}
