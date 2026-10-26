#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0200fd48(GameState* battleStruct, int id);

// USA: func_02057db8
extern "C" ARM void func_02057db8(void* unused, int id) {
    if (id < 0xd0) return;
    if (id > 0xdf) return;
    func_0200fd48(GameState::GetInstance(), id);
}
