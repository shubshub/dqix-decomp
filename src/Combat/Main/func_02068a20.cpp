#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02067fec(int, void*, int);

// USA: func_02068a20
extern "C" ARM int func_02068a20(GameState* battleStruct, int arg1, int arg2) {
    GameObject* c = battleStruct->GetLeader();
    if (c != 0) {
        return func_02067fec(0, c->baseStats_, arg2) == 0;
    }
    return 0;
}
