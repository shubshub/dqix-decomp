#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02057930;
extern "C" void func_0200fd48(GameState* battleStruct, int id);
extern "C" void func_02057930(Struct_02057930* p);

// USA: func_02057978
extern "C" ARM void func_02057978(Struct_02057930* p) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 16; i++) {
        func_0200fd48(bs, i + 0xd0);
    }
    func_02057930(p);
}
