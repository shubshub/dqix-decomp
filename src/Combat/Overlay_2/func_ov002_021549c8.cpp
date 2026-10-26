#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov002_021549c8
extern "C" ARM int func_ov002_021549c8(void* unused, int combatantId, int arg2, unsigned char* arg3) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (!combatant) {
        return 0;
    }
    int* field = *(int**)((char*)combatant + 0x130);
    int word = *field;
    if ((word & arg2) == 0) goto notset;
    *field = (unsigned short)(word & ~arg2);
    *arg3 = 3;
    goto success;
notset:
    *arg3 = 0;
    return 0;
success:
    return 1;
}
