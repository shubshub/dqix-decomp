#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov003_0217fe84[8];
extern float data_ov003_02180ca4[8];

// USA: func_ov003_0217fbf0
extern "C" __declspec(initcode) ARM void __sinit_ov003_0217fbf0(void) {
    float t;
    float a;
    float b;
    data_ov003_02180ca4[3] = data_ov003_0217fe84[1] + (data_ov003_0217fe84[2] + (data_ov003_0217fe84[3] + data_ov003_0217fe84[0]));
    t = data_ov003_02180ca4[4] + data_ov003_0217fe84[3];
    a = data_ov003_0217fe84[0];
    data_ov003_02180ca4[2] = t;
    t = t + a;
    b = data_ov003_0217fe84[2];
    data_ov003_02180ca4[0] = t;
    t = t + b;
    data_ov003_02180ca4[1] = t;
}
