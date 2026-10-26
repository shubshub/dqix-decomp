#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010768(void* obj);
extern "C" void GameState_SetCamera(GameState* battleStruct, int value);

// USA: func_ov001_0215f930
extern "C" ARM int func_ov001_0215f930(void) {
    GameState* battleStruct = GameState::GetInstance();
    int* p = (int*)func_02010768(battleStruct);
    int val = p[1];
    if (val != 0) {
        GameState_SetCamera(battleStruct, val);
        p[1] = 0;
    }
    return 1;
}
