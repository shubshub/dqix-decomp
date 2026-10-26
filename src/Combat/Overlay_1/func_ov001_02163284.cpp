#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov001_02163284
extern "C" ARM int func_ov001_02163284(void* obj) {
    unsigned int v = GameState::GetInstance()->GetTickCount();
    func_ov017_021d6134(obj, v);
    return 1;
}
