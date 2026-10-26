#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* GameState_GetParty(GameState*);
#include "std_library_functions.h"
struct GameObject;

// USA: func_02039768
extern "C" ARM void func_02039768(GameObject* unused, void* src) {
    GameState* battleStruct = GameState::GetInstance();
    memcpy((char*)GameState_GetParty(battleStruct) + 0x2c8d, src, 7);
}
