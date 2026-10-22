#include <globaldefs.h>

struct Struct_ov024_021e4b14_2 {
    char unknown_0_[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 27;
};

struct Struct_ov024_021e4b14 {
    virtual void inline_ov024_021e4b14();
    char unknown_4_[8];
    int unknown_c_;
};

typedef unsigned long long (Struct_ov024_021e4b14::*Type_ov024_021da9e0)(int a, int b, Struct_ov024_021e4b14_2* rec, int d);

struct Struct_ov024_021da9e0_4;
extern "C" void func_ov024_021eb4e4(Struct_ov024_021da9e0_4*, int);

extern unsigned int data_ov024_02200144[];
extern Handler_021e4b14 __ptmf_null;
extern Handler_021e4b14 data_ov024_021ff450[0x17];

// USA: func_ov024_021e4b14
extern "C" ARM unsigned long long func_ov024_021e4b14(Struct_ov024_021e4b14* arg0, int arg1, int arg2, Struct_ov024_021e4b14_2* arg3, int arg4) {
    if (!(data_ov024_02200144[2] & 1)) {
        data_ov024_021ff450[0] = __ptmf_null;
        data_ov024_021ff450[3] = __ptmf_null;
        data_ov024_02200144[2] |= 1;
    }
    if (arg3->unknown_18_0_ >= 0x17) return 0;
    if (data_ov024_021ff450[arg3->unknown_18_0_] == 0) return 0;
    func_ov024_021eb4e4((Struct_ov024_021da9e0_4*)arg0, arg0->unknown_c_);
    return (arg0->*data_ov024_021ff450[arg3->unknown_18_0_])(arg1, arg2, arg3, arg4);
}
