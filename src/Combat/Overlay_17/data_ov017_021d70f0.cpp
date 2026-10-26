#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d7aec[8];
extern float data_ov017_021d8410[8];

// USA: func_ov017_021d70f0
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d70f0(void) {
    float t;
    float a;
    float b;
    data_ov017_021d8410[4] = data_ov017_021d7aec[1] + (data_ov017_021d7aec[2] + (data_ov017_021d7aec[0] + data_ov017_021d7aec[3]));
    t = data_ov017_021d8410[3] + data_ov017_021d7aec[0];
    a = data_ov017_021d7aec[3];
    data_ov017_021d8410[2] = t;
    t = t + a;
    b = data_ov017_021d7aec[2];
    data_ov017_021d8410[1] = t;
    t = t + b;
    data_ov017_021d8410[0] = t;
}
