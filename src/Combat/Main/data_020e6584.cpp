#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f1b40[8];
extern float data_02109fcc[8];

// USA: func_020e6584
extern "C" __declspec(initcode) ARM void __sinit_020e6584(void) {
    float t;
    float a;
    float b;
    data_02109fcc[4] = data_020f1b40[1] + (data_020f1b40[2] + (data_020f1b40[0] + data_020f1b40[3]));
    t = data_02109fcc[3] + data_020f1b40[0];
    a = data_020f1b40[3];
    data_02109fcc[2] = t;
    t = t + a;
    b = data_020f1b40[2];
    data_02109fcc[1] = t;
    t = t + b;
    data_02109fcc[0] = t;
}
