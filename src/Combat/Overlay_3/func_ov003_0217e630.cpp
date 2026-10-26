#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(ByteHeader0204693c* p);

// USA: func_ov003_0217e630
extern "C" ARM void func_ov003_0217e630(void* obj, signed char flag) {
	func_0204693c((ByteHeader0204693c*)obj);
	*(unsigned char*)((char*)obj + 0x0) = 0x18;
	*(int*)((char*)obj + 0x20) = 0;
	*(int*)((char*)obj + 0x1c) = 0;
	*(signed char*)((char*)obj + 0xb4) = flag;
	((SafeAllocator*)((char*)obj + 0x8))->ResetAllocatorPointer();
	*(unsigned short*)((char*)obj + 0xa0) = 0;
	*(int*)((char*)obj + 0xa4) = 0;
	*(int*)((char*)obj + 0xa8) = 0;
	*(int*)((char*)obj + 0xac) = 0;
	*(int*)((char*)obj + 0xb0) = 0;
}
