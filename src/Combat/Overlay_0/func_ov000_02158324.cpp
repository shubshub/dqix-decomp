#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02158324
extern "C" ARM int func_ov000_02158324(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x80000000) != 0;
}
