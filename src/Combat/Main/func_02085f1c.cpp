#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02085f1c_2290 = 0x85a, Enum_02085f1c_2291 = 0x85b };
#else
enum { Enum_02085f1c_2290 = 0x8f2, Enum_02085f1c_2291 = 0x8f3 };
#endif

#include "GameState/GameState.h"

extern "C" int func_0201137c(char* base, int id);

// USA: func_02085f1c
extern "C" ARM int func_02085f1c(unsigned char* actor, int mode) {
    GameState* bs;
    int total;
    if (mode < 0) {
        short v = *(short*)(actor + 0x2ac);
        if (v > 0) {
            int x = *(int*)(actor + 0x29c);
            mode = (unsigned int)(x << 23) >> 27;
        } else {
            mode = 0x21;
        }
    }
    bs = GameState::GetInstance();
    total = 0;
    if (mode == 3) {
        if (actor[Enum_02085f1c_2290] & 0x80) {
            total += func_0201137c((char*)bs, 0x37);
        }
        if (actor[Enum_02085f1c_2291] & 0x8) {
            total += func_0201137c((char*)bs, 0x3b);
        }
        if (actor[Enum_02085f1c_2291] & 0x40) {
            total += func_0201137c((char*)bs, 0x3e);
        }
    }
    return total;
}
