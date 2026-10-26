#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02153a8c
extern "C" ARM int func_ov000_02153a8c(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x200) != 0;
}
