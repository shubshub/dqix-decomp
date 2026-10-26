#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0d1c[8];
extern float data_02108dc4[8];

// USA: func_020e6038
extern "C" __declspec(initcode) ARM void __sinit_020e6038(void) {
    float t;
    float a;
    float b;
    data_02108dc4[4] = data_020f0d1c[0] + (data_020f0d1c[1] + (data_020f0d1c[3] + data_020f0d1c[2]));
    t = data_02108dc4[3] + data_020f0d1c[3];
    a = data_020f0d1c[2];
    data_02108dc4[2] = t;
    t = t + a;
    b = data_020f0d1c[1];
    data_02108dc4[1] = t;
    t = t + b;
    data_02108dc4[0] = t;
}
