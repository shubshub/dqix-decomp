#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Entry8_0218b9ac { int a; int b; };
struct Struct_ov015_0218b6bc { void* f0; Entry8_0218b9ac* arr; void* f8; int count; };

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_0218b9ac
extern "C" ARM void func_ov015_0218b9ac(struct Struct_ov015_0218b6bc* obj, int n) {
	obj->arr = (Entry8_0218b9ac*)AllocatorUnion_AllocateRounded(&g_mainAllocator, n * 8);
	obj->count = 0;
}
