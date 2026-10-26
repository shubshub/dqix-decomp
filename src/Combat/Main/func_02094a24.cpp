#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020421c4_4 {
    int f0, f4, f8, fc, f10;
    int arr[8];
    int f34, unknown_38_, f3c, f40;
    unsigned char buf[0x10];
    unsigned char unknown_54_, unknown_55_, unknown_56_, unknown_57_;
    unsigned char unknown_58_[9];
    unsigned char unknown_61_, unknown_62_, unknown_63_, f64;
};

// USA: func_02094a24
extern "C" ARM void func_02094a24(struct Struct_020421c4_4* s) {
    s->f0 = 0;
    s->f4 = 0;
    s->f8 = 0;
    s->fc = 0;
    s->f10 = 0;
    for (int i = 0; i < 8; i++) {
        s->arr[i] = -1;
    }
    s->f3c = -1;
    s->f40 = -1;
    s->unknown_38_ = -1;
    s->f34 = -1;
    memset(s->buf, 0, 0x10);
    s->unknown_55_ = 0;
    s->unknown_54_ = 0;
    s->unknown_56_ = 1;
    s->unknown_57_ = 0;
    s->unknown_62_ = 0;
    s->unknown_61_ = 0;
    s->unknown_63_ = 0;
    s->f64 = 0;
}
