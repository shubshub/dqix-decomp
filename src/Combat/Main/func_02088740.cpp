#include <globaldefs.h>

struct Struct_02088740 {
    unsigned char unknown_0_[0x18];
    unsigned int unknown_18_;
    unsigned char unknown_1c_[6];
    unsigned short : 9;
    unsigned short state : 3;
    unsigned short : 4;
    unsigned char pad24[0x6a - 0x24];
    unsigned char unknown_6a_;
    unsigned char unknown_6b_[0x8d - 0x6b];
    unsigned char unknown_8d_;
};

// USA: func_02088740
extern "C" ARM int func_02088740(struct Struct_02088740* obj) {
    if (obj->unknown_18_ & 0x80) {
        if (obj->state == 3) {
            return 1;
        }
    }
    return 0;
}
