#include <globaldefs.h>

struct Struct_020de36c {
    char pad8[8];
    unsigned int a : 4;
    unsigned int b : 5;
};

// USA: func_020de36c
extern "C" ARM int func_020de36c(struct Struct_020de36c* obj, int a, int unused, int b) {
    return a == obj->a && b == obj->b;
}
