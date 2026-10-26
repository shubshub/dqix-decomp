#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_021563ec
extern "C" ARM int func_ov000_021563ec(GameObject* combatant) {
    return (*(unsigned int*)(combatant->currentStats_->unk1 + 0) & 0x2000000) != 0;
}
