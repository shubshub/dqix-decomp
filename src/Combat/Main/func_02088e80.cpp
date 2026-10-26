#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02088e80 {
    char pad0[0x14];
    int f14;
    int f18;
    char unknown_1c_[0x21 - 0x1c];
    unsigned char unknown_21_;
    unsigned short unknown_22_;
    unsigned char unknown_24_;
    char unknown_25_[0x32 - 0x25];
    short unknown_32_;
    short unknown_34_;
    char unknown_36_[0x3b - 0x36];
    unsigned char unknown_3b_;
    char unknown_3c_[0x58 - 0x3c];
    unsigned char unknown_58_[4];
    unsigned char unknown_5c_[0x23];
    unsigned char unknown_7f_[0x23];
};

// USA: func_02088e80
extern "C" ARM void func_02088e80(Obj02088e80* obj, int) {
    int var0 = 0;
    if (obj->f14 & 0x4) var0 = 1;
    obj->f14 = 1;
    obj->f18 = 0;
    obj->unknown_21_ = 0;
    obj->unknown_22_ &= ~0x3;
    obj->unknown_22_ &= ~0x3c;
    obj->unknown_22_ &= ~0x1c0;
    obj->unknown_22_ &= ~0xe00;
    obj->unknown_22_ &= ~0x3000;
    obj->unknown_24_ = 0;
    obj->unknown_22_ &= ~0x4000;
    obj->unknown_3b_ &= ~0x8;
    obj->unknown_3b_ &= ~0xf0;
    obj->unknown_3b_ &= ~0x4;
    obj->unknown_32_ = -1;
    obj->unknown_34_ = -1;
    if (var0) {
        obj->f14 |= 0x4;
    }
    memset(obj->unknown_58_, 0, 4);
    memset(obj->unknown_5c_, 0, 0x23);
    memset(obj->unknown_7f_, 0, 0x23);
}
