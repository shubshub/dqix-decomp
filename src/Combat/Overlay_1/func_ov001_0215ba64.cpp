#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" int func_ov001_0215ad2c(int x);
extern SafeAllocator* data_ov001_021658b8[8];
extern "C" void func_0200fd38(GameState* battleStruct, int id, GameObject* combatant);
struct Struct_0203d028_18;

// USA: func_ov001_0215ba64
extern "C" ARM int func_ov001_0215ba64(char* self, int type) {
	GameState* bs = GameState::GetInstance();
	(int)BackgroundLoader::GetInstance();

	int var1 = func_ov001_0215ad2c(func_ov017_021d60f4(self));
	int id2 = func_ov001_0215ad2c(func_ov017_021d60f4(self + 0x8));

	int sel = 0;
	if (type >= 3) {
		sel = func_ov017_021d60f4(self + 0x10);
	}

	SafeAllocator* allocator = data_ov001_021658b8[sel];

	GameObject* combatant = bs->GetGameObjectByIndex(var1);
	if (combatant == NULL) return 0;

	void* newObj = allocator->Allocate(0xac);
	if (newObj == NULL) return 0;

	((Object3D*)newObj)->Initialize();
	combatant->obj3D_.ShallowCloneTo((Object3D*)newObj);
	func_0200fd38(bs, id2, (GameObject*)newObj);
	((Object3D*)((struct Struct_0203d028_18*)newObj))->SetScale(0x10a, 0x10a, 0x10a);
	((Object3D*)newObj)->SetAnimationByIndex(0, 0);
	return 1;
}
