#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" void* Zone3D_GetInstance(void);
struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Element0x318_02028bac { unsigned char data[0x318]; };
extern "C" struct Element0x318_02028bac* ZoneRecords_GetAt(struct Element0x318_02028bac* base, int index);
struct BigRecord020289c4;
extern "C" void ZoneRecord_Reset(struct BigRecord020289c4* obj);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion g_mainAllocator;

// USA: func_ov017_0219fec0
extern "C" ARM void func_ov017_0219fec0(void*) {
	Zone3D_GetInstance();
	struct Entry_02028bd0* entryTable = ZoneRecords_GetInstance();
	struct Element0x318_02028bac* elem0 = ZoneRecords_GetAt((struct Element0x318_02028bac*)entryTable, 0);
	ZoneRecord_Reset((struct BigRecord020289c4*)elem0);
	void* signedAlloc = (void*)(*(SafeAllocator**)((unsigned char*)elem0 + 0x10))->GetSignedAllocator();
	if (signedAlloc) {
		(*(SafeAllocator**)((unsigned char*)elem0 + 0x10))->Destroy();
		AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
	}
	for (int i = 0; i < 4; i++) {
		struct Element0x318_02028bac* elem = ZoneRecords_GetAt((struct Element0x318_02028bac*)entryTable, i);
		void* p = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x28a0);
		SafeAllocator* alloc = *(SafeAllocator**)((unsigned char*)elem + 0x10);
		alloc->CreateTypeA(p, 0x28a0);
	}
}
