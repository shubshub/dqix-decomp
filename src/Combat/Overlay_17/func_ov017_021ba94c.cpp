#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void func_020a1e54(int flag);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct_ov017_021ba94c {
	char pad0[0x8];
	SafeAllocator allocator;
	void* field1c;
};

// USA: func_ov017_021ba94c
extern "C" ARM void func_ov017_021ba94c(struct Struct_ov017_021ba94c* self) {
	if (self->field1c != NULL) {
		func_020a1e54(1);
		self->field1c = NULL;
	}

	void* p = self->allocator.GetSignedAllocator();
	self->allocator.Destroy();
	AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
}
