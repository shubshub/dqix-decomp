#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d73d8[8];
extern float data_ov017_021d8340[8];

// USA: func_ov017_021d6dc0
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6dc0(void) {
    float t;
    float a;
    float b;
    data_ov017_021d8340[9] = data_ov017_021d73d8[3] + (data_ov017_021d73d8[1] + (data_ov017_021d73d8[0] + data_ov017_021d73d8[2]));
    t = data_ov017_021d8340[8] + data_ov017_021d73d8[0];
    a = data_ov017_021d73d8[2];
    data_ov017_021d8340[7] = t;
    t = t + a;
    b = data_ov017_021d73d8[1];
    data_ov017_021d8340[6] = t;
    t = t + b;
    data_ov017_021d8340[5] = t;
}
