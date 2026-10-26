#include <globaldefs.h>

struct Struct_020a99d0_4 { unsigned short v[70]; };
struct Struct_020a99d0_5 { unsigned char v[564]; };
struct Struct_020a99d0 { unsigned short v[6]; };
struct Struct_020a99d0_2 { unsigned char v[102]; };

struct Struct020a99d0 {
    struct Struct_020a99d0_4 a;
    struct Struct_020a99d0_5 b;
    struct Struct_020a99d0 c;
    struct Struct_020a99d0_2 d;
    unsigned char e;
};

// USA: func_020a99d0
extern "C" ARM void func_020a99d0(struct Struct020a99d0* dst, struct Struct020a99d0* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
}
