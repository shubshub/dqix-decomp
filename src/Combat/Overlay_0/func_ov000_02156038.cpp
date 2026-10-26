#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156038
extern "C" ARM int func_ov000_02156038(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x8) != 0;
}
