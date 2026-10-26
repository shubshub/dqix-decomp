#include <globaldefs.h>

struct Struct_ov025_021e5f54 {
    char pad0[0x21c];
    unsigned short unknown_21c_;
    char unknown_21e_[2];
    short unknown_220_;
    short unknown_222_;
};

struct Struct_ov025_021ef988_16 {
#if defined(jpn)
    char pad0[4];
#else
    char pad0[0xc];
#endif
    Struct_ov025_021e5f54* inner;
};

extern Struct_ov025_021ef988_16 data_ov025_021ef988;

struct Struct_ov025_021e5f54_2 {
    char pad0[8];
    unsigned int unknown_8_0_ : 1;
    unsigned int value : 15;
    unsigned int unknown_a_0_ : 1;
    unsigned int unknown_a_1_ : 1;
    unsigned int : 14;
    unsigned int limit : 15;
};

// USA: func_ov025_021e5f54
extern "C" ARM int func_ov025_021e5f54(Struct_ov025_021e5f54_2* p) {
    if (p->unknown_8_0_) {
        data_ov025_021ef988.inner->unknown_21c_ = p->value;
    } else {
        data_ov025_021ef988.inner->unknown_21c_ = 0;
    }
    if (p->unknown_a_0_) {
        data_ov025_021ef988.inner->unknown_220_ = 0x1e;
    } else {
        data_ov025_021ef988.inner->unknown_220_ = -1;
    }
    if (p->unknown_a_1_) {
        data_ov025_021ef988.inner->unknown_222_ = p->limit;
    } else {
        data_ov025_021ef988.inner->unknown_222_ = -1;
    }
    return 1;
}
