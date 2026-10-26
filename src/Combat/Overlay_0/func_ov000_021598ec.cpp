#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021598ec
extern "C" ARM int func_ov000_021598ec(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x18) & 0x2) != 0;
}
