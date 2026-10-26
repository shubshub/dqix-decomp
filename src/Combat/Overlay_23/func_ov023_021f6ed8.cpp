#include <globaldefs.h>

struct Struct_ov023_021f6ed8 {
    char pad0[4];
    unsigned short f4;
    unsigned short unknown_6_;
    unsigned short f8;
    char unknown_a_[2];
    unsigned char fc;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
};

// USA: func_ov023_021f6ed8
extern "C" ARM void func_ov023_021f6ed8(Struct_ov023_021f6ed8* obj) {
    obj->f4 = 0xffff;
    obj->unknown_6_ = 0;
    obj->f8 = 0;
    obj->f10 = 0;
    obj->f14 = 0;
    obj->f18 = 0;
    obj->fc = 0;
    obj->f1c = 0;
}
