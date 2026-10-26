#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov004_0216794c(short* out0, short* out1, short* out2, unsigned char* out3, int* arg4);
extern "C" int func_ov004_02167a0c(void* unused, int count);
extern "C" int func_ov004_02167a6c(void* a, void* b);

extern short data_ov004_02170012;

// USA: func_ov004_02167adc
extern "C" ARM int func_ov004_02167adc(void* self) {
    short var0, m2, var2;
    unsigned char flag;
    int idx;
    GameState_GetParty(GameState::GetInstance());
    func_ov004_0216794c(&var0, &m2, &var2, &flag, &idx);
    if (idx < 0) {
        goto end;
    }
    if (var0 + m2 >= var2) {
        func_ov004_02167a0c(self, (short)(var2 - var0));
        short v = *(short*)((char*)&data_ov004_02170012 + idx * 4);
        func_ov004_02167a6c(self, (void*)(int)v);
    } else {
        func_ov004_02167a0c(self, m2);
    }
end:
    return 0;
}
