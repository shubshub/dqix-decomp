#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020ddb20(unsigned int* obj);
extern "C" void* GameState_GetParty(GameState* battleStruct);

struct Struct_02061c04_23;
extern "C" int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount);

extern "C" int func_020ac4c0(void* dst);

struct Struct_020a0504;
extern "C" void func_020a0504(struct Struct_020a0504* p, unsigned int amount);

extern "C" int func_020ac494(void* src);

// USA: func_020dddcc
extern "C" ARM int func_020dddcc(void* obj) {
    char local[0xb0];
    if (!func_020ddb20((unsigned int*)obj)) {
        return 0;
    }
    GameState* battle = GameState::GetInstance();
    void* ptr = GameState_GetParty(battle);
    short key = *(short*)((char*)obj + 0x18);
    if (!func_020a0a08((struct Struct_02061c04_23*)ptr, key, 1)) {
        return 0;
    }
    int field8 = *(int*)((char*)obj + 0x8);
    if ((unsigned int)field8 >> 31) {
        func_020ac4c0(local);
        func_020a0504((struct Struct_020a0504*)local, 1);
        func_020ac494(local);
    }
    return 1;
}
