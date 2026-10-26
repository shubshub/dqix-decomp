// USA: func_ov003_02160b50
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_GetState(int* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

extern "C" ARM int func_ov003_02160b50(void*) {
    int result = 0;
    if (LinkSession_GetState((int*)LinkSession_GetInstance())) {
        result = GameState_GetProtagonistIndex(GameState::GetInstance()) == 0 ? 1 : 2;
    }
    return result;
}
