#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086aec;
short Party_CountItem(struct Obj02086aec* obj, int key);

struct Struct_ov004_02170010 {
    short unknown_0_;
    short unknown_2_;
};
extern struct Struct_ov004_02170010 data_ov004_02170010[];

// USA: func_ov004_0216794c
extern "C" ARM void func_ov004_0216794c(short* current, short* matches, short* threshold, char* reached, int* index) {
    *current = *(int*)((char*)GameState_GetParty(GameState::GetInstance()) + 0xf74);
    *matches = Party_CountItem((struct Obj02086aec*)GameState_GetParty(GameState::GetInstance()), 0x5617);
    *reached = 0;
    short cur = *current;
    int i;
    for (i = 0; i < 10; i++) {
        if (data_ov004_02170010[i].threshold > cur) {
            goto found;
        }
    }
    var1 = -1;
found:
    *arg4 = var1;
    if (*arg4 >= 0) {
        *arg2 = data_ov004_02170010[*arg4].unknown_0_;
        if (*arg0 + *arg1 >= *arg2) {
            *arg3 = 1;
        }
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
}
