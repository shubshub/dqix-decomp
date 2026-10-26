#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d7f84[8];
extern float data_ov017_021d847c[8];

// USA: func_ov017_021d7288
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d7288(void) {
    float t;
    float a;
    float b;
    data_ov017_021d847c[6] = data_ov017_021d7f84[4] + (data_ov017_021d7f84[0] + (data_ov017_021d7f84[1] + data_ov017_021d7f84[3]));
    t = data_ov017_021d847c[5] + data_ov017_021d7f84[1];
    a = data_ov017_021d7f84[3];
    data_ov017_021d847c[4] = t;
    t = t + a;
    b = data_ov017_021d7f84[0];
    data_ov017_021d847c[3] = t;
    t = t + b;
    data_ov017_021d847c[2] = t;
}
