#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct_020979c0;
extern "C" void func_020979f4(Struct_020979c0* p);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

// USA: func_ov017_021c0364
extern "C" ARM void func_ov017_021c0364(char* self) {
	Struct_020979c0* p = *(Struct_020979c0**)(self + 0x1c);
	if (p != NULL) {
		func_020979f4(p);
	}
	void* signedAlloc = ((SafeAllocator*)(self + 0x8))->GetSignedAllocator();
	((SafeAllocator*)(self + 0x8))->Destroy();
	AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, signedAlloc);
}
