#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" int func_02011538(GameState*);
extern "C" void* GameState_GetParty(GameState*);

// USA: func_0206852c
extern "C" ARM int func_0206852c(void* arg) {
    unsigned char* p = (unsigned char*)GameState_GetParty((GameState*)(arg));
    int v = func_02011538((GameState*)(arg));
    return p[0xf7c] != v;
}
