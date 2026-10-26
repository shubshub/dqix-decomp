#include <globaldefs.h>

struct Struct_020a3578 {
    short f0;
    short f2;
    signed char f4;
    signed char unknown_5_;
    short unknown_6_;
    short f8;
    short fa;
    int fc;
    char pad10[0x24 - 0x10];
    signed char f24;
    signed char f25;
    char unknown_26_[0x2a - 0x26];
    signed char unknown_2a_;
    char unknown_2b_;
    int unknown_2c_;
    int unknown_30_;
    signed char f34;
    signed char unknown_35_;
};

// USA: func_020a3578
extern "C" ARM void func_020a3578(struct Struct_020a3578* s) {
    s->f0 = 0;
    s->unknown_6_ = 0;
    s->f8 = 0;
    s->fa = 0;
    s->unknown_2a_ = -1;
    s->unknown_2c_ = 0;
    s->unknown_30_ = 0;
    s->f34 = 0;
    s->fc = -1;
    s->f4 = 0;
    s->f2 = 0x75a4;
    s->f24 = 0;
    s->f25 = 0;
    s->unknown_35_ = 0;
    s->unknown_5_ = 2;
}
