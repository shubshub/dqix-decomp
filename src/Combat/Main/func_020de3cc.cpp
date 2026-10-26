#include <globaldefs.h>

struct Struct_020de3cc {
    char pad10[0x10];
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int a : 8;
    unsigned int : 4;
};

// USA: func_020de3cc
extern "C" ARM int func_020de3cc(struct Struct_020de3cc* obj, int a, int b, int c) {
    return a == obj->a && b == obj->b && c == obj->c;
}
