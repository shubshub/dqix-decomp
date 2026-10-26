#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
struct KeyMap020a095c;
extern "C" int func_020a095c(struct KeyMap020a095c* map, int key, int amount);

// USA: func_ov017_021b6bb8
extern "C" ARM void func_ov017_021b6bb8(int combatantId) {
    GameState* bs = GameState::GetInstance();
    void* keymap = GameState_GetParty(bs);
    GameObject* c = func_0200ff1c(bs, combatantId);
    if (c == NULL) {
        return;
    }

    char* base = (char*)func_02053c6c((unsigned char*)c);
    unsigned char i = 0;
    while (i < 8) {
        char* p = base + i * 2 + 0x400;
        short v = *(short*)(p + 0x54);
        if (v > 0) {
            func_020a095c((struct KeyMap020a095c*)keymap, v, 1);
        }
        i = (i + 1) & 0xff;
    }
}
