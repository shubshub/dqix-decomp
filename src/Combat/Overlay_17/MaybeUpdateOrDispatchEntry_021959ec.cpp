#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

int Camera_GetKindFlags(int obj);
void UpdateEntry0216d50c(void* work);
extern "C" void Camera_Update(int val);

// USA: func_ov017_021959ec
ARM void MaybeUpdateOrDispatchEntry_021959ec(void*) {
	GameState* bs = GameState::GetInstance();
	void* val = bs->GetCamera();
	if (val == 0) return;
	if (Camera_GetKindFlags((int)val) & 8) {
		UpdateEntry0216d50c(val);
	} else {
		Camera_Update((int)val);
	}
}
