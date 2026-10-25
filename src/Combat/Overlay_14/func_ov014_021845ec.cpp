#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

extern int data_ov014_02189800;

struct HandleState_02188bd0;
struct HandleState_02188d10;
ARM int ResetHandle_02188d10(struct HandleState_02188d10* s);
ARM void Clear0x10Bytes02096fc4(void* p);
ARM int InitHandleState_02188bd0(struct HandleState_02188bd0* s);
ARM void GameState_SetCamera(GameState* battleStruct, int value);

struct Struct_ov014_021845ec_2 {
	char unknown_0_[0xc];
	char unknown_c_[0x10];
	char unknown_1c_[0x1e];
	char unknown_3a_[2];
	SafeAllocator* unknown_3c_;
	char unknown_40_[0x2c];
	int unknown_6c_;
	int unknown_70_;
	char unknown_74_[0x12];
	short unknown_86_[5];
};

// USA: func_ov014_021845ec
extern "C" ARM void func_ov014_021845ec(struct Struct_ov014_021845ec_2* arg0) {
	if (arg0->unknown_6c_ >= 0) {
		BackgroundLoader* var0 = BackgroundLoader::GetInstance();
		var0->RemoveTask(arg0->unknown_6c_);
		arg0->unknown_6c_ = -1;
	}
	if (arg0->unknown_70_ >= 0) {
		BackgroundLoader* var1 = BackgroundLoader::GetInstance();
		var1->RemoveTask(arg0->unknown_70_);
		arg0->unknown_70_ = -1;
	}
	for (int var2 = 0; var2 < 5; var2++) {
		if (arg0->unknown_86_[var2] >= 0) {
			BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_86_[var2]);
			arg0->unknown_86_[var2] = -1;
		}
	}
	ResetHandle_02188d10((struct HandleState_02188d10*)obj->handleState);
	Clear0x10Bytes02096fc4(obj->clr10);
	InitHandleState_02188bd0((struct HandleState_02188bd0*)obj->handleState);
	GameState* battle = GameState::GetInstance();
	GameState_SetCamera(battle, *(int*)((char*)&data_ov014_02189800 + 0xc));
	*(int*)((char*)&data_ov014_02189800 + 0xc) = 0;
	void* var4 = LightingManager::GetInstance();
	*((unsigned char*)var4 + 0x85) = 1;
	if (arg0->unknown_3c_ == 0) {
		return;
	}
	for (int var5 = 0; var5 < 6; var5++) {
		if (arg0->unknown_3c_[var5].GetSignedAllocator()) {
			arg0->unknown_3c_[var5].Destroy();
		}
	}
}
