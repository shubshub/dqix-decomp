#include <globaldefs.h>

struct Struct_ov016_0218fea0_2 {
    unsigned char kind;
    short value;
};

struct Struct_ov016_0218fea0 {
    int value;
    int kind;
};

// USA: func_ov016_0218fea0
extern "C" ARM Struct_ov016_0218fea0* func_ov016_0218fea0(Struct_ov016_0218fea0* dst, const Struct_ov016_0218fea0_2* src) {
    dst->kind = src->kind;
    dst->value = src->value;
    return dst;
}
