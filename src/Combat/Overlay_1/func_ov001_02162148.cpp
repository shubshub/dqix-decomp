#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);

// USA: func_ov001_02162148
extern "C" ARM int func_ov001_02162148(void* obj) {
    GameState* bs = GameState::GetInstance();
    int idx = func_ov017_021d60f4(obj);
    ((GameState*)((char*)bs))->SetTimeOfDay((TimeOfDay)(idx));
    return 1;
}
