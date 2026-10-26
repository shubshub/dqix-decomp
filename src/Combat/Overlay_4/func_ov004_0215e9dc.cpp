#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned short func_ov004_0215eb20(void* obj, int bit);

extern int data_ov004_02170854[];
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_021707e8;
#if defined(jpn)

extern "C" GameObject* func_0200ff1c(GameState*, int);
#else
#endif

// USA: func_ov004_0215e9dc
extern "C" ARM int func_ov004_0215e9dc(void* unused, void* arg1, int counter, int dir) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), (int)arg1);
    int idx = counter;

    if (data_ov004_02170854[idx] == 0) {
        goto done;
    }

    if (dir) {
        idx = (unsigned char)(idx + 1);
        idx = (unsigned char)(idx % 0xd);
        if (idx == 0) idx = 1;
    } else {
        idx = (unsigned char)(idx - 1);
        if ((unsigned)idx < 1) idx = 0xc;
    }

    goto loop_test;
loop_body:
    if (dir) {
        idx = (unsigned char)(idx + 1);
        idx = (unsigned char)(idx % 0xd);
        if (*((unsigned char*)&data_ov004_021707e8 + 2) && idx == 0) idx = (unsigned char)(idx + 1);
        if (!func_ov004_0215eb20(combatant, data_ov004_02170854[idx]) || !data_ov004_02170838[idx]) goto loop_test;
        goto done;
    } else {
        idx = (unsigned char)(idx - 1);
        if ((unsigned)idx < 1) idx = 0xc;
        if (*((unsigned char*)&data_ov004_021707e8 + 2) && idx == 0) idx = 0xc;
        if (!func_ov004_0215eb20(combatant, data_ov004_02170854[idx]) || !data_ov004_02170838[idx]) goto loop_test;
        goto done;
    }
loop_test:
    if (!func_ov004_0215eb20(combatant, data_ov004_02170854[idx]) || !data_ov004_02170838[idx]) goto loop_body;
done:
    return idx;
}
