#include <globaldefs.h>

struct Struct_ov000_02165f90 { char v[8]; };

struct Struct_ov000_02165f90_2 {
    unsigned short a;
    Struct_ov000_02165f90 unknown_2_;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    Struct_ov000_02165f90 unknown_d_;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
};

// USA: func_ov000_02165f90
extern "C" ARM void func_ov000_02165f90(struct Struct_ov000_02165f90_2* dst, struct Struct_ov000_02165f90_2* src) {
    dst->a = src->a;
    dst->unknown_2_ = src->unknown_2_;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->b3 = src->b3;
    dst->unknown_d_ = src->unknown_d_;
    dst->c1 = src->c1;
    dst->c2 = src->c2;
    dst->c3 = src->c3;
}
