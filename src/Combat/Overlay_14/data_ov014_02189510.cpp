#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov014_021895a0[8];
extern float data_ov014_02189800[8];

// USA: func_ov014_02189510
extern "C" __declspec(initcode) ARM void __sinit_ov014_02189510(void) {
    float t;
    float a;
    float b;
    data_ov014_02189800[6] = data_ov014_021895a0[0] + (data_ov014_021895a0[3] + (data_ov014_021895a0[2] + data_ov014_021895a0[1]));
    t = data_ov014_02189800[5] + data_ov014_021895a0[2];
    a = data_ov014_021895a0[1];
    data_ov014_02189800[2] = t;
    t = t + a;
    b = data_ov014_021895a0[3];
    data_ov014_02189800[4] = t;
    t = t + b;
    data_ov014_02189800[0] = t;
}
