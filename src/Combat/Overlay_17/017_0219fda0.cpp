#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

extern "C" void* Zone3D_GetInstance(void);
struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Element0x318_02028bac {
	unsigned short kind;
	unsigned short flags;
	unsigned char unk4[0xc];
	SafeAllocator* allocator;
#if defined(jpn)
	unsigned char unk14[0x2f4];
#else
	unsigned char unk14[0x2f8];
#endif
	unsigned char buffers[0xc];
};
struct Element0x318_02028bac* GetElementStride0x318(struct Element0x318_02028bac* base, int index);
struct BigRecord020289c4;
void InitializeSubObjectsAndFields020289c4(struct BigRecord020289c4* obj);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void Clear12Bytes020a8e88(void* p);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
struct Obj020a8e9c;
void DeserializeElementBuffers020a8e9c(Obj020a8e9c*, SafeAllocator*, void*, unsigned int);

extern AllocatorUnion g_mainAllocator;
extern const char data_ov017_021d7638[];
extern unsigned char g_fileLoadBuffer[0x30000];
#pragma opt_propagation off

// USA: func_ov017_0219fda0  (semantic: ResetEntriesAndReloadCombatData_0219fda0)
extern "C" ARM void func_ov017_0219fda0(void) {
	GameState* battle = GameState::GetInstance();
	Zone3D_GetInstance();
	struct Entry_02028bd0* entryTable = ZoneRecords_GetInstance();
	for (int i = 0; i < 4; i++) {
		struct Element0x318_02028bac* elem = GetElementStride0x318((struct Element0x318_02028bac*)entryTable, i);
		InitializeSubObjectsAndFields020289c4((struct BigRecord020289c4*)elem);
		void* signedAlloc = (void*)elem->allocator->GetSignedAllocator();
		if (signedAlloc) {
			elem->allocator->Destroy();
			AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
		}
	}
	for (int id = 0x70; id <= 0x9f; id++) {
		ClearCombatantSlot_0200fd48(battle, id);
	}
	struct Element0x318_02028bac* elem0 = GetElementStride0x318((struct Element0x318_02028bac*)entryTable, 0);
	unsigned int size = 0xa000;
	elem0->flags |= 4;
	elem0->kind = 3;
	void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
	elem0->allocator->CreateTypeA(buffer, size);
	if (elem0 == NULL) return;
	Clear12Bytes020a8e88(elem0->buffers);
	BackgroundLoader::AddLockGlobal();
	unsigned int fileSize;
	if (LoadFileIntoMemory(data_ov017_021d7638, g_fileLoadBuffer, &fileSize) != NULL) {
		DeserializeElementBuffers020a8e9c((Obj020a8e9c*)elem0->buffers, elem0->allocator, g_fileLoadBuffer, fileSize);
	}
	BackgroundLoader::RemoveLockGlobal();
}
