#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov024_021edbd8(GameObject* combatant);

// USA: func_ov024_021f5768
extern "C" ARM int func_ov024_021f5768(int* p0, short id, int arg2, int* outFlag, short* arg4) {
    GameObject* c = func_ov000_021536f8(*p0, id);
    if (c == NULL) return 0;
    if (func_ov024_021edbd8(c)) {
        return 0;
    }
    *outFlag = 1;
    *arg4 = id;
    return 1;
}
