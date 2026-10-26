#include <globaldefs.h>

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20; int f24; int f28; int unknown_2c_; int unknown_30_;
    int f34; int unknown_38_; int f3c; int f40;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

// USA: func_02078484
extern "C" ARM void func_02078484(struct Struct_02078398_2* p) {
    p->unknown_0_ = 0;
    p->f10 = 1;
    p->f12 = 0;
    p->f14 = -1;
    p->unknown_16_ = -1;
    p->f18 = -1;
    p->unknown_1a_ = -1;
    p->f1c = -0x1000;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = 0;
    p->unknown_2c_ = 0;
    p->unknown_30_ = 0;
    p->f34 = 0;
    p->unknown_38_ = 0;
    p->f3c = 0;
    p->f40 = 0;
    p->unknown_44_ = 0x1000;
    p->unknown_48_ = 0x1000;
    p->unknown_4c_ = 0x1000;
    p->b0 = 0;
    p->b1 = 0;
    p->b2 = 1;
    p->b3 = 0;
    p->unknown_11_4_ = 0;
    p->unknown_11_5_ = 0;
    p->unknown_11_6_ = 0;
    p->unknown_11_7_ = 0;
}
