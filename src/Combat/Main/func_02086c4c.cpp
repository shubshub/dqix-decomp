#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
struct Struct_02083994;
extern "C" int func_02083994(struct Struct_02083994* s, int value);
struct KeyMap020a0b3c;
extern "C" signed char func_020a0b3c(struct KeyMap020a0b3c* map, int key);
extern "C" short func_0207c7a0(void* map, int key, int amount);

// USA: func_02086c4c
extern "C" ARM short func_02086c4c(unsigned char* self, int selector, int key) {
    GameState* bs = GameState::GetInstance();
    short result = 0;
    int take;
    if (selector < 0) {
        goto zero;
    }
    if (selector <= 3) {
        take = 1;
        goto after;
    }
zero:
    take = 0;
after:
    if (take) {
        GameObject* c = func_0200ff1c(bs, selector);
        if (c == NULL) {
            return 0;
        }
        void* x = (void*)func_02053c6c((unsigned char*)c);
        if (x == NULL) {
            return 0;
        }
        result += func_02083994((struct Struct_02083994*)x, key);
    } else if (selector == 4) {
        result = func_020a0b3c((struct KeyMap020a0b3c*)self, key);
    } else if (selector == 5) {
        result = func_0207c7a0(self + 0x1d4, key, 9);
    } else if (selector == 6) {
        result = func_020a0b3c((struct KeyMap020a0b3c*)(self + 0xe04), key);
    }
    return result;
}
