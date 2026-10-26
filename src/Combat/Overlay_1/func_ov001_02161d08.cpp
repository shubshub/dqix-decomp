#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void*, int);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);

// USA: func_ov001_02161d08
extern "C" ARM int func_ov001_02161d08(void* self) {
    GameState* battle = GameState::GetInstance();
    int v = GameState_GetLeaderIndex(battle);
    func_ov017_021d6134(self, v);
    return 1;
}
