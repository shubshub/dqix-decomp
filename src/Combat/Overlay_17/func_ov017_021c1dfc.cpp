#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_0204359c(void* obj, int flag);
extern "C" void func_020439b0(void* obj, int flag);

// USA: func_ov017_021c1dfc
extern "C" ARM void func_ov017_021c1dfc(void*) {
    GameState* battleStruct = GameState::GetInstance();
    void* obj = (void*)MessageSystem_GetInstance();
    int count = battleStruct->GetTickCount();
    func_0204359c(obj, count);
    func_020439b0(obj, 0);
}
