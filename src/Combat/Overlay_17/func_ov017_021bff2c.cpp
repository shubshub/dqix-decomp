#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

void GameObject_EnableControl(void* obj);
int GameState_GetFollowCamera(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);

struct ShortField02033e2c;
void ClearField0xc602033e2c(struct ShortField02033e2c* obj);
struct Foo02033b58;
void GameObject_StoreMotionState(struct Foo02033b58* p, unsigned char v);

// USA: func_ov017_021bff2c
extern "C" ARM void func_ov017_021bff2c(void) {
	GameState* battle = GameState::GetInstance();
	GameObject* c = battle->GetLeader();
	GameObject_EnableControl(c);
	ClearField0xc602033e2c((struct ShortField02033e2c*)c);
	GameObject_StoreMotionState((struct Foo02033b58*)c, 0);

	void* var2 = GetGameResources();

	int flagResult = GameState_GetFollowCamera((char*)battle);
	if (flagResult != 0) {
		SetField0x23cTrue_020a27ac((void*)flagResult);
	}

	if (var2 != NULL) {
		ClearFlags04((GameResources*)var2, 0x80);
	}
}
