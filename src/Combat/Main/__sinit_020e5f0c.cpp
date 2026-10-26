#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void func_02064d1c(void* obj);

extern float data_020f05ac[4];
extern float data_02108830[5];
extern char g_scenario;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e5f0c
extern "C" __declspec(initcode) ARM void __sinit_020e5f0c(void) {
    float t;
    float a;
    float b;
    data_02108830[4] = data_020f05ac[0] + data_020f05ac[1] + data_020f05ac[3] + data_020f05ac[2];
    t = data_02108830[3] + data_020f05ac[0];
    a = data_020f05ac[1];
    data_02108830[2] = t;
    t = t + a;
    b = data_020f05ac[3];
    data_02108830[1] = t;
    t = t + b;
    data_02108830[0] = t;
    func_02064d1c(&g_scenario);
}
