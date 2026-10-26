#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov024_021e67b0
extern "C" ARM int func_ov024_021e67b0(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x18) & 0x20) != 0;
}
