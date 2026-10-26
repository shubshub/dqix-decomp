#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156c94
extern "C" ARM int func_ov000_02156c94(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x8) != 0;
}
