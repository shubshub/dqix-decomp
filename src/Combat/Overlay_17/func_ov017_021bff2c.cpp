#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void GameObject_EnableControl(void* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);

struct Struct_02033e2c;
extern "C" void func_02033e2c(struct Struct_02033e2c* obj);
struct Foo02033b58;
extern "C" void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);

// USA: func_ov017_021bff2c
extern "C" ARM void func_ov017_021bff2c(void) {
	GameState* battle = GameState::GetInstance();
	GameObject* c = battle->GetLeader();
	GameObject_EnableControl(c);
	func_02033e2c((struct Struct_02033e2c*)c);
	GameObject_StoreMotionState((struct Foo02033b58*)c, 0);

	void* ov = GetGameResources();

	int flagResult = GameState_GetFollowCamera((char*)battle);
	if (flagResult != 0) {
		func_020a27ac((void*)flagResult);
	}

	if (ov != NULL) {
		ClearFlags04((GameResources*)ov, 0x80);
	}
}
