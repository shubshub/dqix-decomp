#include <globaldefs.h>

struct Struct_ov017_021d2d00 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    signed char f3;
    unsigned char f4;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
    signed char unknown_7_;
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
    signed char fe;
};

// USA: func_ov017_021d2d00
extern "C" ARM void func_ov017_021d2d00(Struct_ov017_021d2d00* dst, Struct_ov017_021d2d00* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
    dst->f4 = src->f4;
    dst->unknown_5_ = src->unknown_5_;
    dst->unknown_6_ = src->unknown_6_;
    dst->unknown_7_ = src->unknown_7_;
    dst->f8 = src->f8;
    dst->fa = src->fa;
    dst->fc = src->fc;
    dst->fe = src->fe;
}
