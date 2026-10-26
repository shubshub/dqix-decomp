#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

// USA: func_ov024_021d95e0
extern "C" ARM int func_ov024_021d95e0(struct Random** arg0, int unused1, int combatantId, int arg3, int unused4, int value) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(combatantId);
    if (!c) return value;
    if (NextRandomMax(*arg0, 2) > 0) {
        *((unsigned char*)(*arg0) + 0x8e94) = 1;
        return 0xffff;
    }
    unsigned short hp = *(unsigned short*)((char*)c->currentStats_ + 0);
    return (int)((float)hp * 0.99f);
}
