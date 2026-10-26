#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov003_02160bd0
extern "C" ARM void* func_ov003_02160bd0(void* unused, int index) {
    if (index < 0) return NULL;
    void* p = GameState_GetParty(GameState::GetInstance());
    return (char*)p + 0xf80 + index * 0x23c;
}
