#include <globaldefs.h>

struct Struct_020dafd4 {
    char pad0[0x50];
    unsigned char unknown_50_;
    unsigned char unknown_51_;
    unsigned char unknown_52_;
    unsigned char unknown_53_;
    char unknown_54_[0x64 - 0x54];
    unsigned char f64;
    char unknown_65_[0x68 - 0x65];
    short f68;
    short unknown_6a_;
};

// USA: func_020db0c4
extern "C" ARM void func_020db0c4(struct Struct_020dafd4* p) {
    p->f68 = -1;
    p->unknown_6a_ = 0;
    p->unknown_50_ = 0;
    p->unknown_52_ = 0;
    p->unknown_53_ = 1;
    p->unknown_51_ = 0;
    p->f64 = 0;
}
