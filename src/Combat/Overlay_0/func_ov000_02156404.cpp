#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02156404
extern "C" ARM int func_ov000_02156404(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 4) & 0x400) != 0;
}
