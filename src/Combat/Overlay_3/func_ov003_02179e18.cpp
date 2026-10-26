#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

struct Obj02179e18 {
    char pad0[0x1a];
    unsigned short unknown_1a_;
};

// USA: func_ov003_02179e18
extern "C" ARM unsigned int func_ov003_02179e18(struct Obj02179e18* obj) {
    GameState* bs = GameState::GetInstance();
    void* p = GameState_GetParty(bs);
    unsigned int v = *(unsigned int*)((char*)p + 0xf6c);
    return _u32_div_f(0x98967f - v, obj->unknown_1a_);
}
