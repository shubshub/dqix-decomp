#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

void GameObject_EnableControl(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);

struct Struct_02033e2c;
extern "C" void func_02033e2c(struct Struct_02033e2c* arg0);
struct Struct_02033b58;
extern "C" void func_02033b58(struct Struct_02033b58* arg0, unsigned char arg1);

// USA: func_ov017_021bff2c
extern "C" ARM void func_ov017_021bff2c(void) {
	GameState* battle = GameState::GetInstance();
	GameObject* c = battle->GetUnknownGameObject();
	GameObject_EnableControl(c);
	ClearField0xc602033e2c((struct ShortField02033e2c*)c);
	SetByteSavingPrevious((struct Foo02033b58*)c, 0);

	void* var2 = GetGameResources();

	int var3 = func_020100f8((char*)var0);
	if (var3 != 0) {
		func_020a27ac((void*)var3);
	}

	if (var2 != NULL) {
		ClearFlags04((GameResources*)var2, 0x80);
	}
}
