#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov025_021ef3c0[8];
extern float data_ov025_021ef960[8];

// USA: func_ov025_021ef200
extern "C" __declspec(initcode) ARM void __sinit_ov025_021ef200(void) {
    float t;
    float a;
    float b;
    data_ov025_021ef960[4] = data_ov025_021ef3c0[1] + (data_ov025_021ef3c0[2] + (data_ov025_021ef3c0[0] + data_ov025_021ef3c0[3]));
    t = data_ov025_021ef960[3] + data_ov025_021ef3c0[0];
    a = data_ov025_021ef3c0[3];
    data_ov025_021ef960[2] = t;
    t = t + a;
    b = data_ov025_021ef3c0[2];
    data_ov025_021ef960[1] = t;
    t = t + b;
    data_ov025_021ef960[0] = t;
}
