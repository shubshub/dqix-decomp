#include <globaldefs.h>

struct Struct_02088624 {
    unsigned char pad0[0x14];
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned char unknown_1c_[6];
    unsigned short kind : 2;
};

// USA: func_02088624
extern "C" ARM void func_02088624(struct Struct_02088624* obj) {
    obj->unknown_14_ |= 0x2;
    obj->kind = 1;
}
