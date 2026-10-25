#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void func_020a0c0c(void);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Obj021ac2a8 {
	char pad[0x10];
	SafeAllocator allocator;
};

// USA: func_ov017_021ac2a8  (semantic: FinalizeState30_021ac2a8)
extern "C" ARM void func_ov017_021ac2a8(struct Obj021ac2a8* self) {
	func_02057f00(func_02057924(self), 5);

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}

	func_020a0c0c();
}
