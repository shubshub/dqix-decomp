#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021923e0(void* obj, unsigned int value);
extern unsigned short data_ov017_021d618e[8];

// USA: func_ov017_0219230c
extern "C" ARM void func_ov017_0219230c(int p0, int idx, unsigned int flag) {
    int ok;
    if (idx >= 0 && idx <= 3) {
        ok = 1;
    } else {
        ok = 0;
    }
    if (!ok) {
        return;
    }

    GameState* battle = GameState::GetInstance();
    short local[8];
    int i;
    int n = 8;
    unsigned short* dst = (unsigned short*)local;
    unsigned short* src = data_ov017_021d618e;
    do {
        unsigned short v = *src;
        src++;
        n--;
        *dst = v;
        dst++;
    } while (n);

    local[0] = idx;
    local[1] = idx * 0xc + 0x13;
    local[2] = idx * 0xc + 0x14;
    local[3] = idx * 0xc + 0x15;
    local[4] = idx * 0xc + 0x1b;
    local[5] = idx * 0xc + 0x1c;
    local[6] = idx * 0xc + 0x1d;

    for (i = 0; local[i] > -1; i++) {
        GameObject* c = battle->GetGameObjectByIndex(local[i]);
        if (c) {
            func_ov017_021923e0(c, flag);
        }
    }
}
