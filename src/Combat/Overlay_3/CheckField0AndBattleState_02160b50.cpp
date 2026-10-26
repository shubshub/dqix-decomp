// USA: func_ov003_02160b50
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
int LinkSession_GetState(int* obj);
int GameState_GetProtagonistIndex(GameState* battleStruct);

ARM int CheckField0AndBattleState_02160b50(void*) {
    int result = 0;
    if (LinkSession_GetState((int*)LinkSession_GetInstance())) {
        result = GameState_GetProtagonistIndex(GameState::GetInstance()) == 0 ? 1 : 2;
    }
    return result;
}
