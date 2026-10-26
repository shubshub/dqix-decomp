#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Struct_ov023_021fb1dc {
    unsigned int v[3];
};

// USA: func_ov023_021fb1dc
extern "C" ARM void func_ov023_021fb1dc(void* dst, void* src) {
    struct Struct_ov023_021fb1dc t;
    __clear(&t, 0xc);
    t.v[0] = *(unsigned int*)((char*)src + 0x28);
    t.v[2] = *(unsigned int*)((char*)src + 0x2c);
    *(struct Struct_ov023_021fb1dc*)dst = t;
}
