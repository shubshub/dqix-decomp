#include <globaldefs.h>

struct Struct_0204455c {
    char pad0[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
};

// USA: func_0204455c
extern "C" ARM void func_0204455c(void* p, short* out1, short* out2) {
    if (p == 0) return;
    struct Struct_0204455c* lv = (struct Struct_0204455c*)p;
    short a = lv->unknown_a8_;
    short b = lv->unknown_ac_;
    short c = lv->unknown_aa_;
    a <<= 3;
    b <<= 3;
    c <<= 3;
    *out1 = b + (a >> 1);
    *out2 = c - 10;
}
