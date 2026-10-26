#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d79d0[8];
extern float data_ov017_021d83f0[8];

// USA: func_ov017_021d7068
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d7068(void) {
    float t;
    float a;
    float b;
    data_ov017_021d83f0[6] = data_ov017_021d79d0[0] + (data_ov017_021d79d0[1] + (data_ov017_021d79d0[3] + data_ov017_021d79d0[2]));
    t = data_ov017_021d83f0[5] + data_ov017_021d79d0[3];
    a = data_ov017_021d79d0[2];
    data_ov017_021d83f0[4] = t;
    t = t + a;
    b = data_ov017_021d79d0[1];
    data_ov017_021d83f0[3] = t;
    t = t + b;
    data_ov017_021d83f0[2] = t;
}
