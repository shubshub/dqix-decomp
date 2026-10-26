#include <globaldefs.h>

struct Struct_02071874_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 8;
    unsigned int unknown_3_4_ : 4;
};

struct Struct_02071874_3 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 10;
    unsigned int unknown_2_4_ : 1;
    unsigned int unknown_2_5_ : 1;
    unsigned int unknown_2_6_ : 1;
    unsigned int unknown_2_7_ : 8;
    unsigned int unknown_3_7_ : 1;
};

struct Struct_02071874_5 {
    short f0;
    short f2;
    short f4;
    short unknown_6_;
    short f8;
    unsigned short fa;
    Struct_02071874_2 fc;
    Struct_02071874_3 f10;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    int f1c;
};

// USA: func_02071b38
extern "C" ARM void func_02071b38(Struct_02071874_5* s) {
    s->f0 = -1;
    s->f2 = -1;
    s->f4 = -1;
    s->unknown_6_ = -1;
    s->f8 = -1;
    unsigned short* pa = &s->fa;
    *pa &= ~0xf;
    *pa &= ~0xf0;
    *pa &= ~0xf00;
    *pa = (*pa & ~0xf000) | 0x1000;
    s->fc.unknown_0_0_ = 0;
    s->fc.unknown_1_2_ = 0;
    s->fc.unknown_2_4_ = 0;
    s->f10.unknown_0_0_ = 0;
    s->f10.unknown_1_2_ = 0;
    s->f10.unknown_2_4_ = 1;
    s->f10.unknown_2_5_ = 0;
    s->f10.unknown_2_6_ = 0;
    s->f10.unknown_2_7_ = 0;
    s->f14 = -1;
    s->unknown_16_ = -1;
    s->f18 = -1;
    s->unknown_1a_ = -1;
    s->f1c = 0;
}
