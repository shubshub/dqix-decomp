#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov024_021f68c8;
extern "C" void func_ov024_021f68c8(struct Struct_ov024_021f68c8* arr);

// USA: func_ov024_021f73b8
extern "C" ARM void func_ov024_021f73b8(void* objRaw) {
	char* obj = (char*)objRaw;
	*(int*)(obj + 0x74) = 0;
	*(int*)(obj + 0x78) = 0;
	*(int*)(obj + 0x9c) = 0;
	for (int i = 0; i < 3; i++) {
		*(int*)(obj + 0xb8 + i * 4) = 0;
	}
	memset(obj + 0xe4, 0, 0x20);
	*(int*)(obj + 0x174) = 0;
	func_ov024_021f68c8((struct Struct_ov024_021f68c8*)(obj + 0x378));
	memset(obj + 0x10, 0, 0x15);
	*(unsigned char*)(obj + 0x7) = 0;
	*(unsigned char*)(obj + 0x139) = 0;
	memset(obj + 0x104, 0, 0x10);
	memset(obj + 0x114, 0, 0x10);
	memset(obj + 0x44, 0, 0x10);
	memset(obj + 0x13c, 0, 0x18);
	memset(obj + 0x154, 0, 0x18);
}
