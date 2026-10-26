#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_ov017_021d6134(void* param, int val);

// USA: func_ov001_021626a4
extern "C" ARM int func_ov001_021626a4(void* param) {
    GameState* bs = GameState::GetInstance();
    if (func_02011b50(bs, 1)) {
        int val = func_02011b50(bs, 1);
        func_ov017_021d6134(param, val);
    }
    return 1;
}
