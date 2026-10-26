#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0420[8];
extern float data_021079cc[8];

// USA: func_020e5e2c
extern "C" __declspec(initcode) ARM void __sinit_020e5e2c(void) {
#if defined(jpn)
    enum { Enum_020e5e2c_0 = 6, Enum_020e5e2c_2 = 0, Enum_020e5e2c_4 = 2, Enum_020e5e2c_0_2 = 3, Enum_020e5e2c_1 = 2, Enum_020e5e2c_2_2 = 4, Enum_020e5e2c_3 = 0, Enum_020e5e2c_4_2 = 1 };
#else
    enum { Enum_020e5e2c_0 = 0, Enum_020e5e2c_2 = 2, Enum_020e5e2c_4 = 4, Enum_020e5e2c_0_2 = 0, Enum_020e5e2c_1 = 1, Enum_020e5e2c_2_2 = 2, Enum_020e5e2c_3 = 3, Enum_020e5e2c_4_2 = 4 };
#endif
    float t;
    float a;
    float b;
    data_021079cc[Enum_020e5e2c_1] = data_020f0420[3] + (data_020f0420[Enum_020e5e2c_0] + (data_020f0420[Enum_020e5e2c_4] + data_020f0420[Enum_020e5e2c_2]));
    t = data_021079cc[Enum_020e5e2c_0_2] + data_020f0420[Enum_020e5e2c_4];
    a = data_020f0420[Enum_020e5e2c_2];
    data_021079cc[Enum_020e5e2c_4_2] = t;
    t = t + a;
    b = data_020f0420[Enum_020e5e2c_0];
    data_021079cc[Enum_020e5e2c_3] = t;
    t = t + b;
    data_021079cc[Enum_020e5e2c_2_2] = t;
}
