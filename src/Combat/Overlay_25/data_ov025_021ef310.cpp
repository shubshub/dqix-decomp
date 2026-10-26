#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov025_021ef898[8];
extern float data_ov025_021ef9c4[8];

// USA: func_ov025_021ef310
extern "C" __declspec(initcode) ARM void __sinit_ov025_021ef310(void) {
    float t;
    float a;
    float b;
    data_ov025_021ef9c4[3] = data_ov025_021ef898[4] + (data_ov025_021ef898[3] + (data_ov025_021ef898[6] + data_ov025_021ef898[5]));
    t = data_ov025_021ef9c4[1] + data_ov025_021ef898[6];
    a = data_ov025_021ef898[5];
    data_ov025_021ef9c4[2] = t;
    t = t + a;
    b = data_ov025_021ef898[3];
    data_ov025_021ef9c4[4] = t;
    t = t + b;
    data_ov025_021ef9c4[0] = t;
}
