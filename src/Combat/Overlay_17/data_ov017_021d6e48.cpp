#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d73e8[8];
extern float data_ov017_021d8368[8];

// USA: func_ov017_021d6e48
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6e48(void) {
    float t;
    float a;
    float b;
    data_ov017_021d8368[2] = data_ov017_021d73e8[1] + (data_ov017_021d73e8[0] + (data_ov017_021d73e8[3] + data_ov017_021d73e8[2]));
    t = data_ov017_021d8368[1] + data_ov017_021d73e8[3];
    a = data_ov017_021d73e8[2];
    data_ov017_021d8368[3] = t;
    t = t + a;
    b = data_ov017_021d73e8[0];
    data_ov017_021d8368[0] = t;
    t = t + b;
    data_ov017_021d8368[4] = t;
}
