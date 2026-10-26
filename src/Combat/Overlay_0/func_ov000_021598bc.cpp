#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021598bc
extern "C" ARM int func_ov000_021598bc(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x4000000) != 0;
}
