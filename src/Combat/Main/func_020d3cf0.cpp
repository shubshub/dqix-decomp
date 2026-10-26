#include <globaldefs.h>

#if defined(jpn)
struct Struct_020d3cf0_2 { unsigned char c[11]; };
#else
struct Struct_020d3cf0_2 { unsigned char c[16]; };
#endif

struct Struct_020d39dc_3 {
    struct Struct_020d3cf0_2 name;
    unsigned char b10;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned int unknown_1c_;
    unsigned short unknown_20_;
    unsigned short unknown_22_;
};

struct Struct_020d3cf0 {
    struct Struct_020d39dc_3 entries[5];
    int count;
};

// USA: func_020d3cf0
extern "C" ARM void func_020d3cf0(struct Struct_020d3cf0* c, struct Struct_020d39dc_3* src) {
    int idx = c->count;
    struct Struct_020d39dc_3* dst;
    if (idx >= 5) return;
#if defined(jpn)
    c->count = idx + 1;
    dst = &c->entries[idx];
#else
    dst = &c->entries[idx];
    c->count = idx + 1;
#endif
    dst->name = src->name;
    dst->b10 = src->b10;
    dst->unknown_11_ = src->unknown_11_;
    dst->unknown_12_ = src->unknown_12_;
    dst->unknown_13_ = src->unknown_13_;
    dst->unknown_14_ = src->unknown_14_;
    dst->unknown_18_ = src->unknown_18_;
    dst->unknown_1c_ = src->unknown_1c_;
    dst->unknown_20_ = src->unknown_20_;
    dst->unknown_22_ = src->unknown_22_;
}
