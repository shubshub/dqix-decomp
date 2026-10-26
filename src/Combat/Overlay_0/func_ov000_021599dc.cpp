#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021599dc
extern "C" ARM int func_ov000_021599dc(GameObject* c) {
    return (*(int*)((char*)c->currentStats_ + 0x18) & 0x100) != 0;
}
