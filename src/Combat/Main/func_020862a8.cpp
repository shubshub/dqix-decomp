#include <globaldefs.h>
#if defined(jpn)
#define data_020e8bec data_020e8d06
#endif
#include "GameState/GameState.h"

extern short data_020e8bec[];

extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_0201137c(char* base, int id);

// USA: func_020862a8
extern "C" ARM int func_020862a8(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    int total = 0;
    unsigned char i;
    short idx;
    for (i = 0; (idx = data_020e8bec[i]) != -1; i++) {
        if (func_02083b00(obj, idx)) {
            total += func_0201137c((char*)bs, idx);
        }
    }
    return total;
}
