#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_ov017_021d7340 {
    float f0;
    int f4;
    int f8;
    float fc;
    float f10;
    float f14;
};
extern Struct_ov017_021d7340 data_ov017_021d7340;

struct Struct_ov017_021d82e0_3 {
    char pad[8];
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
};
extern Struct_ov017_021d82e0_3 data_ov017_021d82e0;

// USA: func_ov017_021d6d28
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6d28(void) {
    float a = data_ov017_021d7340.fc + data_ov017_021d7340.f10;
    float b = data_ov017_021d7340.f0 + a;
    float c = data_ov017_021d7340.f14 + b;
    data_ov017_021d82e0.f18 = c;
    float d = data_ov017_021d82e0.f14 + data_ov017_021d7340.fc;
    float var4 = data_ov017_021d7340.f10;
    data_ov017_021d82e0.f10 = d;
    float e = d + var4;
    data_ov017_021d82e0.f8 = e;
    float f = e + data_ov017_021d7340.f0;
    data_ov017_021d82e0.fc = f;
    data_ov017_021d7340.f4 = data_ov017_021d7340.f8 + 0xb;
}
