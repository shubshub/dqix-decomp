#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021bd5d0(void);

struct Obj020397cc;
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);

// USA: func_ov001_021609a0
ARM int Function_021609a0(void) {
	func_ov017_021bd5d0();
	GameState* bs = GameState::GetInstance();
	struct Obj020397cc* obj = (struct Obj020397cc*)bs->GetUnknownGameObject();
	GameObject_DisableControl(obj, 1);
	return 1;
}
