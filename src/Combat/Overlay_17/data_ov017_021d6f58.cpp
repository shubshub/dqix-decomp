#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d7654[8];
extern float data_ov017_021d8394[8];

// USA: func_ov017_021d6f58
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6f58(void) {
    float t;
    float a;
    float b;
    data_ov017_021d8394[3] = data_ov017_021d7654[2] + (data_ov017_021d7654[1] + (data_ov017_021d7654[4] + data_ov017_021d7654[3]));
    t = data_ov017_021d8394[2] + data_ov017_021d7654[4];
    a = data_ov017_021d7654[3];
    data_ov017_021d8394[1] = t;
    t = t + a;
    b = data_ov017_021d7654[1];
    data_ov017_021d8394[4] = t;
    t = t + b;
    data_ov017_021d8394[0] = t;
}
