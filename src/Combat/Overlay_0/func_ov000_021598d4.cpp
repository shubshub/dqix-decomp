#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021598d4
extern "C" ARM int func_ov000_021598d4(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x400000) != 0;
}
