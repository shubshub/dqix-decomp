#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_0203970c
extern "C" ARM void func_0203970c(void* unused, int index, int value) {
    char* p = (char*)GameState_GetParty((GameState*)(GameState::GetInstance())) + index;
    p[0x2c8d] = (char)value;
}
