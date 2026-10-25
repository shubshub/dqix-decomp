#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void*, int);
int GameState_GetProtagonistIndex(GameState* battleStruct);

// USA: func_ov001_0215ef20  (semantic: SetFieldFromField3ac_0215ef20)
extern "C" ARM int func_ov001_0215ef20(void* self) {
    GameState* battle = GameState::GetInstance();
    int v = GameState_GetProtagonistIndex(battle);
    func_ov017_021d6134(self, v);
    return 1;
}
