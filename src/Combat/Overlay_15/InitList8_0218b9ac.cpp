#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Entry8_0218b9ac { int a; int b; };
struct List8_0218b9ac { void* f0; Entry8_0218b9ac* arr; void* f8; int count; };

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov015_0218b9ac
ARM void InitList8_0218b9ac(struct List8_0218b9ac* obj, int n) {
	obj->arr = (Entry8_0218b9ac*)AllocatorUnion_AllocateRounded(&g_mainAllocator, n * 8);
	obj->count = 0;
}
