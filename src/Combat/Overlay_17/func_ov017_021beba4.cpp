#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);
struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_ov017_021beba4
extern "C" ARM void func_ov017_021beba4(char* obj) {
	func_0204693c((struct ByteHeader0204693c*)obj);
	obj[0] = 0x34;
	for (int i = 0; i < 0xb; i++) {
		*(int*)(obj + i * 4 + 0x8) = -1;
	}
	obj[0x34] = 0;
	*(int*)(obj + 0x38) = 0;
	*(int*)(obj + 0x40) = -1;
	((SafeAllocator*)(obj + 0x44))->ResetAllocatorPointer();
	KeyTable_Reset((struct Struct020dfc40*)(obj + 0x58));
}
