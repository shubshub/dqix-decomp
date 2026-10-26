#include <globaldefs.h>

struct Struct_0209daa4 {
    char pad[0x6c];
    int f6c;
    char pad2[0x14];
    int f84;
    int unknown_88_;
};

// USA: func_0209fde8
extern "C" ARM void func_0209fde8(struct Struct_0209daa4* p, int a, int b, int c) {
    p->f84 = a;
    p->unknown_88_ = c;
    p->f6c = b;
}
