#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Struct_ov023_021fb88c {
    unsigned int v[3];
};

// USA: func_ov023_021fb88c
extern "C" ARM void func_ov023_021fb88c(void* dst, void* src) {
    struct Struct_ov023_021fb88c t;
    __clear(&t, 0xc);
    t.v[0] = *(unsigned int*)((char*)src + 0xa8);
    t.v[2] = *(unsigned int*)((char*)src + 0xac);
    *(struct Struct_ov023_021fb88c*)dst = t;
}
