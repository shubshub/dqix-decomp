#include <globaldefs.h>

extern char data_021015a0;
extern "C" void func_0202c848(int arg);
extern "C" void WH_Finalize(void);
extern "C" int func_020d559c(int a0, unsigned int a1);
extern "C" void func_0202d5ec(unsigned short* obj);
extern "C" void WH_Reset(void);

// USA: func_0202d584
extern "C" ARM void func_0202d584(unsigned short* obj) {
    unsigned short v = obj[1];
    if (v != 0) {
        func_0202c848(v);
        WH_Finalize();
        return;
    }

    int result;
    *(int*)(&data_021015a0 + 0x10) = 3;
    result = func_020d559c((int)func_0202d5ec, 0);
    if (result == 2) {
        result = 1;
    } else {
        func_0202c848(result);
        WH_Reset();
        result = 0;
    }
    if (result == 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
    }
}
