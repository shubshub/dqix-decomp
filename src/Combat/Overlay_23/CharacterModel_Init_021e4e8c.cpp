#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Graphics/CharacterModel.h"

// Overlay 23, originally InitTenAllocatorsAndClearFields_021e4e8c (USA/EUR 0x021e4e8c, JPN 0x021e5080)
extern "C" ARM void CharacterModel_Init(void* obj) {
	CharacterModel* model = (CharacterModel*)obj;
	model->forceStandAnimation_ = 0;
	for (int i = 0; i < 10; i++) {
		model->parts_[i].Initialize();
		model->allocators_[i].ResetAllocatorPointer();
	}
	model->animationAllocator_.ResetAllocatorPointer();
	model->holdsWithArms_ = 0;

#if defined(jpn)
	memset(model->tasks_, 0, sizeof(model->tasks_));
#else
	for (int i = 0; i < 12; i++) {
		model->tasks_[i] = -1;
	}
#endif
	model->loading_ = 0;
	model->vocation_ = 0;
	model->member_ = 0;
	model->visible_ = 1;
}
