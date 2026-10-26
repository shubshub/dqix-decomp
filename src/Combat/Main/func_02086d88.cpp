#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02061c04_23;
extern "C" int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount);

extern "C" int func_0207c894(void* map, int key, int amount);

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_020838c4;
extern "C" int func_020838c4(struct Struct_020838c4* s, int value);

// USA: func_02086d88
extern "C" ARM int func_02086d88(unsigned char* self, int key) {
    if (key < 0) {
        return 0;
    }
    if (func_020a0a08((struct Struct_02061c04_23*)self, key, 1) != 0) {
        return 1;
    }
    if (func_0207c894(self + 0x1d4, key, 9) != 0) {
        return 1;
    }
    if (func_020a0a08((struct Struct_02061c04_23*)(self + 0xe04), key, 1) != 0) {
        return 1;
    }
    GameState* battleStruct = GameState::GetInstance();
    GameObject* c;
    unsigned char i;
    for (i = 0; i < self[0xf7c]; i++) {
        unsigned char* p = self + i;
        c = func_0200ff1c(battleStruct, p[0xf78]);
        if (c != 0) {
            int field = func_02053c6c((unsigned char*)c);
            if (field != 0) {
                if (func_020838c4((struct Struct_020838c4*)field, key) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
