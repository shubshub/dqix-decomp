#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Struct_ov000_021838c8 {
    float f0;
    float f4;
    float f8;
    float fc;
};

struct Struct_ov000_02184220 {
    char pad0[8];
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
};

extern struct Struct_ov000_021838c8 data_ov000_021838c8;
extern struct Struct_ov000_02184220 data_ov000_02184220;

// USA: func_ov000_02183710
extern "C" __declspec(initcode) ARM void __sinit_ov000_02183710(void) {
    float var0 = data_ov000_021838c8.f0 + data_ov000_021838c8.f4;
    float var1 = data_ov000_021838c8.fc + var0;
    float var2 = data_ov000_021838c8.f8 + var1;
    data_ov000_02184220.f18 = var2;

    float var3 = data_ov000_02184220.f14 + data_ov000_021838c8.f0;
    float var4 = data_ov000_021838c8.f4;
    data_ov000_02184220.f10 = var3;
    float t2 = var3 + var4;
    float var6 = data_ov000_021838c8.fc;
    data_ov000_02184220.fc = t2;
    float var7 = t2 + var6;
    data_ov000_02184220.f8 = var7;
}
