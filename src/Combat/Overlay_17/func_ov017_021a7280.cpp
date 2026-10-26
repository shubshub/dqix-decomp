#include <globaldefs.h>

#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#endif
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"
#if defined(jpn)
#define func_ov017_021a7c28 func_ov017_021a85b8
#endif

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
extern "C" void ROMFilesystem_InitFileTables(void);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void SePlayer_UnloadExtraArchiveB(void* obj);

extern char g_sePlayer;
extern int g_mainAllocator;

struct Struct_ov017_021a7280 {
	char pad[0x30];
	SafeAllocator allocator;
};

// USA: func_ov017_021a7280
extern "C" ARM void func_ov017_021a7280(struct Struct_ov017_021a7280* self) {
	func_02057f00(func_02057924(self), 0xd);

	GameObject_EnableControl(GameState::GetInstance()->GetLeader());

	SePlayer_UnloadExtraArchiveB(&g_sePlayer);

	void* p = self->allocator.GetSignedAllocator();
	if (p != NULL) {
		self->allocator.Destroy();
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}

	ROMFilesystem_InitFileTables();
}
