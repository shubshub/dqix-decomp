#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
struct KeyMap020a0b3c;
extern "C" signed char func_020a0b3c(struct KeyMap020a0b3c* map, int key);

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_0209d9c4
extern "C" ARM int func_0209d9c4(void* p) {
    GameState* battleStruct = GameState::GetInstance();
    void* result = GameState_GetParty(battleStruct);
    int raw = func_ov017_021d60f4(p);
    struct KeyMap020a0b3c* map = (struct KeyMap020a0b3c*)((char*)result + 0x204 + 0xc00);
    signed char val = func_020a0b3c(map, (short)raw);
    func_ov017_021d6134((char*)p + 0x8, val);
    return 1;
}
