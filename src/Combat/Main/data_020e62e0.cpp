#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f16b0[8];
extern float data_02109bb0[8];

// USA: func_020e62e0
extern "C" __declspec(initcode) ARM void __sinit_020e62e0(void) {
    float t;
    float a;
    float b;
    data_02109bb0[5] = data_020f16b0[0] + (data_020f16b0[1] + (data_020f16b0[3] + data_020f16b0[2]));
    t = data_02109bb0[4] + data_020f16b0[3];
    a = data_020f16b0[2];
    data_02109bb0[3] = t;
    t = t + a;
    b = data_020f16b0[1];
    data_02109bb0[2] = t;
    t = t + b;
    data_02109bb0[1] = t;
}
