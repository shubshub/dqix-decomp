#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov024_021edbd8
extern "C" ARM int func_ov024_021edbd8(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x10000000) != 0;
}
