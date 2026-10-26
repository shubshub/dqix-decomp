#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021598a4
extern "C" ARM int func_ov000_021598a4(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x20000000) != 0;
}
