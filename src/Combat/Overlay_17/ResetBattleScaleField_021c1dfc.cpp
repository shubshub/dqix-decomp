#include <globaldefs.h>
#include "GameState/GameState.h"

extern int MessageSystem_GetInstance();
extern void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);

// USA: func_ov017_021c1dfc
ARM void ResetBattleScaleField_021c1dfc(void*) {
    GameState* battleStruct = GameState::GetInstance();
    void* obj = (void*)MessageSystem_GetInstance();
    int count = battleStruct->GetTickCount();
    Forward0204359c(obj, count);
    func_020439b0(obj, 0);
}
