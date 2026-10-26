#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021599ac
extern "C" ARM int func_ov000_021599ac(GameObject* c) {
    return (*(int*)((char*)c->currentStats_ + 0x14) & 0x10000) != 0;
}
