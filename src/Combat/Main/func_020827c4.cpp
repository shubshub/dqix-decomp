#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" unsigned char data_020e8bd8[];

struct Struct_020827c4 {
    unsigned char unknown_0_[0x14];
    unsigned char f14;
    unsigned char f15;
    unsigned short unknown_16_;
    unsigned short f18;
    unsigned short unknown_1a_;
};

// USA: func_020827c4
extern "C" ARM void func_020827c4(struct Struct_020827c4* p) {
    memcpy(p, data_020e8bd8, 0x14);
    p->f14 = p->f14 & ~1;
    p->f14 = (p->f14 & ~0xE) | 4;
    p->f14 = p->f14 & ~0xF0;
    p->f15 = p->f15 & ~0xF;
    p->f18 = 0x1000;
    p->unknown_1a_ = 0x1000;
    p->unknown_16_ = 0x36B7;
}
