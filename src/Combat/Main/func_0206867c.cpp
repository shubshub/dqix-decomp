#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" int func_020546a8(void* obj);

// USA: func_0206867c
extern "C" ARM int func_0206867c(GameState* battleStruct) {
    signed char count = 0;
    int i;
    for (i = 1; i < 4; i++) {
        GameObject* c = func_0200ff58(battleStruct, i);
        if (c != 0) {
            if (func_020546a8(c) == 0) {
                count = count + 1;
            }
        }
    }
    return (signed char)(count + 1) != 1;
}
