#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

void GameObject_EnableControl(void* obj);
int GameState_GetFollowCamera(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

struct List020727d8;
void ResetListHeader020727ec(struct List020727d8* list);

// Overlay 17, originally ClearFieldsAndResetAllocator_021bf398 (USA/EUR 0x021bf398, JPN 0x021bf944)
ARM void FieldTask_EndPutAwayTreasureMap(char* self) {
	GameState* battle = GameState::GetInstance();
	int flagResult = GameState_GetFollowCamera((char*)battle);
	GameObject* combatant = battle->GetLeader();
	SetField0x23cTrue_020a27ac((void*)flagResult);
	GameObject_EnableControl(combatant);
	SafeAllocator* allocator = (SafeAllocator*)(self + 0x14);
	void* p = allocator->GetSignedAllocator();
	if (p) {
		allocator->Reset();
		allocator->Destroy();
		ResetListHeader020727ec((struct List020727d8*)(self + 0xc));
		AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
	}
	self[1] = 1;
}
