#include <globaldefs.h>

struct Struct_02082d38 {
    unsigned char bytes[0x16];
};

struct Struct_02082828 {
    unsigned char arr[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
};

// USA: func_02082d38
extern "C" ARM void func_02082d38(struct Struct_02082828 *dst, struct Struct_02082828 *src) {
    *(struct Struct_02082d38*)dst->arr = *(struct Struct_02082d38*)src->arr;
    dst->unknown_16_ = src->unknown_16_;
    dst->unknown_17_ = src->unknown_17_;
}
