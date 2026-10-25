#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov004_0216794c(short* arg0, short* arg1, short* arg2, unsigned char* arg3, int* arg4);
extern "C" int func_ov004_02167a0c(void* arg0, int arg1);
extern "C" int func_ov004_02167a6c(void* arg0, void* arg1);

extern short data_ov004_02170012;

// USA: func_ov004_02167adc
extern "C" ARM int func_ov004_02167adc(void* self) {
    short m1, m2, m3;
    unsigned char flag;
    int idx;
    GameState_GetParty(GameState::GetInstance());
    func_ov004_0216794c(&m1, &m2, &m3, &flag, &idx);
    if (idx < 0) {
        goto end;
    }
    if (var0 + var1 >= var2) {
        func_ov004_02167a0c(arg0, (short)(var2 - var0));
        short var5 = *(short*)((char*)&data_ov004_02170012 + var4 * 4);
        func_ov004_02167a6c(arg0, (void*)(int)var5);
    } else {
        func_ov004_02167a0c(arg0, var1);
    }
end:
    return 0;
}
