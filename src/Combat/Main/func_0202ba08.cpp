#include <globaldefs.h>

struct Struct_0202ba08_3 { char v[6]; };
struct Struct_0202ba08_4 { char v[0x20]; };
struct Struct_0202ba08 { unsigned int v[0x20]; };

struct Struct_0202ba08_2 {
    unsigned short h0;
    unsigned short h2;
    struct Struct_0202ba08_3 unknown_4_;
    unsigned short ha;
    struct Struct_0202ba08_4 unknown_c_;
    unsigned short unknown_2c_;
    unsigned short unknown_2e_;
    unsigned short unknown_30_;
    unsigned short unknown_32_;
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    struct Struct_0202ba08 unknown_40_;
};

// USA: func_0202ba08
extern "C" ARM struct Struct_0202ba08_2* func_0202ba08(struct Struct_0202ba08_2* dst, struct Struct_0202ba08_2* src) {
    dst->h0 = src->h0;
    dst->h2 = src->h2;
    dst->unknown_4_ = src->unknown_4_;
    dst->ha = src->ha;
    dst->unknown_c_ = src->unknown_c_;
    dst->unknown_2c_ = src->unknown_2c_;
    dst->unknown_2e_ = src->unknown_2e_;
    dst->unknown_30_ = src->unknown_30_;
    dst->unknown_32_ = src->unknown_32_;
    dst->unknown_34_ = src->unknown_34_;
    dst->unknown_36_ = src->unknown_36_;
    dst->unknown_38_ = src->unknown_38_;
    dst->unknown_3a_ = src->unknown_3a_;
    dst->unknown_3c_ = src->unknown_3c_;
    dst->unknown_3e_ = src->unknown_3e_;
    dst->unknown_40_ = src->unknown_40_;
    return dst;
}
