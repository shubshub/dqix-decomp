#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

extern int data_ov014_02189800;

struct Struct_ov014_021844c4;
struct Struct_ov014_021845ec;
extern "C" ARM int func_ov014_02188d10(struct Struct_ov014_021845ec* s);
extern "C" ARM void func_02096fc4(void* p);
extern "C" ARM int func_ov014_02188bd0(struct Struct_ov014_021844c4* s);
extern "C" ARM void GameState_SetCamera(GameState* battleStruct, int value);

struct Struct_ov014_021845ec_2 {
	char pad0[0xc];
	char unknown_c_[0x10];
	char unknown_1c_[0x1e];
	char unknown_3a_[2];
	SafeAllocator* allocs;
	char unknown_40_[0x2c];
	int f6c;
	int unknown_70_;
	char unknown_74_[0x12];
	short unknown_86_[5];
};

// USA: func_ov014_021845ec
extern "C" ARM void func_ov014_021845ec(struct Struct_ov014_021845ec_2* obj) {
	if (obj->f6c >= 0) {
		BackgroundLoader* loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(obj->f6c);
		obj->f6c = -1;
	}
	if (obj->unknown_70_ >= 0) {
		BackgroundLoader* loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(obj->unknown_70_);
		obj->unknown_70_ = -1;
	}
	for (int i = 0; i < 5; i++) {
		if (obj->unknown_86_[i] >= 0) {
			BackgroundLoader::GetInstance()->RemoveTask(obj->unknown_86_[i]);
			obj->unknown_86_[i] = -1;
		}
	}
	func_ov014_02188d10((struct Struct_ov014_021845ec*)obj->unknown_1c_);
	func_02096fc4(obj->unknown_c_);
	func_ov014_02188bd0((struct Struct_ov014_021844c4*)obj->unknown_1c_);
	GameState* battle = GameState::GetInstance();
	GameState_SetCamera(battle, *(int*)((char*)&data_ov014_02189800 + 0xc));
	*(int*)((char*)&data_ov014_02189800 + 0xc) = 0;
	void* d = LightingManager::GetInstance();
	*((unsigned char*)d + 0x85) = 1;
	if (obj->allocs == 0) {
		return;
	}
	for (int j = 0; j < 6; j++) {
		if (obj->allocs[j].GetSignedAllocator()) {
			obj->allocs[j].Destroy();
		}
	}
}
