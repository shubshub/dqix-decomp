#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov000_02183b0c[8];
extern float data_ov000_02184250[8];

// USA: func_ov000_0218381c
extern "C" __declspec(initcode) ARM void __sinit_ov000_0218381c(void) {
    float t;
    float a;
    float b;
    data_ov000_02184250[4] = data_ov000_02183b0c[1] + (data_ov000_02183b0c[2] + (data_ov000_02183b0c[4] + data_ov000_02183b0c[3]));
    t = data_ov000_02184250[3] + data_ov000_02183b0c[4];
    a = data_ov000_02183b0c[3];
    data_ov000_02184250[2] = t;
    t = t + a;
    b = data_ov000_02183b0c[2];
    data_ov000_02184250[1] = t;
    t = t + b;
    data_ov000_02184250[0] = t;
}
