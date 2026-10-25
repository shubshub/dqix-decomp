#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

void CleanupAndReinitCombatState_021e2f38(void* obj);
void PopStack0AndTrigger_020a1e54(int flag);
void PopStack1AndTrigger_020a1f4c(int flag);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern int g_mainAllocator;

struct Obj021a18c8 {
	char pad[0x8];
	SafeAllocator allocator;
};

// USA: func_ov017_021a18c8  (semantic: ResetFlagAndDestroyAllocator_021a18c8)
extern "C" ARM void func_ov017_021a18c8(struct Obj021a18c8* self) {
	int flag = *(int*)((char*)self + 0x1c);
	if (flag != 0) {
		CleanupAndReinitCombatState_021e2f38((void*)flag);
		*(int*)((char*)self + 0x1c) = 0;
		PopStack0AndTrigger_020a1e54(1);
		PopStack1AndTrigger_020a1f4c(1);
	}

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}
}
