#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d7c2c[8];
extern float data_ov017_021d8424[8];

// USA: func_ov017_021d7178
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d7178(void) {
    float t;
    float a;
    float b;
    data_ov017_021d8424[4] = data_ov017_021d7c2c[0] + (data_ov017_021d7c2c[1] + (data_ov017_021d7c2c[3] + data_ov017_021d7c2c[2]));
    t = data_ov017_021d8424[3] + data_ov017_021d7c2c[3];
    a = data_ov017_021d7c2c[2];
    data_ov017_021d8424[2] = t;
    t = t + a;
    b = data_ov017_021d7c2c[1];
    data_ov017_021d8424[1] = t;
    t = t + b;
    data_ov017_021d8424[0] = t;
}
