#include <globaldefs.h>

struct Struct_020887d0 {
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

// USA: func_020887d0
extern "C" ARM int func_020887d0(struct Struct_020887d0* obj) {
    if (obj->unknown_18_ & 0x80) {
        if (obj->state == 5) {
            return 1;
        }
    }
    return 0;
}
