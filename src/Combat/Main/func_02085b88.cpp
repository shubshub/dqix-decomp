#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02085b88_2288 = 0x858 };
#else
enum { Enum_02085b88_2288 = 0x8f0 };
#endif

#include "GameState/GameState.h"

extern "C" int func_0201137c(char* base, int id);

// USA: func_02085b88
extern "C" ARM int func_02085b88(unsigned char* actor) {
    GameState* bs;
    int total;
    if (*(short*)(actor + 0x2cc) <= 0) {
        return 0;
    }
    bs = GameState::GetInstance();
    total = 0;
    if (actor[Enum_02085b88_2288] & 4) {
        total += func_0201137c((char*)bs, 0x22);
    }
    if (actor[Enum_02085b88_2288] & 0x10) {
        total += func_0201137c((char*)bs, 0x24);
    }
    if (actor[Enum_02085b88_2288] & 0x40) {
        total += func_0201137c((char*)bs, 0x26);
    }
    return total;
}
