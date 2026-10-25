#include <globaldefs.h>
#include "GameState/GameState.h"

int MessageSystem_GetInstance();
void Forward0204359c(void* obj, int count);
extern "C" void func_020439b0(int a, int b);

// USA: func_020d844c
ARM void RunBattleScaleStepAndFinalize_020d844c(void*) {
    GameState* b = GameState::GetInstance();
    int x = MessageSystem_GetInstance();
    unsigned int y = b->GetTickCount();
    Forward0204359c((void*)x, y);
    func_020439b0(x, 0);
}
