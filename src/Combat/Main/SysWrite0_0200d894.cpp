#include <globaldefs.h>

struct Struct_020c129c {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int x1;
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int one;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c129c
extern "C" THUMB void Mat3x3_WriteRotationZ(Struct_020c129c* out, int y, int x) {
    out->unknown_0_ = x;
    out->unknown_4_ = y;
    out->unknown_8_ = 0;
    out->unknown_c_ = -y;
    out->x1 = x;
    out->unknown_14_ = 0;
    out->unknown_18_ = 0;
    out->unknown_1c_ = 0;
    out->one = 0x1000;
}
