#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021599c4
extern "C" ARM int func_ov000_021599c4(GameObject* c) {
    return (*(int*)((char*)c->currentStats_ + 0x14) & 0x20000) != 0;
}
