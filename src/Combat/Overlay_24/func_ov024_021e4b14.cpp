#include <globaldefs.h>

struct Struct_ov024_021e4b14_2 {
    char pad0[0x18];
    unsigned int unknown_18_0_ : 5;
    unsigned int rest : 27;
};

struct Struct_ov024_021e4b14 {
    virtual void inline_ov024_021e4b14();
    char pad4[8];
    int fc;
};

typedef unsigned long long (Struct_ov024_021e4b14::*Type_ov024_021da9e0)(int a, int b, Struct_ov024_021e4b14_2* rec, int d);

struct Struct_ov024_021da9e0_4;
extern "C" void func_ov024_021eb4e4(Struct_ov024_021da9e0_4*, int);

extern unsigned int data_ov024_02200144[];
extern Type_ov024_021da9e0 __ptmf_null;
extern Type_ov024_021da9e0 data_ov024_021ff450[0x17];

// USA: func_ov024_021e4b14
extern "C" ARM unsigned long long func_ov024_021e4b14(Struct_ov024_021e4b14* self, int a, int b, Struct_ov024_021e4b14_2* rec, int d) {
    if (!(data_ov024_02200144[2] & 1)) {
        data_ov024_021ff450[0] = __ptmf_null;
        data_ov024_021ff450[3] = __ptmf_null;
        data_ov024_02200144[2] |= 1;
    }
    if (rec->unknown_18_0_ >= 0x17) return 0;
    if (data_ov024_021ff450[rec->unknown_18_0_] == 0) return 0;
    func_ov024_021eb4e4((Struct_ov024_021da9e0_4*)self, self->fc);
    return (self->*data_ov024_021ff450[rec->unknown_18_0_])(a, b, rec, d);
}
