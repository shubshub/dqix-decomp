#include <globaldefs.h>

struct Struct_ov023_021ecbbc {
    char pad0[0x433];
    unsigned char unknown_433_;
    char pad1[0x438 - 0x434];
    unsigned short unknown_438_;
    char pad2[0x43c - 0x43a];
    unsigned char unknown_43c_;
};

// USA: func_ov023_021ecbbc
extern "C" ARM void func_ov023_021ecbbc(Struct_ov023_021ecbbc* obj) {
    obj->unknown_438_ &= ~0x100;
    obj->unknown_438_ |= 0x40;
    obj->unknown_43c_ = 0;
    obj->unknown_433_ = 0;
}
