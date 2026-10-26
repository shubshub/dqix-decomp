#include <globaldefs.h>

struct Struct_0202ecc8 {
    unsigned int v[12];
};

struct Struct_0202ecc8_2 {
    char pad[0xf0];
    struct Struct_0202ecc8 block;
};

// USA: func_0202ecc8
extern "C" ARM void func_0202ecc8(struct Struct_0202ecc8_2* dst, struct Struct_0202ecc8* src) {
    dst->block = *src;
}
