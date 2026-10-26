#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" int Camera_GetKindFlags(int obj);
extern "C" void func_ov000_0216d50c(void* work);
extern "C" void Camera_Update(int val);

// USA: func_ov017_021959ec
extern "C" ARM void func_ov017_021959ec(void*) {
	GameState* bs = GameState::GetInstance();
	void* val = bs->GetCamera();
	if (val == 0) return;
	if (Camera_GetKindFlags((int)val) & 8) {
		func_ov000_0216d50c(val);
	} else {
		Camera_Update((int)val);
	}
}
