#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_ov000_02153710
extern "C" ARM int func_ov000_02153710(int unused, int id) {
    int inRange = id >= 0 && id <= 3;
    if (!inRange) return 0;
    GameObject* c = func_0200ff1c(GameState::GetInstance(), id);
    if (c == 0) return 0;
    return func_02053c6c((unsigned char*)c);
}
