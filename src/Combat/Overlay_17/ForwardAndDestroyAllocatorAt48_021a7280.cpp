#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#endif
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void func_020a0c0c(void);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void GameObject_EnableControl(void* obj);
void SePlayer_UnloadExtraArchiveB(void* obj);

extern char g_sePlayer;
extern int g_mainAllocator;

struct Obj021a7280 {
	char pad[0x30];
	SafeAllocator allocator;
};

// USA: func_ov017_021a7280  (semantic: ForwardAndDestroyAllocatorAt48_021a7280)
extern "C" ARM void func_ov017_021a7280(struct Obj021a7280* self) {
	func_02057f00(func_02057924(self), 0xd);

	GameObject_EnableControl(GameState::GetInstance()->GetUnknownGameObject());

	SePlayer_UnloadExtraArchiveB(&g_sePlayer);

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}

	func_020a0c0c();
}
