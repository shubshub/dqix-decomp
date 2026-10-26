#include <globaldefs.h>


extern char data_021015a0;
extern "C" void HaltSystem(void);

// USA: func_0202dae0
extern "C" ARM void func_0202dae0(unsigned short* obj) {
    if (obj[1] != 8) return;
    *(int*)(&data_021015a0 + 0x10) = 9;
    HaltSystem();
}
