#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov025_021ef464[8];
extern float data_ov025_021ef988[8];

// USA: func_ov025_021ef288
extern "C" __declspec(initcode) ARM void __sinit_ov025_021ef288(void) {
#if defined(jpn)
    enum { Enum_ov025_021ef288_2 = 3, Enum_ov025_021ef288_3 = 2, Enum_ov025_021ef288_0 = 2, Enum_ov025_021ef288_5 = 6, Enum_ov025_021ef288_6 = 4, Enum_ov025_021ef288_1 = 7, Enum_ov025_021ef288_4 = 0 };
#else
    enum { Enum_ov025_021ef288_2 = 2, Enum_ov025_021ef288_3 = 3, Enum_ov025_021ef288_0 = 0, Enum_ov025_021ef288_5 = 5, Enum_ov025_021ef288_6 = 6, Enum_ov025_021ef288_1 = 1, Enum_ov025_021ef288_4 = 4 };
#endif
    float t;
    float a;
    float b;
    data_ov025_021ef988[Enum_ov025_021ef288_0] = data_ov025_021ef464[1] + (data_ov025_021ef464[Enum_ov025_021ef288_3] + (data_ov025_021ef464[Enum_ov025_021ef288_2] + data_ov025_021ef464[4]));
    t = data_ov025_021ef988[Enum_ov025_021ef288_5] + data_ov025_021ef464[Enum_ov025_021ef288_2];
    a = data_ov025_021ef464[4];
    data_ov025_021ef988[Enum_ov025_021ef288_6] = t;
    t = t + a;
    b = data_ov025_021ef464[Enum_ov025_021ef288_3];
    data_ov025_021ef988[Enum_ov025_021ef288_1] = t;
    t = t + b;
    data_ov025_021ef988[Enum_ov025_021ef288_4] = t;
}
