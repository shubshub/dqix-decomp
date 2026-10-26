#include <globaldefs.h>

struct Struct_02088418 {
    unsigned char unknown_0_[0x14];
    unsigned int unknown_14_;
    unsigned char pad18[0x22 - 0x18];
    unsigned short : 2;
    unsigned short field22 : 4;
    unsigned short : 10;
};

// USA: func_02088418
extern "C" ARM int func_02088418(struct Struct_02088418* c, int index, int arg2) {
    unsigned int flags = c->unknown_14_;
    if (flags & 0x1) return 0;
    if ((flags & 0x1000000) && arg2 != 0x1fc && arg2 != 0x20f) return 0;
    if (flags & 0x8) return 0;
    if (flags & 0x80000) {
        if (index == c->field22) return 0;
    }
    return 1;
}
