#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Struct_ov017_021beb48 {
	char pad[0x24];
	SafeAllocator allocator;
};

// USA: func_ov017_021beb48
extern "C" ARM void func_ov017_021beb48(struct Struct_ov017_021beb48* self) {
	func_02057f00(func_02057924(self), 5);

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}

	ROMFilesystem_InitFileTables();
}
