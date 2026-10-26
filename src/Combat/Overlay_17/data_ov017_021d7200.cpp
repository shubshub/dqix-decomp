#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d7cbc[8];
extern float data_ov017_021d845c[8];

// USA: func_ov017_021d7200
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d7200(void) {
    float t;
    float a;
    float b;
    data_ov017_021d845c[5] = data_ov017_021d7cbc[1] + (data_ov017_021d7cbc[2] + (data_ov017_021d7cbc[0] + data_ov017_021d7cbc[3]));
    t = data_ov017_021d845c[4] + data_ov017_021d7cbc[0];
    a = data_ov017_021d7cbc[3];
    data_ov017_021d845c[3] = t;
    t = t + a;
    b = data_ov017_021d7cbc[2];
    data_ov017_021d845c[2] = t;
    t = t + b;
    data_ov017_021d845c[1] = t;
}
