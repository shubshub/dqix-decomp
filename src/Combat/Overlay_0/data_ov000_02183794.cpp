#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov000_021838e8[8];
extern float data_ov000_0218423c[8];

// USA: func_ov000_02183794
extern "C" __declspec(initcode) ARM void __sinit_ov000_02183794(void) {
    float t;
    float a;
    float b;
    data_ov000_0218423c[4] = data_ov000_021838e8[1] + (data_ov000_021838e8[0] + (data_ov000_021838e8[3] + data_ov000_021838e8[2]));
    t = data_ov000_0218423c[0] + data_ov000_021838e8[3];
    a = data_ov000_021838e8[2];
    data_ov000_0218423c[3] = t;
    t = t + a;
    b = data_ov000_021838e8[0];
    data_ov000_0218423c[2] = t;
    t = t + b;
    data_ov000_0218423c[1] = t;
}
