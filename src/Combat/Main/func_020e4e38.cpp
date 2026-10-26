#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020e4e38_2 {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 6;
    unsigned int d : 6;
    unsigned int e : 2;
    unsigned int f : 1;
    unsigned int g : 1;
    unsigned int h : 1;
    unsigned int pad : 3;
};

struct Struct_020e4e38 {
    void* unknown_0_;
    char pad1[0x30];
    void* field0x34;
    struct Struct_020e4e38_2 packed;
};

extern "C" void func_020e4b34(void* obj, void* arg1, void* arg2,
    int p4, int p5, int p6, int p7, int p8, int p9, int p10, int arg10, int arg11);

// USA: func_020e4e38
extern "C" ARM void func_020e4e38(void* obj, struct Struct_020e4e38* src) {
    memset(obj, 0, 0xc);
    if (src != NULL) {
        func_020e4b34(obj, src->unknown_0_, src->field0x34,
            (unsigned char)src->packed.a, (unsigned char)src->packed.b,
            (unsigned char)src->packed.c, (unsigned char)src->packed.d,
            (unsigned char)src->packed.e, (unsigned char)src->packed.f,
            (unsigned char)src->packed.g, (unsigned char)src->packed.h, 0);
    }
}
