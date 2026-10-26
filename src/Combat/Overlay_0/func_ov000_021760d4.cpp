#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void*, int);

// USA: func_ov000_021760d4
extern "C" ARM void func_ov000_021760d4(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        void* found = func_ov000_02161318(obj, i);
        if (found != NULL) {
            GameObject* c = battleStruct->GetCombatantByIndex(i);
            if (c != NULL) {
                void* p = c->currentStats_;
                unsigned short val = *(unsigned short*)((char*)p + 0x22);
                int var6 = val << 30;
                *(unsigned char*)((char*)found + 0x2f) = (unsigned char)((unsigned int)var6 >> 30);
            }
        }
    }
}
