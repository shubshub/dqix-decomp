#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov024_021eadfc
extern "C" ARM int func_ov024_021eadfc(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x18) & 0x200) != 0;
}
