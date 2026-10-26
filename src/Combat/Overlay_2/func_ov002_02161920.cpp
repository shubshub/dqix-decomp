#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void* GameState_GetParty(GameState* battleStruct);

// USA: func_ov002_02161920
extern "C" ARM int func_ov002_02161920(void) {
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        GameState* bs = GameState::GetInstance();
        unsigned char* base = (unsigned char*)GameState_GetParty(bs);
        unsigned char i = 0;
        while (i < base[0xf7c]) {
            unsigned char* p = base + i;
            if (p[0xf78] == 0) {
                return 2;
            }
            i++;
        }
        return 1;
    }
    return 0;
}
