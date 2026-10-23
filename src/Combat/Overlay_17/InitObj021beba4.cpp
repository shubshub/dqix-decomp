#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
struct Struct020dfc40;
void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_ov017_021beba4
ARM void InitObj021beba4(char* obj) {
	ResetByteHeader((struct ByteHeader0204693c*)obj);
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
