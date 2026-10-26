#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* GameState_GetParty(GameState*);

// USA: func_02068650
extern "C" ARM int func_02068650(GameState* battleStruct, void* arg1) {
    signed char v = *(signed char*)((char*)arg1 + 0x30);
    if (v < 0) {
        v = *(signed char*)((char*)GameState_GetParty(battleStruct) + 0xf7c);
    }
    return v != 1;
}
