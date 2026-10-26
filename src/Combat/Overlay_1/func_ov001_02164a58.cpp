#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov001_02164ba0[4];
extern float data_ov001_0216580c[7];

struct Struct_ov001_02165828;
extern "C" Struct_ov001_02165828* func_ov017_021d49d0(Struct_ov001_02165828* obj);
extern Struct_ov001_02165828 data_ov001_02165828;

// USA: func_ov001_02164a58
extern "C" __declspec(initcode) ARM void __sinit_ov001_02164a58(void) {
    float var0 = data_ov001_02164ba0[0] + data_ov001_02164ba0[3];
    float t2 = data_ov001_02164ba0[2] + var0;
    float var2 = data_ov001_02164ba0[1] + t2;
    data_ov001_0216580c[6] = var2;
    float var3 = data_ov001_0216580c[5] + data_ov001_02164ba0[0];
    float var4 = data_ov001_02164ba0[3];
    data_ov001_0216580c[4] = var3;
    float var5 = var3 + var4;
    float b8 = data_ov001_02164ba0[2];
    data_ov001_0216580c[3] = var5;
    float var7 = var5 + b8;
    data_ov001_0216580c[2] = var7;
    func_ov017_021d49d0(&data_ov001_02165828);
}
