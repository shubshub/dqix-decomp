#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f1a8c[8];
extern float data_02109db8[8];

// USA: func_020e64fc
extern "C" __declspec(initcode) ARM void __sinit_020e64fc(void) {
    float t;
    float a;
    float b;
    data_02109db8[3] = data_020f1a8c[0] + (data_020f1a8c[1] + (data_020f1a8c[3] + data_020f1a8c[2]));
    t = data_02109db8[2] + data_020f1a8c[3];
    a = data_020f1a8c[2];
    data_02109db8[1] = t;
    t = t + a;
    b = data_020f1a8c[1];
    data_02109db8[0] = t;
    t = t + b;
    data_02109db8[4] = t;
}
