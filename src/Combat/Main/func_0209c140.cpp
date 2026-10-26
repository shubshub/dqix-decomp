#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086b98;
extern "C" int func_02086b98(struct Obj02086b98*);

// USA: func_0209c140
extern "C" ARM int func_0209c140() {
    GameState* bs = GameState::GetInstance();
    if (bs != NULL) {
        struct Obj02086b98* o = (struct Obj02086b98*)GameState_GetParty((GameState*)(bs));
        if (o != NULL) {
            if (func_02086b98(o) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
