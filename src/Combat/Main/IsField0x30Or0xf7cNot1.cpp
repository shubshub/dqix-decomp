#include <globaldefs.h>
#include "GameState/GameState.h"
void* GameState_GetParty(GameState*);

// USA: func_02068650
ARM int IsField0x30Or0xf7cNot1_02068650(GameState* battleStruct, void* arg2) {
    signed char v = *(signed char*)((char*)arg2 + 0x30);
    if (v < 0) {
        v = *(signed char*)((char*)GameState_GetParty(battleStruct) + 0xf7c);
    }
    return v != 1;
}
