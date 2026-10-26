#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0b30[8];
extern float data_02108d48[8];

// USA: func_020e5f9c
extern "C" __declspec(initcode) ARM void __sinit_020e5f9c(void) {
    float t;
    float a;
    float b;
    data_02108d48[3] = data_020f0b30[0] + (data_020f0b30[1] + (data_020f0b30[3] + data_020f0b30[2]));
    t = data_02108d48[2] + data_020f0b30[3];
    a = data_020f0b30[2];
    data_02108d48[1] = t;
    t = t + a;
    b = data_020f0b30[1];
    data_02108d48[0] = t;
    t = t + b;
    data_02108d48[4] = t;
}
