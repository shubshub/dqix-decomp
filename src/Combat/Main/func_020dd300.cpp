#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0207c5f8(unsigned char* obj, unsigned int index);
extern "C" signed short func_0207c620(unsigned char* obj, unsigned int index);
extern short data_020f29dc[];

// USA: func_020dd300
extern "C" ARM int func_020dd300(int mask) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* obj = (unsigned char*)GameState_GetParty(battleStruct);
    signed short* arr = (signed short*)func_0207c5f8(obj + 0x1d4, 0);
    short count = func_0207c620(obj + 0x1d4, 0);
    short result = 0;
    for (short i = 0; i < count; i++) {
        signed short v = arr[i];
        if (v > 0) {
            v -= v % 100;
            for (unsigned char j = 0; j < 12; j++) {
                if (mask & (1 << j)) {
                    if (v == data_020f29dc[j]) {
                        result++;
                        break;
                    }
                }
            }
        }
    }
    return result;
}
