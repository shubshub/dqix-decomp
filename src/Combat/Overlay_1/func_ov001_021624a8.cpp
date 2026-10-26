#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02011b50(void* obj, int mask);
extern "C" void func_ov017_0219c520(void);

// USA: func_ov001_021624a8
extern "C" ARM int func_ov001_021624a8(void) {
    if (func_02011b50(GameState::GetInstance(), 1)) {
        func_ov017_0219c520();
    }
    return 1;
}
