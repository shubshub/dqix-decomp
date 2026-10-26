#include <globaldefs.h>
#if defined(jpn)
#define data_020e8ab6 data_020e8bd0
#endif
#include "GameState/GameState.h"

extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_0201137c(char* base, int id);
extern short data_020e8ab6[];

// USA: func_02085fb4
extern "C" ARM int func_02085fb4(unsigned char* actor) {
    short* list;
    GameState* bs = GameState::GetInstance();
    int total = 0;
    unsigned char i = 0;
    list = data_020e8ab6;
    short id;
    while ((id = list[i]) != -1) {
        if (func_02083b00(actor, id)) {
            total += func_0201137c((char*)bs, id);
        }
        i = (i + 1) & 0xff;
    }
    return total;
}
