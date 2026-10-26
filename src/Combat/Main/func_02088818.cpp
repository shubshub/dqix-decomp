#include <globaldefs.h>

struct Struct_020886dc_2 {
    unsigned char unknown_0_[0x22];
    unsigned short : 9;
    unsigned short state : 3;
    unsigned short : 4;
    unsigned char pad24[0x6a - 0x24];
    unsigned char unknown_6a_;
    unsigned char unknown_6b_[0x8d - 0x6b];
    unsigned char unknown_8d_;
};

// USA: func_02088818
extern "C" ARM void func_02088818(struct Struct_020886dc_2* obj, unsigned short mode) {
    obj->state = mode;
    obj->unknown_6a_ = 5;
    obj->unknown_8d_ = 0;
}
