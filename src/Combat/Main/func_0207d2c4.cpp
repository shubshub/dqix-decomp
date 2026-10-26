#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);

// USA: func_0207d2c4
extern "C" ARM int func_0207d2c4(int unused, int amount) {
    if (amount < 0) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    char* p = (char*)GameState_GetParty(bs);
    unsigned int cap = 0x98967f;
    if (cap - amount >= *(unsigned int*)(p + 0xf6c)) {
        *(unsigned int*)(p + 0xf6c) += amount;
    } else {
        *(unsigned int*)(p + 0xf6c) = cap;
    }
    return 1;
}
