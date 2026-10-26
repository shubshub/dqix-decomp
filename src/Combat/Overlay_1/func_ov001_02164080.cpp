#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02164080
extern "C" ARM int func_ov001_02164080(void* obj) {
    int cond = func_ov017_021d60f4(obj);
    GameState* battleStruct = GameState::GetInstance();
    if (cond != 0)
        battleStruct->SetDayTimerRunning(0);
    else
        battleStruct->SetDayTimerRunning(1);
    return 1;
}
