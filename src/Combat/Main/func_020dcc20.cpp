#include <globaldefs.h>

#if defined(jpn)
enum { stateFieldOffset = 0x1b8 };
#else
enum { stateFieldOffset = 0x1c4 };
#endif
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

// USA: func_020dcc20
extern "C" ARM int func_020dcc20(int arg0, int flag) {
    GameState* battle = GameState::GetInstance();
    unsigned char count = 0;
    for (signed char i = 0; i < 4; i++) {
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (c != NULL) {
            if (!(flag != 0 && *(int*)((char*)c + stateFieldOffset) != 0)) {
                if (func_02053c6c((unsigned char*)c) != 0) {
                    count = count + 1;
                }
            }
        }
    }
    return count == arg0;
}
