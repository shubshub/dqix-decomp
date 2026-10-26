#include <globaldefs.h>

struct Struct_02093b54 {
#if defined(jpn)
    char data[0xb];
#else
    char data[0x30];
#endif
};

struct Struct_02093ad8 {
    struct Struct_02093b54 payload;
#if defined(jpn)
    unsigned char unknown_b_;
#endif
    short unknown_30_;
    signed char unknown_32_;
    unsigned char unknown_33_;
};

// USA: func_02093b54
extern "C" ARM void func_02093b54(struct Struct_02093ad8* dst, struct Struct_02093ad8* src) {
    dst->payload = src->payload;
#if defined(jpn)
    dst->unknown_b_ = src->unknown_b_;
#endif
    dst->unknown_30_ = src->unknown_30_;
    dst->unknown_32_ = src->unknown_32_;
    dst->unknown_33_ = src->unknown_33_;
}
