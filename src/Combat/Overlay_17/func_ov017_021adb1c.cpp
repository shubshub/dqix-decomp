#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct_ov017_021adb1c {
	char pad[0x8];
	SafeAllocator allocator;
};

// USA: func_ov017_021adb1c
extern "C" ARM void func_ov017_021adb1c(struct Struct_ov017_021adb1c* self) {
	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}
}
