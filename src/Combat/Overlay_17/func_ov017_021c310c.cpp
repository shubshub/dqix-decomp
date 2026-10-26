#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void func_02057f00(void* self, int code);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_sePlayer;
extern int g_mainAllocator;

struct Struct_ov017_021c310c {
	char pad[0x8];
	SafeAllocator allocator;
	char pad2[0x90 - 0x8 - sizeof(SafeAllocator)];
	void* f90;
};

// USA: func_ov017_021c310c
extern "C" ARM void func_ov017_021c310c(struct Struct_ov017_021c310c* self) {
	if (self->f90 != NULL) {
		void* obj = func_02057924(self->f90);
		SePlayer_UnloadExtraArchiveB((void*)&g_sePlayer);
		func_02057f00(obj, 0x11);
	}

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}
}
