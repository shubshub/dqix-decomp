#include <globaldefs.h>

struct Struct_ov024_021e6060_2 {
    char pad0[0x2c];
    unsigned int unknown_2c_0_ : 10;
    unsigned int kind : 4;
    unsigned int unknown_2d_6_ : 18;
};

struct Struct_ov024_021e6060 {
    virtual void inline_ov024_021e6060();
};

typedef void (Struct_ov024_021e6060::*Type_ov024_021e6060)(int id, Struct_ov024_021e6060_2* rec, int amount);

extern unsigned int data_ov024_02200144[];
extern Type_ov024_021e6060 __ptmf_null;
extern Type_ov024_021e6060 data_ov024_021ff3f8[0xb];

// USA: func_ov024_021e6060
extern "C" ARM void func_ov024_021e6060(Struct_ov024_021e6060* self, int id, Struct_ov024_021e6060_2* rec, int amount) {
    if (!(data_ov024_02200144[1] & 1)) {
        data_ov024_021ff3f8[0] = __ptmf_null;
        data_ov024_021ff3f8[7] = __ptmf_null;
        data_ov024_02200144[1] |= 1;
    }
    if (rec->kind >= 0xb) return;
    if (data_ov024_021ff3f8[rec->kind] == 0) return;
    (self->*data_ov024_021ff3f8[rec->kind])(id, rec, amount);
}
