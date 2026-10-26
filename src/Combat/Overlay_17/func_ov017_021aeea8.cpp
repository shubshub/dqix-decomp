#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct_ov017_021aeea8 {
	char pad[0x2c];
	SafeAllocator allocator;
};

// USA: func_ov017_021aeea8
extern "C" ARM void func_ov017_021aeea8(struct Struct_ov017_021aeea8* self) {
	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}
}
