#include <globaldefs.h>

extern "C" int func_020d5f88(void* p);
extern "C" void func_0202c848(int arg);
extern "C" int func_020d5004(int arg);
extern "C" void func_0202d614(unsigned short* obj);

extern char data_021015a0;
extern char data_02102be0;

// Main, originally TryIssueBattleCommandAndUpdateState_0202dd28 (USA 0x0202dd28, EUR 0x0202dd38, JPN 0x0202d898)
extern "C" ARM void WH_Reset(void) {
    if (*(int*)(&data_021015a0 + 0x10) == 5) {
        int r = func_020d5f88(&data_02102be0);
        if (r) {
            func_0202c848(r);
        }
    }

    *(int*)(&data_021015a0 + 0x10) = 3;
    int result = func_020d5004((int)func_0202d614);
    if (result == 2) {
        result = 1;
    } else {
        func_0202c848(result);
        result = 0;
    }

    if (result == 0) {
        *(int*)(&data_021015a0 + 0x10) = 10;
    }
}
