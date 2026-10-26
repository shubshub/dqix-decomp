#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

struct AngleTrig0202e9a4;
extern "C" void Camera_SetFieldOfView(struct AngleTrig0202e9a4* obj, int angle);
extern "C" int func_ov017_021d60f4(void*);
extern "C" float func_ov017_021d6110(void*);

struct Struct_ov001_0215f968 { int mode; };

// USA: func_ov001_0215f968
extern "C" ARM int func_ov001_0215f968(Struct_ov001_0215f968* self) {
	GameState* battle = GameState::GetInstance();
	struct AngleTrig0202e9a4* field = (struct AngleTrig0202e9a4*)battle->GetCamera();
	if (self->mode == 0) {
		int a = func_ov017_021d60f4(self);
		Camera_SetFieldOfView(field, a << 0xc);
	} else if (self->mode == 1) {
		float b = func_ov017_021d6110(self);
		int a = (int)(4096.0f * b);
		Camera_SetFieldOfView(field, a);
	}
	return 1;
}
